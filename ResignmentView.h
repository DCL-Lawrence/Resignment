
// ResignmentView.h: CResignmentView 類別的介面
//

#pragma once


class CResignmentView : public CFormView
{
protected: // 僅從序列化建立
	CResignmentView() noexcept;
	DECLARE_DYNCREATE(CResignmentView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_RESIGNMENT_FORM };
#endif

// 屬性
public:
	CResignmentDoc* GetDocument() const;

// 作業
public:

// 覆寫
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援
	virtual void OnInitialUpdate(); // 建構後第一次呼叫
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 程式碼實作
public:
	virtual ~CResignmentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAgree();
	afx_msg void OnBnClickedDisagree();
	unsigned int count;
};

#ifndef _DEBUG  // 對 ResignmentView.cpp 中的版本進行偵錯
inline CResignmentDoc* CResignmentView::GetDocument() const
   { return reinterpret_cast<CResignmentDoc*>(m_pDocument); }
#endif

