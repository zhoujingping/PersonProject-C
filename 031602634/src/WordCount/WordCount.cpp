#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;

typedef struct
{
	char word[20];												//储存单词，长度最多不超过20
	int count;													//出现次数
}w;


int mycmpstruct(w a, w b);										//用于结构体排序


int main(int argc, char *argv[])
{
	w s;
	w str[20000];
	int n = 0, j, i;
	int charr = 0, liness = 1;									//字符数和行数
	int x;
	char ch;
	int flag = 1;

	FILE *inf;
	fopen_s(&inf, argv[1], "r");								//从文本中读出单词
	fstream file("result.txt", ios::out);						//先清空输出文本
	fstream File("result.txt", ios::in | ios::out);				//将结果输出到文本中
	if (inf == NULL)
	{
		cout << "error" << endl;
		system("pause");
		return 0;
	}

	while (!feof(inf))											//统计字符数
	{
		ch = getc(inf);
		if (ch >= 0 && ch <= 255) charr++;
	}
	File << "characters: " << charr << endl;
	rewind(inf);												//指针复位

	while (!feof(inf))											//读单词写入结构体，并统计单词个数
	{
		ch = getc(inf);
		if (ch == ' ' || ch == 10)								//出现空格或换行的情况跳过
		{
			flag = 1;
			continue;
		}
		if ((ch >= '0' && ch <= '9'))							//flag用于出现“7english”情况的错误判断
		{
			flag = 0;
			continue;
		}
		if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && flag == 1)
		{														//当出现一个字母，并且前一个相邻的不是数字时进入
			int k = 0;
			x = 0;
			s.count = 1;
			while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
			{
				s.word[k++] = tolower(ch);						//将大写转换为小写
				ch = getc(inf);
				x++;
			}
			if (x <= 3)											//如果出现字符数小于4个的情况，不算单词
			{
				k = k - x;
				continue;
			}
			s.word[k++] = '\0';
			j = n;
			for (i = 0; i < j; i++)								//与结构体中比较，如果存在，则改单词次数+1
			{
				if (strcmp(s.word, str[i].word) == 0)
				{
					str[i].count++;
					break;
				}
			}

			if (n == 0 || i == j)								//不存在将单词写入结构体中
			{
				str[n++] = s;
			}
		}
	}

	File << "words: " << n << endl;
	rewind(inf);

	while (!feof(inf))											//统计行数
	{
		ch = getc(inf);
		if (ch == '\n') liness++;
	}
	File << "lines: " << liness << endl;

	sort(str, str + n, mycmpstruct);							//结构体排序，按出现次数从大到小排序

	for (i = 0; i < n; i++)
	{
		File << str[i].word << ": " << str[i].count << endl;
	}
	return 0;
}

int mycmpstruct(w a, w b)
{
	if (a.count != b.count) return a.count > b.count;
	if (a.count = b.count)
	{
		string aa = a.word;
		string bb = b.word;
		return aa < bb;
	}
}