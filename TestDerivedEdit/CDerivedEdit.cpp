// CDerivedEdit.cpp : implementation file
//

#include "pch.h"
#include "TestDerivedEdit.h"
#include "CDerivedEdit.h"


// CDerivedEdit

IMPLEMENT_DYNAMIC(CDerivedEdit, CEdit)

CDerivedEdit::CDerivedEdit()
{

}

CDerivedEdit::~CDerivedEdit()
{
}


BEGIN_MESSAGE_MAP(CDerivedEdit, CEdit)
	ON_WM_KILLFOCUS()
END_MESSAGE_MAP()



// CDerivedEdit message handlers




void CDerivedEdit::OnKillFocus(CWnd* pNewWnd)
{
	CEdit::OnKillFocus(pNewWnd);

	OutputDebugStringA("OnKillFocus called.\n");
}
