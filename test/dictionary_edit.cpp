#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<fstream>
#include <cctype>
#include<map> 
#include <algorithm>
using namespace std;

class counter{
	public:
		counter(){
			char_num=0;
			line_num=0;
			word_num=0;///////////////////////
		}
		/////////////////////////////
		void initInFilename(char tempName[]); 
		void countPerLine(string line);
		void countCharLine();
		
		void splitPerLine(string line);
		void initDic();
		void countWord();
		
		void frequency();
		
		int word_num;
		char * inFilename;
		////////////////////////////
		void print(char * outFilename);
		void splitAndcount(string line);
		int char_num;
		int line_num;
		
	private:
		map<string,int> dic;   //<word, frequency>
		vector<pair<string,int> > sortedDic; ////////////////////////////
};

void counter::initInFilename(char tempName[])
{
	inFilename=(char*)malloc(strlen(tempName)*sizeof(char));
	strcpy(inFilename,tempName);
}

void counter::countPerLine(string line)
{
	int i=0;
	// empty line
	while(i<line.length() && isspace(line[i]) ) 
	{
		char_num++;
		i++;
	}
	if(i!=line.length())
	{
		line_num++; 
		while(i<line.length())
		{	
			if(line[i]>0)
				char_num++;
			i++;
		}
	}
}

void counter::countCharLine()
{
	ifstream inFile(inFilename,ios::in);
	if(inFile.fail())cout<<"damn";
	while(inFile)
	{
		string line;
		getline(inFile,line);
		if(inFile.fail() && line=="") 
            break;
        if(!inFile.eof())
			line+='\n';
		countPerLine(line);
	}
	inFile.close();
}

void counter::splitPerLine(string line)
{
	int i=0;
	while(i<line.length())
	{	
		// handle characters before a word
		while(i<line.length() && !isalpha(line[i]))
		{
			if(isdigit(line[i]))  // handle 123file
			{
				while(isalnum(line[i]) && i<line.length())
				{
					i++;
				}
			}
			i++;
		}
		// handle a word
		string tempWord;
		while(i<line.length())
		{
			if(isalpha(line[i]))
			{
				tempWord+=tolower(line[i]);
			}
			if(isdigit(line[i]))
			{
				if(tempWord.length()<4)
				{
					i++;
					break;	
				}
				else
				{
					tempWord+=line[i];
				}
			}
			if(!isalnum(line[i]) || i==line.length()-1)
			{
				if(tempWord.length()>=4)
				{
					map<string,int>::iterator iter;
    				iter=dic.find(tempWord);  
    				if(iter!=dic.end())  
						iter->second++;
					else
						dic.insert(pair<string,int>(tempWord,1));
				}
				i++;
				break;
			}
			i++;
		}
	}
}

void counter::initDic()
{
	ifstream inFile(inFilename,ios::in);
	while(inFile)
	{
		string line;
		getline(inFile,line);
		if(inFile.fail() && line=="") 
            break;
		splitPerLine(line);
	}
	inFile.close();
}

void counter::countWord()
{
	initDic();
	word_num=dic.size();
}

bool cmp(const pair<string,int>& a,const pair<string,int>& b) 
{
	if(a.second!=b.second)  
		return a.second>b.second;
	else if(a.first!=b.first) 
		return a.first<b.first;
}

void counter::frequency()
{
	sortedDic.assign(dic.begin(),dic.end());
	sort(sortedDic.begin(),sortedDic.end(),cmp);
}

/////////////////////////////////////////////

//bool cmp(const pair<string,int>& a,const pair<string,int>& b) 
//{
//	if(a.second!=b.second)  
//		return a.second>b.second;
//	else if(a.first!=b.first) 
//		return a.first<b.first;
//}

void counter::print(char * outFilename)   /////////////////////////
{
	/*
	ofstream outFile(outFilename,ios::out);
	outFile<<"characters: "<<char_num<<endl;
	outFile<<"words: "<<word_num<<endl;
	outFile<<"lines: "<<line_num<<endl;
	
	for(int i=0;i<sortedDic.size();i++)  
        outFile<<"<"<<sortedDic[i].first<<">"<<": "<<sortedDic[i].second<<endl;  
	
	outFile.close();*/
	
	
	cout<<"characters: "<<char_num<<endl;
	cout<<"words: "<<word_num<<endl;
	cout<<"lines: "<<line_num<<endl;
		
	for(int i=0;i<sortedDic.size();i++)  
        cout<<"<"<<sortedDic[i].first<<">"<<": "<<sortedDic[i].second<<endl;  
}

int main(int argc, char *argv[])
{
	counter *myCounter=new counter;
//	cout<<__LINE__<<endl;
	//myCounter->initInFile(argv[0]);
	char tempName[]="input.txt";
//	cout<<__LINE__<<endl;
	myCounter->initInFilename(tempName);
//	cout<<__LINE__<<endl;
	myCounter->countCharLine();
//	cout<<__LINE__<<endl;
	myCounter->countWord();
//	cout<<__LINE__<<endl;
	myCounter->frequency();
//	cout<<__LINE__<<endl;
	
	char outFilename[]="result.txt";
	myCounter->print(outFilename);
	
	delete myCounter;
	return 0;
}
