#pragma once

#include <QWidget>
namespace Ui { class CWindowCtrlWidget; };
class SpeedMonitor;

class CWindowCtrlWidget : public QWidget
{
	Q_OBJECT

public:
	CWindowCtrlWidget(QWidget *parent = Q_NULLPTR);
	~CWindowCtrlWidget();

public:
	void SetIcon(const QString& strFile);
	void SetTitle(const QString& strTitle);

signals:
	void Sig_BtnMinClicked();
	void Sig_BtnMaxClicked(bool bChecked);
	void Sig_BtnCloseClicked();
	void Sig_WindowMove(const QPoint& pos);
	void Sig_WindowShowMaximum(bool bMax);

protected:
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void mouseDoubleClickEvent(QMouseEvent* event) override;

private:
	void Init();
	void InitGUI();
	void InitConnect();

private:
	Ui::CWindowCtrlWidget *ui;
	QPoint m_BeginPos;
	QPoint m_ComarePos;
	SpeedMonitor* m_pParent = nullptr;
};
