// SeminarskaDlg.h : header file
//

#pragma once
#include "GameClass.h"
#include "afxwin.h"

// CSeminarskaDlg dialog
class CSeminarskaDlg : public CDialog
{
// Construction
public:
	CSeminarskaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SEMINARSKA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	GameClass theGame;
	bool instruction_menu;
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CComboBox diff;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedGo();
	afx_msg void OnBnClickedBack();
};
