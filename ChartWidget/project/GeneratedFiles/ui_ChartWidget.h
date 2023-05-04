/********************************************************************************
** Form generated from reading UI file 'ChartWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTWIDGET_H
#define UI_CHARTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CChartWidget
{
public:

    void setupUi(QWidget *CChartWidget)
    {
        if (CChartWidget->objectName().isEmpty())
            CChartWidget->setObjectName(QStringLiteral("CChartWidget"));
        CChartWidget->resize(400, 300);
        CChartWidget->setMouseTracking(true);
        CChartWidget->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        retranslateUi(CChartWidget);

        QMetaObject::connectSlotsByName(CChartWidget);
    } // setupUi

    void retranslateUi(QWidget *CChartWidget)
    {
        CChartWidget->setWindowTitle(QApplication::translate("CChartWidget", "CChartWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class CChartWidget: public Ui_CChartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTWIDGET_H
