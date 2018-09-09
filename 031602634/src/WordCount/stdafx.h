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



void countfrequency(int n);										//排序得出前十个
int countchar(FILE *f);											//统计字符数
int countline(FILE *f);											//统计行数
int countword(FILE *f);											//统计单词数
int mycmpstruct(w a, w b);										//用于结构体排序
bool isnum(char c);												//判断是不是数字
bool ischar(char c);											//判断是不是字符
void outputtxt(int x,int y,int n);