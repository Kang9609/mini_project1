#ifndef TEMPHUMIDVIEW_H
#define TEMPHUMIDVIEW_H

#pragma once

#include "LCD.h"
#include "Led.h"

class TempHumidView
{
private:
    LCD *lcd;

public:
    TempHumidView(LCD *lcd);
    ~TempHumidView();
    void setTempHumidData(float temp, float humid);



};

#endif