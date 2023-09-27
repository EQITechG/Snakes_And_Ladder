
#pragma once
#include "TCP_Demonstator_General.h"
#include "afxwin.h"
#include "resource.h"

class CClientDialog : public CDialog
{
	DECLARE_DYNAMIC(CClientDialog)

public:
	CClientDialog(CWnd* pParent = NULL);   // constructor
	virtual ~CClientDialog();
	IN_ADDR GetConnectAddress();
	int GetPort();
	void InitiateTimer();
	void StopTimer();
	void OnTimer(UINT nIDEvent); 
	void DoReceive();
	void Close();
	void CloseAndQuit();
	IN_ADDR GetAddress();
	void SendMessage();
	void DoSend(Message_PDU Message);
	int totalScore;
	int diceRandom;
	void SetToken(int totalScore);
	void AddScore(int diceRandom);
	void ReloadBoard();
	#define MAX_PLAYERS_LEN 5
	enum { IDD = IDD_TCP_CLIENT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	// Communications
	SOCKET m_iSocket;
	SOCKADDR_IN m_ConnectSockAddr;

	// Flags
	bool m_bTimerSet;

	// Timer
	UINT_PTR m_nTimer;

	// Controls
	CEdit m_ConnectAddress_1;
	CEdit m_ConnectAddress_2;
	CEdit m_ConnectAddress_3;
	CEdit m_ConnectAddress_4;
	CEdit m_SocketNumber;
	CEdit m_MessageText;
	CEdit m_MessageNumber;
	CButton m_ConnectButton;
	CButton m_DisconnectButton;
	CButton m_CancelButton;
	CBitmap Bmp1, Bmp2, Bmp3,  Bmp4,  Bmp5, Bmp6, Bmp7, Bmp8;
	
	

public:
	int number;
	// Event handlers
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedDisconnect();
	CEdit m_Port;
	CEdit m_Send;
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonDice();
	CStatic p1;
	CStatic p2;
	CStatic p3;
	CStatic p4;
	CStatic p5;
	CStatic p6;
	CStatic p7;
	CStatic p8;
	CStatic p9;
	CStatic p10;
	CStatic p11;
	CStatic p12;
	CStatic p13;
	CStatic p14;
	CStatic p15;
	CStatic p16;
	CStatic p17;
	CStatic p18;
	CStatic p19;
	CStatic p20;
	CStatic p21;
	CStatic p22;
	CStatic p23;
	CStatic p24;
	CStatic p25;
	CStatic p26;
	CStatic p27;
	CStatic p28;
	CStatic p29;
	CStatic p30;
	CStatic p31;
	CStatic p32;
	CStatic p33;
	CStatic p34;
	CStatic p35;
	CStatic p36;
	CStatic p37;
	CStatic p38;
	CStatic p39;
	CStatic p40;
	CStatic p41;
	CStatic p42;
	CStatic p43;
	CStatic p44;
	CStatic p46;
	CStatic p45;
	CStatic p47;
	CStatic p48;
	CStatic p49;
	CStatic p50;
	CStatic p51;
	CStatic p52;
	CStatic p53;
	CStatic p54;
	CStatic p55;
	CStatic p56;
	CStatic p57;
	CStatic p58;
	CStatic p59;
	CStatic p60;
	CStatic p61;
	CStatic p62;
	CStatic p63;
	CStatic p64;
	CStatic dice;
	
	CEdit m_Result;

	CStatic board;
	CEdit t_Address;
	CEdit m_Play_Turn;
	CEdit m_Text_Message;
	CButton m_Dice;
	CEdit m_Player;
	afx_msg void OnBnClickedButtonReg();
	CButton reg;
	CListBox m_PlayerListBox;
	CEdit clientTurn;
	afx_msg void OnBnClickedButtonSelect();
	CButton select;
	CEdit m_Opponent;
};

