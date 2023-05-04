#include "ChartViewImp.h"
#include <QValueAxis>
#include <QLineSeries>

CChartViewImp::CChartViewImp(QWidget *parent)
	: QChartView(parent)
	, m_bPress(false)
{
	Init();
}

CChartViewImp::~CChartViewImp()
{
}

void CChartViewImp::mousePressEvent(QMouseEvent *event)
{
	m_BeginPos = event->pos();
}

void CChartViewImp::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		QPoint oCurPos = event->pos();
		
		QtCharts::QChart* pChart = this->chart();
		if (nullptr == pChart)
		{
			return;
		}
		QPointF posBegin = pChart->mapToValue(m_BeginPos);
		QPointF posEnd = pChart->mapToValue(oCurPos);

		qreal fDeltaValueX = oCurPos.x() - m_BeginPos.x();
		qreal fDeltaValueY = oCurPos.y() - m_BeginPos.y();
		pChart->scroll(-fDeltaValueX, 0);
		
		m_BeginPos = oCurPos;
		emit Sig_RePaintGLB();
		event->accept();
	}
	emit Sig_MouseMoveEvent(event->pos());
}

void CChartViewImp::wheelEvent(QWheelEvent *event)
{
	int nDelta = event->delta();
	if (nDelta > 0)
	{
		m_nScoleMuti--;
		if (m_nScoleMuti < 0)
		{
			m_nScoleMuti++;
			return;
		}
		this->chart()->zoomIn();
		this->chart()->axisY()->setRange(0, 120);
		emit Sig_RePaintGLB();
	}
	else
	{
		m_nScoleMuti++;
		if (m_nScoleMuti > 15)
		{
			m_nScoleMuti--;
			return;
		}
		this->chart()->zoomOut();
		this->chart()->axisY()->setRange(0, 120);
		emit Sig_RePaintGLB();
	}
}

void CChartViewImp::Init()
{
	InitConnect();
}

void CChartViewImp::InitConnect()
{
	//connect()
}
