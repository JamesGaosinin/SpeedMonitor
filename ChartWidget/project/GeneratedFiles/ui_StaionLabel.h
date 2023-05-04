/********************************************************************************
** Form generated from reading UI file 'StaionLabel.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAIONLABEL_H
#define UI_STAIONLABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CStaionLabel
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_Name;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Icon;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *CStaionLabel)
    {
        if (CStaionLabel->objectName().isEmpty())
            CStaionLabel->setObjectName(QStringLiteral("CStaionLabel"));
        CStaionLabel->resize(112, 50);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CStaionLabel->sizePolicy().hasHeightForWidth());
        CStaionLabel->setSizePolicy(sizePolicy);
        CStaionLabel->setMinimumSize(QSize(30, 50));
        CStaionLabel->setMaximumSize(QSize(112, 50));
        CStaionLabel->setMouseTracking(true);
        CStaionLabel->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(CStaionLabel);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_Name = new QLabel(CStaionLabel);
        label_Name->setObjectName(QStringLiteral("label_Name"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Name->sizePolicy().hasHeightForWidth());
        label_Name->setSizePolicy(sizePolicy1);
        label_Name->setMouseTracking(true);

        verticalLayout->addWidget(label_Name);

        frame = new QFrame(CStaionLabel);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMouseTracking(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_Icon = new QLabel(frame);
        label_Icon->setObjectName(QStringLiteral("label_Icon"));
        label_Icon->setMinimumSize(QSize(30, 30));
        label_Icon->setMaximumSize(QSize(30, 30));
        label_Icon->setMouseTracking(true);
        label_Icon->setScaledContents(true);

        horizontalLayout->addWidget(label_Icon);

        horizontalSpacer = new QSpacerItem(77, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(frame);


        retranslateUi(CStaionLabel);

        QMetaObject::connectSlotsByName(CStaionLabel);
    } // setupUi

    void retranslateUi(QWidget *CStaionLabel)
    {
        CStaionLabel->setWindowTitle(QApplication::translate("CStaionLabel", "CStaionLabel", 0));
        label_Name->setText(QApplication::translate("CStaionLabel", "TextLabel", 0));
        label_Icon->setText(QApplication::translate("CStaionLabel", "icon", 0));
    } // retranslateUi

};

namespace Ui {
    class CStaionLabel: public Ui_CStaionLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAIONLABEL_H
