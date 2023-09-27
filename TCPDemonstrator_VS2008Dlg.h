/*	
	Outline operation:
	The top-level dialog allows the user to 
	select either Client operation or server operation
	This is skeletal code with no frills.
	It is intended to provide a minimalistic TCP demonstration
	(and thus hopefully is quite easy to follow).

*/

#pragma once


// CTCPDemonstrator_VS2008Dlg dialog
class CTCPDemonstrator_VS2008Dlg : public CDialog
{
// Construction
public:
	CTCPDemonstrator_VS2008Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TCPDEMONSTRATOR_VS2008_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonServer();
	afx_msg void OnBnClickedButtonClient();
};
