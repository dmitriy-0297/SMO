#ifndef FORMSTEPMODE_H
#define FORMSTEPMODE_H

#include <QWidget>
#include <QStandardItemModel>
#include <event.h>
#include <vector>

namespace Ui {
class FormStepMode;
}

class FormStepMode : public QWidget
{
    Q_OBJECT

public:
    void initForm1(int srCount, int dvCount, int click);
    void initForm2(int sizeBuff, int clik);
    void setEvents(std::vector<Event> &events);
    void setSrCount(int srCount);
    void setDvCount(int dvCount);
    void setSizeBuff(int sizeBuff);
    explicit FormStepMode(QWidget *parent = 0);
    ~FormStepMode();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    int srCount;
    int dvCount;
    int sizeBuff;
    int clik;
    std::vector<Event> Events;
    Ui::FormStepMode *ui;
    QStandardItemModel *model1;
    QStandardItemModel *model2;
};

#endif // FORMSTEPMODE_H
