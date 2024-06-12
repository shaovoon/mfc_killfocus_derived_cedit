// CDerivedEdit.cpp : implementation file
//

#include "pch.h"
#include "TestDerivedEdit.h"
#include "CDerivedEdit.h"


// CDerivedEdit

IMPLEMENT_DYNAMIC(CDerivedEdit, CWnd)

CDerivedEdit::CDerivedEdit()
{

}

CDerivedEdit::~CDerivedEdit()
{
}


BEGIN_MESSAGE_MAP(CDerivedEdit, CWnd)
	ON_WM_KILLFOCUS()
END_MESSAGE_MAP()



// CDerivedEdit message handlers




void CDerivedEdit::OnKillFocus(CWnd* pNewWnd)
{
	CWnd::OnKillFocus(pNewWnd);

	OutputDebugStringA("OnKillFocus called.\n");
}
