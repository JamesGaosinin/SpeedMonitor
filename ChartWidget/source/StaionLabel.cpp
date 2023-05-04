#include "StaionLabel.h"
#include "ui_StaionLabel.h"
#include <QLabel>
#include "Common.h"

CStaionLabel::CStaionLabel(const StationInfo& stStaionInfo, QWidget *parent)
	: QWidget(parent)
	, m_stStaionInfo(stStaionInfo)
{
	ui = new Ui::CStaionLabel();
	ui->setupUi(this);
	Init();
}

CStaionLabel::~CStaionLabel()
{
	delete ui;
}

void CStaionLabel::mouseMoveEvent(QMouseEvent *event)
{
	QString strText = QStringLiteral("站名:%1 公里标:%2")
		.arg(m_stStaionInfo.m_strStationName)
		.arg(QString::number(m_stStaionInfo.m_fGLB, 'f', 2));
	QPoint pos = this->pos();
	emit Sig_ShowStationInfo(pos, strText);
}

void CStaionLabel::Init()
{
	QPixmap pixMap(":/resource/Flag.png");
	pixMap = pixMap.scaled(30, 30);
	ui->label_Icon->setPixmap(pixMap);
	ui->label_Icon->resize(30, 30);
	ui->label_Name->setText(m_stStaionInfo.m_strStationName);
	ui->label_Name->setStyleSheet(QString("color:rgb(255,255,255);"));
	//ui->label_Icon->setAttribute(Qt::WA_TransparentForMouseEvents, true);

	QFontMetrics metrics = this->fontMetrics();
	int nWidth = metrics.width(m_stStaionInfo.m_strStationName);
	this->setFixedWidth(nWidth);
}
