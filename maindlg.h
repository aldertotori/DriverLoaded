// maindlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINDLG_H__DCE86EA3_0D96_4814_AF74_1181F6C52872__INCLUDED_)
#define AFX_MAINDLG_H__DCE86EA3_0D96_4814_AF74_1181F6C52872__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CMainDlg : public CDialogImpl<CMainDlg>
{
public:
	CListViewCtrl	m_list;
public:
	enum { IDD = IDD_MAINDLG };

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		// center the dialog on the screen
		CenterWindow();

		// set icons
		HICON hIcon = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
			IMAGE_ICON, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON), LR_DEFAULTCOLOR);
		SetIcon(hIcon, TRUE);
		HICON hIconSmall = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
			IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
		SetIcon(hIconSmall, FALSE);

		RECT  rc;
		GetClientRect(&rc);

		m_list.Create(m_hWnd, rc,NULL,
			WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | LVS_REPORT | LVS_SHOWSELALWAYS,
			 LVS_EX_FULLROWSELECT);
		
		AddColumns();

		AddItems();

		return TRUE;
	}

	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		CSimpleDialog<IDD_ABOUTBOX, FALSE> dlg;
		dlg.DoModal();
		return 0;
	}

	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		// TODO: Add validation code 
		EndDialog(wID);
		return 0;
	}

	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		EndDialog(wID);
		return 0;
	}

	VOID AddColumns()
	{

		m_list.AddColumn("Order",0);
		m_list.SetColumnWidth(0,80);
		m_list.AddColumn("FileName",1);
		m_list.SetColumnWidth(1,180);
		m_list.AddColumn("FullPathName",2);
		m_list.SetColumnWidth(2,400);
		m_list.AddColumn("Module Address",3);

	}

	VOID AddItems()
	{
		char  szText[MAX_PATH];
		PFN_NtQuerySystemInformation NtQuery = NULL;
		RTL_PROCESS_MODULES	Modules;
		PRTL_PROCESS_MODULES pMods = NULL;
		ULONG				 Length = 0;
		HMODULE hMod = GetModuleHandle("ntdll.dll");
		if(hMod)
		{
			NtQuery = (PFN_NtQuerySystemInformation)GetProcAddress(hMod,"NtQuerySystemInformation");
			if(!NtQuery) return;
		}
		
		if(NtQuery(SystemModuleInformation,&Modules,sizeof(RTL_PROCESS_MODULES),&Length) != 0 && Length)
		{
			pMods = (PRTL_PROCESS_MODULES)malloc(Length);
			ZeroMemory(pMods,Length);
			
			if(NtQuery(SystemModuleInformation,pMods,Length,&Length) == 0)
			{
				for(ULONG i = 0; i < pMods->NumberOfModules; i++)
				{
					wsprintf(szText,"%d",pMods->Modules[i].LoadOrderIndex);
					m_list.AddItem(i,0,szText);
					m_list.AddItem(i,1,	(char*)pMods->Modules[i].FullPathName + pMods->Modules[i].OffsetToFileName);
					m_list.AddItem(i,2,	(char*)pMods->Modules[i].FullPathName);
					wsprintf(szText,"0x%08X",pMods->Modules[i].ImageBase);
					m_list.AddItem(i,3, szText);
				}
			}
			
		}
	}
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__DCE86EA3_0D96_4814_AF74_1181F6C52872__INCLUDED_)
