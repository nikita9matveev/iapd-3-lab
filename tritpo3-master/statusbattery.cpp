#include "statusbattery.h"

statusBattery::statusBattery(QLabel *src, QProgressBar *lvl, QLabel *time, QComboBox *to, QObject *parent) : QObject(parent)
{
    source = src;
    level = lvl;
    timeTo = time;
    timeOut = to;
    timer = new QTimer(this);
    timer->setInterval(100);
    refresh();
    connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start();

    QProcess proc;
    proc.start("dconf read /org/gnome/settings-daemon/plugins/power/sleep-inactive-battery-timeout");
    proc.waitForFinished(-1); //wait forever until finished

    default_timeout = (proc.readAllStandardOutput());
    default_timeout.remove(default_timeout.length()-1,1);
    proc.close();
}

void statusBattery::refresh() {
    bool online;         //заряжается - 1, разряжается - 0
    int lvl, energy, pwr_now;
    float time;
    QFile file_source("/sys/class/power_supply/AC0/online");
    if(file_source.exists()){
        file_source.open(QIODevice::ReadOnly | QIODevice::Text);
        online =QString(file_source.readAll().at(0)).toInt();
        file_source.close();
    }
    sourseInt = online;
    QString sr;
    if(online) {
        sr = "До полной зарядки: ";
        timeOut->setCurrentIndex(0);
        timeOut->setEnabled(false);
    } else {
        sr = "До полной разрядки: ";
        timeOut->setEnabled(true);
    }
    QFile file_level("/sys/class/power_supply/BAT0/capacity");
    if(file_level.exists()){
        file_level.open(QIODevice::ReadOnly | QIODevice::Text);
        QString levelStr = file_level.readAll();
        lvl = levelStr.remove(levelStr.length()-1,1).toInt();
        file_level.close();
    }


    QFile file_power("/sys/class/power_supply/BAT0/power_now");
    if(file_power.exists()){
        file_power.open(QIODevice::ReadOnly | QIODevice::Text);
        QString powerStr = file_power.readAll();
        pwr_now = powerStr.remove(powerStr.length()-1,1).toInt();
        file_power.close();
    }

    QFile file_energy_now("/sys/class/power_supply/BAT0/energy_now");
    if(file_energy_now.exists()) {
        file_energy_now.open(QIODevice::ReadOnly | QIODevice::Text);
        QString chargStr = file_energy_now.readAll();
        energy = chargStr.remove(chargStr.length()-1,1).toInt();
        file_energy_now.close();
    }
    if(online) {
        QFile file_energy_full("/sys/class/power_supply/BAT0/energy_full");
        if(file_energy_full.exists()){
            file_energy_full.open(QIODevice::ReadOnly | QIODevice::Text);
            QString chargStr = file_energy_full.readAll();
            int energy_full = chargStr.remove(chargStr.length()-1,1).toInt();
            energy = energy_full - energy;
            file_energy_full.close();
        }
    }
    time = (float)energy / pwr_now;
    int hour = time;
    int minute = (time - hour)*60;
    QString timeStr;
    if(hour < 0 || minute < 0) {
        timeStr = "Full battery";
    }
    else {
        if(hour)
            timeStr = QString::number(hour) + " час(а) ";
        timeStr += QString::number(minute) + " минут";
    }

    source->setText(sr);
    level->setValue(lvl);
    timeTo->setText(timeStr);
}

void statusBattery::setTimeOut(int to)
{

    switch(to) {
    case 0:
        restoreTimeout("0");
        break;
    case 1:
        restoreTimeout("60");
        break;
    case 2:
        restoreTimeout("300");
        break;
    case 3:
        restoreTimeout("600");
        break;
    case 4:
        restoreTimeout("1200");
        break;
    case 5:
        restoreTimeout("1800");
        break;
    }
}

void statusBattery::restoreTimeout(QString timeout)
{
    system((QString("dconf write /org/gnome/settings-daemon/plugins/power/sleep-inactive-battery-timeout '") + timeout + QString("'")).toStdString().c_str());
}
