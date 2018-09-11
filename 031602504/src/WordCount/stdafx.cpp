#include "pch.h"
#include"stdafx.h"
#include<map>
#include<iostream>

using namespace std;
struct word_frequency {
	string word;
	int count;
};

CountMeths::CountMeths(string name)
{
	strcpy_s(filename,name.size()+1,name.c_str());
	FILE* filein;
	int err;
	err = fopen_s(&filein, filename, "r");
	if (err)
	{
		printf("open erro!Check Yur File Exist\n");
	}
	fclose(filein);
}
int CountMeths::CountCharacters()
{
	FILE *filein;
	int err, characternum;
	characternum = 0;
	err = fopen_s(&filein, filename, "r");
	if (err)
	{
		printf("erro!\n");
		return 0;
	}
	char onechar;
	err = fread(&onechar, sizeof(char), 1, filein);
	while (err)
	{
		if (onechar <= 127 && onechar >= 0)
		{
			characternum++;
		}
		err = fread(&onechar, sizeof(char), 1, filein);
	}
	fclose(filein);
	return characternum;
}
bool CountMeths::IsWord(char *word)
{
	if (strlen(word) < 4)
	{
		return false;
	}
	if (word[0] >= 97 && word[0] <= 122 && word[1] >= 97 && word[1] <= 122
		&& word[2] >= 97 && word[2] <= 122 && word[3] >= 97 && word[3] <= 122)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int CountMeths::CountWords()
{
	int wordnum = 0;
	FILE* filein;
	int err;
	err = fopen_s(&filein, filename, "r");
	if (err)
	{
		printf("erro!\n");
		return 0;
	}
	char *word = (char*)malloc(1000); memset(word, '\0', 1000);
	char onechar;
	char temp[2];
	err = fread(&onechar, sizeof(char), 1, filein);
	while (err)
	{
		if ((onechar >= 48 && onechar <= 57) || (onechar >= 65 && onechar <= 90) || (onechar >= 97 && onechar <= 122))
		{
			if (onechar >= 65 && onechar <= 90)
			{
				onechar += 32;
			}
			memset(temp, '\0', sizeof(char) * 2); temp[0] = onechar;
			strcat_s(word, strlen(word) + strlen(temp) + 1, temp);
		}
		else
		{
			if (IsWord(word))
			{
				wordnum++;
			}
			memset((void*)word, '\0', sizeof(char) * 1000);
		}
		err = fread(&onechar, sizeof(char), 1, filein);
	}
	//判断最后一个单词是否为单词；
	if (IsWord(word))
	{
		wordnum++;
	}
	memset((void*)word, '\0', sizeof(char) * 1000);


	fclose(filein);
	free(word);
	return wordnum;
}
bool CountMeths::IsValid(char *oneline)
{
	int i = 0, len = strlen(oneline);
	for (i = 0; i < len; i++)
	{
		if (oneline[i] >= 33)
		{
			return true;
		}
	}
	return false;
}
int CountMeths::ValidLines()
{
	int validnum = 0;
	FILE *filein;
	int err;
	err = fopen_s(&filein, filename, "r");
	if (err)
	{
		printf("open erro!\n");
	}
	char oneline[1000];

	while (fgets(oneline, 1000, filein))
	{
		if (IsValid(oneline))
		{
			validnum++;
		}
		memset(oneline, '\0', 1000);
	}
	fclose(filein);
	return validnum;
}
void CountMeths::PrintTenWords()
{
	word_frequency maxten[10];
	map<string, int>dict;
	FILE* filein;
	int err;
	err = fopen_s(&filein, filename, "r");
	if (err)
	{
		printf("open erro!\n");
	}
	char *word = (char*)malloc(1000); memset(word, '\0', 1000);
	char onechar;
	char temp[2];
	err = fread(&onechar, sizeof(char), 1, filein);
	while (err)
	{
		if ((onechar >= 48 && onechar <= 57) || (onechar >= 65 && onechar <= 90) || (onechar >= 97 && onechar <= 122))
		{
			if (onechar >= 65 && onechar <= 90)
			{
				onechar += 32;
			}
			memset(temp, '\0', sizeof(char) * 2); temp[0] = onechar;
			strcat_s(word, strlen(word) + strlen(temp) + 1, temp);
		}
		else
		{
			if (IsWord(word))
			{
				if (!dict[word])
				{
					dict[word] = 1;
				}
				else
				{
					dict[word] += 1;
				}
			}
			memset((void*)word, '\0', sizeof(char) * 1000);
		}
		err = fread(&onechar, sizeof(char), 1, filein);
	}
	//判断最后一个单词是否为单词；
	if (IsWord(word))
	{
		if (!dict[word])
		{
			dict[word] = 1;
		}
		else
		{
			dict[word] += 1;
		}
	}
	memset((void*)word, '\0', sizeof(char) * 1000);
	fclose(filein);
	map <string, int>::iterator dict_Iter;
	map <string, int>::iterator dict_Iter2;
	int i;

	for (i = 0; i < 10; i++)
	{
		dict_Iter2 = dict.begin();
		for (dict_Iter = dict.begin(); dict_Iter != dict.end(); dict_Iter++)
		{
			if (dict_Iter2->second < dict_Iter->second)
			{
				dict_Iter2 = dict_Iter;
			}
		}

		maxten[i].word = dict_Iter2->first;
		maxten[i].count = dict_Iter2->second;
		dict[dict_Iter2->first] = 0;

		if (maxten[i].count)
		{
			printf("<%s>: %d\n", maxten[i].word.c_str(), maxten[i].count);
		}
	}
}
void CountMeths::ChangeFiles(string name)
{
	memset(filename,'\0',sizeof(char)*100);
	strcpy_s(filename, name.size() + 1, name.c_str());
	FILE* filein;
	int err;
	err = fopen_s(&filein, filename, "r");
	if (err)
	{
		printf("open erro!Check Yur File Exist\n");
	}
	fclose(filein);
}
void CountMeths::ResultFile(string name)
{
	int r_characters = this->CountCharacters();
	int r_caildlines = this->ValidLines();
	int r_words = this->CountWords();
	char firstpart[100]; memset(firstpart,'\0',100);
	char secondpart[100]; memset(secondpart,'\0',100);
	sprintf_s(firstpart,50,"characters: %d\nwords: %d\nlines: %d\n",r_characters,r_words,r_caildlines);
	char outfilename[100];
	strcpy_s(outfilename, name.size() + 1, name.c_str());
	FILE* fileout;
	int err;
	err = fopen_s(&fileout, outfilename, "w");
	if (err)
	{
		printf("erro! \n");
	}
	fwrite(firstpart,sizeof(char)*strlen(firstpart),1,fileout);
	fclose(fileout);
	//词频统计部分代码
	word_frequency maxten[10];
	map<string, int>dict;
	FILE* filein;
	err = fopen_s(&filein, filename, "r");
	if (err)
	{
		printf("erro!\n");
	}
	char *word = (char*)malloc(1000); memset(word, '\0', 1000);
	char onechar;
	char temp[2];
	err = fread(&onechar, sizeof(char), 1, filein);
	while (err)
	{
		if ((onechar >= 48 && onechar <= 57) || (onechar >= 65 && onechar <= 90) || (onechar >= 97 && onechar <= 122))
		{
			if (onechar >= 65 && onechar <= 90)
			{
				onechar += 32;
			}
			memset(temp, '\0', sizeof(char) * 2); temp[0] = onechar;
			strcat_s(word, strlen(word) + strlen(temp) + 1, temp);
		}
		else
		{
			if (IsWord(word))
			{
				if (!dict[word])
				{
					dict[word] = 1;
				}
				else
				{
					dict[word] += 1;
				}
			}
			memset((void*)word, '\0', sizeof(char) * 1000);
		}
		err = fread(&onechar, sizeof(char), 1, filein);
	}
	//判断最后一个单词是否为单词；
	if (IsWord(word))
	{
		if (!dict[word])
		{
			dict[word] = 1;
		}
		else
		{
			dict[word] += 1;
		}
	}
	memset((void*)word, '\0', sizeof(char) * 1000);
	fclose(filein);

	//写入词频部分
	err = fopen_s(&fileout, outfilename, "a+");
	if (err)
	{
		printf("erro! \n");
	}
	map <string, int>::iterator dict_Iter;
	map <string, int>::iterator dict_Iter2;
	int i;
	for (i = 0; i < 10; i++)
	{
		dict_Iter2 = dict.begin();
		for (dict_Iter = dict.begin(); dict_Iter != dict.end(); dict_Iter++)
		{
			if (dict_Iter2->second < dict_Iter->second)
			{
				dict_Iter2 = dict_Iter;
			}
		}

		maxten[i].word = dict_Iter2->first;
		maxten[i].count = dict_Iter2->second;
		dict[dict_Iter2->first] = 0;

		if (maxten[i].count)
		{
			sprintf_s(secondpart, 100, "<%s>: %d\n",maxten[i].word.c_str(),maxten[i].count);
			fwrite(secondpart, sizeof(char)*strlen(secondpart), 1, fileout);
			memset(secondpart, '\0', 100);
		}
	}
	printf("success!");
	fclose(fileout);
}