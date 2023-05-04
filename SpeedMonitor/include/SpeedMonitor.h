#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SpeedMonitor.h"
#include "CommonHeader.h"
#include "Common.h"

class CChartWidget;
class CWindowCtrlWidget;
class QTabWidget;
class CToolWidget;

class SpeedMonitor : public QMainWindow
{
	Q_OBJECT

public:
	SpeedMonitor(QWidget *parent = Q_NULLPTR);
	~SpeedMonitor();

private slots:
	void Slot_BtnMinClicked();
	void Slot_BtnMaxClicked(bool bChecked);
	void Slot_BtnCloseClicked();
	void Slot_WindowMoveTo(const QPoint& pos);
	void Slot_CreateTrainWgt(int nUpDownType, const QString& strDevName);
	void Slot_ChartUpdate();
	void Slot_GrabWindow();

	void Slot_ChangeUpDownType(E_TRAIN_UP_DOWN_TYPE eType);

private:
	void Init();
	void InitData();
	void InitGUI();
	void InitConnect();
	void InitTimer();

private:
	Ui::SpeedMonitorClass ui;

	QMutex m_Mutex;
	QWidget* m_pCenterWidget = nullptr;					// 中间
	CWindowCtrlWidget* m_pWindowCtrlWgt = nullptr;
	QTabWidget* m_pTabWgt = nullptr;
	QMap<QString, CChartWidget*> m_mapChartWgt;
	QList<StationInfo> m_lstStationInfo;  				// 站点信息
	QTimer* m_pChartTimer = nullptr;					// 更新chart界面

	CToolWidget* m_ToolWgt = nullptr;					// 工具空间
	E_TRAIN_UP_DOWN_TYPE m_eUpDownType = E_TRAIN_UP_DOWN_TYPE_UP;
};