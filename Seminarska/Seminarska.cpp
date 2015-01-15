// Seminarska.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Seminarska.h"
#include "SeminarskaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSeminarskaApp

BEGIN_MESSAGE_MAP(CSeminarskaApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()




CSeminarskaApp::CSeminarskaApp()
{

}



CSeminarskaApp theApp;




BOOL CSeminarskaApp::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	CWinApp::InitInstance();
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	CSeminarskaDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK) {

	}
	else if (nResponse == IDCANCEL) {

	}
	return FALSE;
}