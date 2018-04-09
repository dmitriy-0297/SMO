#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
#include <cctype>
#include <QInputDialog>
#include <formstepmode.h>
#include <formautomode.h>
#include <event.h>
#include <vector>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->requestCount = 0;
    this->lambda = 0;
    this->sizeBuffer = 0;
    this->sourceCount = 0;
    this->deviceCount = 0;
    this->intA = 0;
    this->intB = 0;
    this->mod = Model(lambda, sourceCount, requestCount, sizeBuffer, deviceCount, intA, intB);
    ui->setupUi(this);
    ui->N->setText("5");//значения по умолчанию
    ui->srNum->setText("5");
    ui->sizeBuff->setText("3");
    ui->lmbda->setText("2");
    ui->alpha->setText("1");
    ui->beta->setText("3");
    ui->devNum->setText("3");
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if((ui->N->text()) > 'a' || (ui->N->text()) > 'z' || (ui->N->text()).toInt() <= 0 || (ui->N->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->N->setText(text);
            on_pushButton_clicked();
    }else{
        this->requestCount = (ui->N->text()).toInt();
        mod.requestCount = (ui->N->text()).toInt();
    }
    if((ui->srNum->text()) > 'a' || (ui->srNum->text()) > 'z' || (ui->srNum->text()).toInt() <= 0 || (ui->srNum->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->srNum->setText(text);
            on_pushButton_clicked();
    }else{
        this->sourceCount = ui->srNum->text().toInt();
        mod.sourceCount = ui->srNum->text().toInt();
    }
    if((ui->sizeBuff->text()) > 'a' || (ui->sizeBuff->text()) > 'z' || (ui->sizeBuff->text()).toInt() <= 0 || (ui->sizeBuff->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->sizeBuff->setText(text);
            on_pushButton_clicked();
    }else{
        this->sizeBuffer = ui->sizeBuff->text().toInt();
        mod.sizeBuffer = ui->sizeBuff->text().toInt();
    }
    if((ui->lmbda->text()) > 'a' || (ui->lmbda->text()) > 'z' || (ui->lmbda->text()).toDouble() <= 0 || (ui->lmbda->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->lmbda->setText(text);
            on_pushButton_clicked();
    }else{
        this->lambda = ui->lmbda->text().toDouble();
        mod.lambda = ui->lmbda->text().toDouble();
    }
    if((ui->alpha->text()) > 'a' || (ui->alpha->text()) > 'z' || (ui->alpha->text()).toDouble() <= 0 || (ui->alpha->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->alpha->setText(text);
            on_pushButton_clicked();
    }else{
        this->intA = ui->alpha->text().toDouble();
        mod.intA = ui->alpha->text().toDouble();
    }
    if((ui->beta->text()) > 'a' || (ui->beta->text()) > 'z' || (ui->beta->text()).toDouble() <= 0 || (ui->beta->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->beta->setText(text);
            on_pushButton_clicked();
    }else{
        this->intB = ui->beta->text().toDouble();
        mod.intB = ui->beta->text().toDouble();
    }
    if((ui->devNum->text()) > 'a' || (ui->devNum->text()) > 'z' || (ui->devNum->text()).toInt() <= 0 || (ui->devNum->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->devNum->setText(text);
            on_pushButton_clicked();
    }else{
        this->deviceCount = ui->devNum->text().toInt();
        mod.deviceCount = ui->devNum->text().toInt();
    }
    int flag = 0;
    mod.start(flag); //старт системы
    std::vector<Event> Events;
    for(int i = 0; i != int(mod.getEvents().size()); i++){
        Events.push_back(mod.getEvents().at(i));
    }
    FormStepMode *fStepMode = new FormStepMode;
    fStepMode->setEvents(Events);
    fStepMode->setSrCount(this->sourceCount);
    fStepMode->setDvCount(this->deviceCount);
    fStepMode->setSizeBuff(this->sizeBuffer);
    fStepMode->setParent(this);
    fStepMode->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    if((ui->N->text()) > 'a' || (ui->N->text()) > 'z' || (ui->N->text()).toInt() <= 0 || (ui->N->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->N->setText(text);
            on_pushButton_clicked();
    }else{
        mod.requestCount = (ui->N->text()).toInt();
    }
    if((ui->srNum->text()) > 'a' || (ui->srNum->text()) > 'z' || (ui->srNum->text()).toInt() <= 0 || (ui->srNum->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->srNum->setText(text);
            on_pushButton_clicked();
    }else{
        mod.sourceCount = ui->srNum->text().toInt();
    }
    if((ui->sizeBuff->text()) > 'a' || (ui->sizeBuff->text()) > 'z' || (ui->sizeBuff->text()).toInt() <= 0 || (ui->sizeBuff->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->sizeBuff->setText(text);
            on_pushButton_clicked();
    }else{
        mod.sizeBuffer = ui->sizeBuff->text().toInt();
    }
    if((ui->lmbda->text()) > 'a' || (ui->lmbda->text()) > 'z' || (ui->lmbda->text()).toDouble() <= 0 || (ui->lmbda->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->lmbda->setText(text);
            on_pushButton_clicked();
    }else{
        mod.lambda = ui->lmbda->text().toDouble();
    }
    if((ui->alpha->text()) > 'a' || (ui->alpha->text()) > 'z' || (ui->alpha->text()).toDouble() <= 0 || (ui->alpha->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->alpha->setText(text);
            on_pushButton_clicked();
    }else{
        mod.intA = ui->alpha->text().toDouble();
    }
    if((ui->beta->text()) > 'a' || (ui->beta->text()) > 'z' || (ui->beta->text()).toDouble() <= 0 || (ui->beta->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->beta->setText(text);
            on_pushButton_clicked();
    }else{
        mod.intB = ui->beta->text().toDouble();
    }
    if((ui->devNum->text()) > 'a' || (ui->devNum->text()) > 'z' || (ui->devNum->text()).toInt() <= 0 || (ui->devNum->text()) == ' '){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Error"),
        tr("Invalid input"), QLineEdit::Normal, "try again", &ok);
        if (ok && !text.isEmpty())
            ui->devNum->setText(text);
            on_pushButton_clicked();
    }else{
        mod.deviceCount = ui->devNum->text().toInt();
    }
    int flag = 1;
    mod.start(flag); //старт системы
    std::vector<Source> srCount;
    std::vector<Device> dvCount;
    for(int i = 0; i < int(mod.getSrCount().size()); i++){
        srCount.push_back(mod.getSrCount().at(i));
    }
    for(int i = 0; i < int(mod.getDvCount().size()); i++){
        dvCount.push_back(mod.getDvCount().at(i));
    }
    FormAutoMode *fAutoMode = new FormAutoMode;
    fAutoMode->setSrCount(srCount);
    fAutoMode->setDvCount(dvCount);
    fAutoMode->setParent(this);
    fAutoMode->initForm1();
    fAutoMode->initForm2();
    fAutoMode->show();
}
