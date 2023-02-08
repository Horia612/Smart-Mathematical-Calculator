
// ProiectMPPDlg.h : header file
//

#pragma once


// CProiectMPPDlg dialog
class CProiectMPPDlg : public CDialogEx
{
// Construction
public:
	CProiectMPPDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROIECTMPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	int Nr;
	int Nr2;
	int cmMdc;
	int cmmmc;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton10();
	CString Text;
	int Operatie;
	double Rezultat;
};
