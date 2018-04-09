#ifndef FORMAUTOMODE_H
#define FORMAUTOMODE_H

#include <QWidget>
#include <QStandardItemModel>
#include <vector>
#include "dev.h"
#include "source.h"

namespace Ui {
class FormAutoMode;
}

class FormAutoMode : public QWidget
{
    Q_OBJECT

public:
    void setSrCount(std::vector<Source> &srCount);
    void setDvCount(std::vector<Device> &dvCount);
    void initForm1();
    void initForm2();
    explicit FormAutoMode(QWidget *parent = 0);
    ~FormAutoMode();

private slots:
    void on_pushButton_clicked();

private:
    std::vector<Source> srCount;
    std::vector<Device> dvCount;
    Ui::FormAutoMode *ui;
    QStandardItemModel *model1;
    QStandardItemModel *model2;
};

#endif // FORMAUTOMODE_H
