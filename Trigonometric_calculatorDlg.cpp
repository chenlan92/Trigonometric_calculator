
// Trigonometric_calculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Trigonometric_calculator.h"
#include "Trigonometric_calculatorDlg.h"
#include "afxdialogex.h"
#include "mysin.h"
#include "mycos.h"
#include "myasin.h"
#include "myatan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI        3.14159265358979323846

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


// CTrigonometriccalculatorDlg 对话框



CTrigonometriccalculatorDlg::CTrigonometriccalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRIGONOMETRIC_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDB_BITMAP1);
	m_shownum = 0;
	m_datatype = FALSE;
}

void CTrigonometriccalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTrigonometriccalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NUM1, &CTrigonometriccalculatorDlg::OnBnClickedNum1)
	ON_BN_CLICKED(IDC_NUM2, &CTrigonometriccalculatorDlg::OnBnClickedNum2)
	ON_BN_CLICKED(IDC_NUM3, &CTrigonometriccalculatorDlg::OnBnClickedNum3)
	ON_BN_CLICKED(IDC_NUM4, &CTrigonometriccalculatorDlg::OnBnClickedNum4)
	ON_BN_CLICKED(IDC_NUM5, &CTrigonometriccalculatorDlg::OnBnClickedNum5)
	ON_BN_CLICKED(IDC_NUM6, &CTrigonometriccalculatorDlg::OnBnClickedNum6)
	ON_BN_CLICKED(IDC_NUM7, &CTrigonometriccalculatorDlg::OnBnClickedNum7)
	ON_BN_CLICKED(IDC_NUM8, &CTrigonometriccalculatorDlg::OnBnClickedNum8)
	ON_BN_CLICKED(IDC_NUM9, &CTrigonometriccalculatorDlg::OnBnClickedNum9)
	ON_BN_CLICKED(IDC_NUM0, &CTrigonometriccalculatorDlg::OnBnClickedNum0)
	ON_BN_CLICKED(IDC_SIGN, &CTrigonometriccalculatorDlg::OnBnClickedSign)
	ON_BN_CLICKED(IDC_DOT, &CTrigonometriccalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_SIN, &CTrigonometriccalculatorDlg::OnBnClickedSin)
	ON_BN_CLICKED(IDC_COS, &CTrigonometriccalculatorDlg::OnBnClickedCos)
	ON_BN_CLICKED(IDC_ARCSIN, &CTrigonometriccalculatorDlg::OnBnClickedArcsin)
	ON_BN_CLICKED(IDC_ARCTAN, &CTrigonometriccalculatorDlg::OnBnClickedArctan)
	ON_BN_CLICKED(IDC_DEL, &CTrigonometriccalculatorDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_AC, &CTrigonometriccalculatorDlg::OnBnClickedAc)
	ON_BN_CLICKED(IDC_TYPE, &CTrigonometriccalculatorDlg::OnBnClickedType)
	ON_STN_CLICKED(IDC_SHOWTYPE, &CTrigonometriccalculatorDlg::OnStnClickedShowtype)
END_MESSAGE_MAP()


// CTrigonometriccalculatorDlg 消息处理程序

BOOL CTrigonometriccalculatorDlg::OnInitDialog()
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
	SetDlgItemText(IDC_SHOWTYPE, L"ANG");
	SetDlgItemText(IDC_SHOW, L"0");
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTrigonometriccalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTrigonometriccalculatorDlg::OnPaint()
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
HCURSOR CTrigonometriccalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTrigonometriccalculatorDlg::OnBnClickedNum1()
{
	m_showstr += L"1";
	SetDlgItemText(IDC_SHOW, m_showstr);
	SetDlgItemText(IDC_ERROR, L"");
}


void CTrigonometriccalculatorDlg::OnBnClickedNum2()
{
	m_showstr += L"2";
	SetDlgItemText(IDC_SHOW, m_showstr);
	SetDlgItemText(IDC_ERROR, L"");
}


void CTrigonometriccalculatorDlg::OnBnClickedNum3()
{
	m_showstr += L"3";
	SetDlgItemText(IDC_SHOW, m_showstr);
	SetDlgItemText(IDC_ERROR, L"");
}


void CTrigonometriccalculatorDlg::OnBnClickedNum4()
{
	m_showstr += L"4";
	SetDlgItemText(IDC_SHOW, m_showstr);
	SetDlgItemText(IDC_ERROR, L"");
}


void CTrigonometriccalculatorDlg::OnBnClickedNum5()
{
	m_showstr += L"5";
	SetDlgItemText(IDC_SHOW, m_showstr);
	SetDlgItemText(IDC_ERROR, L"");
}


void CTrigonometriccalculatorDlg::OnBnClickedNum6()
{
	m_showstr += L"6";
	SetDlgItemText(IDC_SHOW, m_showstr);
	SetDlgItemText(IDC_ERROR, L"");
}


void CTrigonometriccalculatorDlg::OnBnClickedNum7()
{
	m_showstr += L"7";
	SetDlgItemText(IDC_SHOW, m_showstr);
	SetDlgItemText(IDC_ERROR, L"");
}


void CTrigonometriccalculatorDlg::OnBnClickedNum8()
{
	m_showstr += L"8";
	SetDlgItemText(IDC_SHOW, m_showstr);
	SetDlgItemText(IDC_ERROR, L"");
}


void CTrigonometriccalculatorDlg::OnBnClickedNum9()
{
	m_showstr += L"9";
	SetDlgItemText(IDC_SHOW, m_showstr);
	SetDlgItemText(IDC_ERROR, L"");
}


void CTrigonometriccalculatorDlg::OnBnClickedNum0()
{
	m_showstr += L"0";
	SetDlgItemText(IDC_SHOW, m_showstr);
	SetDlgItemText(IDC_ERROR, L"");
}


void CTrigonometriccalculatorDlg::OnBnClickedSign()
{
	if (m_showstr.Find(L"-") != -1) {
		m_showstr = m_showstr.Right(m_showstr.GetLength() - 1);
	}	
	else {
		m_showstr = L"-" + m_showstr;
	}
	SetDlgItemText(IDC_SHOW, m_showstr);
	SetDlgItemText(IDC_ERROR, L"");
}


void CTrigonometriccalculatorDlg::OnBnClickedDot()
{
	SetDlgItemText(IDC_ERROR, L"");
	if (m_showstr.Find(L".") != -1)
		return;
	
	m_showstr += L".";
	SetDlgItemText(IDC_SHOW, m_showstr);
}


void CTrigonometriccalculatorDlg::OnBnClickedSin()
{
	SetDlgItemText(IDC_ERROR, L"");
	m_shownum = _wtof(m_showstr);
	if (m_datatype == FALSE) {
		m_shownum = (m_shownum / 180) * PI;
	}//角度转弧度

	m_shownum = mysin(m_shownum);

	m_showstr.Format(L"%lf", m_shownum);
	SetDlgItemText(IDC_SHOW, m_showstr);
}


void CTrigonometriccalculatorDlg::OnBnClickedCos()
{
	SetDlgItemText(IDC_ERROR, L"");
	m_shownum = _wtof(m_showstr);
	if (m_datatype == FALSE) {
		m_shownum = (m_shownum / 180) * PI;
	}//角度转弧度

	m_shownum = mycos(m_shownum);

	m_showstr.Format(L"%lf", m_shownum);
	SetDlgItemText(IDC_SHOW, m_showstr);
}


void CTrigonometriccalculatorDlg::OnBnClickedArcsin()
{
	m_shownum = _wtof(m_showstr);
	if (m_shownum < -1 || m_shownum > 1) {
		SetDlgItemText(IDC_SHOW, m_showstr);
		SetDlgItemText(IDC_ERROR, L"ERROR");
	}
	else {

		m_shownum = myasin(m_shownum);

		if (m_datatype == FALSE) {
			m_shownum = (m_shownum / PI) * 180;
		}//弧度转角度

		m_showstr.Format(L"%lf", m_shownum);
		SetDlgItemText(IDC_SHOW, m_showstr);
		SetDlgItemText(IDC_ERROR, L"");
	}
}


void CTrigonometriccalculatorDlg::OnBnClickedArctan()
{
	SetDlgItemText(IDC_ERROR, L"");
	m_shownum = _wtof(m_showstr);

	m_shownum = myatan(m_shownum);

	if (m_datatype == FALSE) {
		m_shownum = (m_shownum / PI) * 180;
	}//弧度转角度

	m_showstr.Format(L"%lf", m_shownum);
	SetDlgItemText(IDC_SHOW, m_showstr);
}


void CTrigonometriccalculatorDlg::OnBnClickedDel()
{
	if (m_showstr.IsEmpty()) {
		SetDlgItemText(IDC_SHOW, L"0");
	}
	else if (m_showstr.GetLength() == 1) {
		m_showstr = m_showstr.Left(m_showstr.GetLength() - 1);
		SetDlgItemText(IDC_SHOW, L"0");
	}
	else {
		m_showstr = m_showstr.Left(m_showstr.GetLength() - 1);
		SetDlgItemText(IDC_SHOW, m_showstr);
	}
}


void CTrigonometriccalculatorDlg::OnBnClickedAc()
{
	m_showstr.Empty();
	m_shownum = 0;
	SetDlgItemText(IDC_SHOW, L"0");
}


void CTrigonometriccalculatorDlg::OnBnClickedType()
{
	m_shownum = _wtof(m_showstr);
	if (m_datatype == FALSE) {
		m_datatype = TRUE;
		m_shownum = (m_shownum / 180) * 3.1415926;
		SetDlgItemText(IDC_SHOWTYPE, L"RAD");
	}
	else{
		m_datatype = FALSE;
		m_shownum = (m_shownum / 3.1415926) * 180;
		SetDlgItemText(IDC_SHOWTYPE, L"ANG");
	}
	m_showstr.Format(L"%lf", m_shownum);
	SetDlgItemText(IDC_SHOW, m_showstr);
}


void CTrigonometriccalculatorDlg::OnStnClickedShowtype()
{
	// TODO: 在此添加控件通知处理程序代码
}
