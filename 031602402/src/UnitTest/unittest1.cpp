#include "stdafx.h"
#include "CppUnitTest.h"
#include"../WordCount/FileTools.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char filename[] = "test1.txt";
			ifstream in;
			in.open(filename);
			string s = FileTools::getString(in);
			Assert::AreEqual(s, (string)"abcd");
		}
		TEST_METHOD(TestMethod2)
		{
			ifstream in;
			string s = FileTools::getString(in);
			Assert::AreEqual(s, (string)"");
		}
		TEST_METHOD(TestMethod3)
		{
			ifstream in;
			char name[] = "test2.txt";
			in.open(name);
			string s = FileTools::getString(in);
			pair<int,int> p = FileTools::countLine(s);
			map<string, int> mp = FileTools::countWord(s);
			vector<pair<int,string> > v = FileTools::getSort(mp);
			Assert::AreEqual((int)s.length(), 58);
			Assert::AreEqual(p.first, 4);
			Assert::AreEqual(p.second, 3);
			Assert::AreEqual(v[0].second, (string)"aaaa");
			Assert::AreEqual(v[0].first, 2);
			Assert::AreEqual(v[1].second, (string)"abcd123");
			Assert::AreEqual(v[2].second, (string)"bbbb");
			Assert::AreEqual((int)v.size(), 3);
			Assert::AreEqual(FileTools::count(mp), 5);
		}
		TEST_METHOD(TestMethod4)
		{
			ifstream in;
			in.open("test3.txt");
			string s = FileTools::getString(in);
			pair<int, int> p = FileTools::countLine(s);
			map<string, int> mp = FileTools::countWord(s);
			vector<pair<int, string> > v = FileTools::getSort(mp);
			int res = FileTools::count(mp);
			Assert::AreEqual((int)s.length(), 100001);
		}
		TEST_METHOD(TestMethod5)
		{
			ifstream in;
			in.open("test5.txt");
			string s = FileTools::getString(in);
			pair<int, int> p = FileTools::countLine(s);
			map<string, int> mp = FileTools::countWord(s);
			vector<pair<int, string> > v = FileTools::getSort(mp);
			int res = FileTools::count(mp);
			ofstream out;
			out.open("result.txt");
			out << "characters:" << s.length() << endl;
			out << "words:" << FileTools::count(mp) << endl;
			out << "lines:" << p.first << endl;
			int up = 10;
			if (v.size() < 10)up = v.size();
			for (int i = 0; i < up; i++)
			{
				out << "<" << v[i].second << ">:" << v[i].first << endl;
			}
		}
	};
}