#pragma once

#include<iostream>
using namespace std;

class CountMeths
{
	
	private:
		char filename[100];
		bool IsWord(char *word);
		bool IsValid(char *oneline);
	public:
		CountMeths(string name);
		~CountMeths() {};
		int CountCharacters();
		int CountWords();
		int ValidLines();
		void PrintTenWords();
		void ChangeFiles(string name);
		void ResultFile(string name);
};


