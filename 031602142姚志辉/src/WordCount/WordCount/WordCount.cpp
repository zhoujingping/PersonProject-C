#include<stdafx.h>
const int Arsize = 60;//�ı��ļ�����
int main()
{
	char c, fileName[Arsize];
	CharCount charcount;
	WordCount wordcount;
	LineCount linecount;
	WordList wordlist;
	cout << "Please enter the file's name:\n";
	cin.getline(fileName, Arsize);//����txt��ʽ�ı��ļ���
	try
	{
		charcount.charCount(fileName, charcount);//�����ַ���ͳ�ƺ���
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
	try
	{
		linecount.lineCount(fileName, linecount);//��������ͳ�ƺ���
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
	try
	{
		wordcount.wordCount(fileName, wordcount);//���õ�����ͳ�ƺ���
	}
	catch (char *Error)
	{
		cout << Error << endl;
	}
	try
	{
		wordlist.wordCount(fileName, wordlist);//���ô�Ƶͳ�ƺ���
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