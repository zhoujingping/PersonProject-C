#include"pch.h"
#include"readlines.h"
#include<fstream>
#include"structword.h"
using namespace std;

/**********************读取行数*********************/
int readlines(struct word*&head, char *filename, int file_lines)
{

	FILE *file = _fsopen(filename, "r", _SH_DENYNO);
	if (!file)
	{
		printf("打开文件错误！");
		return 0;
	}
	char chars = -1;
	char bb_chars = -1;//前一个字符 
	while (1)
	{
		chars = fgetc(file);
		if (chars == EOF)
			break;
		if (chars == '\n'&&bb_chars != '\n')
			file_lines++;
		bb_chars = chars;
	}
	file_lines++;
	std::ofstream openfile("C:/Users/Mac/Desktop/result.txt", std::ios::app);
	openfile << "lines:" << file_lines << endl;
	openfile.close();
	return 0;
}