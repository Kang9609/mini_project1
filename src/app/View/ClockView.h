#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#pragma once

#include <time.h>
#include "LCD.h"

class ClockView
{
private:
    struct tm timeDate;     // ClockService에서 넘어온 값
    LCD *lcd;

public:
    ClockView(LCD *lcd);
    virtual ~ClockView();
    void updateTime(struct tm *timeData);
};

#endif