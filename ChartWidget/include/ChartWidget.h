#pragma once
#include "chartwidget_global.h"
#include <QDialog>
#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QVector>
#include <QMutex>
#include "Common.h"
#include "../../SpeedMonitor/include/CommonHeader.h"

QT_CHARTS_USE_NAMESPACE

class CChartViewImp;
class CStaionLabel;
class QLabel;

namespace Ui { class CChartWidget; };
class CHARTWIDGET_EXPORT CChartWidget : public QDialog
{
	Q_OBJECT

public:
	CChartWidget(E_TRAIN_UP_DOWN_TYPE eUpDownType, QWidget *parent = Q_NULLPTR);
	~CChartWidget();

	void SetTrainDevName(const QString& strName);
	QString GetTrainDevName();
	void Initalize(const QList<StationInfo>& vecPos);
	void SetStandardPoints(const QList<QPointF>& vecPos);
	void SetCurPoints(const QList<QPointF>& vecPos);
	void Append(const QPointF& point);
	void SetAxisXRange(float fBegin, float fEnd);
	void SetAxisYRange(float fBegin, float fEnd);
	void SetUpDownType(E_TRAIN_UP_DOWN_TYPE eType);
	E_TRAIN_UP_DOWN_TYPE GetUpDownType();
	void Reset();

protected:
	virtual void mouseMoveEvent(QMouseEvent *event) override;

private slots:
	void Slot_DrawCrossLine(const QPoint& pos);
	void Slot_ShowStationInfo(const QPoint& pos, const QString& strText);

protected:
	virtual void showEvent(QShowEvent* Event) override;
	virtual void resizeEvent(QResizeEvent *event) override;

private:
	void Init();
	void UpdateStandard();
	void UpdateCur();
	void UpdateGLB();

private:
	Ui::CChartWidget* pUi;

	QMutex m_Mutex;
	QList<QPointF> m_lstCurPos;			// 运行轨迹集合
	QList<QPointF> m_lstStandardPos;	// 标准轨迹集合
	QList<StationInfo> m_lstStationInfo;// 站点信息
	QMap<float, CStaionLabel*> m_mapfGLBFlags;// 公里标牌子集合

	CChartViewImp* m_pChartView;
	QtCharts::QChart* m_pChart;				
	QLineSeries* m_pCurSeries;			// 实际速度线
	QLineSeries* m_pStandardSeries;		// 标准速度线

	QString m_strTrainSerialName;		// 列车号B001


	QLabel* m_pUpDownLabel = nullptr;	// 上下行标签
	QLabel* m_pCoordinateLabel = nullptr;// 坐标标签
	QPoint m_CoordinatePos;				// 鼠标相对位置
	E_TRAIN_UP_DOWN_TYPE m_eUpDownType = E_TRAIN_UP_DOWN_TYPE_UP;	// 上下行
	int m_nReverseTimes = 0;
};
