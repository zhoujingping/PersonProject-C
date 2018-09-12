#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\WordCount\stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace countchartest							//第一测试
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
			myfile ff;
			ff.countchar(f);
			Assert::AreEqual(ff.getchars(),0);
		}

	};
}

namespace countlinetest							//第二测试
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
			myfile ff;
			ff.countline(f);
			Assert::AreEqual(ff.getlines(), 3);
		}

	};
}

namespace countwordtest							//第三测试
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
			myfile ff;
			ff.countword(f);
			Assert::AreEqual(ff.getwords(), 1);
		}

	};
}
