
// MFCTestCABDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTestCAB.h"
#include "MFCTestCABDlg.h"
#include "afxdialogex.h"
#include "CFirstPlayer.h"
#include "CSecondPlayer.h"
#include "GameDlg.h"
#include <cstring>
#include "Player.h"

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


// CMFCTestCABDlg dialog



CMFCTestCABDlg::CMFCTestCABDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCTESTCAB_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTestCABDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}



BEGIN_MESSAGE_MAP(CMFCTestCABDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_BUTTON, &CMFCTestCABDlg::OnBnClickedStartButton)
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CMFCTestCABDlg::OnBnClickedExitButton)
	ON_BN_CLICKED(IDC_CONTINUE_BUTTON2, &CMFCTestCABDlg::OnBnClickedContinueButton2)
END_MESSAGE_MAP()


// CMFCTestCABDlg message handlers

BOOL CMFCTestCABDlg::OnInitDialog()
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

void CMFCTestCABDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCTestCABDlg::OnPaint()
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
HCURSOR CMFCTestCABDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CMFCTestCABDlg::OnBnClickedStartButton()
{
	CFirstPlayer firstPlayer;
	CSecondPlayer secondPlayer;
	INT_PTR result;
	check:

	 result = firstPlayer.DoModal();

	if (result == IDOK) {	//if first player's registration is OK
		UpdateData(TRUE);
		firstPlayer.num_player1.ReleaseBuffer();
		int length = firstPlayer.num_player1.GetLength();
		if (length == 4 && firstPlayer.num_player1.SpanIncluding(L"0123456789") == firstPlayer.num_player1) {  //check if a number of player 1 is of 4 digits 
			result = secondPlayer.DoModal();
		}
		else {
			AfxMessageBox(_T("Enter a four digit number!"));
			goto check;
		}
		
	}
	
	if (result == IDOK) {	//if second player's registration is OK
		UpdateData(TRUE);
		secondPlayer.num_player2.ReleaseBuffer();
		int length = secondPlayer.num_player2.GetLength();
	
		if (length == 4 && secondPlayer.num_player2.SpanIncluding(L"0123456789") == secondPlayer.num_player2) { //check if a number of player 2 is of 4 digits 
			CT2CA str1(firstPlayer.num_player1);
			std::string s1(str1);
			Player p1(s1);

			CT2CA str2 = secondPlayer.num_player2;
			std::string s2(str2);
			Player p2(s2);

			GameDlg game;
			game.set_number(p1, p2);
			game.DoModal();
		}
		else {
			AfxMessageBox(_T("Enter a four digit number!"));
			goto check;
		}
		
		
	}

	
}

void CMFCTestCABDlg::OnBnClickedContinueButton2()
{
	GameDlg game;
	try
	{
		game.loadGame();
	}
	catch (const std::invalid_argument& e)
	{
		AfxMessageBox(_T("There is NO GAME to load!"));
		return;

	} 
	
	game.DoModal();
}



void CMFCTestCABDlg::OnBnClickedExitButton()
{
	EndDialog(0);
}


