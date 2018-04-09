#include "model.h"

Model::Model(){

}

Model::Model(double lambda, int sourceCount, int requestCount, int sizeBuffer, int deviceCount, double intA, double intB)
{
    this->requestCount = requestCount;
    this->sourceCount = sourceCount;
    this->sizeBuffer = sizeBuffer;
    this->lambda = lambda;
    this->deviceCount = deviceCount;
    this->intA = intA;
    this->intB = intB;
}
/* заявка с полями равными -1
 * есть пустая заявка- зануленная */
void Model::start(int flag){
    std::vector<Request> Requests; //вектор всех заявок
    std::vector<Source> srCount; //вектор Источников
    std::vector<Device> dvCount; //вектор девайсов
    Buffer Buff(sizeBuffer, sourceCount); //обьект буфера
    DispatchManager DM;//первый диспетчер, отвечающий за постановку в буфер заявок
    Dispatchservice DS; //диспетчер выборки
    Request kickReq; //кикнутая заявка
    Statistics Stat(Requests, srCount, dvCount); //обьект статистики*/
    int check = 0;
    std::cout << std::endl;
    for(int i = 0; i < sourceCount; i++){
        Source sr(lambda, i+1);
        srCount.push_back(sr);
        srCount.at(i).clk();
    }
    for(int i = 0; i < deviceCount; i++){
        dvCount.push_back(Device(intA, intB, i));
    }
    /*сначала генерируем время в векторе источников у каждого элемента,
     *  затем ищем элемент с наименьшим временем генерации,
     *  создаем в нем заявку
     *  отправляем заявку в буфер
     *  генерируем новое время для данного элемента вектора источников*/
    for(int i = 0; i < requestCount; i++){
        int sourcEarlyReq = minNum(srCount); //номер источника с наименьшей генерацией заявки
        Request Req = srCount.at(sourcEarlyReq).requestGeneration(); //созданеи заявки
        Requests.push_back(Req);
        if(flag == 0){
            Event Ev(Buff, sizeBuffer, sourceCount, srCount, dvCount);
            Stat.setEvents(Ev);//+ 1 одно событие
        }
        kickReq = DM.checkBuff(Buff); //проверка буфера на свободное место
        if (DM.getDelNumSource() != -1){ //для пошаговой отладки количество отказаных заявок у каждого источника
            for(int j = 0; j < int(srCount.size()); j++){
                if (srCount[j].getNumSource() == DM.getDelNumSource()){
                    srCount[j].plusCountDelReq();
                }
            }
        }
        /*Req - текущая заявка
           * kickReq - кикнутая заявка, та что передней
           * ищем время прибывания в буфере
           * у заявки которая удаляется -
           * - время генерации заявки, которая встает на место удаленной минус
           * время генерации удаленной заявки*/
        if (kickReq.getNumberReq() != -1 && kickReq.getNumberSource() != -1 && kickReq.getNumberSource() != -1){
            kickReq.setBuffTime(Req.getTime() - kickReq.getTime());
            for(int i = 0; i < int(Requests.size());i++){
                if(Requests[i].getNumberReq() == kickReq.getNumberReq() && Requests[i].getNumberSource() == kickReq.getNumberSource() && Requests[i].getTime() == kickReq.getTime()){
                    Requests[i].setBuffTime(kickReq.getBuffTime());
                }
            }
            kickReq.setTime(-1);
            kickReq.setNumberReq(-1);
            kickReq.setNumberSource(-1);
        }
        DM.setElement(Req, Buff); //добавленеи элемента
        srCount.at(sourcEarlyReq).clk();//генерируем новое время для номера источника с наим. временем генерации
        double avTime = dvCount.at(DS.firstDev(dvCount)).getServiceTime();
        if(Req.getTime() >= avTime){
            DS.getRequest(dvCount, Buff);
            if(flag == 0){
                Event Ev(Buff, sizeBuffer, sourceCount, srCount, dvCount);//+ 1 одно событие
                Stat.setEvents(Ev);//stepMod
            }
        }
    }
    check = Buff.checkBuff();//проверка, что в в буфере есть пустые заявки
    for (int i = 0; i < check; i++){
        DS.getRequest(dvCount, Buff);
        if(flag == 0){
            Event Ev(Buff, sizeBuffer, sourceCount, srCount, dvCount);//+ 1 одно событие
            Stat.setEvents(Ev);//stepMod
        }
    }
    if(flag == 0){
        Stat.printEvents();//stepMod
        for(int i = 0; i != int(Stat.getEvents().size()); i++){
            this->events.push_back(Stat.getEvents().at(i));
        }
    }else{
        if(flag == 1){
            Stat.setInf(Requests, srCount, dvCount);//autoMod
            Stat.autoMod();//autoMod
            for(int i = 0; i != int(Stat.getDvCount().size()); i++){
               this->dvices.push_back(Stat.getDvCount()[i]);
            }
            for(int i = 0; i != int(Stat.getSrCount().size()); i++){
                this->sorces.push_back(Stat.getSrCount()[i]);
            }
        }
    }
}

int Model::minNum(std::vector<Source> srCount)//поиск min элемента
{
    int n = 0;
    for (int i = 0; i < sourceCount; i++) {
        if (srCount.at(i).getGenerationTime() < srCount.at(n).getGenerationTime()) {
            n = i;
        }
    }
    return n;
}

std::vector<Event> Model::getEvents(){
    return this->events;
}

std::vector<Source> Model::getSrCount(){
    return this->sorces;
}

std::vector<Device> Model::getDvCount(){
    return this->dvices;
}

