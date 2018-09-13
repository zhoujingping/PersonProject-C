#include "stdafx.h"
#include "CppUnitTest.h"
#include"D:\SE\PersonProject-C\051604103+陈思孝\WordCount\WordCount\WordCount.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			// TODO: 在此输入测试代码
			int x = CountChar("in1.txt");
			Assert::AreEqual(x, 29);
		}
		TEST_METHOD(TestMethod2)
		{
			
			vector<string> v;
			// TODO: 在此输入测试代码
			int line = LineCount("in1.txt", v);
			Assert::AreEqual(line, 2);
		}
		TEST_METHOD(TestMethod3)
		{
			
			vector<string> v;
			// TODO: 在此输入测试代码
			int z = WordNumber("in1.txt");
			Assert::AreEqual(z, 3);
		}
		TEST_METHOD(TestMethod4)
		{
			
			
			char *filename = "in1.txt";
			// TODO: 在此输入测试代码
			vector<Word> words;
			WordFCount(filename, words);
			string a = "hello";
			//cout << words[0].name << ' ' << words[0].cnt << endl;
			//cout << words[1].name << ' ' << words[1].cnt << endl;
			Assert::AreEqual(words[0].cnt,3 );
		}
		TEST_METHOD(TestMethod5)
		{//统计有空格时的情况
			vector<string> v;
			int x = LineCount("in1.txt",v);
			Assert::AreEqual(x, 4);
			
			
		}
		TEST_METHOD(TestMethod6)
		{

			// TODO: 在此输入测试代码
			vector<string> v;
			//统计有空行时是否正确
			int line = LineCount("in1.txt", v);
			Assert::AreEqual(line, 4);
		}
		TEST_METHOD(TestMethod7)
		{
			string x = "78sdas";
			int flag = IsWord(x);
			Assert::AreEqual(flag, 0);
			
		}
		TEST_METHOD(TestMethod8)
		{
			vector<string> s;
			string s1 = "HeLlo";
			s.push_back(s1);

			Lower(s);
			string ans = "hello";
			Assert::AreEqual(s[0], ans);
		}
		TEST_METHOD(TestMethod9)
		{
			//统计空文件
			int x = CountChar("in2.txt");
			
			
			Assert::AreEqual(x, 0);
		}
		TEST_METHOD(TestMethod10)
		{

			// 统计大文件字符数
			int x = CountChar("in2.txt");
			Assert::AreEqual(x, 7424);
		}
		
	};
}