#include "Tool.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>

using namespace std;


//读取txt中的字符串，并将大写字母转化为小写。
string Tool::GetString(ifstream& txt)
{
	if (txt.is_open() == 0)
	{
		return string();
	}
	char c;
	string s;
	while ((c = txt.get()) != EOF)
	{
		if (c >= 'A' && c <= 'Z')
		{
			c = c + 32;
		}
		s.append(1, c);
	}
	return s;
}

int Tool::min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//统计行数；
int Tool::GetLines(string s)
{
	int i = 0;
	int line = 0;
	for (i = 0; i < s.length(); i++)
	{
		if (s[i] == '\n' || (i==(int)s.length()-1 && s[i] == '\n'))
		{
			line++;
		}
	}
	return line;
}

map<string,int> Tool::countWords(string s)
{
	int flag = 1;
	int i,j=0;
	string temp;
	map<string, int> mp;
	for (i = 0; i < s.length(); i++)
	{
		
		if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) ||(s[i] >= '0' && s[i] <= '9'))
		{
			for (j = i; ; j++)
			{
				
				if (j > s.length()-1 || !((s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122) || (s[j]>='0' && s[j]<='9')))
				{
					i = j;
					break;
				}
				temp = temp + s[j];
			}
			if (temp.length() >= 4)
			{
				cout << temp <<endl;
				for (int t = 0; t < 4; t++)
				{
					if (!((temp[t] >= 65 && temp[t] <= 90) || (temp[t] >= 97 && temp[t] <= 122)))
					{
						flag = 0;
						break;
					}
					else
					{
						flag = 1;
					}
				}
				if (flag == 1)
				{
					mp[temp]++;
					
				}
				flag = 1;
				
			}
			temp.clear();
			continue;
		}
	}
	return mp;
}

bool cmp(pair<int, string> a, pair<int, string> b)

{

	if (a.first != b.first)return a.first > b.first;

	return a.second < b.second;

}

vector<pair<int, string> > Tool::GetSort(map<string, int> mp)
{
	map<string, int>::iterator it;
	vector<pair<int, string> > ve;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		ve.push_back(make_pair(it->second, it->first));
	}
	sort(ve.begin(), ve.end(), cmp);
	return ve;
}

int Tool::Count(map<string, int> mp)
{
	map<string, int>::iterator it;
	int num = 0;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		num = num + it->second;
	}
	return num;
}