#ifndef CMAINFORM_H
#define CMAINFORM_H

#include "ui_CMainForm.h"

class CMainForm : public QMainWindow
{
	Q_OBJECT

public:
	CMainForm(QWidget *parent = 0, Qt::WFlags flags = 0);
	~CMainForm();

	Ui::MainForm *ui;

private:
	void ClearProcessMemoryThread();

private slots:
	void CheckBoxToggled(bool state);

protected:
	void closeEvent(QCloseEvent *event);
};

extern CMainForm *MainFormClass;

#endif // CMAINFORM_H
