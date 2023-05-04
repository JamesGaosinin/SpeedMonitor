/********************************************************************************
** Form generated from reading UI file 'ToolWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLWIDGET_H
#define UI_TOOLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CToolWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_Up;
    QRadioButton *radioButton_Down;
    QToolButton *Btn_Grab;

    void setupUi(QWidget *CToolWidget)
    {
        if (CToolWidget->objectName().isEmpty())
            CToolWidget->setObjectName(QStringLiteral("CToolWidget"));
        CToolWidget->resize(338, 48);
        CToolWidget->setStyleSheet(QStringLiteral("border:1px solid rgb(182, 182, 182);"));
        horizontalLayout = new QHBoxLayout(CToolWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer = new QSpacerItem(279, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        frame = new QFrame(CToolWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButton_Up = new QRadioButton(frame);
        radioButton_Up->setObjectName(QStringLiteral("radioButton_Up"));
        radioButton_Up->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_Up);

        radioButton_Down = new QRadioButton(frame);
        radioButton_Down->setObjectName(QStringLiteral("radioButton_Down"));

        horizontalLayout_2->addWidget(radioButton_Down);


        horizontalLayout->addWidget(frame);

        Btn_Grab = new QToolButton(CToolWidget);
        Btn_Grab->setObjectName(QStringLiteral("Btn_Grab"));

        horizontalLayout->addWidget(Btn_Grab);


        retranslateUi(CToolWidget);

        QMetaObject::connectSlotsByName(CToolWidget);
    } // setupUi

    void retranslateUi(QWidget *CToolWidget)
    {
        CToolWidget->setWindowTitle(QApplication::translate("CToolWidget", "CToolWidget", 0));
        radioButton_Up->setText(QApplication::translate("CToolWidget", "\344\270\212\350\241\214", 0));
        radioButton_Down->setText(QApplication::translate("CToolWidget", "\344\270\213\350\241\214", 0));
        Btn_Grab->setText(QApplication::translate("CToolWidget", "\346\210\252\345\233\276", 0));
    } // retranslateUi

};

namespace Ui {
    class CToolWidget: public Ui_CToolWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLWIDGET_H
