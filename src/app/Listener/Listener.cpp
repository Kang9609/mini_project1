#include <wiringPi.h>
#include "Listener.h"


Listener::Listener(Button *modeButton, Button *powerButton, Controller *control, ClockCheck *clock, DHT11 *dht11, UltraSonic *ultraSonic)
{
    this->modeButton = modeButton;
    this->powerButton = powerButton;
    this->controller = control;
    this->clockCheck = clock;
    this->dht11 = dht11;
    this->ultraSonic = ultraSonic;  // 내가 가진 변수를 매개변수로 
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }
    
    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }

    if (clockCheck->isUpdate())   // 이것이 true 이면  || timeClock = 시간 감시
    {
        controller->updateEvent("clockUpdate");
    } 

    static unsigned int prevTempHumidTime = 0;   // 정의되지 않은 정적 변수 선언
    if (millis() - prevTempHumidTime > 2000)     // 1milsec씩 증가한 값을 리턴해준다
    {     
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11->readData();
        if (!dhtData.error)     // ! = 0이 아니다 => 참
        {
            controller->updateTempHumid(dhtData);   // updateEvent는 string 값을 받고 있으니
        }
    }

    static unsigned int prevUltraSonicTime = 0;   // 정의되지 않은 정적 변수 선언
    if (millis() - prevUltraSonicTime > 1000)     // 1milsec씩 증가한 값을 리턴해준다
    {     
        prevUltraSonicTime = millis();
        int distance = ultraSonic->readDistance();
        controller->updateDistance(distance);
    }
}