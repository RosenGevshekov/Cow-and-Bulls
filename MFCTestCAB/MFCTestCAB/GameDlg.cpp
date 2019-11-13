// GameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTestCAB.h"
#include "GameDlg.h"
#include "afxdialogex.h"
#include "FirstPlayerTryDlg.h"
#include "SecondPlayerTryDlg.h"

// GameDlg dialog

IMPLEMENT_DYNAMIC(GameDlg, CDialogEx)

GameDlg::GameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GAME, pParent)
	, history_p1(_T(""))
	, history_p2(_T(""))
	, db()
{
}

GameDlg::~GameDlg()
{
}

void GameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PLAYER1_HISTORYBOX, history_p1);
	DDX_Text(pDX, IDC_PLAYER2_HISTORYBOX, history_p2);
}


BEGIN_MESSAGE_MAP(GameDlg, CDialogEx)
	ON_BN_CLICKED(IDC_GUESS_P1, &GameDlg::OnBnClickedGuessP1)
	ON_BN_CLICKED(IDC_GUESS_P2, &GameDlg::OnBnClickedGuessP2)
END_MESSAGE_MAP()

void GameDlg::set_number(Player player1, Player player2) {
	
	firstPlayer = player1;
	secondPlayer = player2;
	db.Clean();
	set_DataBase();
}

void GameDlg::set_DataBase() {
	CT2CA pszConvertedAnsiString_p1(history_p1);
	std::string history1(pszConvertedAnsiString_p1);
	
	CT2CA pszConvertedAnsiString_p2(history_p2);
	std::string history2(pszConvertedAnsiString_p2);

	CString SqlString = _T("CREATE TABLE Players (PlayerID int NOT NULL PRIMARY KEY, PlayerNumber VARCHAR(4), History NVARCHAR(max));");
	db.Execute(SqlString);

	std::string string = "INSERT INTO Players (PlayerID, PlayerNumber, History) VALUES ('1', '" + firstPlayer.checkNumber() + "', '"+ history1+"')";
	SqlString = string.c_str();
	db.Execute(SqlString);

	string = "INSERT INTO Players (PlayerID, PlayerNumber, History) VALUES ('2', '" + secondPlayer.checkNumber() + "', '"+history2+"')";
	SqlString = string.c_str();
	db.Execute(SqlString);
}

void GameDlg::loadGame() {
	CString num1, history1, num2, history2;
	CString details = db.load();

	if (details == L"No Data") {		//check if there is available game
		throw std::invalid_argument("");
		return;
	}

	int nTokenPos = 0;
	int pos = 0;
	CString detailsToken = details.Tokenize(_T("+"), nTokenPos);
	while (!detailsToken.IsEmpty())
	{
		switch (pos) {
		case 0:
			num1 = detailsToken;
			break;

		case 1:
			history1 = detailsToken;
			break;
		
		case 2:
			num2 = detailsToken;
			break;

		case 3:
			history2 = detailsToken;
			break;

		}
		detailsToken = details.Tokenize(_T("+"), nTokenPos);
		pos++;
	}
	history_p1 += history1;
	history_p2 += history2;
	
	//AfxMessageBox(num2);
	CT2CA str1 = num1;
	std::string s1(str1);
	Player p1(s1);

	CT2CA str2 = num2;
	std::string s2(str2);
	Player p2(s2);

	set_number(p1, p2);

}


bool GameDlg::add_round(CString num,int n) {
	bool win = false;
	CT2CA pszConvertedAnsiString(num);
	std::string number(pszConvertedAnsiString);
	std::string result;
	CString SqlString;
	if (n == 0) {
		result = secondPlayer.addGuess(number);
		if (result == "		WIN!") {
			win = true;
		}

		history_p1 += result.c_str();
		UpdateData(FALSE);
		// Scroll to bottom.
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_PLAYER1_HISTORYBOX);
		pEdit->LineScroll(pEdit->GetLineCount());


		CT2CA pszConvertedAnCString(history_p1);
		std::string converted_history(pszConvertedAnCString);
		std::string string = "UPDATE Players SET history = '"+converted_history+"' WHERE PlayerID = 1";
		SqlString = string.c_str();
		db.Execute(SqlString);
	}
	else {
		result = firstPlayer.addGuess(number);
		if (result == "		WIN!") {
			win = true;
		}
		history_p2 += result.c_str();
		UpdateData(FALSE);

		// Scroll to bottom.
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_PLAYER2_HISTORYBOX);
		pEdit->LineScroll(pEdit->GetLineCount());

		CT2CA pszConvertedAnCString(history_p2);
		std::string converted_history(pszConvertedAnCString);
		std::string string = "UPDATE Players SET history = '" + converted_history + "' WHERE PlayerID = 2";
		SqlString = string.c_str();
		db.Execute(SqlString);
	}
	return win;
}

// GameDlg message handlers


void GameDlg::OnBnClickedGuessP1()
{
	bool win = false;
	FirstPlayerTryDlg ftry;
	INT_PTR result = ftry.DoModal();

	UpdateData(TRUE);
	ftry.player1try_num.ReleaseBuffer();
	int length = ftry.player1try_num.GetLength();

	if (result == IDOK && length == 4 && ftry.player1try_num.SpanIncluding(L"0123456789") == ftry.player1try_num) { //check if a guess number of player 1 is of 4 digits and OK Button is pressed
		CString number = ftry.player1try_num;
		win = add_round(number,0);	

		GetDlgItem(IDC_GUESS_P1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_GUESS_P2)->ShowWindow(SW_SHOW);

		if (win) {
			AfxMessageBox(_T("Player 1 WIN!"));
			db.Clean();
			EndDialog(0);
		}
	}
	else {
		AfxMessageBox(_T("Enter a four digit number!"));
	}
}


void GameDlg::OnBnClickedGuessP2()
{
	bool win = false;

	SecondPlayerTryDlg ftry;
	INT_PTR result = ftry.DoModal();
	
	UpdateData(TRUE);
	ftry.player2try_num.ReleaseBuffer();
	int length = ftry.player2try_num.GetLength();

	if (result == IDOK && length == 4 && ftry.player2try_num.SpanIncluding(L"0123456789") == ftry.player2try_num) { //check if a guess number of player 1 is of 4 digits and OK Button is pressed
		CString number = ftry.player2try_num;																																								//Test
		win = add_round(number, 1);
		
		GetDlgItem(IDC_GUESS_P2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_GUESS_P1)->ShowWindow(SW_SHOW);

		if (win) {
			AfxMessageBox(_T("Player 2 WIN!"));
			db.Clean();
			EndDialog(0);
		}
	}
	else {
		AfxMessageBox(_T("Enter a four digit number!"));
	}
}