#include "stdafx.h"


int main(int argc, char *argv[])
{
	FILE *inf;
	fopen_s(&inf, argv[1], "r");								//从文本中读出单词

	if (inf == NULL)
	{
		cout << "error" << endl;
		system("pause");
		return 0;
	}

	int chars = countchar(inf);
	rewind(inf);												

	int words = countword(inf);
	rewind(inf);

	int lines = countline(inf);


	countfrequency(words);

	outputtxt(chars,lines,words);

	return 0;
}

