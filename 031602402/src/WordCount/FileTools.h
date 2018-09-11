#pragma once
#include<map>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
class FileTools
{
	
public:
	FileTools();
	static pair<int,int> countLine(string s);
	static string getString(ifstream& in);
	static bool isLetter(char ch);
	static bool isDigit(char ch);
	static vector<pair<int,string> > getSort(map<string, int> mp);
	static map<string, int> countWord(string s);
	~FileTools();
};

