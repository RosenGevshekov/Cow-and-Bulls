// SecondPlayerTryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTestCAB.h"
#include "SecondPlayerTryDlg.h"
#include "afxdialogex.h"


// SecondPlayerTryDlg dialog

IMPLEMENT_DYNAMIC(SecondPlayerTryDlg, CDialogEx)

SecondPlayerTryDlg::SecondPlayerTryDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_P2TRY, pParent)
	, player2try_num(_T(""))
{

}

SecondPlayerTryDlg::~SecondPlayerTryDlg()
{
}

void SecondPlayerTryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_P2TRY_NUM, player2try_num);
	DDV_MaxChars(pDX, player2try_num, 4);
}


BEGIN_MESSAGE_MAP(SecondPlayerTryDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SecondPlayerTryDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SecondPlayerTryDlg message handlers


void SecondPlayerTryDlg::OnBnClickedOk()
{
	
	CDialogEx::OnOK();
}
