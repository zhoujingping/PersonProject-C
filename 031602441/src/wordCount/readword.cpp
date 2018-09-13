#include"pch.h"
#include"readword.h"
#include"structword.h"
#include<fstream>
using namespace std;


/**********************读取文件中单词*********************/
int readword(struct word*&head, char *filename, int word_num)
{
	int flag = 0;
	FILE *fp;
	if ((fp = _fsopen(filename, "r", _SH_DENYNO)) == NULL)
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	char ch, b_chars[30];
	struct word *p;
	while (!feof(fp))
	{
		int i = 0;
		ch = fgetc(fp);
		while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))
		{
			b_chars[i] = ch;
			i++;
			ch = fgetc(fp);
			if (feof(fp)) break;
		}
		b_chars[i] = '\0';
		if (((b_chars[0] <= 'z') && (b_chars[0] >= 'a')) || ((b_chars[0] <= 'Z') && (b_chars[0] >= 'A')))
		{
			if (((b_chars[1] <= 'z') && (b_chars[1] >= 'a')) || ((b_chars[1] <= 'Z') && (b_chars[1] >= 'A')))
			{
				if (((b_chars[2] <= 'z') && (b_chars[2] >= 'a')) || ((b_chars[2] <= 'Z') && (b_chars[2] >= 'A')))
				{
					if (((b_chars[3] <= 'z') && (b_chars[3] >= 'a')) || ((b_chars[3] <= 'Z') && (b_chars[3] >= 'A')))
					{
						flag = 1;
						word_num++;
					}
				}
			}
		}
		i = 0;
		if (flag == 1 && b_chars[0] != '\0')
		{
			while (b_chars[i])
			{
				if (b_chars[i] >= 'A'&&b_chars[i] <= 'Z')
				{
					b_chars[i] += 32;
				}
				i++;
			}
		}
		p = head->next;
		while (p&&flag == 1)
		{
			if (!_stricmp(b_chars, p->name))
			{
				p->num++;break;
			}
			p = p->next;
		}
		if (!p&&flag == 1 && b_chars[0] != '\0')
		{
			p = new word;
			strcpy_s(p->name, b_chars);
			p->num = 1;
			p->next = head->next;
			head->next = p;
		}
		flag = 0;
	}
	std::ofstream openfile("result.txt", std::ios::app);
	openfile << "words:" << word_num << endl;
	openfile.close();
	return 0;
}