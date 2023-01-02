#pragma once
#include "global.h"

class Silence
{
private:
    vector<int> silencestep;    // Stepid
public:
    Silence();
    ~Silence();
    void UpdateSilence(int stepid);     /* 更新Silence */
    bool FindSilence(int stepid);       /* 该Stepid下是否设置Silence */
};

