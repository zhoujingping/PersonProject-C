#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

struct node { //链表结构体
 string word;//单词名
 int times;//单词出现频次
 node *next;
 node(string w, int number) //构造函数
 {
  word = w;
  times = number;
  next = NULL;
 }
};
class Text {
private:
 string allstring;//整个文本的内容
 int count_char;//字符个数
 int count_word;//单词个数
 int count_line;//行数
 node *hash_table[18280];//哈希表
public:
 Text()//构造函数
 {
  allstring = "";
  count_char = 0;
  count_word = 0;
  count_line = 0;
  for (int i = 0; i <= 18279; i++)//初始化整个结构体指针数组
   hash_table[i] = new node("", 0);
 }
 int countchar(ifstream *infile, ofstream *outfile);//统计字符个数
 int countword(ofstream *outfile);//统计单词个数
 int countline(ofstream *outfile);//统计行数
 void rank(ofstream *outfile);//统计出现频次最多的10个单词
 void insert(string w);//把每个单词插入哈希表
};
