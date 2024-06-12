
// TestDerivedEditDlg.h : header file
//

#pragma once
#include "CDerivedEdit.h"

// CTestDerivedEditDlg dialog
class CTestDerivedEditDlg : public CDialogEx
{
// Construction
public:
	CTestDerivedEditDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTDERIVEDEDIT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CDerivedEdit m_edtName;
	CEdit m_edtAddress;
	afx_msg void OnBnClickedBtnFocus();
};
