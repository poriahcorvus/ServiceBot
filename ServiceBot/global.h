#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <tchar.h>
using namespace std;

extern string user;		// ��¼�û�����
DWORD WINAPI UserInput(LPVOID lpParameter);		/* �û����� */

#define SYSTEM_ERROR "ϵͳά���У����Ժ����ԣ�"
#define SERVICE_BUSY "�ͷ�æ�����Ժ����ԣ�"
#define SERVICE_BROKEN "ϵͳ���������ԣ�"
