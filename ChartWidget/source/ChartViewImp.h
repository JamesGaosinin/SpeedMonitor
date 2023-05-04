#pragma once

#include <QChartView>

QT_CHARTS_USE_NAMESPACE

namespace QtCharts{ class QLineSeries; };

class CChartViewImp : public QChartView
{
	Q_OBJECT

public:
	CChartViewImp(QWidget *parent = nullptr);
	~CChartViewImp();

signals:
	void Sig_RePaintGLB();
	void Sig_MouseMoveEvent(const QPoint& pos);

protected:
	virtual void mousePressEvent(QMouseEvent *event)override;
	virtual void mouseMoveEvent(QMouseEvent *event)override;
	virtual void wheelEvent(QWheelEvent *event)override;

private:
	void Init();
	void InitConnect();

private:
	QPointF m_BeginPos;		// 按下起点坐标值

	bool m_bPress;
	//QLineSeries* m_pLineX = nullptr;
	//QLineSeries* m_pLineY = nullptr;
	int m_nScoleMuti = 5;		// 缩放倍数
};
