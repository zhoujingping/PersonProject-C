
#ifndef PCH_H
#define PCH_H
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<utility>
#include<set>
#include<map>
using namespace std;
const int N = 100007;
#pragma warning(disable:4996)
#define de(x) cout<<#x<<" = "<<x<<endl
#define rep(i,a,b) for(int i=(a);i<(b);++i)
class  QWE_wordCount {
public:
	string line[N];
	string tmp;
	set<pair<int, string> >qur;//利用set排序，单词次数为第一优先级，string字典序为第二优先级
	set<pair<int, string> >::iterator it;
	struct node {
		node *next[36];
		int gs;
	}root;
	int num_line, eft_num, eft_char, eft_word;//num_line 为文件总行数 eft_num为有效行数 eft_char为字符数 eft_word为有效单词数
	int Atoatoint(char c);
	char FAtoatoint(int c);
	void qinsert(string s);
	void MYscanf(char s[]);
	int CountChar();
	bool is_efct_char(char c);
	int CountWord();
	void dfs_getword(node u);
	void CountMxWord();
	void MYprint();
	void init();
};
// TODO: 添加要在此处预编译的标头
#endif //PCH_H#pragma once
