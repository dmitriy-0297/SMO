#include "formautomode.h"
#include "ui_formautomode.h"
#include "mainwindow.h"

FormAutoMode::FormAutoMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAutoMode)
{
    ui->setupUi(this);
}

FormAutoMode::~FormAutoMode()
{
    delete ui;
}

void FormAutoMode::on_pushButton_clicked()
{
    close();
}

void FormAutoMode::setSrCount(std::vector<Source> &srCount){
    for(int i = 0; i != int(srCount.size()); i++){
        this->srCount.push_back(srCount[i]);
    }
}

void FormAutoMode::setDvCount(std::vector<Device> &dvCount){
    for(int i = 0; i != int(dvCount.size()); i++){
        this->dvCount.push_back(dvCount[i]);
    }
}

void FormAutoMode::initForm1(){
    int sizeTable1 = int(srCount.size());
    int sizeTable2 = 8;
    model1 = new QStandardItemModel(sizeTable1, sizeTable2, this);
    ui->tableMod1->setModel(model1);
    QModelIndex index;
    int numSr = 0;
    for(int row = 0; row < int(srCount.size()); row++){
        int col = 0;
        numSr++;
        index = model1->index(row,col);
        model1->setData(index,numSr);
        col++;
        index = model1->index(row,col);
        model1->setData(index,srCount[row].getCountReq());
        col++;
        index = model1->index(row,col);
        model1->setData(index,srCount[row].getP());
        col++;
        index = model1->index(row,col);
        model1->setData(index,srCount[row].getTimeInSys());
        col++;
        index = model1->index(row,col);
        model1->setData(index,srCount[row].getTimeInBuff());
        col++;
        index = model1->index(row,col);
        model1->setData(index,srCount[row].getTimeInDev());
        col++;
        index = model1->index(row,col);
        model1->setData(index,srCount[row].getDispBuff());
        col++;
        index = model1->index(row,col);
        model1->setData(index,srCount[row].getDispDev());
    }
    model1->setHeaderData(0, Qt::Horizontal, "Num");
    model1->setHeaderData(1, Qt::Horizontal, "CountReq");
    model1->setHeaderData(2, Qt::Horizontal, "P");
    model1->setHeaderData(3, Qt::Horizontal, "T in Sys");
    model1->setHeaderData(4, Qt::Horizontal, "T in Buff");
    model1->setHeaderData(5, Qt::Horizontal, "T on Dev");
    model1->setHeaderData(6, Qt::Horizontal, "Buff Disp");
    model1->setHeaderData(7, Qt::Horizontal, "Dev Disp");
    for(int i = 0; i <= sizeTable2; i++){
        if(i <= int(srCount.size())){
            model1->setHeaderData(i, Qt::Vertical, "Source");
        }
    }
}

void FormAutoMode::initForm2(){
    int sizeTable1 = int(dvCount.size());
    int sizeTable2 = 2;
    model2 = new QStandardItemModel(sizeTable1, sizeTable2, this);
    ui->tableMod2->setModel(model2);
    QModelIndex index;
    int numDv = 0;
    for(int row = 0; row < int(dvCount.size()); row++){
        int col = 0;
        numDv++;
        index = model2->index(row,col);
        model2->setData(index,numDv);
        col++;
        index = model2->index(row,col);
        model2->setData(index,dvCount[row].getK());
    }
    model2->setHeaderData(0, Qt::Horizontal, "Num");
    model2->setHeaderData(1, Qt::Horizontal, "К");
    for(int i = 0; i <= sizeTable2; i++){
        if(i <= int(dvCount.size())){
            model2->setHeaderData(i, Qt::Vertical, "Device");
        }
    }
}



