#include"linecount.h"
#include<string>
#include<fstream>
int lines_number(string txt)//统计文件有效行数
{
	unsigned int  i;
	int count = 0;
	string content;
	ifstream file(txt);

	while (getline(file, content))//直到文件结尾，依次逐行读入文本
	{

		for (i = 0; i < content.length(); i++)
		{
			if (content[i] != '\n'&& content[i] != '\t' && content[i] != ' '&&content[i] != '\r')
			{
				count++;
				break;
			}
		}
	}
	
	file.clear();
	file.seekg(0);
	return count;
	
}