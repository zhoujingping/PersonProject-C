#pragma once
#include<iostream>
#include<fstream>
#include <vector> 
#include<string>
#include <algorithm>

using namespace std;
struct Word {
	string name;
	int cnt=0;
};//存储单词名和个数



//用容器实现分割字符串  
vector<string> split(const string &s, const string &seperator) {//s为待处理的字符串，t中存放分隔符
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
int IsEn(char t) {

	if ((t <= 'Z'&&'A' <= t) || (t <= 'z'&&'a' <= t))
		return 1;
	return  0;
}
int IsWord(string x)
{
	


	if (x.size() >= 4 && IsEn(x[0])&& IsEn(x[1])&& IsEn(x[2])&& IsEn(x[3]))
		return 1;
	return 0;
}
int exist1(string x, vector<Word> &words )//判断单词是否已经存在
{
	for (int i = 0; i < words.size(); i++)
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
int  CountChar(char *filename) {//统计字符串
	ifstream file(filename);
	int cnt = 0;
	char t;
	if (!file)
	{
		cout << "Open Failure!" << endl;

	}
	else
	{
		
		while (file.get(t))
		{
			
			//cout << (int)t<<endl;
			
			cnt++;
			
		}
	}
	file.close();
	return cnt;
}
int LineCount(char *filename, vector<string> &lines)//统计行数
{
	ifstream file(filename);
	if (!file)
		cout << "Open failure!LineCount" << endl;
	else {


		string s;
		while (getline(file, s))
		{
			if (s.empty() == 0&& judgeblank(s)==0)
			{
				lines.push_back(s);

			}
		}
	}
	file.close();
	return lines.size();
}
int WordNumber(char *filename)//统计单词数
{
	string sign = "#￥%……&*@ .？!\\|`~^()-_=+{}[],<>/";
	vector<string> lines;
	int line = LineCount(filename, lines);
	ifstream file(filename);
	if (!file)
		cout << "Open failure!WordNumber" << endl;
	int cnt = 0;
	for (int unsigned i = 0; i < lines.size(); i++)//size()为无符号
	{
		vector<string> t;
		t = split(lines[i], sign);
		for (unsigned int i = 0; i < t.size(); i++)
		{
			if (IsWord(t[i])==1)
				cnt++;
		}

	}
	file.close();
	return cnt;
}

void Lower(vector<string> &str)
{
	for (unsigned int i = 0; i < str.size(); i++) {


		transform(str[i].begin(), str[i].end(), str[i].begin(), ::tolower);
	}
}
void WordFCount(char *filename, vector<Word> &words)//统计单词词频
{
	string sign = "#￥%……&*@ .？!\\|`~^()-_=+{}[],<>/";
	vector<string> lines;
	int line = LineCount(filename, lines);
	ifstream file(filename);
	if (!file)
		cout << "Open failure!WordFCount" << endl;
	Lower(lines);
	unsigned int i = 0;
	for (i = 0; i < lines.size(); i++)
	{
		vector<string> t = split(lines[i], sign);
		for (unsigned int j = 0; j < t.size(); j++)
		{
			if (IsWord(t[j]) == 1) {
				Word x;
				x.name = t[j];
				x.cnt++;
				if (exist1(x.name,words) == 0)
				{
					words.push_back(x);
					
				}
			}
		}
	}
	file.close();
}
void ResultOut(vector<Word> &words, int Count_char, int Word_num, int Line_count)
{//输出结果到文本中
	ofstream file1("result.txt");
	//char name[80] = "D:/SE/PersonProject-C/051604103+陈思孝/WordCount/Debug/result.txt";
	//ofstream file1(name);
	if (!file1)
		cout << "Open failure!ResultOut" << endl;
	else
	{
		file1 << "characters: " << Count_char << endl;
		file1 << "words: " << Word_num << endl;
		file1 << "lines: " << Line_count << endl;
		for (int i = 0; i < 10&&i!=words.size(); i++)
		{//cout << words[i].name << ' ' << words[i].cnt << endl;
			file1 <<'<'<< words[i].name <<'>'<< ": " << words[i].cnt << endl;
		}
		file1.close();
		cout << "Out Success!" << endl;
	}
}
int cmp(Word a, Word b)
{   if(a.cnt!=b.cnt)
	return a.cnt > b.cnt;
    else
    return a.name < b.name;
}
void SortResult(vector<Word> &words) {//vector排序
	sort(words.begin(),words.end(), cmp);
}

