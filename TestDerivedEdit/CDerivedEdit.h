#pragma once


// CDerivedEdit

class CDerivedEdit : public CWnd
{
	DECLARE_DYNAMIC(CDerivedEdit)

public:
	CDerivedEdit();
	virtual ~CDerivedEdit();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKillFocus(CWnd* pNewWnd);
};


