#include<iostream>
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
		}
		void print(char * outFilename);
		void splitAndcount(string line);
		int char_num;
		int line_num;
		
	private:
		map<string,int> dic;   //<word, frequency>	
};

bool cmp(const pair<string,int>& a,const pair<string,int>& b) 
{
	if(a.second!=b.second)  
		return a.second>b.second;
	else if(a.first!=b.first) 
		return a.first<b.first;
}

void counter::splitAndcount(string line)
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
			// handle characters before a word
			while(i<line.length() && !isalpha(line[i]))
			{
				if(isdigit(line[i]))  // handle 123file
				{
					while(isalnum(line[i]) && i<line.length())
					{
						char_num++;
						i++;
					}
				}
				if(i!=line.length() && line[i]>=0)
				{
					char_num++; 
				}
				i++;
			}
			// handle a word
			string tempWord;
			while(i<line.length())
			{
				if(line[i]>0)
					char_num++;
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
//				else
//				{
//					printf("sth you didnt consider\n");
//				}
				i++;
			}
		}
	}
}

void counter::print(char * outFilename)
{
	/*
	ofstream outFile(outFilename,ios::out);
	outFile<<"characters: "<<char_num<<endl;
	outFile<<"words: "<<dic.size()<<endl;
	outFile<<"lines: "<<line_num<<endl;
	
	
	vector<pair<string,int> > tempVec(dic.begin(),dic.end());
	sort(tempVec.begin(),tempVec.end(),cmp);
		
	vector<pair<string,int> >::iterator iter;
	for(int i=0;i<tempVec.size();i++)  
        outFile<<"<"<<tempVec[i].first<<">"<<": "<<tempVec[i].second<<endl;  
	
	outFile.close();*/
	
	
	cout<<"characters: "<<char_num<<endl;
	cout<<"words: "<<dic.size()<<endl;
	cout<<"lines: "<<line_num<<endl;
	
	vector<pair<string,int> > tempVec(dic.begin(),dic.end());
	sort(tempVec.begin(),tempVec.end(),cmp);
		
	for(int i=0;i<tempVec.size();i++)  
        cout<<"<"<<tempVec[i].first<<">"<<": "<<tempVec[i].second<<endl;  
}

int main(int argc, char *argv[])
{
	counter *myCounter=new counter;
	
	ifstream inFile("input.txt",ios::in);
	//ifstream inFile(argv[0],ios::in);
	
	while(inFile)
	{
		string line;
		getline(inFile,line);
		if(inFile.fail() && line=="") 
            break;
        if(!inFile.eof())
			line+='\n';
		myCounter->splitAndcount(line);
	}
	inFile.close();
	
	char outFilename[]="result.txt";
	myCounter->print(outFilename);
	
	delete myCounter;
	return 0;
} 
