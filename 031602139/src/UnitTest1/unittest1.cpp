#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/WordCount.cpp"
#include "../WordCount/pch.h"
#include "../WordCount/pch.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD_INITIALIZE(Start)
		{
			testCounter = new counter();
			Logger::WriteMessage("Test initialized.\n"); 
		}

		TEST_METHOD_CLEANUP(Done)
		{
			delete testCounter;
			Logger::WriteMessage("Test completed.\n");
		}
		
		TEST_METHOD(TestMethod1)
		{
			//init answer
			aChar = 38;
			aWord = 2;
			aLine = 2;
			aFrequency = pair<string, int>("file123", 1);
			//init result
			rChar = 0;
			rWord = 0;
			rLine = 0;
			rFrequency = pair<string, int>("", 0);
			//init file name
			char inFilename[] = "input.txt";
			char outFilename[] = "result.txt";
			//running
			testCounter->initInFilename(inFilename);
			testCounter->countCharLine();
			testCounter->countWord();
			testCounter->frequency();
			testCounter->print(outFilename);
			//result read in
			ifstream checkFile(outFilename, ios::in);
			if(checkFile.fail()) Logger::WriteMessage("faile to open check file.\n");
		
			string temp;

			checkFile >> temp >> rChar;
			if (rChar != aChar)
				Logger::WriteMessage(temp.c_str());

			checkFile >> temp >> rWord;
			if (rWord != aWord)
				Logger::WriteMessage(temp.c_str());

			checkFile >> temp >> rLine;
			if (rLine != aLine)
				Logger::WriteMessage(temp.c_str());

			if (aWord != 0 && rWord != 0)
			{
				checkFile >> temp;
				Logger::WriteMessage(temp.c_str());
				rFrequency.first = temp.substr(1, (int)temp.length() - 3);
				Logger::WriteMessage(rFrequency.first.c_str());
				checkFile >> rFrequency.second;
			}
			
			checkFile.close();
			//check
			Assert::AreEqual(aChar, rChar);
			Assert::AreEqual(aWord, rWord);
			Assert::AreEqual(aLine, rLine);
			if (aWord != 0 && rWord != 0)
			{
				Assert::AreEqual(aFrequency.first, rFrequency.first);
				Assert::AreEqual(aFrequency.second, rFrequency.second);
			}
		}


	private:

		counter *testCounter;
		//Result
		int rChar;
		int rLine;
		int rWord;
		pair<string, int> rFrequency;
		//Answer
		int aChar;
		int aLine;
		int aWord;
		pair<string, int> aFrequency;
	};
}