#include<stdafx.h>
const int Arsize = 60;//文本文件长度
int main()
{
	char c, fileName[Arsize];
	CharCount charcount;
	WordCount wordcount;
	LineCount linecount;
	WordList wordlist;
	cout << "Please enter the file's name:\n";
	cin.getline(fileName, Arsize);//输入txt格式文本文件名
	try
	{
		charcount.charCount(fileName, charcount);//调用字符数统计函数
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
	try
	{
		linecount.lineCount(fileName, linecount);//调用行数统计函数
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
	try
	{
		wordcount.wordCount(fileName, wordcount);//调用单词数统计函数
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
	try
	{
		wordlist.wordCount(fileName, wordlist);//单用词频统计函数
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
	charcount.countresult();
	wordcount.countresult();
	linecount.countresult();
	wordlist.outPut();
	return 0;
}