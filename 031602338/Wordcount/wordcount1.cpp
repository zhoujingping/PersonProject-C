#include"wordcount1.h"
#include<string>
#include<regex>
#include<map>
#include<fstream>
int words_number(string txt)//统计文件的单词总数
{
	 int count=0;
	map<string, int>m;
	string content;
	ifstream file(txt);
	regex wordtemplate("^[a-zA-Z]{4}[a-zA-Z0-9]*");//要求单词的正则式
	while (file >> content)
	{

		const std::sregex_token_iterator  end;
		for (sregex_token_iterator wordIter(content.begin(), content.end(), wordtemplate); wordIter != end; wordIter++)
		{
			m[*wordIter]++;//统计每个单词的个数；
		}
		
	}
	map<string, int>::const_iterator pp;

	for (pp = m.begin(); pp != m.end(); pp++)
	{
		count=count+pp->second;
	}
	
	file.clear();
	file.seekg(0);
	return count;

	
}
