#pragma once
#include "global.h"

class Listen
{
private:
    vector<int> listenstep; // Stepid
    vector<int> listendata; // Listenʱ��
public:
    Listen();
    ~Listen();
    void UpdateListen(string str, int stepid);  /* ����Listen */
    int GetTime(int stepid);                    /* Listen��ʱ�� */
};

