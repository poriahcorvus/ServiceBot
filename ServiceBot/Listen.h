#pragma once
#include "global.h"

class Listen
{
private:
    vector<int> listenstep; // Stepid
    vector<int> listendata; // Listen时间
public:
    Listen();
    ~Listen();
    void UpdateListen(string str, int stepid);  /* 更新Listen */
    int GetTime(int stepid);                    /* Listen的时间 */
};

