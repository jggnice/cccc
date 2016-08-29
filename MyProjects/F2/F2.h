// F2.h : main header file for the F2 application
//

#if !defined(AFX_F2_H__150ADAEF_C1C8_4834_AA3B_8FC91DC3E226__INCLUDED_)
#define AFX_F2_H__150ADAEF_C1C8_4834_AA3B_8FC91DC3E226__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CF2App:
// See F2.cpp for the implementation of this class
//

class CF2App : public CWinApp
{
public:
	CF2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CF2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CF2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_F2_H__150ADAEF_C1C8_4834_AA3B_8FC91DC3E226__INCLUDED_)
