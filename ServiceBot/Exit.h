#pragma once
#include "global.h"

class Exit
{
private:
    vector<int> exitstep;   // Stepid
public:
    Exit();
    ~Exit();
    void UpdateExit(int stepid);    /* ����Exit */
    bool IsExit(int stepid);        /* �жϸ�Stepid���Ƿ�ִ��Exit */
};

