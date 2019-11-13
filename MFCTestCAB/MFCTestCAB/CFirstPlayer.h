#pragma once


// CFirstPlayer dialog

class CFirstPlayer : public CDialogEx
{
	DECLARE_DYNAMIC(CFirstPlayer)

public:

	CFirstPlayer(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFirstPlayer();
	
	CString num_player1;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_P1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	afx_msg void OnBnClickedOk();
};
