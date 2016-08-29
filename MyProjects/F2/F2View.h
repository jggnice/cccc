// F2View.h : interface of the CF2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_F2VIEW_H__E90E1443_90D0_4103_8571_600765C718D0__INCLUDED_)
#define AFX_F2VIEW_H__E90E1443_90D0_4103_8571_600765C718D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CF2View : public CView
{
protected: // create from serialization only
	CF2View();
	DECLARE_DYNCREATE(CF2View)

// Attributes
public:
	CF2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CF2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CF2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CF2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in F2View.cpp
inline CF2Doc* CF2View::GetDocument()
   { return (CF2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_F2VIEW_H__E90E1443_90D0_4103_8571_600765C718D0__INCLUDED_)
