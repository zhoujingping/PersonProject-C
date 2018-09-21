#pragma once
#include<iostream>
#include<fstream>
#include<strstream>
#include<cstring>
#include<string>
using namespace std;
//�ַ���ͳ����
struct CharCount
{
private:
	int charnum;//�ַ�����
public:
	CharCount()
	{
		charnum = 0;
	}
	void charCount(string fileName, CharCount &charcount);//ͳ���ַ���
	void countresult();//����ַ���
};
//������ͳ����
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
//����ͳ����
struct LineCount
{
private:
	int linenum;//����
public:
	LineCount()
	{
		linenum = 0;
	}
	void lineCount(string fileName, LineCount &linecount);//����ͳ�ƺ���
	void countresult();//�������
};
//���ʴ�Ƶͳ����
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
	//���ʹ����ָ�룬�������������ͷ� 
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
	int Hash(char *word);			//��ϣ����
	void shiftWord(Word * pWord);	//ʹwordǰ��һ��
	Word* pWordHead;				//ָ��Word��ָ��
	Word* pWordTail;
	WordIndex* index[512];			//��ϣ����
public:
	WordList();
	~WordList();
	void addWord(char word[]);
	void wordCount(string fileName, WordList &wordList);
	void outPut();
};