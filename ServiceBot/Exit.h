#pragma once
#include "global.h"

class Exit
{
private:
    vector<int> exitstep;   // Stepid
public:
    Exit();
    ~Exit();
    void UpdateExit(int stepid);    /* 更新Exit */
    bool IsExit(int stepid);        /* 判断该Stepid下是否执行Exit */
};

