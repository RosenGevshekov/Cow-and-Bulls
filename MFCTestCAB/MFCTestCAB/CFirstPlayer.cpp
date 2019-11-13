// CFirstPlayer.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTestCAB.h"
#include "CFirstPlayer.h"
#include "afxdialogex.h"
#include <stdlib.h>


// CFirstPlayer dialog

IMPLEMENT_DYNAMIC(CFirstPlayer, CDialogEx)

CFirstPlayer::CFirstPlayer(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_P1, pParent)
	, num_player1(_T(""))
{

}

CFirstPlayer::~CFirstPlayer()
{
}

void CFirstPlayer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PLAYER1_NUM, num_player1);
	DDV_MaxChars(pDX, num_player1, 4);
}


BEGIN_MESSAGE_MAP(CFirstPlayer, CDialogEx)
	ON_BN_CLICKED(IDOK, &CFirstPlayer::OnBnClickedOk)
END_MESSAGE_MAP()


// CFirstPlayer message handlers


void CFirstPlayer::OnBnClickedOk()
{
	CDialogEx::OnOK();
}
