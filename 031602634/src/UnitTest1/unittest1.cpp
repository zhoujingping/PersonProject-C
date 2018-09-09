#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\WordCount\stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace countchartest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char file[100] = "input.txt";
			FILE *f;
			fopen_s(&f, file, "r");
			int x = countchar(f);
			Assert::AreEqual(x,0);
		}

	};
}

namespace countlinetest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char file[100] = "input.txt";
			FILE *f;
			fopen_s(&f, file, "r");
			int x = countline(f);
			Assert::AreEqual(x, 2);
		}

	};
}

namespace countwordtest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char file[100] = "input.txt";
			FILE *f;
			fopen_s(&f, file, "r");
			int x = countword(f);
			Assert::AreEqual(x, 5);
		}

	};
}
