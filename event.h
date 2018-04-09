#ifndef EVENT_H
#define EVENT_H

#include "buffer.h"
#include "request.h"
#include "source.h"
#include "dev.h"
#include "vector"

class Event
{
private:
    int sizeBuff;//размер буфера
    int sourceCount;//количество источниеов
public:
    std::vector<Source> srCount;//вектор источников
    std::vector<Device> dvCount;//вектор приборов
    Buffer Buff;//буффер
    Event(Buffer& buff, int sizeBuff, int sourceCount, std::vector<Source> srCount, std::vector<Device> dvCount);
    void printBuff();//выводим буфер
    void printStCount();//выводим источники
    void printDvCount();//выводим девайсы
    int getSizeBuff();//возвращаем размер буфера
    int getCountDev();//возвращаем количество приборов
    int getCountSr();//возвращаем количество приборов
};

#endif // EVENT_H
