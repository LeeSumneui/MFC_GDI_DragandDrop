
// 2014111624_�̼���View.h : CMy2014111624_�̼���View Ŭ������ �������̽�
//

#pragma once
#include "atltypes.h"


class CMy2014111624_�̼���View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy2014111624_�̼���View();
	DECLARE_DYNCREATE(CMy2014111624_�̼���View)

// Ư���Դϴ�.
public:
	CMy2014111624_�̼���Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy2014111624_�̼���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	bool m_bTimerType;
	CString m_strTimer;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	bool m_bDrag;
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	CPoint m_ptMousePoint;
	CPoint m_ptMouseMove;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_ptMouseRange;
};

#ifndef _DEBUG  // 2014111624_�̼���View.cpp�� ����� ����
inline CMy2014111624_�̼���Doc* CMy2014111624_�̼���View::GetDocument() const
   { return reinterpret_cast<CMy2014111624_�̼���Doc*>(m_pDocument); }
#endif

