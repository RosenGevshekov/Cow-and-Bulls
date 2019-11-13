#pragma once


// SecondPlayerTryDlg dialog

class SecondPlayerTryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SecondPlayerTryDlg)

public:
	SecondPlayerTryDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SecondPlayerTryDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_P2TRY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeP2tryNum();
	CString player2try_num;
};
