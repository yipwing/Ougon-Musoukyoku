// Test.cpp : ����Ӧ�ó������ڵ㡣

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

	if (!InitInstances(hInstance,nCmdShow)) //��ʼ��ʵ��
	{
		return false;
	}
	hAccelTable = LoadAccelerators(hInstance,MAKEINTRESOURCE(IDR_ACC)); //������̱�
	while (GetMessage(&msg, NULL, 0, 0))		//��Ϣѭ��
	{
		if (TranslateAccelerator(g_hMainDlg, hAccelTable, &msg)||!IsDialogMessage(g_hMainDlg,&msg)) //��Ϣ����
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;

} 

bool InitInstances(HINSTANCE hInstance, int nShowCmd)
{
 	INITCOMMONCONTROLSEX icex;		//ĳЩ�ؼ���Ҫ,����һ���ṹ��						 ��
 	icex.dwSize=sizeof(icex);		//���ô˽ṹ��Ĵ�С								 ��
 	icex.dwICC=ICC_INTERNET_CLASSES + ICC_WIN95_CLASSES;	//�ؼ�ʹ�õ���ʽ			 ��
 	InitCommonControlsEx(&icex);	//��ʼ���ؼ���

	g_hInst = hInstance;			//���ݸ�ȫ�ֱ���
	g_hMainDlg = CreateDialog(hInstance,MAKEINTRESOURCE(IDD_MAIN),NULL,(DLGPROC)Evol);  //����Dialog����

	if (g_hMainDlg==NULL)
	{
		return false;
	}
////////////////////////////////////////////
//  ������ֻ�ó�������һ��,�����кü���������������Ϊ��򵥵ġ�
//
	if (!CreateMutex(NULL,TRUE,L"KeyCodeAddr")) //����һ���������
	{
		return false;					
	}
	if (GetLastError()==ERROR_ALREADY_EXISTS) //����Ѿ���һ������
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
//  �����ڻص�
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
			MessageBox(hwnd,L"��ע���exe�ļ���ΪGamemain.exe",L"��ʾ",MB_OK|MB_ICONINFORMATION);
			GetFileNames(hwnd,hFileName);
			_wfopen_s(&hFile,hFileName,L"rb");
			fseek(hFile, 0, SEEK_END);
			size = ftell(hFile);
			fseek(hFile, 0, SEEK_SET);
			data =(unsigned char*)malloc(size);
			fread(data,size,1,hFile);
			if(!isPEfile(data))
			{
				MessageBox(hwnd,L"����һ����Ч��ִ�г���",L"����",MB_OK|MB_ICONERROR);
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
					fprintf(pOutput,"0x%X,��������ϼ�λ��(�õ�Դ���Ա���,��������Ҫ������������(�൱�����ӹ���)..)\n",i);
					fprintf(pOutput,"����˵��Դ��,�Ǹļ���C���Ե�Դ��,����˵�ĶԱ�,�ǶԱ�����Ļ�����.�ǵü���JMP����תֵ(����)\n");
					y = i + 0x00400000;
					z = y - x - 5 + 1;
					//�¸��汾�Ѽ���õ���תֵת��Ϊopcode ��һ��һ���İѴ����Ϊ�Զ�̽�⻯..
					fprintf(pOutput,"0x%X,������JMP����תֵ(��һ����ȷ,���Ҫ�ҵ�RVA��Լ������,��û��PE��ʽ���RVA)\n������ԭʼ��(Ҳ��Ҫ�޸ĵĵط�,Ҳ����Ҫ��ϸ�Աȵĵط�):\n",z);
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
					fprintf(pOutput,"0x%X,���λ���ǰ汾��Ϣ\n",i);
				}
				else if(memcmp(data + i,version2,sizeof(version2))==0)
				{
					fprintf(pOutput,"0x%X,���λ���ǰ汾��Ϣ\n",i);
				}
				i++;
				if(i==0x000F7000)
				{
					break;
				}
			}	
				fprintf(pOutput,"%s","KeyCodeAddr by QQ: 8532125 ��,������������Ժ���Ӧ�ö���Ū�ļ����˰�");
				free(data);
//				free(hexchar);
				fclose(hFile);
				fclose(pOutput);
				if (IDYES==MessageBox(hwnd,L"���,�Ƿ���ļ��鿴?",L"��ʾ",MB_YESNO|MB_ICONINFORMATION))
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
//  ���ڴ��ڻص�
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
//  ��ʼ��Dialog����
//	�����ﴦ����Ǵ������Ͻǵ�Сͼ��ʹ�����Ϣ����Դ
bool InitDialogs(HWND hwnd)
{
	HMENU hMenu = GetSystemMenu(hwnd,FALSE);	//��ô��ھ��,������HMENU�ı���
	if (hMenu)
	{
		AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);	//��ĩβ���һ���˵�,��..��ӵ���һ������
		AppendMenu(hMenu, MF_STRING, IDM_ABOUT, _T("About Author...")); //ͬ��,ֻ���������һ���ַ���
	}
	HICON hIcon = (HICON)LoadImage(g_hInst,		//����- -!!��֪����ô˵,������������һ��ͼ��
		MAKEINTRESOURCE(IDI_TEST),				//MAKEINTRESOURCE��һ����,��IDת��Ϊ�ַ���
		IMAGE_ICON, 0,0, LR_SHARED+LR_DEFAULTSIZE);
	SendMessage(hwnd,WM_SETICON,ICON_BIG,(LPARAM)hIcon);	//������Ϣ
	SendMessage(hwnd,WM_SETICON,ICON_SMALL,(LPARAM)hIcon);	//ͬ��
	_wfopen_s(&pOutput,L"output.txt",L"w");
	fprintf(pOutput,"%s","�����Ǽ�λλ��\n");
	return TRUE;
}

