#ifndef TEMPHUMIDSERVICE_H
#define TEMPHUMIDSERVICE_H

#pragma once

#include "DHT_data.h"
#include "TempHumidView.h"


class TempHumidService
{
private:TempHumidView *tempHumidView;

public:
    TempHumidService(TempHumidView *tempHumidView);
    virtual ~TempHumidService();
    void updateTempHumid(DHT_Data dhtData);
};

#endif