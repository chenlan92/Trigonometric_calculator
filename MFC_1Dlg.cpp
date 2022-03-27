
// MFC_1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC_1.h"
#include "MFC_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC1Dlg 对话框



CMFC1Dlg::CMFC1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_input = 0;
	m_output = 0;
	m_operation = 0;
	m_datatype = FALSE;
}

void CMFC1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NUM1, &CMFC1Dlg::OnBnClickedNum1)
	ON_BN_CLICKED(IDC_NUM2, &CMFC1Dlg::OnBnClickedNum2)
	ON_BN_CLICKED(IDC_NUM3, &CMFC1Dlg::OnBnClickedNum3)
	ON_BN_CLICKED(IDC_NUM4, &CMFC1Dlg::OnBnClickedNum4)
	ON_BN_CLICKED(IDC_NUM5, &CMFC1Dlg::OnBnClickedNum5)
	ON_BN_CLICKED(IDC_NUM6, &CMFC1Dlg::OnBnClickedNum6)
	ON_BN_CLICKED(IDC_NUM7, &CMFC1Dlg::OnBnClickedNum7)
	ON_BN_CLICKED(IDC_NUM8, &CMFC1Dlg::OnBnClickedNum8)
	ON_BN_CLICKED(IDC_NUM9, &CMFC1Dlg::OnBnClickedNum9)
	ON_BN_CLICKED(IDC_NUM0, &CMFC1Dlg::OnBnClickedNum0)
	ON_BN_CLICKED(IDC_SIGN, &CMFC1Dlg::OnBnClickedSign)
	ON_BN_CLICKED(IDC_DOT, &CMFC1Dlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_ADD, &CMFC1Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &CMFC1Dlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &CMFC1Dlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIV, &CMFC1Dlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_SIN, &CMFC1Dlg::OnBnClickedSin)
	ON_BN_CLICKED(IDC_COS, &CMFC1Dlg::OnBnClickedCos)
	ON_BN_CLICKED(IDC_TAN, &CMFC1Dlg::OnBnClickedTan)
	ON_BN_CLICKED(IDC_COT, &CMFC1Dlg::OnBnClickedCot)
	ON_BN_CLICKED(IDC_SEC, &CMFC1Dlg::OnBnClickedSec)
	ON_BN_CLICKED(IDC_CSC, &CMFC1Dlg::OnBnClickedCsc)
	ON_BN_CLICKED(IDC_EQU, &CMFC1Dlg::OnBnClickedEqu)
	ON_BN_CLICKED(IDC_DEL, &CMFC1Dlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_AC, &CMFC1Dlg::OnBnClickedAc)
	ON_BN_CLICKED(IDC_ANS, &CMFC1Dlg::OnBnClickedAns)
	ON_STN_CLICKED(IDC_OPERATION, &CMFC1Dlg::OnStnClickedOperation)
	ON_STN_CLICKED(IDC_OUTPUT, &CMFC1Dlg::OnStnClickedOutput)
	ON_STN_CLICKED(IDC_INPUT, &CMFC1Dlg::OnStnClickedInput)
	ON_BN_CLICKED(IDC_SAVE, &CMFC1Dlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_RAD, &CMFC1Dlg::OnBnClickedRad)
	ON_BN_CLICKED(IDC_ANG, &CMFC1Dlg::OnBnClickedAng)
END_MESSAGE_MAP()


// CMFC1Dlg 消息处理程序

BOOL CMFC1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFC1Dlg::OnBnClickedNum1()
{
	m_inputstr += L"1";
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedNum2()
{
	m_inputstr += L"2";
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedNum3()
{
	m_inputstr += L"3";
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedNum4()
{
	m_inputstr += L"4";
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedNum5()
{
	m_inputstr += L"5";
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedNum6()
{
	m_inputstr += L"6";
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedNum7()
{
	m_inputstr += L"7";
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedNum8()
{
	m_inputstr += L"8";
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedNum9()
{
	m_inputstr += L"9";
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedNum0()
{
	m_inputstr += L"0";
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedSign()
{
	m_input = _wtof(m_inputstr);
	m_input = -m_input;
	m_inputstr.Format(L"%lf", m_input);
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedDot()
{
	m_inputstr += L".";
	SetDlgItemText(IDC_INPUT, m_inputstr);
}


void CMFC1Dlg::OnBnClickedAdd()
{
	m_operationstr = "+";
	SetDlgItemText(IDC_OPERATION, m_operationstr);
}


void CMFC1Dlg::OnBnClickedSub()
{
	m_operationstr = "-";
	SetDlgItemText(IDC_OPERATION, m_operationstr);
}


void CMFC1Dlg::OnBnClickedMul()
{
	m_operationstr = "*";
	SetDlgItemText(IDC_OPERATION, m_operationstr);
}


void CMFC1Dlg::OnBnClickedDiv()
{
	m_operationstr = "/";
	SetDlgItemText(IDC_OPERATION, m_operationstr);
}


void CMFC1Dlg::OnBnClickedSin()
{
	m_operationstr = "sin";
	SetDlgItemText(IDC_OPERATION, m_operationstr);
}


void CMFC1Dlg::OnBnClickedCos()
{
	m_operationstr = "cos";
	SetDlgItemText(IDC_OPERATION, m_operationstr);
}


void CMFC1Dlg::OnBnClickedTan()
{
	m_operationstr = "tan";
	SetDlgItemText(IDC_OPERATION, m_operationstr);
}


void CMFC1Dlg::OnBnClickedCot()
{
	m_operationstr = "cot";
	SetDlgItemText(IDC_OPERATION, m_operationstr);
}


void CMFC1Dlg::OnBnClickedSec()
{
	m_operationstr = "sec";
	SetDlgItemText(IDC_OPERATION, m_operationstr);
}


void CMFC1Dlg::OnBnClickedCsc()
{
	m_operationstr = "csc";
	SetDlgItemText(IDC_OPERATION, m_operationstr);
}


void CMFC1Dlg::OnBnClickedEqu()
{
	m_operationstr = "=";
	SetDlgItemText(IDC_OPERATION, m_operationstr);
}


void CMFC1Dlg::OnBnClickedDel()
{
	if (m_inputstr.IsEmpty()) {
		SetDlgItemText(IDC_INPUT, L"0");
	}
	else if (m_inputstr.GetLength() == 1) {
		m_inputstr = m_inputstr.Left(m_inputstr.GetLength() - 1);
		SetDlgItemText(IDC_INPUT, L"0");
	}
	else {
		m_inputstr = m_inputstr.Left(m_inputstr.GetLength() - 1);
		SetDlgItemText(IDC_INPUT, m_inputstr);
	}
}


void CMFC1Dlg::OnBnClickedAc()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC1Dlg::OnBnClickedAns()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC1Dlg::OnBnClickedSave()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC1Dlg::OnStnClickedOperation()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC1Dlg::OnStnClickedOutput()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC1Dlg::OnStnClickedInput()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC1Dlg::OnBnClickedRad()
{
	m_datatype = FALSE;
}


void CMFC1Dlg::OnBnClickedAng()
{
	m_datatype = TRUE;
}
