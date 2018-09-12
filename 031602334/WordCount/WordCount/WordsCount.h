#pragma once
#pragma once
//
//  WordsCount.h
//  词频统计
//
//  Created by wenyiqian on 2018/9/9.
//  Copyright © 2018年 ding. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <cstring>
#include <regex>
#include <iostream>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define msi map<string, int>
#define psi pair<string, int>
#define vpsi vector<psi>

long WordsCount(const char *filename);