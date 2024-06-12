#pragma once


// CDerivedEdit

class CDerivedEdit : public CEdit
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


