#include "ChartWidget.h"
#include "ui_ChartWidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QFontMetrics>
#include "ChartViewImp.h"
#include "StaionLabel.h"
#include "Common.h"



CChartWidget::CChartWidget(E_TRAIN_UP_DOWN_TYPE eUpDownType, QWidget *parent)
	: QDialog(parent)
	, m_eUpDownType(eUpDownType)
	, m_pChartView(nullptr)
	, m_pChart(nullptr)
	, m_pCurSeries(nullptr)
	, m_pStandardSeries(nullptr)
{
	pUi = new Ui::CChartWidget();
	pUi->setupUi(this);

	Init();
}

CChartWidget::~CChartWidget()
{
	delete pUi;
}

void CChartWidget::SetTrainDevName(const QString& strName)
{
	m_strTrainSerialName = strName;
}

QString CChartWidget::GetTrainDevName()
{
	return m_strTrainSerialName;
}

void CChartWidget::Initalize(const QList<StationInfo>& vecPos)
{
	QMutexLocker locker(&m_Mutex);
	m_lstStationInfo = vecPos;
}

void CChartWidget::SetStandardPoints(const QList<QPointF>& vecPos)
{
	QMutexLocker locker(&m_Mutex);
	m_lstStandardPos = vecPos;
	UpdateStandard();
}

void CChartWidget::SetCurPoints(const QList<QPointF>& vecPos)
{
	QMutexLocker locker(&m_Mutex);
	m_lstCurPos = vecPos;
	UpdateCur();
}

void CChartWidget::Append(const QPointF& point)
{
	QMutexLocker locker(&m_Mutex);
	m_lstCurPos.push_back(point);
	m_pCurSeries->append(point);
}

void CChartWidget::SetAxisXRange(float fBegin, float fEnd)
{
	m_pChart->axisX()->setRange(fBegin, fEnd);
}

void CChartWidget::SetAxisYRange(float fBegin, float fEnd)
{
	m_pChart->axisY()->setRange(fBegin, fEnd);
}

void CChartWidget::SetUpDownType(E_TRAIN_UP_DOWN_TYPE eType)
{
	QMutexLocker locker(&m_Mutex);
	if (m_eUpDownType != eType)
	{
		m_eUpDownType = eType;
		m_nReverseTimes++;
		if (m_nReverseTimes > 1)
		{
			m_lstCurPos.clear();
			m_nReverseTimes = 0;
		}
		if (eType == E_TRAIN_UP_DOWN_TYPE_UP)
		{
			m_pUpDownLabel->setText(QStringLiteral("上行方向"));
		}
		else if (eType == E_TRAIN_UP_DOWN_TYPE_DOWN)
		{
			m_pUpDownLabel->setText(QStringLiteral("下行方向"));
		}
		UpdateGLB();
	}
}

E_TRAIN_UP_DOWN_TYPE CChartWidget::GetUpDownType()
{
	QMutexLocker locker(&m_Mutex);
	return m_eUpDownType;
}

void CChartWidget::Reset()
{
	QMutexLocker locker(&m_Mutex);
	if (nullptr != m_pStandardSeries)
	{
		m_lstCurPos.clear();
		m_pCurSeries->clear();
	}
	
	if (nullptr != m_pStandardSeries)
	{
		m_lstStandardPos.clear();
		m_pStandardSeries->clear();
	}
}

void CChartWidget::mouseMoveEvent(QMouseEvent *event)
{

}

void CChartWidget::Slot_DrawCrossLine(const QPoint& pos)
{
	QPointF pointF = m_pChart->mapToValue(pos, m_pCurSeries);
	QPoint coordinate = QPoint(pointF.x(), pointF.y());
	QString strText = QString("  %1, %2").arg((double)pointF.x(), 0, 'f', 2).arg((double)pointF.y(), 0, 'f', 2);
	m_pCoordinateLabel->setText(strText);
	QFontMetrics metrics = m_pCoordinateLabel->fontMetrics();
	int nWidth = metrics.width(strText);
	m_pCoordinateLabel->setFixedWidth(nWidth);
	m_pCoordinateLabel->move(pos - QPoint(0, m_pCoordinateLabel->height()));
}

void CChartWidget::Slot_ShowStationInfo(const QPoint& pos, const QString& strText)
{
	m_pCoordinateLabel->setText(strText);
	QFontMetrics metrics = m_pCoordinateLabel->fontMetrics();
	int nWidth = metrics.width(strText);
	m_pCoordinateLabel->setFixedWidth(nWidth);
	m_pCoordinateLabel->move(pos + QPoint(0, m_pCoordinateLabel->height()));
}

void CChartWidget::showEvent(QShowEvent* Event)
{
	UpdateGLB();
}

void CChartWidget::resizeEvent(QResizeEvent *event)
{
	UpdateGLB();
}

void CChartWidget::Init()
{
	m_pChartView = new CChartViewImp;
	connect(m_pChartView, &CChartViewImp::Sig_RePaintGLB, [=](){
		UpdateGLB(); });
	connect(m_pChartView, &CChartViewImp::Sig_MouseMoveEvent, this, &CChartWidget::Slot_DrawCrossLine);
	
	QHBoxLayout* pLayout = new QHBoxLayout(this);
	pLayout->addWidget(m_pChartView);
	this->setLayout(pLayout);
	pLayout->setMargin(0);
	pLayout->setSpacing(0);
	m_pChartView->installEventFilter(this);

	m_pChart = new QChart();
	m_pChartView->setChart(m_pChart);
	m_pChart->zoom(0.1);

	m_pChartView->chart()->setTheme(QChart::ChartThemeDark);
	m_pCurSeries = new QLineSeries;
	m_pCurSeries->setName(QStringLiteral("实际速度"));
	m_pChartView->chart()->addSeries(m_pCurSeries);
	m_pCurSeries->setColor(Qt::red);
	m_pCurSeries->setPointLabelsColor(Qt::red);

	/*m_pStandardSeries = new QLineSeries;
	m_pStandardSeries->setName(QStringLiteral("标准速度"));
	m_pChartView->chart()->addSeries(m_pStandardSeries);
	m_pStandardSeries->setColor(Qt::green);
	m_pStandardSeries->setPointLabelsColor(Qt::green);
	m_pChart->addSeries(m_pStandardSeries);*/

	m_pChart->createDefaultAxes();
	//m_pChart->addSeries(m_pCurSeries);
	m_pChart->axisY()->setRange(0, 120);
	m_pChart->axisX()->setRange(0, 2000);
	this->setWindowFlags(Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint/* | Qt::WindowStaysOnTopHint*/);

	m_pCoordinateLabel = new QLabel(this);
	m_pCoordinateLabel->setText("0.0, 0.0");
	m_pCoordinateLabel->setStyleSheet(QString("color:rgb(255,255,255)"));
	m_pCoordinateLabel->setAttribute(Qt::WA_TransparentForMouseEvents, true);
	m_CoordinatePos = QPoint(-100, -100);

	m_pUpDownLabel = new QLabel(this);
	m_pUpDownLabel->setText(QStringLiteral("上行方向"));
	m_pUpDownLabel->setStyleSheet(QString("color:rgb(255,255,255); background-color:transparent;"));
	m_pUpDownLabel->setAttribute(Qt::WA_TransparentForMouseEvents, true);
	QPoint point;
	int nWidth = ((QWidget*)this->parent())->width();
	point.setX(nWidth - m_pUpDownLabel->width());
	point.setY(10);
	m_pUpDownLabel->move(point);
}

void CChartWidget::UpdateStandard()
{
	if (nullptr == m_pStandardSeries)
	{
		return;
	}
	m_pStandardSeries->clear();
	m_pStandardSeries->append(m_lstStandardPos);
}

void CChartWidget::UpdateCur()
{
	if (nullptr == m_pCurSeries)
	{
		return;
	}
	m_pCurSeries->clear();
	m_pCurSeries->append(m_lstCurPos);

	if (m_lstCurPos.empty())
	{
		return;
	}
	QPointF pointF = m_lstCurPos.front();
	this->SetAxisXRange(pointF.x(), pointF.x() + 2000);
}

void CChartWidget::UpdateGLB()
{
	auto itr = m_mapfGLBFlags.begin();
	for (; itr != m_mapfGLBFlags.end(); ++itr)
	{
		CStaionLabel* pLabel = itr.value();
		if (nullptr == pLabel)
		{
			continue;
		}
		pLabel->hide();
	}

	foreach(StationInfo var, m_lstStationInfo)
	{
		if (var.m_eUpDownType == m_eUpDownType)
		{
			QPointF pointF = m_pChart->mapToPosition(QPointF(var.m_fGLB, 0.0f), m_pCurSeries);
			pointF = m_pChart->mapToParent(pointF);
			QPoint pos(pointF.x(), pointF.y());
			CStaionLabel* pStationLabel = nullptr;
			auto itr = m_mapfGLBFlags.find(var.m_fGLB);
			if (itr == m_mapfGLBFlags.end())
			{
				pStationLabel = new CStaionLabel(var, this);
				connect(pStationLabel, &CStaionLabel::Sig_ShowStationInfo, this, &CChartWidget::Slot_ShowStationInfo);
				pStationLabel->setStyleSheet(QString("background-color:transparent;"));
				//pStationLabel->resize(30, 30);
				m_mapfGLBFlags[var.m_fGLB] = pStationLabel;
			}
			else
			{
				pStationLabel = m_mapfGLBFlags[var.m_fGLB];
			}
			if (nullptr != pStationLabel)
			{
				pos.setY(pos.y() - pStationLabel->height());
				pStationLabel->move(pos);
				pStationLabel->show();
			}
		}
	}
}
