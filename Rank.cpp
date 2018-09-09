#include"work_2.h"
void Text::insert(string w)//把单词插入哈希表
{
 int hash = ((w[0] - 96)) + ((w[1] - 96) * 26) + ((w[2] - 96) * 26 * 26);//计算哈希值
 node *p = new node("", 1);
 node *q = new node("", 1);
 if (hash_table[hash]->next == NULL)//空表插入
 {
  p = hash_table[hash];
  hash_table[hash] = new node(w, 1);
  hash_table[hash]->next = p;
 }
 else//非空表
 {
  int flag = 0;
  q = p = hash_table[hash];
  while (p->next != NULL)//遍历链表
  {
   if (p->word == w)//在表中找到该单词，并且times加1
   {
    p->times++;
    flag = 1;
   }
   q = p;
   p = p->next;
  }
  if (flag == 0)//在链表中没有找到该单词，则在链表尾部插入新结点
  {
   node *newnode = new node(w, 1);
   q->next = newnode;
   newnode->next = p;
  }
 }
 return;
}

void Text::rank(ofstream *outfile)//统计词频
{
 int num;
 int flag = 0;//判断出现次数最大的结点是不是表首 0不是 1是
 node *max, *q, *p, *front_max;
 front_max = new node("", 0);
 for (int j = 0; j < 10 && j < count_word; j++)//遍历10次哈希表
 {
  max = new node("", 0);//初始化max
  for (int i = 0; i <= 18279; i++)
  {
   if (hash_table[i]->next == NULL) continue;//空表跳过
   else//非空表
   {
    q = p = hash_table[i];
    while (p->next != NULL)
    {
     if (p->times > max->times || (p->times == max->times&&p->word < max->word))
     {

      if (p == hash_table[i])
      {
       flag = 1;//表示该单词在表头
       num = i;
      }
      else flag = 0;//表示该单词在表中
      max = p;
      front_max = q;
     }
     q = p;
     p = p->next;
    }
   }
  }
  if (max->times != 0)
  {
   cout << "<" << max->word << ">:" << max->times << endl;//输出一个结果
   *outfile << "<" << max->word << ">:" << max->times << endl;//输出一个结果
  }
  else  break;//如果max没有被替换，则此时哈希表是空的，不需要输出

  if (flag == 1) hash_table[num] = max->next;//如果频次最大的单词在表首，替换表首指针
  else front_max->next = max->next;//如果频次最大的单词在表中，删除结点
 }
 return;
}
