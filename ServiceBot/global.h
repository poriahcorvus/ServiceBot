#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <tchar.h>
using namespace std;

extern string user;		// 记录用户输入
DWORD WINAPI UserInput(LPVOID lpParameter);		/* 用户输入 */

#define SYSTEM_ERROR "系统维护中，请稍后再试！"
#define SERVICE_BUSY "客服忙，请稍后再试！"
#define SERVICE_BROKEN "系统错误，请重试！"
