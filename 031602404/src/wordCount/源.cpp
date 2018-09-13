#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cctype>
#include<regex>
#include<io.h>
#include<unordered_map>
#include<iterator>
#include "Դ.h"
#include"Tool.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		ifstream test;
		test.open(argv[1]);
		if (test.is_open())
		{
			string s = Tool::GetString(test);
			ofstream out;
			out.open("result.txt");
			if (!out.is_open())
			{
				cout << "The result.txt can't open" << endl;
			}
			else
			{
				out << "characters:" << s.length() << endl;
				map<string, int> mp = Tool::countWords(s);
				int lines = Tool::GetLines(s);
				vector<pair<int, string> > v= Tool::GetSort(mp);
				out << "words:" << Tool::Count(mp) << endl;
				out << "lines:" << lines << endl;
				for (int i = 0; i < Tool::min(v.size(), 10); i++)
				{
					out << "<" << v[i].second << ">:" << v[i].first << endl;
				}
			}
			
		}
		else
		{
			
		}
	}
	else 
	{
		cout << "Please input the correct filename!" << endl;
	}
}