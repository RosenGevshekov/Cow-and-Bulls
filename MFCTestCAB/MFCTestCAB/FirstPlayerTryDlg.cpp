// FirstPlayerTryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTestCAB.h"
#include "FirstPlayerTryDlg.h"
#include "afxdialogex.h"


// FirstPlayerTryDlg dialog

IMPLEMENT_DYNAMIC(FirstPlayerTryDlg, CDialogEx)

FirstPlayerTryDlg::FirstPlayerTryDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_P1TRY, pParent)
	, player1try_num(_T(""))
{

}

FirstPlayerTryDlg::~FirstPlayerTryDlg()
{
}

void FirstPlayerTryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_P1TRY_NUM, player1try_num);
	DDV_MaxChars(pDX, player1try_num, 4);
}


BEGIN_MESSAGE_MAP(FirstPlayerTryDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &FirstPlayerTryDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// FirstPlayerTryDlg message handlers




void FirstPlayerTryDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
