// MFC_display_control_01Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_display_control_01.h"
#include "MFC_display_control_01Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_display_control_01Dlg dialog




CMFC_display_control_01Dlg::CMFC_display_control_01Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_display_control_01Dlg::IDD, pParent)
	, Add_Items(_T(""))
	, displayBox(_T(""))
	, info(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_display_control_01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Add_Items);
	DDX_Control(pDX, IDC_COMBO1, Display_Item_Combo);
	DDX_Text(pDX, IDC_EDIT_info, info);
}

BEGIN_MESSAGE_MAP(CMFC_display_control_01Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_display_control_01Dlg::OnBnClickedAddItem)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CMFC_display_control_01Dlg::OnCbnDropdownDisplayItemCombo)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_display_control_01Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFC_display_control_01Dlg message handlers

BOOL CMFC_display_control_01Dlg::OnInitDialog()
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

void CMFC_display_control_01Dlg::OnPaint()
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
HCURSOR CMFC_display_control_01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFC_display_control_01Dlg::OnBnClickedAddItem()
{
	UpdateData(TRUE);				// これは control_to_variable
	CStdioFile file;
	BOOL ret = file.Open(_T("Data.txt"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	file.SeekToEnd();
	file.WriteString(Add_Items);	// これはアイテムを追加
	file.WriteString(_T("\n"));
	file.Close();

	Add_Items = _T("");
	if(ret ==1)
	{
		AfxMessageBox(_T("File has saved sucessfully"));
	}

	UpdateData(FALSE);				// これは variable_to_control
}

void CMFC_display_control_01Dlg::OnCbnDropdownDisplayItemCombo()
{
	UpdateData(TRUE);
	CStdioFile file;

	if(file.Open(_T("Data.txt"), CFile::modeRead))
	{
		CString line;
		while(file.ReadString(line))
		{
			if(line.GetLength() > 0)
			{
				Display_Item_Combo.AddString(line);
			}
		}
	}
	file.Close();
	UpdateData(FALSE);
}
void CMFC_display_control_01Dlg::OnBnClickedButton4()
{
	AfxMessageBox(_T("Select a TXT file to be displayed"));
	LPCTSTR pszFilter = _T("Text (*.txt)|*.txt||");
	CFileDialog dlgFile(TRUE, _T("line"), NULL, OFN_HIDEREADONLY , pszFilter, AfxGetMainWnd());
	if(IDOK == dlgFile.DoModal())
	{
		CStdioFile file(dlgFile.GetPathName(), CFile::modeRead | CFile::typeText);
		CString line;
		UpdateData(TRUE);
		info.Format(_T("Name: %s, \tSex: %s, \tPhone: %s"), "Tim", "Male", "090xxx");
		UpdateData(FALSE);
	}
}

void CMFC_display_control_01Dlg::OnEnChangeEdit3()
{
}

void CMFC_display_control_01Dlg::OnCbnSelchangeCombo2()
{
}
