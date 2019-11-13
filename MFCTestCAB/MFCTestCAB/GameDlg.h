#include "Player.h"
#include "Database.h"

#pragma once


// GameDlg dialog

class GameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(GameDlg)

public:
	GameDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~GameDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedGuessP1();
	afx_msg void OnBnClickedGuessP2();

	void set_number(Player player1, Player player2);
	bool add_round(CString, int);
	void set_DataBase();
	void loadGame();

private:
	Player firstPlayer;
	Player secondPlayer;

	Database db;

	CString history_p1;
	CString history_p2;
};
