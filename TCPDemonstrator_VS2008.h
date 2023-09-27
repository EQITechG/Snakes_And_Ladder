
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTCPDemonstrator_VS2008App:
// See TCPDemonstrator_VS2008.cpp for the implementation of this class
//

class CTCPDemonstrator_VS2008App : public CWinAppEx
{
public:
	CTCPDemonstrator_VS2008App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTCPDemonstrator_VS2008App theApp;