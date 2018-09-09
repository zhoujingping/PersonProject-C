#include"work_2.h"

int Text::countchar(ifstream *infile, ofstream *outfile)//统计字符数
{
 char a;
 while ((*infile).get(a))//字符读取不成功就终止
 {
  if ((a >= 32 && a <= 126) || a == '\n' || a == '\t')
   count_char++;
  allstring += a;//把每个字符传入all_string
 }
 cout << "characters:" << count_char << endl;
 *outfile << "characters:" << count_char << endl;//结果输入result.txt文件
 return count_char;
}
