#pragma once

//////////////////////////////////////////////////////////////////////////
//   ����ģ��:
//		�ṩ��Ҫ����
//		�������Щ��������
//
//
//////////////////////////////////////////////////////////////////////////

#define TRAYICONID	1				//	����ͼ��ID��
/************************************************************************/
/* User Messages
/************************************************************************/
#define SWM_TRAYMSG	WM_APP			//	��ϢID,���͸����̳���
#define SWM_SHOW	WM_APP + 1		//	������
#define SWM_HIDE	WM_APP + 2		//	ͬ��
#define SWM_EXIT	WM_APP + 3		//	��ͬ��
/************************************************************************/
/* Socket Messages
/************************************************************************/
#define UM_SOCK		WM_APP + 4      //  �ٴ�ͬ��

bool UpgradePriv(HANDLE hProcess=NULL);
bool CheckFile(LPCTSTR lpFile);
BOOL AddTrayIcon(HWND hwnd, HINSTANCE hInstance,UINT uId);
BOOL DelTrayIcon(HWND hwnd,UINT uId);
void GetFileNames(HWND hwnd, TCHAR *szNames);
bool RegHotKey(int num,int* id,UINT mod,UINT vk,HWND hWnd,bool breg=true);
void FRC(HINSTANCE hInst,char* filename,int Idname,char* sourcename);
void setfonts(HWND hwnd,int iFont,LPCWSTR FontName,int nId);