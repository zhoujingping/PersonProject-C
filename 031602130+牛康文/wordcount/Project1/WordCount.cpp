#include "pch.h"
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<utility>
#include<set>
#include<map>
#pragma warning(disable:4996)
using namespace std;
#define de(x) cout<<#x<<" = "<<x<<endl
#define rep(i,a,b) for(int i=(a);i<(b);++i)
int main(int argc, char *argv[])
{
	QWE_wordCount *A = new  QWE_wordCount();
	A->init();
	A->MYscanf(argv[1]);
	A->eft_char = A->CountChar();
	A->eft_word = A->CountWord();
	A->CountMxWord();
	A->MYprint();
	return 0;
}