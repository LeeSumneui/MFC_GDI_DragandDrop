
// 2014111624_�̼���View.cpp : CMy2014111624_�̼���View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2014111624_�̼���.h"
#endif

#include "2014111624_�̼���Doc.h"
#include "2014111624_�̼���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2014111624_�̼���View

IMPLEMENT_DYNCREATE(CMy2014111624_�̼���View, CView)

BEGIN_MESSAGE_MAP(CMy2014111624_�̼���View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy2014111624_�̼���View ����/�Ҹ�

CMy2014111624_�̼���View::CMy2014111624_�̼���View()
	: m_bTimerType(false)
	, m_strTimer(_T(""))
	, m_bDrag(false)
	, m_ptMousePoint(0)
	, m_ptMouseMove(0)
	, m_ptMouseRange(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy2014111624_�̼���View::~CMy2014111624_�̼���View()
{
}

BOOL CMy2014111624_�̼���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2014111624_�̼���View �׸���

void CMy2014111624_�̼���View::OnDraw(CDC* pDC)
{
	CMy2014111624_�̼���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	if(m_bDrag)
	{
		pDC->TextOut(m_ptMouseRange.x, m_ptMouseRange.y, m_strTimer);
	}
	else
	{
		pDC->TextOut(m_ptMouseRange.x, m_ptMouseRange.y, m_strTimer);
	}
}


// CMy2014111624_�̼���View �μ�

BOOL CMy2014111624_�̼���View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2014111624_�̼���View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2014111624_�̼���View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy2014111624_�̼���View ����

#ifdef _DEBUG
void CMy2014111624_�̼���View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2014111624_�̼���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2014111624_�̼���Doc* CMy2014111624_�̼���View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2014111624_�̼���Doc)));
	return (CMy2014111624_�̼���Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2014111624_�̼���View �޽��� ó����


void CMy2014111624_�̼���View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(AfxMessageBox(_T("30�� Ÿ�̸Ӹ� ���� �Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION, 0)==IDYES)
	{	
		m_bTimerType = true;
		SetTimer(1,1000,NULL);
	}
	else
	{
		if(AfxMessageBox(_T("60�� Ÿ�̸Ӹ� ���� �Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION, 0)==IDYES)
			SetTimer(0,1000,NULL);
	}
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

int count = 0;
void CMy2014111624_�̼���View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CTime timer;
	timer = CTime::GetCurrentTime();
	count++;

	m_strTimer.Format(_T("���� %d��"), timer.GetSecond());
	if(count == 60)
	{
		AfxMessageBox(_T("Ÿ�̸Ӱ� �����Ǿ����ϴ�."), MB_OK | MB_ICONINFORMATION, 0);
		KillTimer(0);
	}
	else if(count == 30)
	{
		AfxMessageBox(_T("Ÿ�̸Ӱ� �����Ǿ����ϴ�."), MB_OK | MB_ICONINFORMATION, 0);
		KillTimer(1);
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy2014111624_�̼���View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
		//if(point.x <=m_ptMouseRange.x + 30 && point.y <= m_ptMouseRange.y + 30)
			//if(point.x >= m_ptMouseRange.x -30 && point.y >= m_ptMouseRange.y -30)
		//	{
				m_bDrag =  TRUE;
				m_ptMouseMove = point;
			//}
	
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


void CMy2014111624_�̼���View::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_bDrag = FALSE;
	m_ptMouseRange = point;
	Invalidate();
	CView::OnRButtonUp(nFlags, point);
}


void CMy2014111624_�̼���View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

			if (m_bDrag)
			{
				m_ptMouseRange =  point;
			}
			
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
