
// Trigonometric_calculatorDlg.h: 头文件
//

#pragma once


// CTrigonometriccalculatorDlg 对话框
class CTrigonometriccalculatorDlg : public CDialogEx
{
// 构造
public:
	CTrigonometriccalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRIGONOMETRIC_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_showstr;
	CString m_typestr;
	double m_shownum;
	bool m_datatype;
	afx_msg void OnBnClickedNum1();
	afx_msg void OnBnClickedNum2();
	afx_msg void OnBnClickedNum3();
	afx_msg void OnBnClickedNum4();
	afx_msg void OnBnClickedNum5();
	afx_msg void OnBnClickedNum6();
	afx_msg void OnBnClickedNum7();
	afx_msg void OnBnClickedNum8();
	afx_msg void OnBnClickedNum9();
	afx_msg void OnBnClickedNum0();
	afx_msg void OnBnClickedSign();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedSin();
	afx_msg void OnBnClickedCos();
	afx_msg void OnBnClickedArcsin();
	afx_msg void OnBnClickedArctan();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedAc();
	afx_msg void OnBnClickedType();
	afx_msg void OnStnClickedShowtype();
};
