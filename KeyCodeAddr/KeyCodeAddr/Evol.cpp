// Test.cpp : 定义应用程序的入口点。

#include "stdafx.h"
#include "Evol.h"
#include "Define.h"
#include "Function.h"
#pragma comment(lib,"Comctl32.lib") 



int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow) 
{
	MSG msg;
	HACCEL hAccelTable;

	if (!InitInstances(hInstance,nCmdShow)) //初始化实例
	{
		return false;
	}
	hAccelTable = LoadAccelerators(hInstance,MAKEINTRESOURCE(IDR_ACC)); //载入键盘表
	while (GetMessage(&msg, NULL, 0, 0))		//消息循环
	{
		if (TranslateAccelerator(g_hMainDlg, hAccelTable, &msg)||!IsDialogMessage(g_hMainDlg,&msg)) //消息处理
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;

} 

bool InitInstances(HINSTANCE hInstance, int nShowCmd)
{
 	INITCOMMONCONTROLSEX icex;		//某些控件需要,这是一个结构体						 │
 	icex.dwSize=sizeof(icex);		//设置此结构体的大小								 │
 	icex.dwICC=ICC_INTERNET_CLASSES + ICC_WIN95_CLASSES;	//控件使用的样式			 │
 	InitCommonControlsEx(&icex);	//初始化控件类

	g_hInst = hInstance;			//传递给全局变量
	g_hMainDlg = CreateDialog(hInstance,MAKEINTRESOURCE(IDD_MAIN),NULL,(DLGPROC)Evol);  //创建Dialog窗口

	if (g_hMainDlg==NULL)
	{
		return false;
	}
////////////////////////////////////////////
//  这里是只让程序运行一个,方法有好几个，这里用我认为最简单的。
//
	if (!CreateMutex(NULL,TRUE,L"KeyCodeAddr")) //创建一个互斥对象
	{
		return false;					
	}
	if (GetLastError()==ERROR_ALREADY_EXISTS) //如果已经有一个存在
	{
		ShowWindow(g_hMainDlg,SW_RESTORE);		
		SetForegroundWindow(g_hMainDlg);
		return false;
	}
////////////////////////////////////////////
	ShowWindow(g_hMainDlg,SW_SHOWNORMAL);
	UpdateWindow(g_hMainDlg);
	return true;
}
////////////////////////////////////////////
//  主窗口回调
//  
LRESULT CALLBACK Evol(HWND hwnd,UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int wmId,wmEvent;
	wmId    = LOWORD(wParam);
	wmEvent = HIWORD(wParam);
	FILE *hFile;
	TCHAR hFileName[MAX_PATH];
	unsigned char *data;
	unsigned int size;
	unsigned int i = 22528;
	unsigned int x = 0; unsigned int y = 0; unsigned int z = 0;
	unsigned int *b = 0;
	unsigned char* hexchar;
	
	fpos_t pos;
	switch(uMsg)
	{
	case WM_SYSCOMMAND:
		switch(wParam)
		{
		case IDM_ABOUT:
			DialogBox(g_hInst,MAKEINTRESOURCE(IDD_ABOUTBOX),hwnd,(DLGPROC)About);
			break;
		}
	case WM_COMMAND:
		switch(wmId)
		{
		case IDC_OPENFILE:
			MessageBox(hwnd,L"请注意把exe文件改为Gamemain.exe",L"提示",MB_OK|MB_ICONINFORMATION);
			GetFileNames(hwnd,hFileName);
			_wfopen_s(&hFile,hFileName,L"rb");
			fseek(hFile, 0, SEEK_END);
			size = ftell(hFile);
			fseek(hFile, 0, SEEK_SET);
			data =(unsigned char*)malloc(size);
			fread(data,size,1,hFile);
			if(!isPEfile(data))
			{
				MessageBox(hwnd,L"不是一个有效的执行程序",L"错误",MB_OK|MB_ICONERROR);
				free(data);
				fclose(hFile);
				return 0;
			}
			hexchar = (unsigned char*)malloc(90);
			//_wfopen_s(&pOutput,L"output.txt",L"w");
			while (i < size){
				if(memcmp(data + i,code1,sizeof(code1))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code2,sizeof(code2))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code3,sizeof(code3))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code4,sizeof(code4))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code5,sizeof(code5))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code6,sizeof(code6))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code7,sizeof(code7))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code8,sizeof(code8))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code9,sizeof(code9))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code10,sizeof(code10))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code11,sizeof(code11))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code12,sizeof(code12))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code13,sizeof(code13))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code14,sizeof(code14))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code15,sizeof(code15))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
				}
				if(memcmp(data + i,code16,sizeof(code16))==0)
				{
					fprintf(pOutput,"0x%X\n",i+2);
					x = i;
					x += 0x00400000;
				}
				if(memcmp(data + i,combocode,sizeof(combocode))==0)
				{
					fprintf(pOutput,"0x%X,这里是组合键位置(拿到源码后对比下,这里是需要汇编代码来做的(相当于增加功能)..)\n",i);
					fprintf(pOutput,"上面说的源码,是改键器C语言的源码,这里说的对比,是对比下面的机器码.记得计算JMP的跳转值(回跳)\n");
					y = i + 0x00400000;
					z = y - x - 5 + 1;
					//下个版本把计算好的跳转值转换为opcode 并一步一步的把代码改为自动探测化..
					fprintf(pOutput,"0x%X,这里是JMP的跳转值(不一定正确,这个要找到RVA相对计算才行,咱没用PE方式获得RVA)\n以下是原始码(也是要修改的地方,也是需要仔细对比的地方):\n",z);
					pos = i;
					fsetpos(hFile,&pos);
					fread(hexchar,92,1,hFile);
					fgetpos(hFile,&pos);
					unsigned int b = 0;
					for(; b < 92; hexchar++,b++)
					{
						fprintf(pOutput,"0x%X%X ",(*hexchar>>4) & 0xF,(*hexchar) & 0xF);
						if(hexchar+3==0x00)
							break;
					}
					fprintf(pOutput,"\n","");
				}
				if(memcmp(data + i,version1,sizeof(version1))==0)
				{
					fprintf(pOutput,"0x%X,这个位置是版本信息\n",i);
				}
				else if(memcmp(data + i,version2,sizeof(version2))==0)
				{
					fprintf(pOutput,"0x%X,这个位置是版本信息\n",i);
				}
				i++;
				if(i==0x000F7000)
				{
					break;
				}
			}	
				fprintf(pOutput,"%s","KeyCodeAddr by QQ: 8532125 嗯,有了这个东东以后大家应该都会弄改键器了吧");
				free(data);
//				free(hexchar);
				fclose(hFile);
				fclose(pOutput);
				if (IDYES==MessageBox(hwnd,L"完成,是否打开文件查看?",L"提示",MB_YESNO|MB_ICONINFORMATION))
				{
					ShellExecute(NULL,L"open",L"output.txt",L"",L"",SW_SHOWMAXIMIZED);
				}
			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_INITDIALOG:
		return InitDialogs(hwnd);
// 	default:
// 		DefWindowProc(hwnd,uMsg,wParam,lParam);
	}

	return 0;
}
////////////////////////////////////////////
//  关于窗口回调
//
LRESULT CALLBACK About(HWND hwnd,UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hwnd,wParam);
			return TRUE;
		}
		break;
	}
	return FALSE;
}

///////////////////////////////////////////
//  初始化Dialog窗口
//	我这里处理的是窗口左上角的小图标和触发消息的资源
bool InitDialogs(HWND hwnd)
{
	HMENU hMenu = GetSystemMenu(hwnd,FALSE);	//获得窗口句柄,并赋给HMENU的变量
	if (hMenu)
	{
		AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);	//在末尾添加一个菜单,呃..添加的是一个横线
		AppendMenu(hMenu, MF_STRING, IDM_ABOUT, _T("About Author...")); //同上,只不过是添加一个字符串
	}
	HICON hIcon = (HICON)LoadImage(g_hInst,		//载入- -!!不知道怎么说,反正就是载入一个图像
		MAKEINTRESOURCE(IDI_TEST),				//MAKEINTRESOURCE是一个宏,把ID转换为字符串
		IMAGE_ICON, 0,0, LR_SHARED+LR_DEFAULTSIZE);
	SendMessage(hwnd,WM_SETICON,ICON_BIG,(LPARAM)hIcon);	//发送消息
	SendMessage(hwnd,WM_SETICON,ICON_SMALL,(LPARAM)hIcon);	//同上
	_wfopen_s(&pOutput,L"output.txt",L"w");
	fprintf(pOutput,"%s","以下是键位位置\n");
	return TRUE;
}

