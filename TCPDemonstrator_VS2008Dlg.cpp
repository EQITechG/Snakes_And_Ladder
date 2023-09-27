

#include "stdafx.h"
#include "TCPDemonstrator_VS2008.h"
#include "TCPDemonstrator_VS2008Dlg.h"
#include "ClientDialog.h"
#include "ServerDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTCPDemonstrator_VS2008Dlg dialog




CTCPDemonstrator_VS2008Dlg::CTCPDemonstrator_VS2008Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTCPDemonstrator_VS2008Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTCPDemonstrator_VS2008Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTCPDemonstrator_VS2008Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_SERVER, &CTCPDemonstrator_VS2008Dlg::OnBnClickedButtonServer)
	ON_BN_CLICKED(IDC_BUTTON_CLIENT, &CTCPDemonstrator_VS2008Dlg::OnBnClickedButtonClient)
END_MESSAGE_MAP()


// CTCPDemonstrator_VS2008Dlg message handlers

BOOL CTCPDemonstrator_VS2008Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTCPDemonstrator_VS2008Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTCPDemonstrator_VS2008Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTCPDemonstrator_VS2008Dlg::OnBnClickedButtonServer()
{
	// Create an object (serverDialog) of the class CServerDialog
	CServerDialog* serverDialog = new CServerDialog;
	
	// Display the resource related to the new object
	serverDialog->DoModal();
}

void CTCPDemonstrator_VS2008Dlg::OnBnClickedButtonClient()
{
	// Create an object (clientDialog) of the class CClientDialog
	CClientDialog* clientDialog = new CClientDialog;

	
	// Display the resource related to the new object

	clientDialog->DoModal();
	
}
