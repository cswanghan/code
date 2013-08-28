
// helloworldView.cpp : ChelloworldView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "helloworld.h"
#endif

#include "helloworldDoc.h"
#include "helloworldView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ChelloworldView

IMPLEMENT_DYNCREATE(ChelloworldView, CView)

BEGIN_MESSAGE_MAP(ChelloworldView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &ChelloworldView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ChelloworldView ����/����

ChelloworldView::ChelloworldView()
{
	// TODO: �ڴ˴���ӹ������

}

ChelloworldView::~ChelloworldView()
{
}

BOOL ChelloworldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// ChelloworldView ����

void ChelloworldView::OnDraw(CDC* /*pDC*/)
{
	ChelloworldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// ChelloworldView ��ӡ


void ChelloworldView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL ChelloworldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void ChelloworldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void ChelloworldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void ChelloworldView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void ChelloworldView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ChelloworldView ���

#ifdef _DEBUG
void ChelloworldView::AssertValid() const
{
	CView::AssertValid();
}

void ChelloworldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ChelloworldDoc* ChelloworldView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ChelloworldDoc)));
	return (ChelloworldDoc*)m_pDocument;
}
#endif //_DEBUG


// ChelloworldView ��Ϣ�������
