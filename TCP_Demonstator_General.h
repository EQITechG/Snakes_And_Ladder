
#pragma once

#define iPORT 8000  // Decimal

#define MAX_MESSAGE_LENGTH 100

struct Message_PDU {
	char szText[MAX_MESSAGE_LENGTH + 1];
	char iSender[MAX_MESSAGE_LENGTH + 1];
	char chatText[MAX_MESSAGE_LENGTH + 1];
	char player[MAX_MESSAGE_LENGTH + 1];
	char opponent[MAX_MESSAGE_LENGTH + 1];
	int iMessageNumber;
	int iNumber;
	int iScore;
	int iTurn;
	};
