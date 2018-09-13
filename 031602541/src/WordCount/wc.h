//wc.h

#ifndef __WC__
#define __WC__

#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

long cchar(string filename)
{
	long cc = 0;
	fstream fcc(filename.c_str(), ios::in);
	char c;
	try
	{
		while (fcc.get(c))
		{
			++cc;
		}
	}
	catch (exception & e)
	{
		cout << "Error processing file when counting characters.\n";
		cout << e.what() << endl;
	}
	fcc.close();
	return cc;
}

long cword(string filename)
{
	long cw = 0;
	stringstream ssword;
	string wt;
	string text;
	ifstream infile(filename.c_str());
	int i;
	try
	{
		while (getline(infile, text))
		{
			for (i = 0; i < text.length(); ++i)
			{
				if (ispunct(text[i])) text[i] = ' ';
			}
			ssword.clear();
			ssword.str(text);
			while (ssword >> wt)
			{
				if (wt.length() >= 4 && !isdigit(wt[0]) && !isdigit(wt[1]) && !isdigit(wt[2]) && !isdigit(wt[3]))
				{
					++cw;
				}
			}
		}
	}
	catch (exception & e)
	{
		cout << "Error processing file when counting words.\n";
		cout << e.what() << endl;
	}
	infile.close();
	return cw;
}

typedef struct _wcn
{
	string w;
	long c;
}wcn;

bool cmp(const wcn &w1, const wcn &w2)
{
	return w1.c > w2.c;
}

vector<wcn> c10(string filename)
{
	string text;
	string res;
	string wt;
	res.clear();
	stringstream ssword;
	map <string, long> wc;
	vector <wcn> v1;
	vector <wcn> rep;
	map <string, long>::iterator it;
	vector <wcn>::iterator is;
	ifstream infile(filename.c_str());
	int i;
	try
	{
		while (getline(infile, text))
		{
			transform(text.begin(), text.end(), text.begin(), ::tolower);
			for (i = 0; i < text.length(); ++i)
			{
				if (ispunct(text[i])) text[i] = ' ';
			}
			ssword.clear();
			ssword.str(text);
			while (ssword >> wt)
			{
				if (wt.length() >= 4 && !isdigit(wt[0]) && !isdigit(wt[1]) && !isdigit(wt[2]) && !isdigit(wt[3]))
				{
					++wc[wt];
				}
			}
		}
		it = wc.begin();
		wcn a;
		while (it != wc.end())
		{
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
			a.w = is->w;
			a.c = is->c;
			rep.push_back(a);
			++is;
			++p;
		}
	}
	catch (exception & e)
	{
		cout << "Error processing file when calculating word frequency.\n";
		cout << e.what() << endl;
	}

	infile.close();
	return rep;
}

#endif