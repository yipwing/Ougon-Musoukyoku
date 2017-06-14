// KeyCodeDec.cpp : 定义控制台应用程序的入口点。
// 下个版本改进探测程序,增加静态机器码复制到文本,计算JMP的数值,咱得认真学习PE文件结构..重新编写此程序..
#include "stdafx.h"
#include "KeyCodeDec.h"
#include "DefineHead.h"

int main(int argc, char* argv[])
{
	FILE *pfile;
	fopen_s(&pfile,"GameMain.exe", "rb");
    unsigned char *data;
    unsigned int size;
    FILE *pcfile;
	fopen_s(&pcfile,"kbrebind.key","w");
	fprintf(pcfile,"[NKEY]");
    fprintf(pcfile,"%s","\n;以下是键位位置\n");
    unsigned int i = 22528;
	unsigned int x = 0; unsigned int y = 0; unsigned int z = 0;
	unsigned int *b = 0;
//	unsigned char* hexchar;
//	fpos_t pos;
    if(!pfile){
        printf("打开文件失败,或找不到文件\n");
		getchar();
        return 0;
    }
    fseek(pfile, 0, SEEK_END);
	size = ftell(pfile);
	fseek(pfile, 0, SEEK_SET);
	if (size < 0xb0000){
		printf("貌似不是一个有效的可执行程序.\n");
		getchar();
		return 0;
	}
	printf("本程序会自动在程序目录生成kbrebind.key文件\n");
	printf("按回车键继续");
	getchar();
    data =(unsigned char*)malloc(size);
    fread(data,size,1,pfile);
	if(!isPEfile(data))
	{
		printf("不是一个windows可执行程序.\n");
		getchar();
		return 0;
	}
//	hexchar = (unsigned char*)malloc(90);
    while (i < size){
            if(memcmp(data + i,code1,sizeof(code1))==0)
			{
				fprintf(pcfile,"KeyUp = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code2,sizeof(code2))==0)
			{
				fprintf(pcfile,"KeyDown = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code3,sizeof(code3))==0)
			{
				fprintf(pcfile,"KeyLeft = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code4,sizeof(code4))==0)
			{
				fprintf(pcfile,"KeyRight = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code5,sizeof(code5))==0)
			{
				fprintf(pcfile,"KeyA = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code6,sizeof(code6))==0)
			{
				fprintf(pcfile,"KeyB = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code7,sizeof(code7))==0)
			{
				fprintf(pcfile,"KeyC = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code8,sizeof(code8))==0)
			{
				fprintf(pcfile,"KeyTouch = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code9,sizeof(code9))==0)
			{
				fprintf(pcfile,"KeyAppeal = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code10,sizeof(code10))==0)
			{
				fprintf(pcfile,"KeyUnknown1 = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code11,sizeof(code11))==0)
			{
				fprintf(pcfile,"KeyUnknown2 = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code12,sizeof(code12))==0)
			{
				fprintf(pcfile,"KeyUnknown3 = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code13,sizeof(code13))==0)
			{
				fprintf(pcfile,"KeyUnknown4 = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code14,sizeof(code14))==0)
			{
				fprintf(pcfile,"KeyStart = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code15,sizeof(code15))==0)
			{
				fprintf(pcfile,"KeyUnknown5 = 0x%X\n",i+2);
			}
			if(memcmp(data + i,code16,sizeof(code16))==0)
			{
				fprintf(pcfile,"KeyUnknown6 = 0x%X\n",i+2);
				x = i;
				x += 0x00400000;
			}
			if(memcmp(data + i,combocode,sizeof(combocode))==0)
			{
				fprintf(pcfile,"[COMBOKEY]\nCOMBOAD = 0x%X\n;上面是组合键位置\n",i);		
				y = i + 0x00400000;
				z = y - x - 5 + 1;
				//下个版本把计算好的跳转值转换为opcode 并一步一步的把代码改为自动探测化..
				fprintf(pcfile,"[JMPKEY]\nJMPCA = 0x%X\n;上面是JMP的跳转值(记得反转喔..)\n",z);
//				pos = i;
//				fsetpos(pfile,&pos);
//				fread(hexchar,92,1,pfile);
//				fgetpos(pfile,&pos);
//				unsigned int b = 0;
//				for(; b < 92; hexchar++,b++)
//				{
//					fprintf(pcfile,"0x%X%X ",(*hexchar>>4) & 0xF,(*hexchar) & 0xF);
//					if(hexchar+3==0x00)
//						break;
//				}
//				fprintf(pcfile,"\n","");

			}
			if(memcmp(data + i,version1,sizeof(version1))==0)
			{
				fprintf(pcfile,"[VERSION]\nVer = 0x%X\n;上面是版本信息\n",i);
			}
			else if(memcmp(data + i,version2,sizeof(version2))==0)
			{
				fprintf(pcfile,"[VERSION]\nVer = 0x%X\n;上面是版本信息\n",i);
			}
        i++;
		if(i==0x000F7000)
		{
			break;
		}
    }
	fprintf(pcfile,"%s",";KeyAddress by QQ: 8532125 ");
	free(data);
	fclose(pcfile);
	fclose(pfile);
    return 0;
}



