#pragma once
#include "global.h"

class Silence
{
private:
    vector<int> silencestep;    // Stepid
public:
    Silence();
    ~Silence();
    void UpdateSilence(int stepid);     /* ����Silence */
    bool FindSilence(int stepid);       /* ��Stepid���Ƿ�����Silence */
};

