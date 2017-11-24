#ifndef STATUSBATTERY_H
#define STATUSBATTERY_H

#include <QObject>
#include <QFile>
#include <QTimer>
#include <QLabel>
#include <QProgressBar>
#include <QComboBox>
#include <QDebug>
#include <QProcess>
#include <stdio.h>

class statusBattery : public QObject
{
    Q_OBJECT
public:
    explicit statusBattery(QLabel *src, QProgressBar *lvl, QLabel *time, QComboBox *to,QObject *parent = NULL);
    QTimer *timer;
    QString default_timeout;
private:
    QLabel *source;           //connectTypeLabel
    QProgressBar *level;      //levelProgressBar
    QLabel *timeTo;           //timeToLabel
    QComboBox *timeOut;       //timeoutComboBox
    bool sourseInt;           //заряжается - 1, разряжается - 0
signals:

public slots:
    void refresh();           //обновление инфы
    void setTimeOut(int to);  //установка таймаута
public:
    void restoreTimeout(QString timeout);
};

#endif // STATUSBATTERY_H
