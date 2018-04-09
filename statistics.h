#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <request.h>
#include <source.h>
#include <dev.h>
#include <buffer.h>
#include <event.h>
#include <vector>

class Statistics
{
private:
    std::vector<Request> Requests; //вектор всех заявок
    std::vector<Source> srCount; //вектор Источников
    std::vector<Device> dvCount; //вектор девайсов
    std::vector<Request> endReq; //вектор отработаных заявок
    std::vector<Event> Events; //вектор событий
public:
    Statistics(std::vector<Request> Requests,  std::vector<Source> srCount,  std::vector<Device> dvCount);
    void setKDev();//считаем K прибора
    void setRequests();//заполняем полный вектор заявок
    void setP();//выражаем вероятность отказов для каждого источника
    void setTInBuff();//выражаем среднее время в буфере для каждого источника
    void setTOnDev();//выражаем среднее время на приборах заявок данного источника
    void setTInSys();//выражаем среднее время заявок данного источника в системе
    void setDispBuff();//выражаем дисперсию в буфере для каждого источника
    void setDispDev();//выражаем дисперсию на приборе для каждого источника
    void setInf(std::vector<Request> Requests,  std::vector<Source> srCount,  std::vector<Device> dvCount);//ввод векторов для AutoMod
    void autoMod();//автоматический режим
    void setEvents(Event& ev);// добавление события в вектор
    void printEvents();//печать событий - пошаговый режим
    std::vector<Event> getEvents();//получение вектора событий
    std::vector<Source> getSrCount();
    std::vector<Device> getDvCount();
};

#endif // STATISTICS_H
