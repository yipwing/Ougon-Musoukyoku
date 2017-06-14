#pragma once

//////////////////////////////////////////////////////////////////////////
//   功能模块:
//		提供主要功能
//		后期添加些其他功能
//
//
//////////////////////////////////////////////////////////////////////////

#define TRAYICONID	1				//	拖盘图标ID号
/************************************************************************/
/* User Messages
/************************************************************************/
#define SWM_TRAYMSG	WM_APP			//	消息ID,传送给拖盘程序
#define SWM_SHOW	WM_APP + 1		//	测试用
#define SWM_HIDE	WM_APP + 2		//	同上
#define SWM_EXIT	WM_APP + 3		//	在同上
/************************************************************************/
/* Socket Messages
/************************************************************************/
#define UM_SOCK		WM_APP + 4      //  再次同上

bool UpgradePriv(HANDLE hProcess=NULL);
bool CheckFile(LPCTSTR lpFile);
BOOL AddTrayIcon(HWND hwnd, HINSTANCE hInstance,UINT uId);
BOOL DelTrayIcon(HWND hwnd,UINT uId);
void GetFileNames(HWND hwnd, TCHAR *szNames);
bool RegHotKey(int num,int* id,UINT mod,UINT vk,HWND hWnd,bool breg=true);
void FRC(HINSTANCE hInst,char* filename,int Idname,char* sourcename);
void setfonts(HWND hwnd,int iFont,LPCWSTR FontName,int nId);