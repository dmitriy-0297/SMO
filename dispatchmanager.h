#ifndef DISPATCHMANAGER_H
#define DISPATCHMANAGER_H

#include"request.h"
#include"buffer.h"

class DispatchManager//диспетчер постановки заявок
{
private:
    //int sizeBuff(); //размер буфера
    int countRef; //количество отказов
    int NumSourceWithDel; // номер источника с отказом
public:
    DispatchManager();
    void setElement(Request& req, Buffer& Bf);//добавление элементов в буфер
    Request checkBuff(Buffer& Bf);//добавление заявки если буфер поплон
    int getCountRef();//получение количество отказаных заявок
    int getDelNumSource();//номер источника с отказаной заявкой;
};

#endif // DISPATCHMANAGER_H
