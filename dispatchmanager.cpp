#include "dispatchmanager.h"

DispatchManager::DispatchManager(){
    this->countRef = 0;
    this->NumSourceWithDel = -1;
}

void DispatchManager::setElement(Request& req,Buffer& Bf){
    for(Bf.iter = Bf.Buff.begin(); Bf.iter != Bf.Buff.end(); Bf.iter++){
        if (Bf.iter->getTime() == -1){
            *Bf.iter = req;
            return;
        }
    }
}
/*в методе описанном ниже
 * сначало происходит проверка на заполненность,
 * счетчиком заполненых элементов
 * если счетчик = size буфера,
 * то буфер полом,
 * в этом случае выкидываем первую заявку
 * и на ее место добавляем новую
 * передвигаем указатель на след. элемент*/
Request DispatchManager::checkBuff(Buffer& Bf){
    Request kickReq; //удаленная заявка
    kickReq.setBuffTime(-1);
    kickReq.setTime(-1);
    kickReq.setNumberSource(-1);
    NumSourceWithDel = -1;
    size_t counter = 0;//счетчик занятых элементов
    for(Bf.iter = Bf.Buff.begin(); Bf.iter != Bf.Buff.end(); Bf.iter++){
        if(Bf.iter->getTime() != -1 && Bf.iter->getNumberReq() != -1 && Bf.iter->getNumberSource() != -1){
            counter++;
        }
    }
    if(counter == Bf.Buff.size()){
       Bf.iter = Bf.Buff.begin();
       kickReq.setNumberReq(Bf.iter->getNumberReq());
       kickReq.setNumberSource(Bf.iter->getNumberSource());
       kickReq.setTime(Bf.iter->getTime());
       NumSourceWithDel = Bf.iter->getNumberSource();
       Bf.iter->setTime(-1);
       Bf.iter->setNumberReq(-1);
       Bf.iter->setNumberSource(-1);
       countRef++;
       Bf.iter++;
    }
    return kickReq;
}

int DispatchManager::getCountRef(){
    return countRef;
}

int DispatchManager::getDelNumSource(){
    return NumSourceWithDel;
}
