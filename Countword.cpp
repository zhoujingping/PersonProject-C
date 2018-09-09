#include"work_2.h"
int Text::countword(ofstream *outfile)//统计单词数
{
 int flag = 0;
 string temp = "";
 int len = allstring.length();
 for (int i = 0; i < len; i++)
 {
  if ((allstring[i] >= 65 && allstring[i] <= 90) || (allstring[i] >= 97 && allstring[i] <= 122))//找到第一个字母  判断是不是单词
  {
   flag = 0;
   for (int j = i; j <= i + 3; j++)
   {
    if (allstring[j] <= 64 || (allstring[j] >= 91 && allstring[j] <= 96) || allstring[j] >= 123 || len - i < 4)
    {
     flag = 1;
     break;
    }
   }
   if (flag == 0)//如果是单词就提取单词到temp
   {
    temp = "";
    for (; i < len && ((allstring[i] >= 65 && allstring[i] <= 90) || (allstring[i] >= 97 && allstring[i] <= 122) || (allstring[i] >= 48 && allstring[i] <= 57)); i++)
    {
     if (allstring[i] >= 65 && allstring[i] <= 90)
      allstring[i] += 32;
     temp += allstring[i];
    }
    count_word++;
    //cout << temp << endl;
    Text::insert(temp);
   }
   else//如果不是单词就跳到下一个单词的第一个字母
   {
    for (; (allstring[i] >= 65 && allstring[i] <= 90) || (allstring[i] >= 97 && allstring[i] <= 122); i++) {}
   }
  }
  else if (allstring[i] >= 48 && allstring[i] <= 57)
  {
   for (; (allstring[i] >= 65 && allstring[i] <= 90) || (allstring[i] >= 97 && allstring[i] <= 122) || (allstring[i] >= 48 && allstring[i] <= 57); i++) {}
  }
 }

 cout << "words:" << count_word << endl;
 *outfile << "words:" << count_word << endl;//统计单词个数
 return count_word;
 }
}
