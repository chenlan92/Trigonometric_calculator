
// MFC_1Dlg.h: 头文件
//

#pragma once


// CMFC1Dlg 对话框
class CMFC1Dlg : public CDialogEx
{
// 构造
public:
	CMFC1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_1_DIALOG };
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
	CString m_outputstr;     //结果
	CString m_inputstr;        //显示
	CString m_operationstr;        //运算
	CString m_textstr;        //临时存储
	double m_input;
	double m_output;
	char m_operation;
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
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedSin();
	afx_msg void OnBnClickedCos();
	afx_msg void OnBnClickedTan();
	afx_msg void OnBnClickedCot();
	afx_msg void OnBnClickedSec();
	afx_msg void OnBnClickedCsc();
	afx_msg void OnBnClickedEqu();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedAc();
	afx_msg void OnBnClickedAns();
	afx_msg void OnStnClickedOperation();
	afx_msg void OnStnClickedOutput();
	afx_msg void OnStnClickedInput();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedRad();
	afx_msg void OnBnClickedAng();
};
