#include "buffer.h"

/*заявка с полями равными -1
 * есть пустая заявка -- зануленная*/

Buffer::Buffer(int sizeBuf, int sourceCount)
{
    this->sourceCount = sourceCount;
    this->sizeBuf = sizeBuf;
    this->iter = Buff.begin();
    /*контейнер сразу заполняется пустыми заявками
     * элемент контейнера пуст,
     * когда в нем лежит заявка со значениями -1
     * удаление элемента - присваивание лементам заявки,
     *  лежащей в контейнере -1*/
    for (int i = 0; i < sizeBuf; i++){
        Buff.push_back(Request(-1,-1,-1));
    }
    iter = Buff.begin();
}

Buffer::Buffer(){

}

void Buffer::PrintBuff(){ //временный вывод буфера для проверки
    for(int i = 0; i != int(Buff.size()); i++){
        std::cout.precision(4);
        std::cout << "Buffer" << i << " \t Time: " << Buff[i].getTime() << "\t NumberSource: " << Buff[i].getNumberSource() << "\t NumberReq: " << Buff[i].getNumberReq() << std::endl;
    }
}

bool Buffer::checkFinishedPac(){
    return vecInd.size() == 0;
}

void Buffer::genPack(){
    curPriority = prioritySource();
    for (int i = 0; i < int(Buff.size()); i++) {
        if (Buff.at(i).getNumberSource() == curPriority) {
            vecInd.push_back(i);
        }
    }
    for (int i = 0; i < int(vecInd.size()); i++) {
        for (int j = i; j < int(vecInd.size()); j++) {
            if (Buff.at(vecInd.at(i)).getTime() > Buff.at(vecInd.at(j)).getTime()) {
                std::swap(vecInd.at(i), vecInd.at(j));
            }
        }
    }
    for (int i = 0; i < int(vecInd.size()); i++) {
    }
}

int Buffer::prioritySource(){
    int tmp = sourceCount;
    for (Iterator i = Buff.begin(); i != Buff.end(); i++) {
        if ((i->getNumberSource() < tmp) && (i->getNumberReq() != -1) && (i->getNumberSource() != -1) && (i->getTime() != -1)) {
            tmp = i->getNumberSource();
        }
    }
    return tmp;
}

Request Buffer::getElement(){
    if (!checkFinishedPac()) {
        Request req = Buff.at(vecInd.back());
        Buff.at(vecInd.back()).setNumberReq(-1);
        Buff.at(vecInd.back()).setNumberSource(-1);
        Buff.at(vecInd.back()).setTime(-1);
        vecInd.pop_back();
        return req;
    } else {
        genPack();
        Request req = Buff.at(vecInd.back());
        Buff.at(vecInd.back()).setNumberReq(-1);
        Buff.at(vecInd.back()).setNumberSource(-1);
        Buff.at(vecInd.back()).setTime(-1);
        vecInd.pop_back();
        return req;
    }
    return Request();
}

int Buffer::checkBuff(){
    int check = 0;
    for(Iterator i = Buff.begin(); i != Buff.end(); i++){
        if(i->getTime() != -1 && i->getNumberReq() != -1 && i->getNumberSource() != -1){
            check++;
        }
    }
    return check;
}

Request Buffer::getReq(int i){
    return Buff[i];
}






