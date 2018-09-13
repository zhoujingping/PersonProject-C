#include<iostream>
#include<fstream>
#include<string>
#include"FileTools.h"
using namespace std;
int min(int a, int b)
{
	if (a < b)return a;
	else return b;
}
int main(int argc, char* argv[])
{
	if (argc == 0)
	{
		cout << "System Error!" << endl;
	}
	else if (argc == 1)
	{
		cout << "do nothing" << endl;
	}
	else if (argc == 2)
	{
		ifstream in;
		in.open(argv[1]);
		
		if (in.is_open())
		{
			
			string s = FileTools::getString(in);
			ofstream out;
			out.open("result.txt");
			if (!out.is_open())
			{
				cout << "output open failed" << endl;
				return -1;
			}
			out << "characters:" << s.length() << endl;
			map<string, int> mp = FileTools::countWord(s);
			pair<int, int> p = FileTools::countLine(s);
			vector<pair<int,string> > v = FileTools::getSort(mp);
			out << "words:" << FileTools::count(mp)<< endl;
			out << "lines:" << p.first<<endl;
			for (int i = 0; i < min(v.size(),10); i++)
			{
				out << "<" << v[i].second << ">:" << v[i].first << endl;
			}
		}
		else
		{
			cout << "input open fail" << endl;
		}
		
	}
	else
	{
		cout << "do nothing" << endl;
	}
	//system("pause");
	return 0;
}