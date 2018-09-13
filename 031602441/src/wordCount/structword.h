#pragma once
#include<iostream>
using namespace std;
/***********************单词结构体***********************/
struct word
{
	char name[30];
	int num;
	struct word *next;
};
