#pragma once

#define DLL_API __declspec(dllexport)

#include<iostream>
#include<fstream>
#include<cassert>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int Char = 0, Word = 0, Line = 0;

DLL_API int charCount(string fname);

DLL_API int wordCount(string fname);

DLL_API void wordSeq(string fname, pair<string, int> str_cnt[]);

bool isWord(string w);
int cmp(const pair<string, int> &x, const pair<string, int> &y);