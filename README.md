# MFC KillFocus Derived CEdit

## Table of Content

	* Introduction
	* Solution
	* History

## Introduction

This tip is written in response to [Member 14594285](https://www.codeproject.com/script/Membership/View.aspx?mid=14594285)&#39;s Q&A question on [Kill focus derived class cedit](https://www.codeproject.com/Questions/5383653/Kill-focus-derived-class-cedit) which he reposted more than once. Hopefully this tip can help him to resolve his issue.

## Solution

First we create a test application by adding two static controls, two edit controls and a button to switch focus away from the first edit control to second edit control.

![00_AppScreenshot.png](/images/00_AppScreenshot.png)

Secondly, we right-click on the first edit control to add variable to control it.

![01_AddVariable.png](/images/01_AddVariable.png)

The "Add Control Variable" dialog appears. Fill in the control name and make sure the "Category" is `Control` and "Variable Type" is `CEdit`. Remember to add variable for the second edit control as well.

![02_AddVariable.png](/images/02_AddVariable.png)

Next, we are going to create our `CEdit` derived class. Go to "Solution Explorer" and right-click on your MFC project and select "Class Wizard..."

![03_ClassWizard.png](/images/03_ClassWizard.png)

The "Class Wizard" appears. Click on the right dropdown of "Add Class..."

![04_ClassWizard.png](/images/04_ClassWizard.png)

The "MFC Class..." dropdown appears and click on it.

![05_ClassWizard.png](/images/05_ClassWizard.png)

The "Add MFC Class" dialog appears. Give your derived class a proper name under "Class name". I call mine `CDerivedEdit`. Remember to change from `CWnd` to `CEdit` for the "Base class" dropdown on the right. Click Ok when done.

![06_CreateDerivedEdit.png](/images/06_CreateDerivedEdit.png)

We are back to Class Wizard dialog. Now we are going to add the function handler for `WM_KILLFOCUS`.

![07_AddKillFocus2.png](/images/07_AddKillFocus2.png)

If for some reason, you cannot add the function handler for `WM_KILLFOCUS`. You can add it manually in code. Open the _CDerivedEdit.h_ in your editor and add this function declaration to the `CDerivedEdit` class. Don&#39;t worry about `afx_msg`; it is to tell Visual Studio that this function is to handle message. `afx_msg` is defined to be nothing. AFX is the old name of MFC which is never released.

```Cpp
afx_msg void OnKillFocus(CWnd* pNewWnd);

```

Open _CDerivedEdit.cpp_ in your editor and go to the `BEGIN_MESSAGE_MAP` section.

```Cpp
BEGIN_MESSAGE_MAP(CDerivedEdit, CEdit)
END_MESSAGE_MAP()
```

And add `ON_WM_KILLFOCUS()`

```Cpp
BEGIN_MESSAGE_MAP(CDerivedEdit, CEdit)
    ON_WM_KILLFOCUS()
END_MESSAGE_MAP()
```

Add the `OnKillFocus` as below if it haven&#39;t been added by Class Wizard. The only new line is the `OutputDebugStringA` call to display in the debugger that `OnKillFocus` has been called.

```Cpp
void CDerivedEdit::OnKillFocus(CWnd* pNewWnd)
{
    CEdit::OnKillFocus(pNewWnd);

    OutputDebugStringA("OnKillFocus called.\n");
}

```

For the button function action, double-click on the button, a function will be added automatically. Add `m_edtAddress.SetFocus();` to the function. This kills focus of the `m_edtName` by setting focus to `m_edtAddress`.

```Cpp
void CTestDerivedEditDlg::OnBnClickedBtnFocus()
{
    m_edtAddress.SetFocus();
}
```

The last thing we need to do is to change the class of `m_edtName` from `CEdit` to `CDerivedEdit`. First, open your dialog header in your editor and include the _CDerivedEdit.h_

```Cpp
#include "CDerivedEdit.h"
```

Change the class of `m_edtName` from `CEdit`

```Cpp
CEdit m_edtName;
```

to `CDerivedEdit`

```Cpp
CDerivedEdit m_edtName;
```

We are ready to test our `CDerivedEdit`! Debug the application in Visual Studio. Click on the first edit control to set focus on it and then click the button to switch focus to second edit control. You can also kill focus by selecting the second edit control with your mouse click.

![00_AppScreenshot.png](/images/00_AppScreenshot.png)

You should see this line displayed in your debugger output.

```
OnKillFocus called.
```

Hurray! Our code works.

## History

* __12<sup>th</sup> June 2024__: First Release and fixed the bug of `CDerivedEdit` inherited from `CWnd` instead of `CEdit`.




