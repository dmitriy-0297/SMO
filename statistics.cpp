#include "statistics.h"

Statistics::Statistics(std::vector<Request> Requests,  std::vector<Source> srCount,  std::vector<Device> dvCount)
{
    for(int i = 0; i != int(Requests.size()); i++){
        this->Requests.push_back(Requests[i]);
    }
    for(int i = 0; i != int(srCount.size()); i++){
        this->srCount.push_back(srCount[i]);
    }
    for(int i = 0; i != int(dvCount.size()); i++){
        this->dvCount.push_back(dvCount[i]);
    }
}

void Statistics::setKDev(){
    for(int i = 0; i < int(dvCount.size()); i++){//вектор отбработаных приборами заявок
        int tmp = 0;
        for(int j = 0; j < int(dvCount.at(i).getEndReq().size()); j++){
            this->endReq.push_back(dvCount.at(i).getEndReq().at(j));
            tmp++;
        }
        endReq[int(endReq.size()) - tmp].setEndTimeWork(endReq[int(endReq.size()) - tmp].getTime() + endReq[int(endReq.size()) - tmp].getServiceTime());
        endReq[int(endReq.size()) - tmp].setBuffTime(0);
        for(int j = int(endReq.size()) - tmp + 1 ; j != int(endReq.size()); j++){
            endReq[j].setEndTimeWork(endReq[j-1].getEndTimeWork() + endReq[j].getServiceTime());//время когда заявка вышла из приборв
            endReq[j].setBuffTime(endReq[j-1].getServiceTime());//добавление времени заявки в буфере
            if(j == int(endReq.size()) - 1){
                dvCount[i].setK(dvCount[i].getSumTimeDev()/endReq[j].getEndTimeWork());//коэфицент прибора
            }
        }
    }
}

void Statistics::setRequests(){
    for(int i = 0; i < int(Requests.size()); i++){ //вывод вектора всех заявок с временем на приборе
        for (int j = 0; j < int(endReq.size()); j++){
            if(Requests[i].getTime() == endReq[j].getTime() && Requests[i].getNumberSource() == endReq[j].getNumberSource() && Requests[i].getNumberReq() == endReq[j].getNumberReq()){
                Requests[i].setServiceTime(endReq[j].getServiceTime());
                Requests[i].setBuffTime(endReq[j].getBuffTime());
            }
        }
    }
}
void Statistics::setP(){
    double n = 0; //общее количество заявок сгенерированных источником
    double m = 0; //количество заявок этого источника получивших отказ
    for(int i = 0; i < int(srCount.size()); i++){// выражаем вероятность отказов для каждого источника
        for(int j = 0; j < int(Requests.size()); j++){
            if (Requests[j].getNumberSource() == srCount[i].getNumSource()){
                n++;
                if (Requests[j].getServiceTime() == 0){
                    m++;
                }
            }
        }
        double p = m / n;
        srCount[i].setP(p);
        n = 0;
        m = 0;
    }
}
void Statistics::setTInBuff(){
    double n = 0;
    double sumTimeInBuff = 0; //суммарное время в буфере
    for(int i = 0; i != int(srCount.size()); i++){// выражаем среднее время в буфере для каждого источника
        for(int j = 0; j < int(Requests.size()); j++){
            if (Requests[j].getNumberSource() == srCount[i].getNumSource()){
                n++;//количество заявок источника
                sumTimeInBuff = Requests[j].getBuffTime() + sumTimeInBuff;//суммарное время прибывая в буфере заявок данного источника
            }
        }
        double averTimeBuff = sumTimeInBuff / n;
        srCount[i].setTimeInBuff(averTimeBuff);
        n = 0;
        sumTimeInBuff = 0;
    }
}
void Statistics::setTOnDev(){
    double n = 0;
    double sumTimeDev = 0;//суммарное время на приборе
    for(int i = 0; i != int(srCount.size()); i++){// выражаем среднее время на приборах заявок данного источника
        for(int j = 0; j < int(Requests.size()); j++){
            if(Requests[j].getNumberSource() == srCount[i].getNumSource()){
                if(Requests[j].getServiceTime() != 0){
                    n++;//количество заявок источника
                    sumTimeDev = Requests[j].getServiceTime() + sumTimeDev;//суммарное время прибывания на приборах
                }
            }
        }
        double averTimeServ = sumTimeDev / n;
        srCount[i].setTimeOnDev(averTimeServ);
        n = 0;
        sumTimeDev = 0;
    }
}
void Statistics::setTInSys(){
    double timeInSys = 0;//время в системе
    for(int i = 0; i != int(srCount.size()); i++){// выражаем среднее время заявок данного источника в системе
        timeInSys = srCount[i].getTimeInBuff() + srCount[i].getTimeInDev();
        srCount[i].setTimeInSys(timeInSys);
        timeInSys = 0;
    }
}
void Statistics::setDispBuff(){
    double n = 0;
    double dispBuff = 0;
    double sumTimeInBuffPow = 0;
    for(int i = 0; i != int(srCount.size()); i++){// выражаем дисперсию в буфере для каждого источника
        for(int j = 0; j < int(Requests.size()); j++){
            if (Requests[j].getNumberSource() == srCount[i].getNumSource()){
                n++;//количество заявок источника
                sumTimeInBuffPow = (Requests[j].getBuffTime() - srCount[i].getTimeInBuff())*(Requests[j].getBuffTime() - srCount[i].getTimeInBuff()) + sumTimeInBuffPow;
            }
        }
        double averTimeBuffPow = sumTimeInBuffPow / n;
        dispBuff = averTimeBuffPow;
        srCount[i].setDispBuff(dispBuff);
        n = 0;
        sumTimeInBuffPow = 0;
        dispBuff = 0;
    }
}
void Statistics::setDispDev(){
    double n = 0;
    double dispDev = 0;
    double sumTimeOnDevPow = 0;
    for(int i = 0; i != int(srCount.size()); i++){// выражаем дисперсию на приборе для каждого источника
        for(int j = 0; j < int(Requests.size()); j++){
            if (Requests[j].getNumberSource() == srCount[i].getNumSource()){
                if(Requests[j].getServiceTime() != 0)
                    n++;//количество заявок источника
                sumTimeOnDevPow = (Requests[j].getServiceTime() - srCount[i].getTimeInDev()) * (Requests[j].getServiceTime() - srCount[i].getTimeInDev()) + sumTimeOnDevPow;
            }
        }
        double averTimeServPow = sumTimeOnDevPow / n;
        dispDev = averTimeServPow;
        srCount[i].setDispDev(dispDev);
        n = 0;
        sumTimeOnDevPow = 0;
        dispDev = 0;
    }
}

void Statistics::autoMod(){
    setKDev();
    setRequests();
    setP();
    setTInBuff();
    setTOnDev();
    setTInSys();
    setDispBuff();
    setDispDev();
    for(int i = 0; i < int(srCount.size()); i++){//первая таблица(Source)
        std::cout << "Source Num: " << i << "\t" << "CountReq: " << srCount[i].getCountReq() << "\t" << "P: " << srCount[i].getP() << "     \t" <<"T in sys: " << srCount[i].getTimeInSys() << "    \t" << "T in Buff: " << srCount[i].getTimeInBuff() << "     \t" << "T on dev: " << srCount[i].getTimeInDev() << "    " << "Buff Disp: " << srCount[i].getDispBuff() << "   \t" <<"Dev Disp: " << srCount[i].getDispDev() << std::endl;
    }
    for(int i = 0; i < int(dvCount.size()); i++){//вторая таблица(Dev)
        std::cout << "Dev Num: " << i << " K: " << dvCount[i].getK() << std::endl;
    }
}

void Statistics::setInf(std::vector<Request> Requests,  std::vector<Source> srCount,  std::vector<Device> dvCount){
    for(int i = 0; i != int(Requests.size()); i++){
        this->Requests.push_back(Requests[i]);
    }
    for(int i = 0; i != int(srCount.size()); i++){
        this->srCount.push_back(srCount[i]);
    }
    for(int i = 0; i != int(dvCount.size()); i++){
        this->dvCount.push_back(dvCount[i]);
    }
}

void Statistics::setEvents(Event& ev){
    this->Events.push_back(ev);
}

void Statistics::printEvents(){
    for(int i = 0; i < int(Events.size()); i++){
        this->Events[i].printStCount();
        this->Events[i].printBuff();
        this->Events[i].printDvCount();
    }
}

std::vector<Event> Statistics::getEvents(){
    return Events;
}

std::vector<Source> Statistics::getSrCount(){
    return srCount;
}

std::vector<Device> Statistics::getDvCount(){
    return dvCount;
}
