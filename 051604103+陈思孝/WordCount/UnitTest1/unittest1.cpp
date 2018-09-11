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
			int x = CountChar("D:/test/ttt.txt");
			Assert::AreEqual(x, 29);
		}
		TEST_METHOD(TestMethod2)
		{
			
			vector<string> v;
			// TODO: 在此输入测试代码
			int line = LineCount("D:/test/ttt.txt", v);
			Assert::AreEqual(line, 2);
		}
		TEST_METHOD(TestMethod3)
		{
			
			vector<string> v;
			// TODO: 在此输入测试代码
			int z = WordNumber("D:/test/ttt.txt");
			Assert::AreEqual(z, 3);
		}
		TEST_METHOD(TestMethod4)
		{
			int k;
			
			char *filename = "D:/test/ttt.txt";
			// TODO: 在此输入测试代码
			Word words[500];
			WordFCount(filename, words, k);
			string a = "hello";
			//cout << words[0].name << ' ' << words[0].cnt << endl;
			//cout << words[1].name << ' ' << words[1].cnt << endl;
			Assert::AreEqual(words[0].cnt,3 );
		}
	};
}