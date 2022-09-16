#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService * tempHumidServ)
{
    this->service = serv;
    this->clockService = clockServ;
    this->tempHumidService = tempHumidServ;
    this->lightState = LIGHT_OFF;

}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton") 
    {   
        service->updateState("modeButton");         //service에서 
    }
    if (strBtn == "powerButton") 
    {   
        service->updateState("powerButton");         //service에서 
    }
   
   if (strBtn == "clockUpdate") 
    {   
        clockService->updateEvent();      // ("clockUpdate") = 1초 간격으로 신호 => 없어도 된다
    }
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    tempHumidService->updateTempHumid(dhtData);
    service->updateTempHumid(dhtData);
}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
}