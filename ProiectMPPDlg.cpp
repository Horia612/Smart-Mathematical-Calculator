
// ProiectMPPDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ProiectMPP.h"
#include "ProiectMPPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CProiectMPPDlg dialog



CProiectMPPDlg::CProiectMPPDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROIECTMPP_DIALOG, pParent)
	, Nr(0)
	, Nr2(0)
	, cmMdc(0)
	, cmmmc(0)
	, Text(_T(""))
	, Operatie(0)
	, Rezultat(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProiectMPPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Nr);
	DDX_Text(pDX, IDC_EDIT2, Nr2);
	DDX_Text(pDX, IDC_EDIT3, cmMdc);
	DDX_Text(pDX, IDC_EDIT4, cmmmc);
	DDX_Text(pDX, IDC_STATIC2, Text);
	DDX_Radio(pDX, IDC_OPERATIE1, Operatie);
	DDX_Text(pDX, IDC_EDIT5, Rezultat);
}

BEGIN_MESSAGE_MAP(CProiectMPPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CProiectMPPDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CProiectMPPDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON10, &CProiectMPPDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CProiectMPPDlg message handlers

BOOL CProiectMPPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProiectMPPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProiectMPPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProiectMPPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProiectMPPDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString text;
	int n;
	n = Nr;
	if (n == 0 || n == 1)
	{
		MessageBox((LPCWSTR)L"Numerele 0 si 1 nu sunt prime!");
		return;
	}
	if (n == 2)
	{
		MessageBox((LPCWSTR)L"Numarul 2 este singurul numar prim care este par!");
		return;
	}
	for (int i = 2; i <= sqrt((float)n); i++)
		if (n % i == 0)
		{
			text.Format((LPCWSTR)L"Numarul %d nu este prim (se divide prin %d)", n, i);
			AfxMessageBox(text);
			return;
		}
	text.Format((LPCWSTR)L"Numarul %d este prim", n);
	AfxMessageBox(text);
	UpdateData(FALSE);
}


void CProiectMPPDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int x, y, r;
	x = Nr;
	y = Nr2;
	if (x == y && y == 0)
	{

		AfxMessageBox((LPCWSTR)L"A și B nu pot fi simultan nule!");
		return;

	}

	if (y != 0)
		do
		{
			r = x % y;
			x = y;
			y = r;
		} while (r != 0);
		cmMdc = x;
		cmmmc = Nr * Nr2 / cmMdc;
		UpdateData(FALSE);
}


void CProiectMPPDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	switch (Operatie) {
	case 0:

		Rezultat = Nr + Nr2;
		Text = "A+B=";
		break;

	case 1:
		Rezultat = Nr - Nr2;
		Text = "A-B=";
		break;
	case 2:
		Rezultat = Nr * Nr2;
		Text = "A*B=";
		break;
	case 3:
		if (!Nr2)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = (double)Nr / Nr2;
		Text = "A/B=";
		break;

	case 4:
		if (!Nr2)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = Nr / Nr2;
		Text = "[A/B]=";
		break;
	case 5:
		if (!Nr2)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = (double)Nr / Nr2 - Nr / Nr2;
		Text = "{A/B}=";
		break;

	case 6:
		if (!Nr2)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = Nr % Nr2;
		Text = "A%B=";
		break;
	default: AfxMessageBox((LPCWSTR)L"Nu s-a optat pentru o operatie");
	}
	UpdateData(FALSE);
}
