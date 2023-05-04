#pragma once

#include <QWidget>
#include "Common.h"
namespace Ui { class CStaionLabel; };
class QLabel;

class CStaionLabel : public QWidget
{
	Q_OBJECT

public:
	CStaionLabel(const StationInfo& stStaionInfo, QWidget *parent = Q_NULLPTR);
	~CStaionLabel();

signals:
	void Sig_ShowStationInfo(const QPoint& pos, const QString& strText);

protected:
	virtual void mouseMoveEvent(QMouseEvent *event)override;

private:
	void Init();

private:
	Ui::CStaionLabel *ui;
	StationInfo m_stStaionInfo;
};
