#include"work_2.h"
int main(int argc, char *argv[])
{
 ifstream infile;//创建输入文件流对象
 ofstream outfile;//创建输出文件流对象
 infile.open("input.txt", ios::in);//打开input.txt文件
 outfile.open("result.txt", ios::out);//打开result.txt文件
 Text text1;

 text1.countchar(&infile,&outfile);//统计字符个数
 text1.countword(&outfile);//统计单词个数
 text1.countline(&outfile);//统计行数
 text1.rank(&outfile);//统计出现频次最多的10个单词

 system("pause");
 return 0;
}
