#pragma once
#include "global.h"

class Step
{
private:
    vector<string> stepdata;    // Proc

public:
    Step();
    ~Step();
    void UpdateStep(string str);    /* 更新Step */
    int FindStep(string str);       /* Step对应的Proc名 所对应的Stepid */
    string FindProc(int stepid);    /* 返回Stepid对应的Step(Proc)名字 */
    int CountStep();                /* 返回脚本中Step总数 */
};

