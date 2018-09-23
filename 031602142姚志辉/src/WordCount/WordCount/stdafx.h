#pragma once
#include<iostream>
#include<fstream>
#include<strstream>
#include<cstring>
#include<string>
using namespace std;
//字符数统计类
struct CharCount
{
private:
	int charnum;//字符个数
public:
	CharCount()
	{
		charnum = 0;
	}
	void charCount(string fileName, CharCount &charcount);//统计字符数
	void countresult();//输出字符数
};
//单词数统计类
struct WordCount
{
private:
	int wordnum;
public:
	WordCount()
	{
		wordnum = 0;
	}
	void wordCount(string fileName, WordCount &wordcount);
	void countresult();
};
//行数统计类
struct LineCount
{
private:
	int linenum;//行数
public:
	LineCount()
	{
		linenum = 0;
	}
	void lineCount(string fileName, LineCount &linecount);//行数统计函数
	void countresult();//输出行数
};
//单词词频统计类
#define	MAX_WORD_LENGTH 50
struct Word {
	char word[MAX_WORD_LENGTH];
	int num;
	Word *next;
	Word *previous;
	Word() {
		word[0] = 0;
		num = 0;
		next = nullptr;
		previous = nullptr;
	}
	Word(char* theWord, int theNum) {
		strcpy_s(word, theWord);
		num = theNum;
		next = nullptr;
		previous = nullptr;
	}
	//如果使用了指针，在析构函数中释放 
	~Word() {
		delete next;
		next = nullptr;
	}
};

struct WordIndex {
	Word* pWord;
	WordIndex* next;
	WordIndex(Word* theWord, WordIndex* theNext)
	{
		pWord = theWord;
		next = theNext;
	}
	~WordIndex() {
		delete next;
		next = nullptr;
	}
};

struct WordList
{
private:
	int Hash(char *word);			//哈希函数
	void shiftWord(Word * pWord);	//使word前移一格
	Word* pWordHead;				//指向Word的指针
	Word* pWordTail;
	WordIndex* index[512];			//哈希索引
public:
	WordList();
	~WordList();
	void addWord(char word[]);
	void wordCount(string fileName, WordList &wordList);
	void outPut();
};