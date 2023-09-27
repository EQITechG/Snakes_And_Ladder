
#pragma once
#include "afxwin.h"
#include "resource.h"
#include "TCP_Demonstator_General.h"

#define MAX_CONNECTIONS 3

struct Connection {
	SOCKET iConnectSocket;
	SOCKADDR_IN ConnectSockAddr;
	bool bInUse;
};

class CServerDialog : public CDialog
{
	DECLARE_DYNAMIC(CServerDialog)

public:
	CServerDialog(CWnd* pParent = NULL);   // constructor
	virtual ~CServerDialog();
	void InitialiseControls();
	int GetPort();
	void SetUpLocalAddressStruct();
	IN_ADDR GetLocalHostAddressDetails();
	void InitiateTimer();					// REPEAT for non-blocking recv's
	void StopTimer();
	void OnTimer(UINT nIDEvent); 
	int CountActiveConnections();
	int GetUnusedConnection();
	void CloseAll();
	void CloseConnection(int iConnection);
	void Accept();
	void SendMessage();
	void DoSend(Message_PDU Message);
	void DoSplit(Message_PDU Message);
	void DoReceive();
	void DosendOne(Message_PDU Message, int ClientID);
	//void DosendTwo(Message_PDU Message);


	enum { IDD = IDD_TCP_SERVER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	// Controls
	CEdit m_LocalAddress;
	CEdit m_ConnectedCount;
	CButton m_EnableServerButton;
	CButton m_ShutdownServerButton;
	CButton m_CancelButton;
	
	// Communications
	int m_iMessageNumber;
	SOCKET m_iSocket;
	SOCKADDR_IN m_LocalSockAddr;
	Connection m_ConnectionArray[MAX_CONNECTIONS];

	// Flags
	bool m_bTimerSet;

	// Timer
	UINT_PTR m_nTimer;

public:
	// Event handlers
	afx_msg void OnBnClickedEnableServer();
	afx_msg void OnBnClickedClose();
	afx_msg void OnBnClickedCancel();
	CEdit m_Port;
	CEdit m_ReceivedMessage;
};



