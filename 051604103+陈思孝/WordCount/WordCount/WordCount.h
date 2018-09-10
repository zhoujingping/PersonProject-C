#pragma once
#include<iostream>
#include<fstream>
#include <vector> 
#include<string>
#include <algorithm>
using namespace std;
struct Word {
	string name;
	int cnt;
};//存储单词名和个数

int sum1(int  x, int y)
{
	return x + y;
}

//用容器实现分割字符串  
vector<string> split(const string &s, const string &seperator) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//找到字符串中首个不等于分隔符的字母；
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[i] == seperator[x]) {

					++i;
					flag = 0;
					break;
				}
		}

		//找到又一个分隔符，将两个分隔符之间的字符串取出；
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[j] == seperator[x]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				++j;
		}
		if (i != j) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}
int exist1(string x, Word words[500], int k)//判断单词是否已经存在
{
	for (int i = 0; i < k; i++)
	{
		if (x == words[i].name)
		{
			words[i].cnt++;
			return 1;
		}
	}
	return 0;
}

int judgeblank(string s)//判断是否为空格行
{
	//cout<<s<<endl;
	int i = 0;
	int cnt = 0;
	while (i != s.size())
	{
		if (s[i] == ' ')
			cnt++;
		i++;
	}

	//cout<<"cnt:"<<cnt<< ' '<<"size:"<<s.size()<<endl;
	if (s.size() == cnt)
		return 1;
	return 0;
}
int  CountChar(vector<string> &lines, int line) {//统计字符数
	int cnt = 0;
	int i = 0;
	for (i = 0; i < line; i++)
	{
		cnt += lines[i].size();
	}
	cnt = cnt + line;
	return cnt;
}
int WordNumber(vector<string> &lines)//统计单词数
{
	int cnt = 0;
	for (int unsigned i = 0; i < lines.size(); i++)//size()为无符号
	{
		vector<string> t;
		t = split(lines[i], "1234567890 ");
		cnt += t.size();
	}

	return cnt;
}
int LineCount(vector<string> &lines)//统计行数
{
	return lines.size();
}
void WordFCount(vector<string> &lines, Word words[500], int &k)//统计单词词频
{

	unsigned int i = 0;
	for (i = 0; i < lines.size(); i++)
	{
		vector<string> t = split(lines[i], "#￥%……&*@ .？！");
		for (unsigned int j = 0; j < t.size(); j++)
		{
			if (exist1(t[j], words, k) == 0)
			{
				words[k].name = t[j];
				words[k].cnt++;
				k++;
			}
		}
	}
}
void ResultOut(Word words[500], int Count_char, int Word_num, int Line_count)
{//输出结果到文本中
	ofstream file1("D:/test/result.txt");
	if (!file1)
		cout << "Open failure!" << endl;
	else
	{
		cout << "characters: " << Count_char << endl;
		cout << "words: " << Word_num << endl;
		cout << "lines: " << Line_count << endl;
		for (int i = 0; i < 10; i++)
		{
			file1 << words[i].name << ' ' << words[i].cnt << endl;
		}
		file1.close();
	}
}
int cmp(Word a, Word b)
{
	return a.cnt > b.cnt;
}
void SortResult(Word words[500], int k) {//结构体排序
	sort(words, words + k, cmp);
}
void  GetFile(vector<string> &lines)//读文件到字符串数组
{
	//int i = 0;
	ifstream file("D:/test/ttt.txt");
	if (!file)
		cout << "Open failure!" << endl;
	else
	{
		string s;
		while (getline(file, s))
		{
			if (s.empty() == 0 && judgeblank(s) == 0)
			{
				lines.push_back(s);

			}
		}
	}
	file.close();
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		cout << lines[i] << ' ';
	}
}
void Lower(vector<string> &str)
{
	for (unsigned int i = 0; i < str.size(); i++) {


		transform(str[i].begin(), str[i].end(), str[i].begin(), ::tolower);
	}
}