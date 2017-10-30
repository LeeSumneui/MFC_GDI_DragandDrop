
// 2014111624_이수민View.cpp : CMy2014111624_이수민View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "2014111624_이수민.h"
#endif

#include "2014111624_이수민Doc.h"
#include "2014111624_이수민View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2014111624_이수민View

IMPLEMENT_DYNCREATE(CMy2014111624_이수민View, CView)

BEGIN_MESSAGE_MAP(CMy2014111624_이수민View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy2014111624_이수민View 생성/소멸

CMy2014111624_이수민View::CMy2014111624_이수민View()
	: m_bTimerType(false)
	, m_strTimer(_T(""))
	, m_bDrag(false)
	, m_ptMousePoint(0)
	, m_ptMouseMove(0)
	, m_ptMouseRange(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy2014111624_이수민View::~CMy2014111624_이수민View()
{
}

BOOL CMy2014111624_이수민View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2014111624_이수민View 그리기

void CMy2014111624_이수민View::OnDraw(CDC* pDC)
{
	CMy2014111624_이수민Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	if(m_bDrag)
	{
		pDC->TextOut(m_ptMouseRange.x, m_ptMouseRange.y, m_strTimer);
	}
	else
	{
		pDC->TextOut(m_ptMouseRange.x, m_ptMouseRange.y, m_strTimer);
	}
}


// CMy2014111624_이수민View 인쇄

BOOL CMy2014111624_이수민View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy2014111624_이수민View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy2014111624_이수민View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy2014111624_이수민View 진단

#ifdef _DEBUG
void CMy2014111624_이수민View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2014111624_이수민View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2014111624_이수민Doc* CMy2014111624_이수민View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2014111624_이수민Doc)));
	return (CMy2014111624_이수민Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2014111624_이수민View 메시지 처리기


void CMy2014111624_이수민View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(AfxMessageBox(_T("30초 타이머를 설정 하시겠습니까?"), MB_YESNO | MB_ICONQUESTION, 0)==IDYES)
	{	
		m_bTimerType = true;
		SetTimer(1,1000,NULL);
	}
	else
	{
		if(AfxMessageBox(_T("60초 타이머를 설정 하시겠습니까?"), MB_YESNO | MB_ICONQUESTION, 0)==IDYES)
			SetTimer(0,1000,NULL);
	}
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

int count = 0;
void CMy2014111624_이수민View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CTime timer;
	timer = CTime::GetCurrentTime();
	count++;

	m_strTimer.Format(_T("현재 %d초"), timer.GetSecond());
	if(count == 60)
	{
		AfxMessageBox(_T("타이머가 정지되었습니다."), MB_OK | MB_ICONINFORMATION, 0);
		KillTimer(0);
	}
	else if(count == 30)
	{
		AfxMessageBox(_T("타이머가 정지되었습니다."), MB_OK | MB_ICONINFORMATION, 0);
		KillTimer(1);
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy2014111624_이수민View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
		//if(point.x <=m_ptMouseRange.x + 30 && point.y <= m_ptMouseRange.y + 30)
			//if(point.x >= m_ptMouseRange.x -30 && point.y >= m_ptMouseRange.y -30)
		//	{
				m_bDrag =  TRUE;
				m_ptMouseMove = point;
			//}
	
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


void CMy2014111624_이수민View::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = FALSE;
	m_ptMouseRange = point;
	Invalidate();
	CView::OnRButtonUp(nFlags, point);
}


void CMy2014111624_이수민View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

			if (m_bDrag)
			{
				m_ptMouseRange =  point;
			}
			
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
