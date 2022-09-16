#include "ClockService.h"

ClockService::ClockService(ClockView *view)
{
    curTime = 0;
    clockView = view;
}

ClockService::~ClockService()
{

}

void ClockService::updateEvent()                 // 시간 계산 필요
{
    curTime = time(NULL);
    struct tm *timeDate = localtime(&curTime);   // struct tm : 기존의 timer 구조체 사용하겠다
    clockView->updateTime(timeDate);            // timeDate를 ClockView 쪽으로 넘겨줘야한다
}