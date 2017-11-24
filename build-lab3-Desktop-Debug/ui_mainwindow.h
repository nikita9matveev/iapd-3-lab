/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *timeoutComboBox;
    QLabel *connectTypeLabel;
    QLabel *timeToLabel;
    QLabel *timeoutLabel;
    QProgressBar *levelProgressBar;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(630, 220);
        MainWindow->setMinimumSize(QSize(630, 220));
        MainWindow->setMaximumSize(QSize(630, 220));
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        timeoutComboBox = new QComboBox(centralWidget);
        timeoutComboBox->setObjectName(QStringLiteral("timeoutComboBox"));
        timeoutComboBox->setGeometry(QRect(190, 130, 131, 27));
        connectTypeLabel = new QLabel(centralWidget);
        connectTypeLabel->setObjectName(QStringLiteral("connectTypeLabel"));
        connectTypeLabel->setGeometry(QRect(50, 30, 161, 20));
        timeToLabel = new QLabel(centralWidget);
        timeToLabel->setObjectName(QStringLiteral("timeToLabel"));
        timeToLabel->setGeometry(QRect(230, 30, 520, 20));
        timeoutLabel = new QLabel(centralWidget);
        timeoutLabel->setObjectName(QStringLiteral("timeoutLabel"));
        timeoutLabel->setGeometry(QRect(50, 130, 150, 19));
        levelProgressBar = new QProgressBar(centralWidget);
        levelProgressBar->setObjectName(QStringLiteral("levelProgressBar"));
        levelProgressBar->setGeometry(QRect(50, 80, 531, 23));
        levelProgressBar->setValue(24);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(500, 130, 85, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 630, 32));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Battery Status", 0));
        connectTypeLabel->setText(QApplication::translate("MainWindow", "\320\224\320\276 \320\277\320\276\320\273\320\275\320\276\320\271 \321\200\320\260\320\267\321\200\321\217\320\264\320\272\320\270", 0));
        timeToLabel->setText(QString());
        timeoutLabel->setText(QApplication::translate("MainWindow", "\320\242\320\260\320\271\320\274-\320\260\321\203\321\202 \321\215\320\272\321\200\320\260\320\275\320\260:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
