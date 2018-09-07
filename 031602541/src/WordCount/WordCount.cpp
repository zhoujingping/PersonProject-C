/*
* wordcount 031602541
* 2018-09-07 trial
* 14-16
*/
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
//#define DBUG
using namespace std;

typedef struct _wcn
{
	string w;
	long c;
}wcn;

string text;
string tline;
map <string, long> wc;
vector <wcn> v1;

bool cmp(const wcn &w1, const wcn &w2)
{
	return w1.c > w2.c;
}

int main(int argc, char* argv[])
{
	long characters = 0;
	long words = 0;
	long lines = 0;
	int i;
	stringstream ssword;
	string wt;
	map <string, long>::iterator it;
	vector <wcn>::iterator is;
	if (argc < 2)
	{
		cout << "no filename\n";
		return 0;
	}
	text.clear();
	ifstream infile(argv[1]);
	ofstream oufile;

	//read file 
	while (getline(infile, text))
	{
		++lines;
		text.append(tline);
		//TOLOWER
		transform(text.begin(), text.end(), text.begin(), ::tolower);
#ifdef DBUG
		cout << "line " << lines << endl;
		cout << text << endl;
#endif
		characters += text.length();
		++characters; // CR/LF
		for (i = 0; i < text.length(); ++i)
		{
			if (ispunct(text[i])) text[i] = ' ';
		}
		ssword.clear();
		ssword.str(text);
		while (ssword >> wt)
		{
			//condition : 
			if (wt.length() >= 4 && !isdigit(wt[0]) && !isdigit(wt[1]) && !isdigit(wt[2]) && !isdigit(wt[3]))
			{
#ifdef DBUG
				cout << wt << "\n";
#endif
				++words;
				++wc[wt];
			}
		}
		tline.clear();
	}

	infile.close();

	oufile.open("result.txt", ios::out);

	oufile << "characters: " << characters - 1 << endl;
	oufile << "words: " << words << endl;
	oufile << "lines: " << lines << endl;


	it = wc.begin();
	wcn a;
	while (it != wc.end())
	{
		//cout << it->first << ": "<< it->second << endl;
		a.w = it->first;
		a.c = it->second;
		v1.push_back(a);
		++it;
	}
	stable_sort(v1.begin(), v1.end(), cmp);
	is = v1.begin();
	int p = 0;
	while (p < 10 && is != v1.end())
	{
		oufile << '<' << is->w << ">: " << is->c << endl;
		++is;
		++p;
	}

	/* OUTPUT RESULT
	* output format:
	* characters: x
	* lines: x
	* <word>.....
	*/
	//test output


	return 0;
}