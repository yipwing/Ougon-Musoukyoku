#pragma once

#include "stdafx.h"
#include "Function.h"

BOOL AddTrayIcon(HWND hwnd, HINSTANCE hInstance,UINT uId)
{
	wchar_t lpszTip[]=L"Double Click me";
	NOTIFYICONDATA tnid;
	ZeroMemory(&tnid,sizeof(NOTIFYICONDATA));
	tnid.cbSize = sizeof(NOTIFYICONDATA);
	tnid.hWnd = hwnd;
	tnid.uID = uId;
	tnid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
	tnid.uCallbackMessage = SWM_TRAYMSG;						//自定义消息
	tnid.hIcon = (HICON)LoadImage(hInstance,MAKEINTRESOURCE(uId),IMAGE_ICON,GetSystemMetrics(SM_CXSMICON),GetSystemMetrics(SM_CYSMICON),LR_DEFAULTCOLOR);
	lstrcpyn(tnid.szTip, lpszTip, sizeof(tnid.szTip));


	//调用Shell_NotifyIcon函数通过NIM_ADD向任务栏写图标
	return Shell_NotifyIcon(NIM_ADD, &tnid);
}

BOOL DelTrayIcon(HWND hwnd,UINT uId)
{
	NOTIFYICONDATA tnid;
//	IDI_ICON=uId;
	tnid.cbSize = sizeof(NOTIFYICONDATA);
	tnid.hWnd = hwnd;
	tnid.uID = uId;

	//用NIM_DELETE删除图标
	return Shell_NotifyIcon(NIM_DELETE, &tnid);
}

bool CheckFile(LPCTSTR lpFile)
{

	WIN32_FIND_DATA wfd;
	HANDLE hFind = FindFirstFile(lpFile,&wfd);
	DWORD dwsize;
	LONG err = GetLastError();

	if ( err == ERROR_FILE_NOT_FOUND)
	{
		FindClose(hFind);
		return false;
	}
	else
	{
		dwsize=GetFileSize(hFind,NULL);
		if (dwsize!=0)
		{
			return true;
		}
		return false;
	}
	FindClose(hFind);
	return true;
}

void GetFileNames(HWND hwnd, TCHAR *szNames)
{
	OPENFILENAME ofn;
	TCHAR szFileName[MAX_PATH];TCHAR szFileTitle[MAX_PATH];TCHAR szBuffer[MAX_PATH-130];
	lstrcpyn(szFileName,L"",MAX_PATH);lstrcpyn(szFileTitle,L"",MAX_PATH);lstrcpyn(szBuffer,L"",MAX_PATH-130);
	TCHAR const szFilter[] = L"Gamemain.exe\0Gamemain.exe";
	//TCHAR const szFilter[] = L".exe(*.exe)\0*.exe\0" L".bat(*.bat)\0*.bat\0" L".cmd(*.cmd)\0*.cmd\0";
	ofn.lStructSize		  = sizeof(OPENFILENAME);
	ofn.hwndOwner		  = hwnd;
	ofn.hInstance		  = NULL;
	ofn.lpstrFilter		  = szFilter;
	ofn.lpstrCustomFilter = NULL;
	ofn.nMaxCustFilter	  = 0;
	ofn.nFilterIndex	  = 1;
	ofn.lpstrFile		  = szFileName;
	ofn.nMaxFile		  = MAX_PATH;
	ofn.lpstrFileTitle	  = szFileTitle;
	ofn.nMaxFileTitle	  = MAX_PATH;
	ofn.lpstrInitialDir   = NULL;
	ofn.lpstrTitle		  = szBuffer;
	ofn.Flags			  = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY;
	ofn.lpstrDefExt		  = L"exe";

	if (!GetOpenFileName(&ofn))
	{
		ofn.lpstrFile=NULL;
	}

	lstrcpyn(szNames,ofn.lpstrFile,MAX_PATH);
}

bool RegHotKey(int num,int* id,UINT mod,UINT vk,HWND hWnd,bool breg)
{
	for (int i = 1; i < num; i++)
	{
		if (breg==false)
		{
			if (!UnregisterHotKey(hWnd,id[i]))
			{
				return false;
			}
		}
		if (!RegisterHotKey(hWnd,id[i],mod,vk))
		{
			return false;
		}
	}
	return true;
}

bool UpgradePriv(HANDLE hProcess)
{
	HANDLE hToken;
	LUID sedebugnameValue;
	TOKEN_PRIVILEGES tkp;
	if (hProcess==NULL)
	{
		if (!OpenProcessToken(GetCurrentProcess(),TOKEN_ALL_ACCESS_P,&hToken))
		{
			MessageBox(NULL,L"没进程可提升权限",L"错误",MB_OK|MB_ICONERROR);
		}
	}else if (!OpenProcessToken(hProcess,TOKEN_ALL_ACCESS_P, &hToken))
	{
		MessageBox(NULL,L"无法提升本程序权限",L"错误",MB_OK|MB_ICONERROR);
		return false;
	}
	if (!LookupPrivilegeValue(NULL,SE_DEBUG_NAME, &sedebugnameValue))
	{
		MessageBox(NULL,L"无法提升本程序权限",L"错误",MB_OK|MB_ICONERROR);
		CloseHandle(hToken);
		return false;
	}

	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = sedebugnameValue;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!AdjustTokenPrivileges(hToken,FALSE,&tkp,sizeof(tkp),NULL,NULL))
	{
		MessageBox(NULL,L"无法提升权限",L"",MB_OK|MB_ICONERROR);
		return false;
	}
	CloseHandle(hToken);
	return true;
}

void FRC(HINSTANCE hInst,LPCWSTR filename,int Idname,LPCWSTR sourcename)
{
	wchar_t pathname[MAX_PATH];
	ZeroMemory(pathname,MAX_PATH);
	GetCurrentDirectory(MAX_PATH,pathname);
	wcscat_s(pathname,wcslen(filename),filename);
	LPVOID lpDll = NULL;
	DWORD DLLSize = 0;
	HGLOBAL hMem = NULL;
	HRSRC hRes = FindResourceEx(hInst, sourcename,MAKEINTRESOURCE(Idname),MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL));  // 资源类型
	if(hRes)
	{   
		// 得到资源大小
		DLLSize = SizeofResource(hInst, hRes);
		hMem = LoadResource(hInst, hRes);
		if(hMem)
		{   
			lpDll = LockResource(hMem);
		}   
	}
	if (lpDll == NULL)   
	{
		MessageBox(NULL,L"无法释放必要文件",L"警告",MB_OK|MB_ICONEXCLAMATION);
		return;
	}
	HANDLE hFile = CreateFile(pathname,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,NULL);
	DWORD unuse = 0;
	WriteFile(hFile, lpDll, DLLSize, &unuse, NULL);   

	// 释放所有资源
	UnlockResource(hMem);   
	FreeResource(hMem);
	CloseHandle(hFile);
}

void setfonts(HWND hwnd,int iFont,LPCWSTR FontName,int nId)
{
	HDC hdc;
	HFONT hFont;
	LOGFONT lf;

	lf.lfHeight = iFont;
	lf.lfEscapement = 0;
	lf.lfWeight = 40;
	lf.lfItalic = 0;
	lf.lfUnderline = 0;
	lf.lfStrikeOut = 0;
	lf.lfCharSet = GB2312_CHARSET;
	lf.lfOutPrecision = 3;
	lf.lfClipPrecision = 2;
	lf.lfQuality = 1;
	lf.lfPitchAndFamily = 2;
	lstrcpy(lf.lfFaceName,FontName);

	hFont = CreateFontIndirect(&lf);
	if (hFont==NULL)
	{
		MessageBox(hwnd,L"无法载入字体",L"警告",MB_OK|MB_ICONERROR);
		return;
	}
	hdc = GetDC(hwnd);
	SelectObject(hdc,hFont);
	SendDlgItemMessage(hwnd,nId,WM_SETFONT,WPARAM(hFont),0);
	ReleaseDC(hwnd,hdc);
}