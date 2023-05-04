/********************************************************************************
** Form generated from reading UI file 'SpeedMonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPEEDMONITOR_H
#define UI_SPEEDMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpeedMonitorClass
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *SpeedMonitorClass)
    {
        if (SpeedMonitorClass->objectName().isEmpty())
            SpeedMonitorClass->setObjectName(QStringLiteral("SpeedMonitorClass"));
        SpeedMonitorClass->setWindowModality(Qt::NonModal);
        SpeedMonitorClass->resize(600, 400);
        SpeedMonitorClass->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(SpeedMonitorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SpeedMonitorClass->setCentralWidget(centralWidget);

        retranslateUi(SpeedMonitorClass);

        QMetaObject::connectSlotsByName(SpeedMonitorClass);
    } // setupUi

    void retranslateUi(QMainWindow *SpeedMonitorClass)
    {
        SpeedMonitorClass->setWindowTitle(QApplication::translate("SpeedMonitorClass", "SpeedMonitor", 0));
    } // retranslateUi

};

namespace Ui {
    class SpeedMonitorClass: public Ui_SpeedMonitorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPEEDMONITOR_H
