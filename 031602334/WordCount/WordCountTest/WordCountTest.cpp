#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/WordsCount.h"
#include "../WordCount/CharCount.h"
#include "../WordCount/LinesCount.h"
#include "../WordCount/WordFrequency.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordCountTest
{		
	TEST_CLASS(UnitTest1)
	{
	private:
/*	

*/


	public:

		
		TEST_METHOD(TestEmptyFile)
		{
			// TODO: 测试空文件
			char filename[100] = "../WordCountTest/Empty.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int CharNum = CharCount(filename);
			int LinesNum = LinesCount(filename);
			Assert::IsFalse(CharNum);
			Assert::IsFalse(LinesNum);
		}

		TEST_METHOD(TestChineseFile)
		{
			// TODO: 测试中文文件
			char filename[100] = "../WordCountTest/Chinese.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int CharNum = CharCount(filename);
			Assert::IsFalse(CharNum);
		}

		TEST_METHOD(TestBlankFile)
		{
			// TODO: 测试空白行文件
			char filename[100] = "../WordCountTest/Blank.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int CharNum = CharCount(filename);
			int LinesNum = LinesCount(filename);
			Assert::IsTrue(CharNum);
			Assert::IsFalse(LinesNum);
		}

		TEST_METHOD(TestBlankCharFile)
		{
			// TODO: 测试空白字符文件
			char filename[200] = "../WordCountTest/BlankChar.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int CharNum = CharCount(filename);
			int LinesNum = LinesCount(filename);
			Assert::IsTrue(CharNum);
			Assert::IsFalse(LinesNum);
		}

		TEST_METHOD(TestWrongWordFile)
		{
			// TODO: 测试满是错误单词的文件
			char filename[100] = "../WordCountTest/WrongWord.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int WordsNum = WordsCount(filename);
			int CharNum = CharCount(filename);
			Assert::IsFalse(WordsNum);
			Assert::IsTrue(CharNum);
		}

		TEST_METHOD(TestFullDelimiterFile)
		{
			// TODO: 测试分隔符文件
			char filename[100] = "../WordCountTest/FullDelimiter.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int CharNum = CharCount(filename);
			int WordsNum = WordsCount(filename);
			Assert::IsFalse(WordsNum);
			Assert::IsTrue(CharNum == 13);
		}

		TEST_METHOD(TestOneWordFile)
		{
			// TODO: 测试一个长单词的文件
			char filename[100] = "../WordCountTest/OneWord.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int WordsNum = WordsCount(filename);
			Assert::IsTrue(WordsNum == 1);
		}
	};
}