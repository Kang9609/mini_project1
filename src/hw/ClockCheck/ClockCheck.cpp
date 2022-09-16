#include "ClockCheck.h"

ClockCheck::ClockCheck()
{
    prevSec = 0;
}

ClockCheck::~ClockCheck()
{

}

bool ClockCheck::isUpdate()
{
    time_t curSec = time(NULL);         // 현재 시간을 읽어옴
    if (curSec == prevSec)
    {
        return false;
    }
    else{
        prevSec = curSec;               // 거짓이면 맞춰주고 가야한다
        return true;
    }
    return false;
}