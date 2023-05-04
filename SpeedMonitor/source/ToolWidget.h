#pragma once

#include <QWidget>
#include "../include/CommonHeader.h"

namespace Ui { class CToolWidget; };

class CToolWidget : public QWidget
{
	Q_OBJECT

public:
	CToolWidget(QWidget *parent = Q_NULLPTR);
	~CToolWidget();

signals:
	void Sig_GrabWindow();
	void Sig_UpDownClicked(E_TRAIN_UP_DOWN_TYPE eType);

private slots:
	void Slot_UpDownClicked(bool bChecked);

private:
	void Init();

private:
	Ui::CToolWidget *ui;
};
