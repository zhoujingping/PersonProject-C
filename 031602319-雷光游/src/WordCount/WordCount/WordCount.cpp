#include "stdafx.h"

int main()
{
	cout << "输入要写入的文件路径及文件名：" << endl;
	string filename;
	cin >> filename;
	File f;
	f.Infile(filename);
	f.Wordscount(filename);
	f.Wordsway();
	f.Show();
	cout << "输入要读取的文件路径及文件名：" << endl;
	cin >> filename;
	f.Outfile(filename);
	system("pause");
	return 0;
}