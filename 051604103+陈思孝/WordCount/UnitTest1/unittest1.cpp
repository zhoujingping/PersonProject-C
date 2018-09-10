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
			int ans = sum1(10, 20);
			Assert::AreEqual(ans, (int)30);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			vector<string> str;
			str.push_back("Hsaseqww");
			Lower(str);
			Assert::AreEqual(str[0], (string)"hsaseqww");
		}
	};
}