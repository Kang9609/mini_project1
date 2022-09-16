#ifndef __LISTENER_H__
#define __LISTENER_H__

#include "Button.h"
#include "ClockCheck.h"
#include "Controller.h"
#include "DHT11.h"
#include "DHT_data.h"
#include "UltraSonic.h"


class Listener
{
private :
    Button *modeButton;
    Button *powerButton;
    ClockCheck *clockCheck;
    Controller *controller;
    DHT11 *dht11;
    UltraSonic *ultraSonic;

public:
    Listener(Button *modeButton, Button *powerButton, Controller *control, 
                ClockCheck *clock, DHT11 *dht11, UltraSonic *ultraSonic);    // 해당 주소를 받아와서 그곳의 instance를 직접 제어한다
    virtual ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */
