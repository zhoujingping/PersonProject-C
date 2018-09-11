#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<regex>
#include<list>
using namespace std;
typedef list<string> List;

//保持单词即其出现个数的类
class Word
{
public:
	string name;
	int count;
	bool operator < (Word& w1)//重载<运算符
	{
		return count > w1.count;
	}
};
typedef list<Word> Wordlist;
//文件类，实现各项关于文件的操作
class File
{
public:
	File();
	~File();
	void Infile(string filename);
	void Outfile(string filename);
	void Wordscount(string filename);
	void Wordsway();
	void Show();
private:
	int charcount;
	int wordscount;
	int line;
	List words;
	Wordlist words_count;
};