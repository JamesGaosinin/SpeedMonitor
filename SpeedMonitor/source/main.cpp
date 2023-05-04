#include "../include/SpeedMonitor.h"
#include <QtWidgets/QApplication>
#include "TrainManagement.h"
#include "NetWorkManager.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SpeedMonitor w;
	w.showMaximized();
	CTrainManagement::GetInstance();
	CNetWorkManager::GetInstance();
	int nRet = a.exec();
	CTrainManagement::Release();
	CNetWorkManager::Release();
	return nRet;  
}
