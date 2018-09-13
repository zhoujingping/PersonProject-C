#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/core.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char name[100];
			strcpy_s(name, "../UnitTest1/test/test1.txt");      //获取文件名
			int count_chars = CountChar(name);
			Assert::AreEqual(count_chars, 3);
		}
		TEST_METHOD(TestMethod2)
		{
			char name[100];
			strcpy_s(name, "../UnitTest1/test/test2.txt");
			pii count_words = CountWord(name);	
			Assert::AreEqual(count_words.fi, 94);
		}
		TEST_METHOD(TestMethod3)
		{
			char name[100];
			strcpy_s(name, "../UnitTest1/test/test3.txt");
			vector<pair<string, int> > word_rank = CountFrequentWord(name);
			Assert::AreEqual(word_rank[0].fi, string("image"));
			Assert::AreEqual(word_rank[0].se, 4);
			Assert::AreEqual(word_rank[1].fi, string("systems"));
			Assert::AreEqual(word_rank[1].se, 4);
			Assert::AreEqual(word_rank[2].fi, string("detection"));
			Assert::AreEqual(word_rank[2].se, 3);
			Assert::AreEqual(word_rank[3].fi, string("object"));
			Assert::AreEqual(word_rank[3].se, 3);
			Assert::AreEqual(word_rank[4].fi, string("accurate"));
			Assert::AreEqual(word_rank[4].se, 2);
			Assert::AreEqual(word_rank[5].fi, string("classifier"));
			Assert::AreEqual(word_rank[5].se, 2);
			Assert::AreEqual(word_rank[6].fi, string("fast"));
			Assert::AreEqual(word_rank[6].se, 2);
			Assert::AreEqual(word_rank[7].fi, string("human"));
			Assert::AreEqual(word_rank[7].se, 2);
			Assert::AreEqual(word_rank[8].fi, string("like"));
			Assert::AreEqual(word_rank[8].se, 2);
			Assert::AreEqual(word_rank[9].fi, string("locations"));
			Assert::AreEqual(word_rank[9].se, 2);
		}
		TEST_METHOD(TestMethod4)
		{
			char name[100];
			strcpy_s(name, "../UnitTest1/test/test4.txt");
			int count_chars = CountChar(name);
			pii tmp = CountWord(name);
			int count_words = tmp.fi;
			int count_lines = tmp.se;
			vector<pair<string, int> > word_rank = CountFrequentWord(name);
			Assert::AreEqual(count_chars, 10000000);
		}
		TEST_METHOD(TestMethod5)
		{
			char name[100];
			strcpy_s(name, "../UnitTest1/test/test5.txt");
			int count_lines = CountWord(name).se;
			Assert::AreEqual(count_lines, 3);
		}
		TEST_METHOD(TestMethod6)
		{
			char name[100];
			strcpy_s(name, "../UnitTest1/test/test6.txt");
			vector<pair<string, int> > word_rank = CountFrequentWord(name);
			Assert::AreEqual(word_rank[0].fi, string("ubuntu14"));
			Assert::AreEqual(word_rank[0].se, 1);
			Assert::AreEqual(word_rank[1].fi, string("ubuntu16"));
			Assert::AreEqual(word_rank[1].se, 1);
			Assert::AreEqual(word_rank[2].fi, string("windows"));
			Assert::AreEqual(word_rank[2].se, 1);
			Assert::AreEqual(word_rank[3].fi, string("windows2000"));
			Assert::AreEqual(word_rank[3].se, 1);
			Assert::AreEqual(word_rank[4].fi, string("windows97"));
			Assert::AreEqual(word_rank[4].se, 1);
			Assert::AreEqual(word_rank[5].fi, string("windows98"));
			Assert::AreEqual(word_rank[5].se, 1);
		}
		TEST_METHOD(TestMethod7)
		{
			char name[100];
			strcpy_s(name, "../UnitTest1/test/test7.txt");
			int count_chars = CountChar(name);
			Assert::AreEqual(count_chars, 0);
		}
		TEST_METHOD(TestMethod8)
		{
			char name[100];
			strcpy_s(name, "../UnitTest1/test/test8.txt");

			int count_chars = CountChar(name);
			pii tmp = CountWord(name);
			int count_words = tmp.fi;
			int count_lines = tmp.se;
			vector<pair<string, int> > word_rank = CountFrequentWord(name);

			Assert::AreEqual(word_rank[0].fi, string("file123"));
			Assert::AreEqual(word_rank[0].se, 1);
			Assert::AreEqual(count_words, 1);
			Assert::AreEqual(count_chars, 15);
			Assert::AreEqual(count_lines, 1);
		}
		TEST_METHOD(TestMethod9)
		{
			char name[100];
			strcpy_s(name, "../UnitTest1/test/test9.txt");
			int count_words = CountWord(name).fi;
			Assert::AreEqual(count_words, 0);
		}
		TEST_METHOD(TestMethod10)
		{
			char name[100];
			strcpy_s(name, "../UnitTest1/test/test10.txt");
			int count_chars = CountChar(name);
			pii tmp = CountWord(name);
			int count_words = tmp.fi;
			int count_lines = tmp.se;

			Assert::AreEqual(count_chars, 1703);
			Assert::AreEqual(count_lines, 25);
			Assert::AreEqual(count_words, 119);
		}

	};
}
