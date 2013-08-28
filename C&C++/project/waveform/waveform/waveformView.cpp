
// waveformView.cpp : CwaveformView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "waveform.h"
#endif

#include "waveformDoc.h"
#include "waveformView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CwaveformView

IMPLEMENT_DYNCREATE(CwaveformView, CView)

BEGIN_MESSAGE_MAP(CwaveformView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CwaveformView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CwaveformView ����/����

CwaveformView::CwaveformView()
{
	// TODO: �ڴ˴���ӹ������

}

CwaveformView::~CwaveformView()
{
}

BOOL CwaveformView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CwaveformView ����

void CwaveformView::OnDraw(CDC* /*pDC*/)
{
	CwaveformDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CwaveformView ��ӡ


void CwaveformView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CwaveformView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CwaveformView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CwaveformView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CwaveformView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CwaveformView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CwaveformView ���

#ifdef _DEBUG
void CwaveformView::AssertValid() const
{
	CView::AssertValid();
}

void CwaveformView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CwaveformDoc* CwaveformView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CwaveformDoc)));
	return (CwaveformDoc*)m_pDocument;
}
#endif //_DEBUG


// CwaveformView ��Ϣ�������
