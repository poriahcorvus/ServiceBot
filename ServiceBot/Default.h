#pragma once
#include "global.h"

class Default
{
private:
    vector<int> defaultstep;    // Stepid
    vector<string> defaultdata; // Default跳转的语句
public:
    Default();
    ~Default();
    void UpdataDefault(string str, int stepid);     /* 更新Default */
    string FindDefault(int stepid);                 /* 返回当前Stepid下所执行的Default */
};

