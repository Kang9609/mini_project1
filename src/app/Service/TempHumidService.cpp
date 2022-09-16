#include "TempHumidService.h"

TempHumidService::TempHumidService(TempHumidView *tempHumidView)
{
    this->tempHumidView = tempHumidView;
}

TempHumidService::~TempHumidService()
{

}
void TempHumidService::updateTempHumid(DHT_Data dhtData)
{
    float temp, humid;       // float = 실수형 (부동 소수점)
    temp = (float)dhtData.Temp + (float)(dhtData.TempDec/10.0);
    humid = (float)dhtData.RH + (float)(dhtData.RH/10.0);
    tempHumidView->setTempHumidData(temp, humid);
}