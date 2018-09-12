#include"frequent_words_count.h"
#include <string>
#include<map>
#include<vector>
#include<regex>
#include<fstream>




bool wordsort(pair<string, int>k1, pair<string, int> k2)
{
	return k1.second > k2.second;
}
void frequent_words(string txt)//求出频繁出现的十个单词
{
	unsigned int i;
	map<string, int>m;
	string content, add;
	ifstream file(txt);
	regex wordtemplate("^[a-zA-Z]{4}[a-zA-Z0-9]*");//要求单词的正则式
	while (file >> content)
	{
		for (i = 0; i < content.length(); i++)//将大写换成小写
		{
			if ('A' <= content[i] && content[i] <= 'Z')
			{
				content[i] = content[i] + 32;
			}
		}
		const std::sregex_token_iterator  end;
		for (sregex_token_iterator wordIter(content.begin(), content.end(), wordtemplate); wordIter != end; wordIter++)
		{
			m[*wordIter]++;//统计每个单词的个数；
		}
	}
	file.clear();
	file.seekg(0);
	vector <pair<string, int>> v;
	for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
	{
		v.push_back(pair<string, int>(iter->first, iter->second));
	}
	sort(v.begin(), v.end(), wordsort);
	int length = 10;
	if (v.size() < 10)
	{
		length = v.size();
	}
	vector<pair<string, int>>::iterator mm;
	ofstream out("result.txt", ios::in | ios::out);
	for (mm = v.begin(); mm != v.begin() + length; mm++)
	{
		out.seekp(0, ios::end);
		out << "<" << mm->first << ">" << mm->second << endl;
	}
	out.clear();
	
}

