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
	QList<QPointF> m_lstCurPos;			// ���й켣����
	QList<QPointF> m_lstStandardPos;	// ��׼�켣����
	QList<StationInfo> m_lstStationInfo;// վ����Ϣ
	QMap<float, CStaionLabel*> m_mapfGLBFlags;// ��������Ӽ���

	CChartViewImp* m_pChartView;
	QtCharts::QChart* m_pChart;				
	QLineSeries* m_pCurSeries;			// ʵ���ٶ���
	QLineSeries* m_pStandardSeries;		// ��׼�ٶ���

	QString m_strTrainSerialName;		// �г���B001


	QLabel* m_pUpDownLabel = nullptr;	// �����б�ǩ
	QLabel* m_pCoordinateLabel = nullptr;// �����ǩ
	QPoint m_CoordinatePos;				// ������λ��
	E_TRAIN_UP_DOWN_TYPE m_eUpDownType = E_TRAIN_UP_DOWN_TYPE_UP;	// ������
	int m_nReverseTimes = 0;
};
