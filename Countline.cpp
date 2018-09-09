clude"work_2.h"
int Text::countline(ofstream *outfile)//统计行数
{
 int flag = 0;
 int len = allstring.length();//文本长度
 for (int i = 0; i < len; i++)
 {
  if (allstring[i] >= 33 && allstring[i] <= 126)//表示该行是有效行
  {
   flag = 1;
   continue;
  }
  if (allstring[i] == '\n'&&flag == 1)//当该行是有效行，并且遍历到1个换行符时，行数加1
  {
   count_line++;
   flag = 0;
  }
 }
 if (flag == 1)//最后一行如果没有换行符，也要加1
  count_line++;

 cout << "lines:" << count_line << endl;
 *outfile << "lines:" << count_line << endl;//结果输入result.txeturn count_line;
  return count_line;
}
