// MFC_Database_01.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFC_Database_01App:
// See MFC_Database_01.cpp for the implementation of this class
//

class CMFC_Database_01App : public CWinApp
{
public:
	CMFC_Database_01App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFC_Database_01App theApp;