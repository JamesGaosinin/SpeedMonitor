#include "ToolWidget.h"
#include "ui_ToolWidget.h"
#include <QPushButton>

CToolWidget::CToolWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::CToolWidget();
	ui->setupUi(this);
	Init();
}

CToolWidget::~CToolWidget()
{
	delete ui;
}

void CToolWidget::Slot_UpDownClicked(bool bChecked)
{
	if (!bChecked)
	{
		return;
	}

	QObject* obj = sender();
	E_TRAIN_UP_DOWN_TYPE eType;
	if (obj == ui->radioButton_Down)
	{
		eType = E_TRAIN_UP_DOWN_TYPE_DOWN;
	}
	else if (obj == ui->radioButton_Up)
	{
		eType = E_TRAIN_UP_DOWN_TYPE_UP;
	}
	emit Sig_UpDownClicked(eType);
}

void CToolWidget::Init()
{
	this->setStyleSheet(QString(".QWidget{border:1px solid rgb(182,182,182);}"));
	connect(ui->Btn_Grab, &QPushButton::clicked, this, &CToolWidget::Sig_GrabWindow);
	connect(ui->radioButton_Down, &QRadioButton::toggled, this, &CToolWidget::Slot_UpDownClicked);
	connect(ui->radioButton_Up, &QRadioButton::toggled, this, &CToolWidget::Slot_UpDownClicked);
	ui->Btn_Grab->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	ui->Btn_Grab->setText(QStringLiteral("НиЭМ"));
	ui->Btn_Grab->setIcon(QIcon(":/resource/grab.png"));
}
