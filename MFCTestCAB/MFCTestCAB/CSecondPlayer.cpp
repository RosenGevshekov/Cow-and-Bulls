// CSecondPlayer.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTestCAB.h"
#include "CSecondPlayer.h"
#include "afxdialogex.h"


// CSecondPlayer dialog

IMPLEMENT_DYNAMIC(CSecondPlayer, CDialogEx)

CSecondPlayer::CSecondPlayer(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_P2, pParent)
	, num_player2(_T(""))
{

}

CSecondPlayer::~CSecondPlayer()
{
}

void CSecondPlayer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PLAYER2_NUM, num_player2);
	DDV_MaxChars(pDX, num_player2, 4);
}


BEGIN_MESSAGE_MAP(CSecondPlayer, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSecondPlayer::OnBnClickedOk)
END_MESSAGE_MAP()


// CSecondPlayer message handlers


void CSecondPlayer::OnBnClickedOk()
{	
	UpdateData(TRUE);
	CDialogEx::OnOK();
	
}
