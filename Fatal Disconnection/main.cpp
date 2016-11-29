#include "Includes.h"
#include "CMainForm.h"

int main(int argc, char **argv)
{
	PacketsClass.Initialize();

	QApplication a(argc, NULL);
	CMainForm w;

	w.show();

	return a.exec();
}

BOOL APIENTRY DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)main, (LPVOID)instance, 0, NULL);

		break;
	}

	return TRUE;
}