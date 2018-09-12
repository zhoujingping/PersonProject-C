#include<stdafx.h>
void CharCount::countresult()//输出字符数
{
	fstream outFile("result.txt", ios::out);
	outFile << "characters:" << charnum;
	outFile << endl;
	outFile.close();
}
void CharCount::charCount(string fileName, CharCount &charcount)//定义字符数统计函数
{
	char c;
	fstream inFile;
	inFile.open(fileName);//读取文件
	if (inFile.fail()) //读取文件失败
	{
		cout << "Could not find the file\n";
		cout << "Program terminating\n";
		exit(EXIT_FAILURE);
	}
	inFile >> noskipws;
	inFile >> c;
	while (!inFile.eof())
	{
		if (inFile.good())
		{
			if (c > 0 && c < 255)
			{
				charcount.charnum++;
			}
			inFile >> c;
		}
	}
}

void WordCount::countresult()
{
	fstream outFile("result.txt", ios::app);
	outFile << "words:" << wordnum;
	outFile << endl;
}
void WordCount::wordCount(string fileName, WordCount &wordcount)
{
	char c;
	int flag = 0;
	int wordposition = 0;//记录当前字母在单词的位置
	fstream inFile(fileName);
	inFile >> noskipws;
	while (true)
	{
		c = inFile.get();
		bool separator1 = ((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z'));
		bool separator2 = (c >= '0'&&c <= '9');
		if (separator1)
		{
			wordposition++;
		}
		if (separator2)
		{
			if (wordposition < 4)
			{
				wordposition = 0;
			}
		}
		if (!separator1 && !separator2 && wordposition < 4)
		{
			wordposition = 0;
		}
		if (!separator1 && !separator2&&wordposition >= 4)
		{
			wordcount.wordnum++;
			wordposition = 0;
		}
		if (c == EOF)break;
	}
	inFile.close();
}

void LineCount::countresult()//输出行数
{
	fstream outFile("result.txt", ios::app);
	outFile << "lines:" << linenum;
	outFile << endl;
}
void LineCount::lineCount(string fileName, LineCount &linecount)
{
	fstream inFile;
	string tmp;
	inFile.open(fileName, ios::in);//读取文件
	if (inFile.fail())//文件打开失败
	{
		cout << "Could not find the file\n";
		cout << "Program terminating\n";
		exit(EXIT_FAILURE);
	}
	while (getline(inFile, tmp, '\n'))
	{
		linecount.linenum++;
	}
	inFile.close();
}

WordList::WordList()
{
	pWordHead = new Word();
	pWordTail = new Word();
	pWordHead->next = pWordTail;
	pWordTail->previous = pWordHead;
	for (int i = 0; i<128; i++) index[i] = nullptr;
}
WordList::~WordList()
{
	delete pWordHead;

	for (int i = 0; i<128; i++) {
		delete index[i];
		index[i] = nullptr;
	}
}
void WordList::addWord(char word[])
{
	//将word这个单词添加到词频统计表中（或者词频+1）
	int  p_index = Hash(word);
	WordIndex* pIndex = index[p_index];
	while (pIndex != nullptr)
	{
		Word *pWord = pIndex->pWord;
		if (!strcmp(word, pWord->word))
		{
			pWord->num++;

			Word *qWord = pWord->previous;
			while (qWord->num < pWord->num) {
				if (qWord == pWordHead) return;
				shiftWord(pWord);

				qWord = pWord->previous;
			}
			while (strcmp(qWord->word, pWord->word) > 0) {
				if (qWord->num > pWord->num) return;
				shiftWord(pWord);
				qWord = pWord->previous;
			}
			return;
		}
		pIndex = pIndex->next;
	}

	Word *pWord = new Word(word, 1);
	pWord->previous = pWordTail->previous;
	pWord->next = pWordTail;

	pWordTail->previous->next = pWord;
	pWordTail->previous = pWord;

	pIndex = new WordIndex(pWord, index[p_index]);
	index[p_index] = pIndex;

	Word *qWord = pWord->previous;
	while (strcmp(qWord->word, pWord->word) > 0) {
		if (qWord->num > pWord->num) return;
		shiftWord(pWord);
		qWord = pWord->previous;
	}
}
void WordList::outPut()
{
	fstream outFile("result.txt", ios::app);
	//将十个单词全部通过outFile写入文本文件
	Word *p = pWordHead->next;
	if (p != pWordTail) outFile << "<" << p->word << ">" << ' ' << p->num;
	else return;
	p = p->next;

	for (int i = 0; i < 10; i++) {
		if (p != pWordTail) outFile << endl << "<" << p->word << ">" << ' ' << p->num;
		else return;

		p = p->next;
	}
}
int WordList::Hash(char* word) {
	int HashVal = 0;

	while (*word != '\0')
		HashVal += *word++;

	return HashVal & 127;

}
void WordList::shiftWord(Word *pWord)
{
	if (pWord == pWordHead) return;
	Word *qWord = pWord->previous;
	if (qWord == pWordHead) return;

	pWord->next->previous = qWord;
	qWord->previous->next = pWord;

	qWord->next = pWord->next;
	pWord->previous = qWord->previous;

	pWord->next = qWord;
	qWord->previous = pWord;
}
void WordList::wordCount(string fileName, WordList &wordList)
{
	char word[MAX_WORD_LENGTH];
	ifstream inFile;
	inFile >> noskipws;
	inFile.open(fileName);
	int wordposition = 0;
	int wordPosition = 0;
	char c;
	int delta = 'a' - 'A';
	do {
		c = inFile.get();
		if (c <= 'Z'&&c >= 'A') c += delta;
		bool separator1 = (c >= 'a'&&c <= 'z');
		bool separator2 = (c >= '0'&&c <= '9');
		if (separator1)
		{
			wordposition++;
			word[wordPosition] = c;
			wordPosition++;
		}
		if (separator2)
		{
			if (wordposition < 4)
			{
				wordposition = 0;
				wordPosition = 0;
			}
			else
			{
				word[wordPosition] = c;
				wordPosition++;
			}
		}
		if (!separator1 && !separator2 && wordposition < 4)
		{
			wordPosition = 0;
			wordposition = 0;
		}
		if (!separator1 && !separator2 && wordposition >= 4)
		{
			word[wordPosition] = 0;
			wordList.addWord(word);
			wordPosition = 0;
			wordposition = 0;
		}

	} while (c != EOF);

	inFile.close();
}