#include"pch.h"
#include"readchars.h"
#include<fstream>
using namespace std;

extern struct word head;
/**********************¶ÁÈ¡×Ö·û*********************/
int readchars(struct word*&head, char *filename, int file_chars)
{

	FILE *file = _fsopen(filename, "r", _SH_DENYNO);
	char chars = -1;
	while (1)
	{
		chars = fgetc(file);
		if (chars == EOF)
			break;
		file_chars++;
	}
	std::ofstream openfile("C:/Users/Mac/Desktop/result.txt", std::ios::trunc);
	openfile << "characters:" << file_chars << endl;
	openfile.close();
	return 0;
}