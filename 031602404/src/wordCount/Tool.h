#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;



class Tool
{
public:
	Tool();
	static string GetString(ifstream& txt);
	static int GetLines(string s);
	static map<string,int> countWords(string s);
	static vector<pair<int, string> > GetSort(map<string, int> mp);
	static int Count(map<string, int> mp);
	static int min(int a, int b);
	~Tool();

private:

};

