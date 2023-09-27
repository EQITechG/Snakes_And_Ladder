
#include "stdafx.h"
#include "ClientDialog.h"
#include <sys/types.h>
#include <sys/timeb.h>


IMPLEMENT_DYNAMIC(CClientDialog, CDialog)
CClientDialog::CClientDialog(CWnd* pParent /*=NULL*/) // Class Constructor
	: CDialog(CClientDialog::IDD, pParent)
{	
	m_bTimerSet = false;
}

CClientDialog::~CClientDialog() // Class Destructor
{
	Close();
}

BEGIN_MESSAGE_MAP(CClientDialog, CDialog)
	ON_WM_TIMER()	// Needed if using a timer

	// User Interface Event handlers
	ON_BN_CLICKED(IDC_CONNECT, OnBnClickedConnect)
	ON_BN_CLICKED(IDC_Disconnect, OnBnClickedDisconnect)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CClientDialog::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_DICE, &CClientDialog::OnBnClickedButtonDice)
	ON_BN_CLICKED(IDC_BUTTON_REG, &CClientDialog::OnBnClickedButtonReg)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &CClientDialog::OnBnClickedButtonSelect)
END_MESSAGE_MAP()

void CClientDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	// Map controls onto variables in the code
	DDX_Control(pDX, IDC_MESSAGE_TEXT, m_MessageText);
	DDX_Control(pDX, IDC_MESSAGE_NUMBER, m_MessageNumber);
	DDX_Control(pDX, IDC_ADD_1, m_ConnectAddress_1);
	DDX_Control(pDX, IDC_ADD_2, m_ConnectAddress_2);
	DDX_Control(pDX, IDC_ADD_3, m_ConnectAddress_3);
	DDX_Control(pDX, IDC_ADD_4, m_ConnectAddress_4);
	DDX_Control(pDX, IDC_EDIT_PORT, m_Port);
	DDX_Control(pDX, IDC_CONNECT, m_ConnectButton);
	DDX_Control(pDX, IDC_Disconnect, m_DisconnectButton);
	DDX_Control(pDX, IDCANCEL, m_CancelButton);
	DDX_Control(pDX, IDC_EDIT_SEND, m_Send);
	DDX_Control(pDX, IDC_BUTTON_DICE, m_Dice);
	DDX_Control(pDX, IDC_BUTTON_REG, reg);
	DDX_Control(pDX, IDC_BUTTON_SELECT, select);

	// Initialisation of User Interface controls
	m_ConnectButton.EnableWindow(true);
	m_CancelButton.EnableWindow(true);
	m_DisconnectButton.EnableWindow(false);
	m_Port.SetWindowTextA("8001");
	m_Port.EnableWindow(true);
	m_Send.EnableWindow(false);
	m_Dice.EnableWindow(false);
	reg.EnableWindow(false);
	select.EnableWindow(false);
	totalScore = 0;
	number = 0;

	DDX_Control(pDX, IDC_STATIC_TOKEN_1, p1);
	DDX_Control(pDX, IDC_STATIC_TOKEN_2, p2);
	DDX_Control(pDX, IDC_STATIC_TOKEN_3, p3);
	DDX_Control(pDX, IDC_STATIC_TOKEN_4, p4);
	DDX_Control(pDX, IDC_STATIC_TOKEN_5, p5);
	DDX_Control(pDX, IDC_STATIC_TOKEN_6, p6);
	DDX_Control(pDX, IDC_STATIC_TOKEN_7, p7);
	DDX_Control(pDX, IDC_STATIC_TOKEN_8, p8);
	DDX_Control(pDX, IDC_STATIC_TOKEN_16, p9);
	DDX_Control(pDX, IDC_STATIC_TOKEN_15, p10);
	DDX_Control(pDX, IDC_STATIC_TOKEN_14, p11);
	DDX_Control(pDX, IDC_STATIC_TOKEN_13, p12);
	DDX_Control(pDX, IDC_STATIC_TOKEN_12, p13);
	DDX_Control(pDX, IDC_STATIC_TOKEN_11, p14);
	DDX_Control(pDX, IDC_STATIC_TOKEN_10, p15);
	DDX_Control(pDX, IDC_STATIC_TOKEN_9, p16);
	DDX_Control(pDX, IDC_STATIC_TOKEN_17, p17);
	DDX_Control(pDX, IDC_STATIC_TOKEN_18, p18);
	DDX_Control(pDX, IDC_STATIC_TOKEN_19, p19);
	DDX_Control(pDX, IDC_STATIC_TOKEN_20, p20);
	DDX_Control(pDX, IDC_STATIC_TOKEN_21, p21);
	DDX_Control(pDX, IDC_STATIC_TOKEN_22, p22);
	DDX_Control(pDX, IDC_STATIC_TOKEN_23, p23);
	DDX_Control(pDX, IDC_STATIC_TOKEN_24, p24);
	DDX_Control(pDX, IDC_STATIC_TOKEN_32, p25);
	DDX_Control(pDX, IDC_STATIC_TOKEN_31, p26);
	DDX_Control(pDX, IDC_STATIC_TOKEN_30, p27);
	DDX_Control(pDX, IDC_STATIC_TOKEN_29, p28);
	DDX_Control(pDX, IDC_STATIC_TOKEN_28, p29);
	DDX_Control(pDX, IDC_STATIC_TOKEN_27, p30);
	DDX_Control(pDX, IDC_STATIC_TOKEN_26, p31);
	DDX_Control(pDX, IDC_STATIC_TOKEN_25, p32);
	DDX_Control(pDX, IDC_STATIC_TOKEN_33, p33);
	DDX_Control(pDX, IDC_STATIC_TOKEN_34, p34);
	DDX_Control(pDX, IDC_STATIC_TOKEN_35, p35);
	DDX_Control(pDX, IDC_STATIC_TOKEN_36, p36);
	DDX_Control(pDX, IDC_STATIC_TOKEN_37, p37);
	DDX_Control(pDX, IDC_STATIC_TOKEN_38, p38);
	DDX_Control(pDX, IDC_STATIC_TOKEN_39, p39);
	DDX_Control(pDX, IDC_STATIC_TOKEN_40, p40);
	DDX_Control(pDX, IDC_STATIC_TOKEN_48, p41);
	DDX_Control(pDX, IDC_STATIC_TOKEN_47, p42);
	DDX_Control(pDX, IDC_STATIC_TOKEN_46, p43);
	DDX_Control(pDX, IDC_STATIC_TOKEN_45, p44);
	DDX_Control(pDX, IDC_STATIC_TOKEN_44, p46);
	DDX_Control(pDX, IDC_STATIC_TOKEN_43, p45);
	DDX_Control(pDX, IDC_STATIC_TOKEN_42, p47);
	DDX_Control(pDX, IDC_STATIC_TOKEN_41, p48);
	DDX_Control(pDX, IDC_STATIC_TOKEN_49, p49);
	DDX_Control(pDX, IDC_STATIC_TOKEN_50, p50);
	DDX_Control(pDX, IDC_STATIC_TOKEN_51, p51);
	DDX_Control(pDX, IDC_STATIC_TOKEN_52, p52);
	DDX_Control(pDX, IDC_STATIC_TOKEN_53, p53);
	DDX_Control(pDX, IDC_STATIC_TOKEN_54, p54);
	DDX_Control(pDX, IDC_STATIC_TOKEN_55, p55);
	DDX_Control(pDX, IDC_STATIC_TOKEN_56, p56);
	DDX_Control(pDX, IDC_STATIC_TOKEN_64, p57);
	DDX_Control(pDX, IDC_STATIC_TOKEN_63, p58);
	DDX_Control(pDX, IDC_STATIC_TOKEN_62, p59);
	DDX_Control(pDX, IDC_STATIC_TOKEN_61, p60);
	DDX_Control(pDX, IDC_STATIC_TOKEN_60, p61);
	DDX_Control(pDX, IDC_STATIC_TOKEN_59, p62);
	DDX_Control(pDX, IDC_STATIC_TOKEN_58, p63);
	DDX_Control(pDX, IDC_STATIC_TOKEN_57, p64);
	DDX_Control(pDX, IDC_STATIC_DICE, dice);
	DDX_Control(pDX, IDC_EDIT1, m_Result);
	DDX_Control(pDX, IDC_STATIC_BOARD, board);
	DDX_Control(pDX, IDC_EDIT5, t_Address);
	DDX_Control(pDX, IDC_EDIT4, m_Play_Turn);
	DDX_Control(pDX, IDC_EDIT6, m_Text_Message);
	DDX_Control(pDX, IDC_BUTTON_DICE, m_Dice);
	DDX_Control(pDX, IDC_EDIT2, m_Player);
	DDX_Control(pDX, IDC_BUTTON_REG, reg);
	DDX_Control(pDX, IDC_LIST1, m_PlayerListBox);
	DDX_Control(pDX, IDC_EDIT7, clientTurn);
	DDX_Control(pDX, IDC_BUTTON_SELECT, select);
	DDX_Control(pDX, IDC_EDIT3, m_Opponent);
}

IN_ADDR CClientDialog::GetConnectAddress()
{	
	IN_ADDR addr;
	CString csStr;
	m_ConnectAddress_1.GetWindowText(csStr);
	addr.S_un.S_un_b.s_b1 = (unsigned  char) atol(csStr.GetString());
	m_ConnectAddress_2.GetWindowText(csStr);
	addr.S_un.S_un_b.s_b2 = (unsigned  char) atol(csStr.GetString());
	m_ConnectAddress_3.GetWindowText(csStr);
	addr.S_un.S_un_b.s_b3 = (unsigned  char) atol(csStr.GetString());
	m_ConnectAddress_4.GetWindowText(csStr);
	addr.S_un.S_un_b.s_b4 = (unsigned  char) atol(csStr.GetString());
	return addr;
}

int CClientDialog::GetPort()
{	
	CString csStr;
	int iPort;
	m_Port.GetWindowText(csStr);
	iPort = (int) atol(csStr.GetString());
	return iPort;
}

void CClientDialog::OnBnClickedConnect() // Connect Button handler
{	
	m_iSocket = socket(AF_INET, SOCK_STREAM, PF_UNSPEC); // Create the (listen) socket
	if(INVALID_SOCKET == m_iSocket)
	{
		MessageBox("Socket create failed","Client");
		CloseAndQuit();
	}
	
	u_long lBlocking = 0;
	int iError = ioctlsocket(m_iSocket, FIONBIO, &lBlocking); // Set blocking socket behaviour
	if(SOCKET_ERROR == iError)
	{
		MessageBox("Could not set Blocking behaviour for socket","Client");
		CloseAndQuit();
	}

	m_ConnectSockAddr.sin_addr = GetConnectAddress();	// Setup Connect Address Structure
	m_ConnectSockAddr.sin_family = AF_INET;
	
	int iPort = GetPort();
	m_ConnectSockAddr.sin_port = htons(iPort);
	
	// Connect
	iError = connect(m_iSocket, (const SOCKADDR FAR*)&m_ConnectSockAddr, sizeof(m_ConnectSockAddr));
	if(SOCKET_ERROR == iError)
	{
		MessageBox("Connect failed !\n\nIs server address correct ?\nIs server running ?","Client");
		closesocket(m_iSocket);		// Close the socket
		return;
	}

	// Set socket non-blocking (now that connection established) for receiving
	u_long lNonBlocking = 1;
	iError = ioctlsocket(m_iSocket, FIONBIO, &lNonBlocking);
	if(SOCKET_ERROR == iError)
	{
		MessageBox("Could not set Non Blocking behaviour for socket","Client");
		closesocket(m_iSocket);		// Close the socket
		return;
	}

	
	DoReceive();	// 7. Enable receiving 
	m_ConnectButton.EnableWindow(false); // Update controls
	m_CancelButton.EnableWindow(false);
	m_Port.EnableWindow(false);
	m_DisconnectButton.EnableWindow(true);
	m_Send.EnableWindow(true);
	reg.EnableWindow(true);
}

void CClientDialog::InitiateTimer()
{	
	m_nTimer = SetTimer(1, 100, 0);
	m_bTimerSet = true;
}

void CClientDialog::StopTimer()
{
	if(true == m_bTimerSet)
	{
		KillTimer(m_nTimer);
		m_bTimerSet = false;
	}
}

void CClientDialog::OnTimer(UINT nIDEvent) 
{	
        DoReceive();
}

void CClientDialog::DoReceive()
{		
	StopTimer();
	int iBytesRecd;
	Message_PDU Message;

	iBytesRecd = recv(m_iSocket, (char *) &Message, sizeof(Message_PDU), 0);
	if(SOCKET_ERROR == iBytesRecd)
	{
		int iError = WSAGetLastError();
		// If no packet is queued for the socket the operation would block.
		if(iError != WSAEWOULDBLOCK)
		{	
			MessageBox("Receive failed","Client");
			CloseAndQuit();	// Simplistic - assumes connection has been lost
		}
	}
	else
	{	// Received a message
		if(Message.iMessageNumber < 0)
		{
			CloseAndQuit();	// Simplistic - assumes server has disconnected
		}


//Handle Message 2
else if(Message.iMessageNumber == 2)
{if(number == 0)
{number = Message.iNumber;
char szTemp[15];
 _itoa_s(number,szTemp,10);
m_Play_Turn.SetWindowTextA(szTemp);
	m_MessageText.SetWindowText(Message.szText);
		char szMessageNumber[15];
		_itoa_s(Message.iMessageNumber,szMessageNumber,10);
		m_MessageNumber.SetWindowText(szMessageNumber);

}
}


else if(Message.iMessageNumber == 3)
	{
		char iReceiver[15];
		m_Play_Turn.GetWindowText(iReceiver, 10);
		if (strcmp (iReceiver,Message.iSender) == 0)
		{}else{m_PlayerListBox.AddString(Message.player);
		select.EnableWindow(true);
		}
				
}

// Handles message 4 selecting opponent
else if(Message.iMessageNumber == 4)
	{
		char iReceiver[15];
		m_Play_Turn.GetWindowText(iReceiver, 10);
		if (strcmp (iReceiver,Message.iSender) == 0)
		{}else{
			m_PlayerListBox.SetCurSel( 0 ); 
			int iSelection = m_PlayerListBox.GetCurSel();
		char sPlayer[MAX_PLAYERS_LEN + 1];
		int iLen = m_PlayerListBox.GetText(iSelection , sPlayer);
		m_Opponent.SetWindowTextA(sPlayer);
		while( m_PlayerListBox.GetCount() > 0 )
		{m_PlayerListBox.DeleteString(0);}
	clientTurn.SetWindowTextA(Message.opponent);
			m_Dice.EnableWindow(true);
			select.EnableWindow(false);

		
		}
		
}


		//Handle Message 1 chatting message
else if(Message.iMessageNumber == 1)
	{
		char iReceiver[15];
		m_Play_Turn.GetWindowText(iReceiver, 10);
		if (strcmp (iReceiver,Message.iSender) == 0)
		{}else{m_Text_Message.SetWindowTextA(Message.chatText);}
		
}//handles message 6 for winner or loser
else if(Message.iMessageNumber == 6)
	{
		char iReceiver[15];
		m_Play_Turn.GetWindowText(iReceiver, 10);
		if (strcmp (iReceiver,Message.iSender) == 0)
		{}else{MessageBox("You have lost","Client",MB_OK);}
		
}//Handles message 5 got turns
else if(Message.iMessageNumber == 5)
	{
		char iReceiver[15];
		m_Play_Turn.GetWindowText(iReceiver, 10);
		if (strcmp (iReceiver,Message.iSender) == 0)
		{}else{
				if (Message.iTurn == 2)
				{
					clientTurn.SetWindowTextA(Message.opponent);
					m_Dice.EnableWindow(true);}
		}}
	}
	InitiateTimer();
}


void CClientDialog::OnBnClickedDisconnect() // Disconnect Button handler
{
	SendMessage();
	CloseAndQuit();
}

void CClientDialog::Close()
{
	shutdown(m_iSocket,2);	// Close the connection
	closesocket(m_iSocket);	// Close the socket
}

void CClientDialog::CloseAndQuit()
{
	Close();
	StopTimer();
	OnCancel();	// Exit the application
}

IN_ADDR CClientDialog::GetAddress()
{
	char szStr[200];
	DWORD lLen = sizeof(szStr);
    GetComputerNameA(szStr,&lLen);
	hostent * m_pHostent;
	m_pHostent = gethostbyname(szStr); 

	IN_ADDR addr;
	char **ppChar = m_pHostent->h_addr_list;
	char * pChar;
	if(ppChar != NULL && *ppChar != NULL)  
	{
		pChar = *ppChar; 
		addr.S_un.S_un_b.s_b1 = (unsigned  char) *pChar++;
		addr.S_un.S_un_b.s_b2 = (unsigned  char) *pChar++;
		addr.S_un.S_un_b.s_b3 = (unsigned  char) *pChar++;
		addr.S_un.S_un_b.s_b4 = (unsigned  char) *pChar;
	}
	else
	{
		addr.S_un.S_addr = -1;	// signal error
	}
	return addr;
}

void CClientDialog::SendMessage() // Send a simple message to all connected clients
{
	Message_PDU Message;
	strcpy_s(Message.szText,"_Disconnect");
	DoSend(Message);
}

void CClientDialog::DoSend(Message_PDU Message) // The actual send
{	
	int iBytesSent;
	iBytesSent = send(m_iSocket, (char *) &Message, sizeof(Message_PDU), 0);
	if(SOCKET_ERROR == iBytesSent)
	{
		MessageBox("Failed to send","Client");
	}
}

void CClientDialog::OnBnClickedButtonSend()
{
	Message_PDU Message;
	Message.iMessageNumber = 1;
	m_Play_Turn.GetWindowTextA(Message.iSender,MAX_MESSAGE_LENGTH);
	m_Send.GetWindowTextA(Message.chatText,MAX_MESSAGE_LENGTH);
	DoSend(Message);
	m_Send.SetWindowTextA("");
}









void CClientDialog::OnBnClickedButtonDice()
{
	// Generates random dice number
	srand(time(0));
	int diceRandom = 0;
	diceRandom = (rand() % 6 ) + 1;
	//displays required dice image
	if (diceRandom == 1){
	Bmp1.LoadBitmap(IDB_BITMAP_DICE_1);
	dice.SetBitmap(Bmp1);
	}
	else if (diceRandom == 2){
	Bmp2.LoadBitmap(IDB_BITMAP_DICE_2);
	dice.SetBitmap(Bmp2);
	}
	else if (diceRandom == 3){
	Bmp3.LoadBitmap(IDB_BITMAP_DICE_3);
	dice.SetBitmap(Bmp3);
	}
	else if  (diceRandom == 4){
	Bmp4.LoadBitmap(IDB_BITMAP_DICE_4);
	dice.SetBitmap(Bmp4);
	}
	else if  (diceRandom == 5){
	Bmp5.LoadBitmap(IDB_BITMAP_DICE_5);
	dice.SetBitmap(Bmp5);
	}
	else {
	Bmp6.LoadBitmap(IDB_BITMAP_DICE_6);
	dice.SetBitmap(Bmp6);
	}//calls add score method
	AddScore(diceRandom);
}

void CClientDialog::AddScore(int diceRandom)
{	
	totalScore = totalScore + diceRandom;
	//checks for snakes and ladders
	if (totalScore == 3)
	{totalScore = 18;
	ReloadBoard();
	SetToken(totalScore);}
	else if (totalScore == 19)
	{totalScore = 5;
	ReloadBoard();
	SetToken(totalScore);}
	else if (totalScore == 27)
	{totalScore = 8;
	ReloadBoard();
	SetToken(totalScore);}
	else if (totalScore == 24)
	{totalScore = 39;
	ReloadBoard();
	SetToken(totalScore);}
	else if (totalScore == 29)
	{totalScore = 53;
	ReloadBoard();
	SetToken(totalScore);}
	else if (totalScore == 62)
	{totalScore - 32;
	ReloadBoard();
	SetToken(totalScore);}
	else if (totalScore == 48)
	{totalScore = 63;
	ReloadBoard();
	SetToken(totalScore);}
	else if (totalScore == 58)
	{totalScore = 41;
	ReloadBoard();
	SetToken(totalScore);}
	else {
		//calls reaload and settoken methods
	ReloadBoard();
	SetToken(totalScore);}
}

void CClientDialog::ReloadBoard()
{//reloads board for new token
Bmp7.LoadBitmap(IDB_BITMAP_BOARD);
board.SetBitmap(Bmp7);

}
void CClientDialog::SetToken(int totalScore)
{//loads token at required position
	if (totalScore == 1){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p1.SetBitmap(Bmp8);
	}else if (totalScore == 2){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p2.SetBitmap(Bmp8);
	}else if (totalScore == 3){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p3.SetBitmap(Bmp8);
	}else if (totalScore == 4){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p4.SetBitmap(Bmp8);
	}else if (totalScore == 5){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p5.SetBitmap(Bmp8);
	}else if (totalScore == 6){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p6.SetBitmap(Bmp8);
	}else if (totalScore == 7){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p7.SetBitmap(Bmp8);
	}else if (totalScore == 8){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p8.SetBitmap(Bmp8);
	}else if (totalScore == 9){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p9.SetBitmap(Bmp8);
	}else if (totalScore == 10){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p10.SetBitmap(Bmp8);
	}else if (totalScore == 11){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p11.SetBitmap(Bmp8);
	}else if (totalScore == 12){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p12.SetBitmap(Bmp8);
	}else if (totalScore == 13){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p13.SetBitmap(Bmp8);
	}else if (totalScore == 14){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p14.SetBitmap(Bmp8);
	}else if (totalScore == 15){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p15.SetBitmap(Bmp8);
	}else if (totalScore == 16){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p16.SetBitmap(Bmp8);
	}else if (totalScore == 17){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p17.SetBitmap(Bmp8);
	}else if (totalScore == 18){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p18.SetBitmap(Bmp8);
	}else if (totalScore == 19){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p19.SetBitmap(Bmp8);
	}else if (totalScore == 20){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p20.SetBitmap(Bmp8);
	}else if (totalScore == 21){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p21.SetBitmap(Bmp8);
	}else if (totalScore == 22){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p22.SetBitmap(Bmp8);
	}else if (totalScore == 23){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p23.SetBitmap(Bmp8);
	}else if (totalScore == 24){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p24.SetBitmap(Bmp8);
	}else if (totalScore == 25){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p25.SetBitmap(Bmp8);
	}else if (totalScore == 26){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p26.SetBitmap(Bmp8);
	}else if (totalScore == 27){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p27.SetBitmap(Bmp8);
	}else if (totalScore == 28){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p28.SetBitmap(Bmp8);
	}else if (totalScore == 29){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p29.SetBitmap(Bmp8);
	}else if (totalScore == 30){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p30.SetBitmap(Bmp8);
	}else if (totalScore == 31){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p31.SetBitmap(Bmp8);
	}else if (totalScore == 32){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p32.SetBitmap(Bmp8);
	}else if (totalScore == 33){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p33.SetBitmap(Bmp8);
	}else if (totalScore == 34){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p34.SetBitmap(Bmp8);}
	else if (totalScore == 35){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p35.SetBitmap(Bmp8);
	}else if (totalScore == 36){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p36.SetBitmap(Bmp8);
	}else if (totalScore == 37){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p37.SetBitmap(Bmp8);
	}else if (totalScore == 38){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p38.SetBitmap(Bmp8);
	}else if (totalScore == 39){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p39.SetBitmap(Bmp8);
	}else if (totalScore == 40){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p40.SetBitmap(Bmp8);
	}else if (totalScore == 41){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p41.SetBitmap(Bmp8);
	}else if (totalScore == 42){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p42.SetBitmap(Bmp8);
	}else if (totalScore == 43){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p43.SetBitmap(Bmp8);
	}else if (totalScore == 44){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p44.SetBitmap(Bmp8);
	}else if (totalScore == 45){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p45.SetBitmap(Bmp8);
	}else if (totalScore == 46){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p46.SetBitmap(Bmp8);
	}else if (totalScore == 47){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p47.SetBitmap(Bmp8);
	}else if (totalScore == 48){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p48.SetBitmap(Bmp8);
	}else if (totalScore == 49){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p49.SetBitmap(Bmp8);
	}else if (totalScore == 50){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p50.SetBitmap(Bmp8);
	}else if (totalScore == 51){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p51.SetBitmap(Bmp8);
	}else if (totalScore == 52){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p52.SetBitmap(Bmp8);
	}else if (totalScore == 53){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p53.SetBitmap(Bmp8);
	}else if (totalScore == 54){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p54.SetBitmap(Bmp8);
	}else if (totalScore == 55){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p55.SetBitmap(Bmp8);
	}else if (totalScore == 56){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p56.SetBitmap(Bmp8);
	}else if (totalScore == 57){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p57.SetBitmap(Bmp8);
	}else if (totalScore == 58){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p58.SetBitmap(Bmp8);
	}else if (totalScore == 59){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p59.SetBitmap(Bmp8);
	}else if (totalScore == 60){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p60.SetBitmap(Bmp8);
	}else if (totalScore == 61){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p61.SetBitmap(Bmp8);
	}else if (totalScore == 62){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p62.SetBitmap(Bmp8);
	}else if (totalScore == 63){
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p63.SetBitmap(Bmp8);}
	else if (totalScore >= 63) {
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p64.SetBitmap(Bmp8);
	// Sender winner message 
	Message_PDU Message;
	Message.iMessageNumber = 6;
	m_Play_Turn.GetWindowTextA(Message.iSender,MAX_MESSAGE_LENGTH);
	Message.iScore = totalScore;
	DoSend(Message);
	MessageBox("You have Won","Client",MB_OK);
	}
	else {
	Bmp8.LoadBitmap(IDB_BITMAP_TOKEN);
	p64.SetBitmap(Bmp8);
	}
	// sets the total score on the window
	CString cstrResult;
	cstrResult.Format("%d",totalScore);
	m_Result.SetWindowText(cstrResult.GetString());	
	
	//Set Turn
	char playTurn[15];
	strcpy(playTurn,"Opponents");
	clientTurn.SetWindowTextA(playTurn);
	//Send Turn to server
	Message_PDU Message;
	Message.iMessageNumber = 5;
	m_Play_Turn.GetWindowTextA(Message.iSender,MAX_MESSAGE_LENGTH);
	Message.iTurn = 2;
	strcpy_s(Message.opponent,"Yours");
	DoSend(Message);
	//Disable Dice Button
	m_Dice.EnableWindow(false);
	}


	void CClientDialog::OnBnClickedButtonReg()
	{
		// Send Player Name
	Message_PDU Message;
	Message.iMessageNumber = 3;
	m_Play_Turn.GetWindowTextA(Message.iSender,MAX_MESSAGE_LENGTH);
	m_Player.GetWindowTextA(Message.player,MAX_MESSAGE_LENGTH);
	DoSend(Message);
	reg.EnableWindow(false);
	m_Player.SetWindowTextA("");

	}



	void CClientDialog::OnBnClickedButtonSelect()
	{
		// Selecting and setting an opponent
		int iSelection = m_PlayerListBox.GetCurSel();
		char sPlayer[MAX_PLAYERS_LEN + 1];
		int iLen = m_PlayerListBox.GetText(iSelection , sPlayer);
		m_Opponent.SetWindowTextA(sPlayer);
				//Clear Player List
		while( m_PlayerListBox.GetCount() > 0 )
		{m_PlayerListBox.DeleteString(0);}

		//Set Turn String
		char playTurn[15];
		strcpy(playTurn,"Opponents");
		clientTurn.SetWindowTextA(playTurn);

		//Send Message
		Message_PDU Message;
		Message.iMessageNumber = 4;
		m_Play_Turn.GetWindowTextA(Message.iSender,MAX_MESSAGE_LENGTH);
		strcpy_s(Message.opponent,"Yours");
		DoSend(Message);
		select.EnableWindow(false);
		//Disable Dice Button
	}
