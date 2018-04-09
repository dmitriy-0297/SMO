#include "event.h"

Event::Event(Buffer& buf, int sizeBuff, int sourceCount,  std::vector<Source> srCount,  std::vector<Device> dvCount)
{
    this->sizeBuff = sizeBuff;
    this->sourceCount = sourceCount;
    this->Buff = Buffer(sizeBuff, sourceCount);
    this->Buff = buf;
    for(int i = 0; i < int(srCount.size()); i++)
        this->srCount.push_back(srCount[i]);
    for(int i = 0; i < int(dvCount.size()); i++)
        this->dvCount.push_back(dvCount[i]);
}

void Event::printStCount(){
    for (int i = 0; i != int(srCount.size()); i++){//Календарь событий
        std::cout << "Num Source: " << srCount[i].getNumSource() << " Time: " << srCount[i].getGenerationTime() << " ReqCount: " << srCount[i].getCountReq() << " CountDelReq: " << srCount[i].getCountDelReq() << std::endl;
    }
}

void Event::printBuff(){
    for(int i = 0; i != int(this->Buff.Buff.size()); i++){
        std::cout.precision(4);
        std::cout << "Buffer" << i << " \t Time: " << this->Buff.Buff[i].getTime() << "\t NumberSource: " << this->Buff.Buff[i].getNumberSource() << "\t NumberReq: " << this->Buff.Buff[i].getNumberReq() << std::endl;
    }
}

void Event::printDvCount(){
    for (int i = 0; i != int(dvCount.size()); i++){
        std::cout << "Num Device: " << dvCount[i].getDeviceNumber() << " Time: " << dvCount[i].getServiceTime() << std::endl;
    }
    std::cout << std::endl;
}

int Event::getCountDev(){
    return int(dvCount.size());
}
int Event::getCountSr(){
    return int(srCount.size());
}
int Event::getSizeBuff(){
    return sizeBuff;
}
