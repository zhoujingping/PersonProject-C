#include "FileTools.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
	if (a.first != b.first)return a.first > b.first;
	return a.second < b.second;
}

FileTools::FileTools()
{
}

pair<int, int> FileTools::countLine(string s)
{
	bool emp = true;
	int line = 0;
	int eline = 0;
	for (int i = 0; i <(int) s.length(); i++)
	{
		if (s[i] == '\n')
		{
			if (emp)
			{
				eline++;
			}
			else
			{
				line++;
			}
			emp = true;
		}
		else
		{
			emp = false;
		}
	}
	return pair<int, int>(line,eline);
}



string FileTools::getString(ifstream& in)
{

	if (!in.is_open())
	{
		return string();
	}
	char ch;
	string s;
	while ((ch = in.get()) != EOF)
	{
		if (ch >= 0 && ch <= 127)
		{
			s.append(1, ch);
		}
		
	}
	return s;
}

bool FileTools::isLetter(char ch)
{
	if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z'))return true;
	return false;
}

bool FileTools::isDigit(char ch)
{
	if (ch >= '0'&&ch <= '9')return true;
	return false;
}

vector<pair<int,string> > FileTools::getSort(map<string, int> mp)
{
	map<string, int>::iterator it;
	vector<pair<int, string> > ve;
	for (it=mp.begin(); it!=mp.end(); it++)
	{
		ve.push_back(make_pair(it->second,it->first));
	}
	sort(ve.begin(), ve.end(),cmp);
	return ve;
}

map<string, int> FileTools::countWord(string s)
{
	map<string, int> mp;
	string temp;
	for (int i = 0; i < (int)s.length()-3; i++)
	{
		temp.clear();
		bool is=true;
		for(int j=0;j<4;j++)
		{
			if (!isLetter(s.at(i + j))) 
			{
				is = false;
				break;
			}
		}
		if (is)
		{
			for (int j = 0; j < 4; j++)
			{
				if (s[i + j] >= 'A'&&s[i+j]<='Z')
				{
					s[i + j] += ('a' - 'A');
				}
				temp.append(1,s.at(i+j));
			}
			i = i + 4;
			while (i<(int)s.length()&&(isdigit(s.at(i)) || isLetter(s.at(i))))
			{
				if (s[i] >= 'A'&&s[i]<'Z')
				{
					s[i] -=  ('A' - 'a');
				}
				temp.append(1,s.at(i));
				i++;
			}
			i--;
			mp[temp]++;
		}
	}
	return mp;
}

FileTools::~FileTools()
{
}