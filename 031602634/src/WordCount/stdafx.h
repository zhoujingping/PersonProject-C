#pragma once
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

class myfile
{
public:
	myfile();
	~myfile();
	void fileoutput();
	void px();													//排序得出前十个
	void countchar(FILE *f);									//统计字符数
	void countline(FILE *f);									//统计行数
	void countword(FILE *f);									//统计单词数	
	int getchars()												//得到字符数，为单元测试使用
	{
		return chars;
	}
	int getwords()												//得到单词数，为单元测试使用
	{
		return words;
	}
	int getlines()												//得到行数，为单元测试使用
	{
		return lines;
	}
public:
	int chars, lines, words;
};

int mycmpstruct(w a, w b);										//用于结构体排序
bool isnum(char c);												//判断是不是数字
bool ischar(char c);											//判断是不是字符
