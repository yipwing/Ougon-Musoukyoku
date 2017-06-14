#pragma once

#include "resource.h"


bool InitInstances(HINSTANCE hInstance, int nShowCmd);

bool InitDialogs(HWND hwnd);

LRESULT CALLBACK Evol(HWND hwnd,UINT uMsg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK About(HWND hwnd,UINT uMsg, WPARAM wParam, LPARAM lParam);



// 全局变量:
HINSTANCE g_hInst;								// 当前实例
HWND g_hMainDlg;								// 主窗口句柄
HANDLE g_hFile;									// 主要修改文件
FILE *pOutput;