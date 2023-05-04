/********************************************************************************
** Form generated from reading UI file 'WindowCtrlWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWCTRLWIDGET_H
#define UI_WINDOWCTRLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CWindowCtrlWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_Icon;
    QLabel *label_WindowName;
    QSpacerItem *horizontalSpacer;
    QToolButton *Btn_Min;
    QToolButton *Btn_Max;
    QToolButton *Btn_Close;

    void setupUi(QWidget *CWindowCtrlWidget)
    {
        if (CWindowCtrlWidget->objectName().isEmpty())
            CWindowCtrlWidget->setObjectName(QStringLiteral("CWindowCtrlWidget"));
        CWindowCtrlWidget->resize(843, 53);
        CWindowCtrlWidget->setStyleSheet(QLatin1String(".QToolButton\n"
"{\n"
"	background-color:transparent;\n"
"	border:none;\n"
"	width:50px;\n"
"	height:50px;\n"
"}\n"
"\n"
".QToolButton:hover\n"
"{\n"
"	background-color:rgb(182,182,182);\n"
"}\n"
"\n"
".QToolButton:pressed\n"
"{\n"
"	background-color:rgb(128,128,128);\n"
"}"));
        horizontalLayout = new QHBoxLayout(CWindowCtrlWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        label_Icon = new QLabel(CWindowCtrlWidget);
        label_Icon->setObjectName(QStringLiteral("label_Icon"));

        horizontalLayout->addWidget(label_Icon);

        label_WindowName = new QLabel(CWindowCtrlWidget);
        label_WindowName->setObjectName(QStringLiteral("label_WindowName"));

        horizontalLayout->addWidget(label_WindowName);

        horizontalSpacer = new QSpacerItem(512, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Btn_Min = new QToolButton(CWindowCtrlWidget);
        Btn_Min->setObjectName(QStringLiteral("Btn_Min"));
        Btn_Min->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Min->setIcon(icon);
        Btn_Min->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(Btn_Min);

        Btn_Max = new QToolButton(CWindowCtrlWidget);
        Btn_Max->setObjectName(QStringLiteral("Btn_Max"));
        Btn_Max->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resource/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Max->setIcon(icon1);
        Btn_Max->setIconSize(QSize(25, 25));
        Btn_Max->setCheckable(true);

        horizontalLayout->addWidget(Btn_Max);

        Btn_Close = new QToolButton(CWindowCtrlWidget);
        Btn_Close->setObjectName(QStringLiteral("Btn_Close"));
        Btn_Close->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/resource/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Close->setIcon(icon2);
        Btn_Close->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(Btn_Close);


        retranslateUi(CWindowCtrlWidget);

        QMetaObject::connectSlotsByName(CWindowCtrlWidget);
    } // setupUi

    void retranslateUi(QWidget *CWindowCtrlWidget)
    {
        CWindowCtrlWidget->setWindowTitle(QApplication::translate("CWindowCtrlWidget", "CWindowCtrlWidget", 0));
        label_Icon->setText(QApplication::translate("CWindowCtrlWidget", "Icon", 0));
        label_WindowName->setText(QApplication::translate("CWindowCtrlWidget", "WindowName", 0));
        Btn_Min->setText(QApplication::translate("CWindowCtrlWidget", "...", 0));
        Btn_Max->setText(QApplication::translate("CWindowCtrlWidget", "...", 0));
        Btn_Close->setText(QApplication::translate("CWindowCtrlWidget", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class CWindowCtrlWidget: public Ui_CWindowCtrlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWCTRLWIDGET_H
