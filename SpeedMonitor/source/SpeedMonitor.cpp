#include "../include/SpeedMonitor.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QTabWidget>
#include "ChartWidget.h"
#include "WindowCtrlWidget.h"
#include "TrainManagement.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTimer>
#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QWindow>
#include <QDateTime>
#include <QScreen>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include "TrainEntity.h"
#include "ToolWidget.h"

SpeedMonitor::SpeedMonitor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Init();    
}

SpeedMonitor::~SpeedMonitor()
{
	if (nullptr != m_pChartTimer)
	{
		m_pChartTimer->start();
	}
}

void SpeedMonitor::Slot_BtnMinClicked()
{
	this->showMinimized();
}

void SpeedMonitor::Slot_BtnMaxClicked(bool bChecked)
{
	if (bChecked)
		this->showMaximized();
	else
		this->showNormal();
}

void SpeedMonitor::Slot_BtnCloseClicked()
{
	QMessageBox box(this);
	QPixmap pixMap(":/resource/question.png");
	pixMap = pixMap.scaled(32, 32);
	box.setIconPixmap(pixMap);
	box.setWindowTitle(QStringLiteral("提示"));
	box.setText(QStringLiteral("确定关闭软件 ？"));
	box.setStandardButtons(QMessageBox::Cancel | QMessageBox::Close);
	box.setButtonText(QMessageBox::Cancel, QStringLiteral("取消"));
	box.setButtonText(QMessageBox::Close, QStringLiteral("关闭"));
	box.setDefaultButton(QMessageBox::Cancel);
	if (QMessageBox::Cancel == box.exec())
	{
		return;
	}

	qApp->quit();
}

void SpeedMonitor::Slot_WindowMoveTo(const QPoint& pos)
{
	this->move(pos);
}

void SpeedMonitor::Slot_CreateTrainWgt(int nUpDownType, const QString& strDevName)
{
	CChartWidget* pChartWidget = new CChartWidget((E_TRAIN_UP_DOWN_TYPE)nUpDownType, this);
	pChartWidget->Initalize(m_lstStationInfo);
	pChartWidget->SetTrainDevName(strDevName);
	m_mapChartWgt[strDevName] = pChartWidget;
	m_pTabWgt->addTab(pChartWidget, strDevName);
}

void SpeedMonitor::Slot_ChartUpdate()
{
	QMutexLocker locker(&m_Mutex);
	auto itr = m_mapChartWgt.begin();
	for (; itr != m_mapChartWgt.end(); ++itr)
	{
		CChartWidget* pChartWgt = itr.value();
		if (nullptr == pChartWgt)
		{
			continue;
		}

		QString strDevName = pChartWgt->GetTrainDevName();
		CTrainEntity* pEntity = TRAINMANAGEMENT.GetTrainEntity(strDevName);
		if (nullptr == pEntity)
		{
			continue;
		}
		E_TRAIN_UP_DOWN_TYPE eType = pEntity->GetCurUpDpwnType();
		if (m_eUpDownType != eType)
		{
			continue;
		}

		TrainBasicInfo info = pEntity->GetCurTrainInfo();
		QPointF point(info.m_fAbsolutePosition, info.m_fSpeed);
		pChartWgt->Append(point);
		pChartWgt->SetUpDownType((E_TRAIN_UP_DOWN_TYPE)info.m_nUpOrDown);
		/*QList<QPointF> lstPoint = pEntity->GetHistoryInfo(m_eUpDownType);
		pChartWgt->SetCurPoints(lstPoint);*/
	}
}

void SpeedMonitor::Slot_GrabWindow()
{
	if (nullptr == m_pTabWgt)
	{
		return;
	}
	QString strPath = QFileDialog::getExistingDirectory(this, QStringLiteral("保存路径"), "/home/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (strPath.isEmpty())
	{
		return;
	}
	QString strDir = strPath + QString("/");
	QDir dir(strDir);
	if (!dir.exists())
	{
		if (!dir.mkpath(strDir))
		{
			return;
		}
	}
	QString strFileName = strDir + QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss") + QString(".jpg");
	QFile file(strFileName);
	if (file.exists())
	{
		return;
	}
	QRect rect = m_pTabWgt->geometry();
	QScreen* pScreen = this->windowHandle()->screen();
	QPixmap pixMap = pScreen->grabWindow(this->winId(), rect.x(), rect.y(), rect.width(), rect.height());
	file.open(QIODevice::WriteOnly);
	pixMap.save(&file, "jpg");
	file.close();
	QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("截图成功"));
}

void SpeedMonitor::Slot_ChangeUpDownType(E_TRAIN_UP_DOWN_TYPE eType)
{
	QMutexLocker locker(&m_Mutex);
	m_eUpDownType = eType;
	auto itr = m_mapChartWgt.begin();
	for (; itr != m_mapChartWgt.end(); ++itr)
	{
		QString strDevName = itr.key();
		CTrainEntity* pEntity = TRAINMANAGEMENT.GetTrainEntity(strDevName);
		if (nullptr == pEntity)
		{
			continue;
		}
		QList<QPointF> lstPoint = pEntity->GetHistoryInfo(eType);
		CChartWidget* pWidget = itr.value();
		if (nullptr == pWidget)
		{
			continue;
		}
		pWidget->SetUpDownType(eType);
		pWidget->SetCurPoints(lstPoint);
	}
}

void SpeedMonitor::Init()
{
	this->setStyleSheet(QString(".QWidget{border:1px solid rgb(182,182,182);}"));

	InitData();
	InitGUI();
	InitConnect();
	InitTimer();
}

void SpeedMonitor::InitData()
{
	QString strStationFile = QApplication::applicationDirPath() + QString("/Config/StopkilometerPost.json");
	m_lstStationInfo.clear();
	QFile file(strStationFile);
	if (!file.exists())
	{
		return;
	}
	if (!file.open(QIODevice::ReadOnly))
	{
		return;
	}
	QByteArray arr = file.readAll();
	file.close();

	QJsonDocument doc = QJsonDocument::fromJson(arr);
	if (doc.isNull())
	{
		return;
	}
	QJsonArray arrJson = doc.array();
	for (int i = 0; i < arrJson.count(); ++i)
	{
		QJsonValue jsValue = arrJson.at(i); 
		StationInfo stStationInfo;
		stStationInfo.m_fGLB = jsValue.toObject().toVariantMap().value("glb").toDouble();
		stStationInfo.m_strStationName = jsValue.toObject().toVariantMap().value("StationName").toString();
		stStationInfo.m_eUpDownType = (E_TRAIN_UP_DOWN_TYPE)(jsValue.toObject().toVariantMap().value("upline").toString() == "true" ? 1 : 0);
		m_lstStationInfo.append(stStationInfo);
	}
}

void SpeedMonitor::InitGUI()
{
	QHBoxLayout* pHLayout = new QHBoxLayout(this);
	m_pCenterWidget = new QWidget(this);
	pHLayout->addWidget(m_pCenterWidget);
	pHLayout->setMargin(0);
	this->centralWidget()->setLayout(pHLayout);

	m_pWindowCtrlWgt = new CWindowCtrlWidget(this);
	m_pWindowCtrlWgt->SetTitle(QStringLiteral("列车速度监视软件"));
	m_pWindowCtrlWgt->SetIcon(":/resource/Speed.png");
	m_ToolWgt = new CToolWidget(this);

	m_pTabWgt = new QTabWidget(this);
	QVBoxLayout* pVLayout = new QVBoxLayout(this);
	pVLayout->setMargin(3);
	pVLayout->setSpacing(3);
	pVLayout->addWidget(m_pWindowCtrlWgt);
	pVLayout->addWidget(m_ToolWgt);
	pVLayout->addWidget(m_pTabWgt);
	m_pCenterWidget->setLayout(pVLayout);

#if 0
	CChartWidget* pChartWidget = new CChartWidget(E_TRAIN_UP_DOWN_TYPE_UP, this);
	pChartWidget->Initalize(m_lstStationInfo);
	pChartWidget->SetTrainSerialName("B001");
	CChartWidget* pChartWidget2 = new CChartWidget(E_TRAIN_UP_DOWN_TYPE_DOWN, this);
	pChartWidget2->Initalize(m_lstStationInfo);
	pChartWidget2->SetTrainSerialName("B002");
	m_mapChartWgt["B001"] = pChartWidget;
	m_mapChartWgt["B002"] = pChartWidget2;
	m_pTabWgt->addTab(pChartWidget, "B001");
	m_pTabWgt->addTab(pChartWidget2, "B002");
#endif


	setWindowIcon(QIcon(":/resource/Speed.png"));
	setWindowFlags(Qt::FramelessWindowHint);
}

void SpeedMonitor::InitConnect()
{
	if (nullptr != m_pWindowCtrlWgt)
	{
		connect(m_pWindowCtrlWgt, &CWindowCtrlWidget::Sig_BtnMinClicked, this, &SpeedMonitor::Slot_BtnMinClicked);
		connect(m_pWindowCtrlWgt, &CWindowCtrlWidget::Sig_BtnMaxClicked, this, &SpeedMonitor::Slot_BtnMaxClicked);
		connect(m_pWindowCtrlWgt, &CWindowCtrlWidget::Sig_BtnCloseClicked, this, &SpeedMonitor::Slot_BtnCloseClicked);
		connect(m_pWindowCtrlWgt, &CWindowCtrlWidget::Sig_WindowMove, this, &SpeedMonitor::Slot_WindowMoveTo);
		connect(m_pWindowCtrlWgt, &CWindowCtrlWidget::Sig_WindowShowMaximum, this, &SpeedMonitor::Slot_BtnMaxClicked);
	}
	connect(CTrainManagement::GetInstance(), &CTrainManagement::Sig_CreateTrain, this, &SpeedMonitor::Slot_CreateTrainWgt, Qt::QueuedConnection);
	connect(m_ToolWgt, &CToolWidget::Sig_GrabWindow, this, &SpeedMonitor::Slot_GrabWindow);
	connect(m_ToolWgt, &CToolWidget::Sig_UpDownClicked, this, &SpeedMonitor::Slot_ChangeUpDownType);
}

void SpeedMonitor::InitTimer()
{
	m_pChartTimer = new QTimer(this);
	m_pChartTimer->setInterval(2000);
	m_pChartTimer->setSingleShot(false);
	connect(m_pChartTimer, &QTimer::timeout, this, &SpeedMonitor::Slot_ChartUpdate);
	m_pChartTimer->start();
}
