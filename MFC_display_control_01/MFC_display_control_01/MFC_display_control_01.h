// MFC_display_control_01.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFC_display_control_01App:
// See MFC_display_control_01.cpp for the implementation of this class
//

class CMFC_display_control_01App : public CWinApp
{
public:
	CMFC_display_control_01App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFC_display_control_01App theApp;