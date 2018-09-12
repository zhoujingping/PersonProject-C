#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Count/Count/Count.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//Returns my solution's directory

namespace WordCountTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			string name = "input1.txt";
			Assert::AreEqual(charCount(name), 177);
		}

		TEST_METHOD(TestMethod2)
		{
			string name = "input2.txt";
			Assert::AreEqual(charCount(name), 262);
		}

		TEST_METHOD(TestMethod3)
		{
			string name = "input3.txt";
			Assert::AreEqual(charCount(name), 1147);
		}

		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码
			string name = "input1.txt";
			Assert::AreEqual(wordCount(name), 15);
		}

		TEST_METHOD(TestMethod5)
		{
			// TODO: 在此输入测试代码
			string name = "input2.txt";
			Assert::AreEqual(wordCount(name), 3);
		}

		TEST_METHOD(TestMethod6)
		{
			// TODO: 在此输入测试代码
			string name = "input3.txt";
			Assert::AreEqual(wordCount(name), 44);
		}
	};
}