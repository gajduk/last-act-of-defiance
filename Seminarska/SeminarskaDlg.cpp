// SeminarskaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Seminarska.h"
#include "SeminarskaDlg.h"
#include "GameClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CSeminarskaDlg dialog




CSeminarskaDlg::CSeminarskaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSeminarskaDlg::IDD, pParent)
{
	instruction_menu = false;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSeminarskaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DIFF, diff);
}

BEGIN_MESSAGE_MAP(CSeminarskaDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CSeminarskaDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CSeminarskaDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_GO, &CSeminarskaDlg::OnBnClickedGo)
	ON_BN_CLICKED(IDC_BACK, &CSeminarskaDlg::OnBnClickedBack)
END_MESSAGE_MAP()


// CSeminarskaDlg message handlers

BOOL CSeminarskaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, _T("Credits"));
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSeminarskaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSeminarskaDlg::OnPaint()
{
	CPaintDC dc(this);
	if ( ! instruction_menu ) {
		CPen pen(PS_SOLID,4,RGB(50,200,50));
		dc.SelectObject(pen);
		dc.SelectStockObject(NULL_BRUSH);
		dc.Ellipse(250,250,500,500);
		dc.Ellipse(-50,-50,70,70);
		dc.Ellipse(120,120,190,190);
		dc.Ellipse(300,-500,1300,500);
		CBrush brush(RGB(150,150,150));
	}
	else {
		CBrush brush(RGB(200,200,200));	
		dc.SelectObject(brush);
		dc.Rectangle(-10,-10,800,1000);
		CPen pen(PS_SOLID,4,RGB(30,120,30));
		dc.SelectObject(pen);
		dc.SelectStockObject(NULL_BRUSH);
		dc.Ellipse(250,250,500,500);
		dc.Ellipse(-50,-50,70,70);
		dc.Ellipse(120,20,190,90);
		dc.Ellipse(300,-500,1300,500);
		dc.SetBkMode(0);
		dc.TextOutW(100,100,_T("Use W,A,S,D to move around"),30);
		dc.TextOutW(100,115,_T("Press SPACE to shoot , hold fo continued fire"),50);
		dc.TextOutW(100,130,_T("You can toggle autofire by hitting  LEFT SHIFT"),50);
		dc.TextOutW(100,145,_T("To pause the game hit P or PAUSE"),40);
		dc.TextOutW(100,160,_T("To quit first accses the in-game menu by pressing either P,Q or X"),70);
		dc.TextOutW(100,175,_T("To drop a bomb use the T key"),30);
		dc.TextOutW(100,190,_T("Have FUN!"),10);
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSeminarskaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSeminarskaDlg::OnBnClickedOk()
{
	UpdateData(true);
	if (GetDlgItem(IDC_STAT)->IsWindowVisible() ) {
		
	}
	else {
		GetDlgItem(IDC_BUTTON1)->ShowWindow(false);
		GetDlgItem(IDOK)->ShowWindow(false);
		GetDlgItem(IDCANCEL)->ShowWindow(false);
		diff.SetCurSel(1);
		GetDlgItem(IDC_GO)->ShowWindow(true);
		GetDlgItem(IDC_STAT)->ShowWindow(true);
		GetDlgItem(IDC_DIFF)->ShowWindow(true);
		GetDlgItem(IDC_BACK)->ShowWindow(true);
	}
	
}

void CSeminarskaDlg::OnBnClickedButton1()
{
	GetDlgItem(IDC_BUTTON1)->ShowWindow(false);
	GetDlgItem(IDOK)->ShowWindow(false);
	GetDlgItem(IDCANCEL)->ShowWindow(false);
	GetDlgItem(IDC_BACK)->ShowWindow(true);
	instruction_menu = true;
	Invalidate();
}

void CSeminarskaDlg::OnBnClickedGo()
{
	GameClass::DIFFICULTY = diff.GetCurSel()+1;
	if ( theGame.DoModal() == IDCANCEL ) {
		OnOK();
	}
	else {
		GetDlgItem(IDC_BUTTON1)->ShowWindow(true);
		GetDlgItem(IDOK)->ShowWindow(true);
		GetDlgItem(IDCANCEL)->ShowWindow(true);
		GetDlgItem(IDC_GO)->ShowWindow(false);
		GetDlgItem(IDC_STAT)->ShowWindow(false);
		GetDlgItem(IDC_DIFF)->ShowWindow(false);
		GetDlgItem(IDC_BACK)->ShowWindow(false);
	}
}

void CSeminarskaDlg::OnBnClickedBack()
{	
	GetDlgItem(IDC_BACK)->ShowWindow(false);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(true);
	GetDlgItem(IDOK)->ShowWindow(true);
	GetDlgItem(IDCANCEL)->ShowWindow(true);
	GetDlgItem(IDC_GO)->ShowWindow(false);
	GetDlgItem(IDC_STAT)->ShowWindow(false);
	GetDlgItem(IDC_DIFF)->ShowWindow(false);
	instruction_menu = false;
	Invalidate();
}
