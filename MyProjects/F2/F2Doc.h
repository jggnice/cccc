// F2Doc.h : interface of the CF2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_F2DOC_H__46FC80C5_161D_45B5_9CAB_CDC22E0992E5__INCLUDED_)
#define AFX_F2DOC_H__46FC80C5_161D_45B5_9CAB_CDC22E0992E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CF2Doc : public CDocument
{
protected: // create from serialization only
	CF2Doc();
	DECLARE_DYNCREATE(CF2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CF2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CF2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CF2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_F2DOC_H__46FC80C5_161D_45B5_9CAB_CDC22E0992E5__INCLUDED_)
