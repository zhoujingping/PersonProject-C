#include"pch.h"
#include"readlines.h"
#include<fstream>
#include"structword.h"
using namespace std;

/**********************读取行数*********************/
int readlines(struct word*&head, char *filename, int file_lines)
{

	FILE *file = _fsopen(filename, "r", _SH_DENYNO);
	char chars = -1;
	int flag1 = 0;//有字符为1
	while (1)
	{
		chars = fgetc(file);
		if (chars == EOF)
			break;
		if (flag1 == 0)
		{
			if (!isspace(chars))
			{
				flag1 = 1;
			}
		}
		if (chars == '\n'&&flag1 == 1)
		{
			flag1 = 0;
			file_lines++;
		}
		
	}
	if(flag1==1)
	file_lines++;
	std::ofstream openfile("result.txt", std::ios::app);
	openfile << "lines:" << file_lines << endl;
	openfile.close();
	return 0;
}