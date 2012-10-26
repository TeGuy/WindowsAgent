//====================================================================================
// Open Computer and Software Inventory Next Generation
// Copyright (C) 2010 OCS Inventory NG Team. All rights reserved.
// Web: http://www.ocsinventory-ng.org

// This code is open source and may be copied and modified as long as the source
// code is always made freely available.
// Please refer to the General Public Licence V2 http://www.gnu.org/ or Licence.txt
//====================================================================================

// DownloadDlg.h: interface for the CDownloadDlg class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "SimpleBrowser.h"

// CDownloadDlg dialog
class CDownloadDlg : public CDialog
{
// Construction
public:
	CDownloadDlg(CWnd* pParent = NULL);	// standard constructor

	// Set package informations
	void setAbortAllowed( BOOL bAbort = FALSE);
	void setDelayAllowed( BOOL bDelay = FALSE);
	void setTimeOut( UINT uTimeOut = 0);
	void setNotification( LPCTSTR lpstrText);
	// Allow to check if user press "delay" button
	BOOL isDelayed();

// Dialog Data
	enum { IDD = IDD_DOWNLOAD_DIALOG };

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	// Generated message map functions
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCancel();
	afx_msg void OnDelay();
	DECLARE_MESSAGE_MAP()

// Implementation
protected:
	HICON m_hIcon;
	BOOL m_bAbortAllowed;
	BOOL m_bDelayAllowed;
	BOOL m_bDelayed;
	UINT m_uNotifyCountdown;
	UINT m_uWaited;
	CString	m_csEdit;

	CButton	m_buttonOK;
	CButton	m_buttonCancel;
	CButton	m_buttonWait;
	SimpleBrowser m_Browser;
};
