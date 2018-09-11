#include "stdafx.h"
//构造函数，初始化文件类参数
File::File()
{
	charcount = 0;
	line = 0;
	wordscount = 0;
}
//读入文件,统计行数和字符数
void File::Infile(string filename)
{
	ifstream infile(filename, ios::in | ios::_Nocreate);
	if (!infile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	string s;
	while (getline(infile, s))
	{
		charcount += s.length();
		line++;
	}
	charcount += line;
	infile.close();
}

//实现文件单词个数统计，并将所有单词（包括重复）加入一个string的list
void File::Wordscount(string filename)
{
	ifstream infile(filename, ios::in | ios::_Nocreate);
	if (!infile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	smatch m;
	string s, s1;
	regex r("[a-zA-Z]{4}[0-9a-zA-Z]*");
	while (getline(infile, s))
	{
		while (regex_search(s, m, r))
		{
			s1 = m.str();
			transform(s1.begin(), s1.end(), s1.begin(), tolower);
			words.push_back(s1);
			wordscount++;
			s = m.suffix().str();
		}
	}
	infile.close();
}

//将单词的list按字典序排序，整理出单词即其出现的个数放入单词对象，并加入一个新list，之后去除单词list中重复的单词。
void File::Wordsway()
{
	List::iterator i, j;
	if (!words.empty())
	{
		words.sort();
		string s;
		int k;
		for (i = words.begin(); i != words.end(); ++i)
		{
			Word *w = new Word;
			s = *i;
			w->name = s;
			k = 1;
			for (j = ++i; j != words.end(); ++j)
			{
				if (s == *j)
					k++;
				else
					break;
			}
			w->count = k;
			i = --j;
			words_count.push_back(*w);
		}
		words.unique();
	}
	else
		cout << "words list中没元素";
}
//将单词输入文件
void File::Outfile(string filename)
{
	ofstream outfile(filename);
	if (!outfile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	string s;
	List::iterator i;
	if (!words.empty())
	{
		for (i = words.begin(); i != words.end(); ++i)
		{
			s = *i;
			outfile << s << endl;
		}
	}
	else
	{
		cout << "words list中没元素";
	}
	outfile.close();
}
//输出文件即单词的属性
void File::Show()
{
	Wordlist::iterator i;
	cout << "characters:" << charcount << endl;
	cout << "words:" << wordscount << endl;
	cout << "lines" << line << endl;
	words_count.sort();
	if (!words_count.empty())
	{
		words.sort();
		string s;
		int k = 0;
		for (i = words_count.begin(); i != words_count.end(); ++i)
		{
			k++;
			cout << "<" << i->name << ">:" << i->count << endl;
			if (k == 10)
				break;
		}
	}
	else
		cout << "words_count list中没元素";


}
File::~File()
{
}