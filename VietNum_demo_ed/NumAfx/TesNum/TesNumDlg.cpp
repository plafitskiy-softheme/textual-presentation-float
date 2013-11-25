// TesNumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TesNum.h"
#include "TesNumDlg.h"
#include "..\resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTesNumDlg dialog

CTesNumDlg::CTesNumDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTesNumDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTesNumDlg)
	m_sSS = _T("");
	m_sRR = _T("");
	m_iLgn = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTesNumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTesNumDlg)
	DDX_Text(pDX, IDC_EDIT1, m_sSS);
	DDX_Text(pDX, IDC_EDIT2, m_sRR);
	DDX_Radio(pDX, IDC_RADIO1, m_iLgn);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTesNumDlg, CDialog)
	//{{AFX_MSG_MAP(CTesNumDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTesNumDlg message handlers

BOOL CTesNumDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

void CTesNumDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTesNumDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTesNumDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTesNumDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	char s[255];
	char *ss;
	UpdateData(TRUE);
	strcpy(s,m_sSS);
	if (m_iLgn==0)
		ss = VS_MainNum(s);
	else 
		ss = VS_CardinalE(s);
	
	m_sRR.Format("%s",ss);
	UpdateData(FALSE);
}

void CTesNumDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	char s[255];
	char *ss;
	UpdateData(TRUE);
	strcpy(s,m_sSS);
	if (m_iLgn == 0)
		ss = VS_NonCount(s);
	else 
		ss = VS_OrdinalE(s);
	
	m_sRR.Format("%s",ss);
	UpdateData(FALSE);
}

void CTesNumDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	char s[255];
	char *ss;
	UpdateData(TRUE);
	strcpy(s,m_sSS);
	if (m_iLgn == 0)
		ss = VS_DateTimeV(s);
	else 
		ss = VS_DateTimeE(s);
	m_sRR.Format("%s",ss);
	UpdateData(FALSE);
}
