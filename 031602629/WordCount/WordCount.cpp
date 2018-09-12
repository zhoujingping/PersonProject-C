#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
/*
int write()
{

	return 0;
}
*/
int main(int argc, char * argv[])
{
	//定义一个名叫fp文件指针
	FILE *fp;
	//c存储每个字符
	int c;
	//s存储中间单词
	string s = "", word[100];
	int i = 0;
	//都是题目要求的输出的计数
	int characters = 0, words = 0, lines = 1, wordc[100] = { 0 };
	//count计数单词字母个数是否有4个以上字母，t标志单词，k代表单词个数,tt标记是否已经存入单词表中,p代表单词可以计数的标志
	int count = 0, t = 0, k = 0, tt = 0, p = 1;
	if ((fp = fopen(argv[1], "r")) == NULL)//打开操作不成功
	{
		
	}
	if ((fp = fopen("test.txt", "r")) == NULL)//打开操作不成功
	{
		printf("The file can not be opened.\n");
		exit(1);//结束程序的执行
	}
	else
	{
		printf("打开文件成功\n");
		while ((c = fgetc(fp)) != EOF)
		{
			if (c >= 128)
			{
				continue;
				/*
				s[i++]=c;
				printf("中文字符\n");
				*/
			}
			else
			{
				characters++;
				//设置p标志，是为了给单词的计数做起始
				if (!((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z') || (c >= '0'&&c <= '9')))
				{
					p = 1;
				}
				if (t == 0 && !((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')))
				{
					count = 0;
					p = 0;
				}
				if (c == '\n')
				{
					lines++;
				}
				if (p == 1 && ((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')))
				{
					count++;
					if (c >= 'A'&&c <= 'Z')
						c = c - 32;
					s += char(c);
					if (count >= 4)
						t = 1;
				}
				else if (t == 1 && c >= '0'&&c <= '9')
				{
					s += c;
				}
				else if (t == 1 && !(c >= '0'&&c <= '9'))
				{
					tt = 0;
					for (i = 0;i<k;i++)
					{
						if (word[i] == s)
						{
							wordc[i]++;
							tt = 1;
						}
					}
					if (tt == 0)
					{
						//cout<<"单词"<<s<<"\n";
						word[k] = s;
						wordc[k++] = 1;
					}
					s = "";
					t = 0;
				}
			}
		}
		if (t == 1)
		{
			tt = 0;
			for (i = 0;i<k;i++)
			{
				if (word[i] == s)
				{
					wordc[i]++;
					tt = 1;
				}
			}
			if (tt == 0)
			{
				word[k] = s;
				wordc[k++] = 1;
			}
		}
	}
	fclose(fp);
	printf("characters: %d\n", characters);
	printf("words: %d\n", words);
	printf("lines: %d\n", lines);
	for (i = 0;i<k;i++)
	{
		cout << "<" << word[i] << ">：" << wordc[i] << endl;
	}
	/*
	getchar();
	getchar();
	*/
	return 0;
}
