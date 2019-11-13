#pragma once


// FirstPlayerTryDlg dialog

class FirstPlayerTryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FirstPlayerTryDlg)

public:
	FirstPlayerTryDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~FirstPlayerTryDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_P1TRY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString player1try_num;
	afx_msg void OnEnChangeP1tryNum();
	afx_msg void OnBnClickedOk();
};
