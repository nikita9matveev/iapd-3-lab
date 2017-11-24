#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->timeoutComboBox->addItem("Never");
    ui->timeoutComboBox->addItem("1 minute");
    ui->timeoutComboBox->addItem("5 minute");
    ui->timeoutComboBox->addItem("10 minute");
    ui->timeoutComboBox->addItem("20 minute");
    ui->timeoutComboBox->addItem("30 minute");
    status = new statusBattery(ui->connectTypeLabel, ui->levelProgressBar, ui->timeToLabel, ui->timeoutComboBox);
    thread = new QThread();
    connect(this, SIGNAL(destroyed()), thread, SLOT(quit()));
    connect(ui->timeoutComboBox, SIGNAL(currentIndexChanged(int)), status, SLOT(setTimeOut(int)));
    status->moveToThread(thread);
    thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    status->restoreTimeout(status->default_timeout);
}

void MainWindow::on_pushButton_clicked()
{
    status->restoreTimeout(status->default_timeout);
    this->close();
}
