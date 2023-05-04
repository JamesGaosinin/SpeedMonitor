#include "WindowCtrlWidget.h"
#include "ui_WindowCtrlWidget.h"
#include <QToolButton>
#include <QLabel>
#include <QMouseEvent>
#include "../include/SpeedMonitor.h"

CWindowCtrlWidget::CWindowCtrlWidget(QWidget *parent)
	: QWidget(parent)
	, m_pParent((SpeedMonitor*)parent)
{
	ui = new Ui::CWindowCtrlWidget();
	ui->setupUi(this);

	Init();
}

CWindowCtrlWidget::~CWindowCtrlWidget()
{
	delete ui;
}

void CWindowCtrlWidget::SetIcon(const QString& strFile)
{
	QPixmap pixMap(strFile);
	pixMap.scaledToHeight(30);
	pixMap.scaledToHeight(30);
	ui->label_Icon->setPixmap(pixMap);
}

void CWindowCtrlWidget::SetTitle(const QString& strTitle)
{
	ui->label_WindowName->setText(strTitle);
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setBold(true);
	font.setPixelSize(20);
	ui->label_WindowName->setFont(font);
}

void CWindowCtrlWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_BeginPos = event->pos();
		m_ComarePos = event->pos();
	}
}

void CWindowCtrlWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		if (ui->Btn_Max->isChecked())
		{
			return;
		}
		QPoint point = event->pos() - m_ComarePos;
		if (point.manhattanLength() > 3)
		{
			QPoint endPos = event->pos();
			endPos = mapToGlobal(endPos) - m_BeginPos;

			m_ComarePos = endPos;
			emit Sig_WindowMove(endPos);
			event->accept();
		}
	}
}

void CWindowCtrlWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
	ui->Btn_Max->setChecked(!ui->Btn_Max->isChecked());
	emit Sig_WindowShowMaximum(ui->Btn_Max->isChecked());
}

void CWindowCtrlWidget::Init()
{
	InitGUI();
	InitConnect();
}

void CWindowCtrlWidget::InitGUI()
{
	this->setStyleSheet(QString(".QWidget{border:1px solid rgb(182,182,182);}"));
	ui->Btn_Max->setChecked(true);
}

void CWindowCtrlWidget::InitConnect()
{
	connect(ui->Btn_Min, &QToolButton::clicked, this, &CWindowCtrlWidget::Sig_BtnMinClicked);
	connect(ui->Btn_Max, &QToolButton::clicked, this, &CWindowCtrlWidget::Sig_BtnMaxClicked);
	connect(ui->Btn_Close, &QToolButton::clicked, this, &CWindowCtrlWidget::Sig_BtnCloseClicked);
}
