#include "CMainForm.h"
#include "Includes.h"

CMainForm *MainFormClass;

CMainForm::CMainForm(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui = new Ui::MainForm;
	MainFormClass = this;

	ui->setupUi(this);

	setWindowFlags(Qt::Tool | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowStaysOnTopHint);
	
	new boost::thread(&CMainForm::ClearProcessMemoryThread, this);
}

CMainForm::~CMainForm()
{

}

void CMainForm::ClearProcessMemoryThread()
{
	while (true)
	{
		EmptyWorkingSet(GetCurrentProcess());
		Sleep(1000);
	}
}

void CMainForm::CheckBoxToggled(bool state)
{
	QObject *s = sender();

	if (s = ui->checkBoxOneClickBoardGameDisconnect)
	{
		// QString packet = "";

		if (ui->checkBoxOneClickBoardGameDisconnect->isChecked())
		{
			// PacketsClass.AddToBlockRecvPacketsList(packet);

			is_one_click_boardgame = true;
		}
		else
		{
			// PacketsClass.RemoveFromBlockRecvPacketsList(packet);

			is_one_click_boardgame = false;
		}
	}
}

void CMainForm::closeEvent(QCloseEvent *event)
{
	switch (QMessageBox::question(this, "Question", "Terminate MapleStory?", QMessageBox::Ok | QMessageBox::Cancel))
	{
	case QMessageBox::Ok:
		TerminateProcess(GetCurrentProcess(), -1);
		
		break;

	case QMessageBox::Cancel:
		event->ignore();
		
		break;
	}
}