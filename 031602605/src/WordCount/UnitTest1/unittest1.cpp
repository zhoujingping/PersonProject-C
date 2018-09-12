#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/stdafx.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(empty)
		{
			/*
			测试空白文件
			int n1 = w.Countcharacters(file);
			int n2 = w.Countlines(file);
			int n3 = w.Countwords(file);
			Assert::IsTrue(n1 == 0 && n2 == 0 && n3 == 0);*/
			Word w=Word();
			char file[1000] = "../UnitTest1/empty.txt";
			int n1 = w.Countcharacters(file);
			int n2 = w.Countlines(file);
			int n3 = w.Countwords(file);
			Assert::IsTrue(n1 == 0 && n2 == 0 && n3 == 0);
			// TODO: 在此输入测试代码
		}
		TEST_METHOD(none)
		{
			/*
			没有命令行参数；
			*/
			File f = File();
			Word w = Word();
			char *file[] = { "../UnitTest1/empty.txt","" };
			int a = f.FileTest(file);
			int n1 = w.Countcharacters(file[1]);
			int n2 = w.Countlines(file[1]);
			int n3 = w.Countwords(file[1]);
			Assert::IsTrue(a == 0 && n1 == -1 && n2 == -1 && n3 == -1);
			// TODO: 在此输入测试代码
		}
		TEST_METHOD(exist)
		{
			/*
			文本不存在;
			*/
			File f = File();
			Word w = Word();
			char *file[] = {"","e.txt" };
			int a = f.FileTest(file);
			int n1 = w.Countcharacters(file[1]);
			int n2 = w.Countlines(file[1]);
			int n3 = w.Countwords(file[1]);
			Assert::IsTrue(a == 0&& n1 == -1 && n2 == -1 && n3 == -1);
			// TODO: 在此输入测试代码
		}
		TEST_METHOD(num)
		{
			/*
			含数字;
			*/
			Word w = Word();
			char file[1000] = "../UnitTest1/num.txt";
			int n3 = w.Countwords(file);
			Assert::IsTrue(n3 == 0);
			// TODO: 在此输入测试代码
		}
		TEST_METHOD(text_transform)
		{
			/*
			大小写;
			*/
			Word w = Word();
			char file[1000] = "../UnitTest1/text-transform.txt";
			int n3 = w.Countwords(file);
			Assert::IsTrue(n3 == 3);
			// TODO: 在此输入测试代码
		}
		TEST_METHOD(blank)
		{
			/*
			空白行;
			*/
			Word w = Word();
			char file[1000] = "../UnitTest1/blank.txt";
			int n2 = w.Countlines(file);
			Assert::IsTrue(n2 == 0);
			// TODO: 在此输入测试代码
		}
		TEST_METHOD(Countlines_test)
		{
			/*
			测试行;
			*/
			Word w = Word();
			char file[1000] = "../test/input.txt";
			int n2 = w.Countlines(file);
			Assert::IsTrue(n2 == 11);
			// TODO: 在此输入测试代码
		}
		TEST_METHOD(Countwords_test)
		{
			/*
			测试词;
			*/
			Word w = Word();
			char file[1000] = "../test/input.txt";
			int n2 = w.Countwords(file);
			Assert::IsTrue(n2 == 9);
			// TODO: 在此输入测试代码
		}
		TEST_METHOD(Countcharacters_test)
		{
			/*
			测试字符;
			*/
			Word w = Word();
			char file[1000] = "../test/input.txt";
			int n2 = w.Countcharacters(file);
			Assert::IsTrue(n2 == 98);
			// TODO: 在此输入测试代码
		}
		TEST_METHOD(top10_test)
		{
			/*
			测试top10;
			*/
			Word w = Word();
			char file[1000] = "../UnitTest1/manyword.txt";
			vector<pair<string, int>> v = w.Counttop10(file);
			int n2 = v.size();
			Assert::IsTrue(n2 == 10);
			// TODO: 在此输入测试代码
		}
	};


}