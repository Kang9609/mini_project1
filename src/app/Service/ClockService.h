#ifndef CLOCKSERVICE_H
#define CLOCKSERVICE_H

#pragma once

#include <time.h>
#include <ClockView.h>

class ClockService
{
private:
    time_t curTime;
    ClockView *clockView;        // ClcokService가 ClockView에게 message를 전달해야하니

public:
    ClockService(ClockView *view);                 
    virtual ~ClockService();
    void updateEvent();

};

#endif