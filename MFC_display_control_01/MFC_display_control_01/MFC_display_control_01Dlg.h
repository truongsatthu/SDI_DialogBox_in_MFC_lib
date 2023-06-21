// MFC_display_control_01Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFC_display_control_01Dlg dialog
class CMFC_display_control_01Dlg : public CDialog
{
// Construction
public:
	CMFC_display_control_01Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_DISPLAY_CONTROL_01_DIALOG };

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
	afx_msg void OnEnChangeEdit2();
	CString Add_Items;
	afx_msg void OnBnClickedAddItem();
	CComboBox Display_Item_Combo;
	afx_msg void OnCbnDropdownDisplayItemCombo();
	afx_msg void OnBnClickedButtonOpenFile();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnCbnSelchangeCombo2();

public:
	CString displayBox;
	CString info;
};
