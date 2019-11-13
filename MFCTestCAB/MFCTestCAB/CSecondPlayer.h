#pragma once


// CSecondPlayer dialog

class CSecondPlayer : public CDialogEx
{
	DECLARE_DYNAMIC(CSecondPlayer)

public:
	CString num_player2;

	CSecondPlayer(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSecondPlayer();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_P2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	afx_msg void OnBnClickedOk();
};
