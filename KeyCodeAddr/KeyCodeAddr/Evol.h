#pragma once

#include "resource.h"


bool InitInstances(HINSTANCE hInstance, int nShowCmd);

bool InitDialogs(HWND hwnd);

LRESULT CALLBACK Evol(HWND hwnd,UINT uMsg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK About(HWND hwnd,UINT uMsg, WPARAM wParam, LPARAM lParam);



// ȫ�ֱ���:
HINSTANCE g_hInst;								// ��ǰʵ��
HWND g_hMainDlg;								// �����ھ��
HANDLE g_hFile;									// ��Ҫ�޸��ļ�
FILE *pOutput;