//
//  CharCount.cpp
//  词频统计
//
//  Created by wenyiqian on 2018/9/9.
//  Copyright © 2018年 ding. All rights reserved.
//

#include "CharCount.h"

int CharCount(const char *filename)
{
	int CharNum = 0;
	ifstream ifs(filename);
	char charTemp;
	mci charCountMap;
	while ((charTemp = ifs.get()) != EOF)
	{
		if (charTemp >= NULL && charTemp <= '~')
			CharNum++;
	}
	ifs.clear();
	ifs.seekg(0);
	return CharNum;
}