#pragma once
#include "global.h"

class Default
{
private:
    vector<int> defaultstep;    // Stepid
    vector<string> defaultdata; // Default��ת�����
public:
    Default();
    ~Default();
    void UpdataDefault(string str, int stepid);     /* ����Default */
    string FindDefault(int stepid);                 /* ���ص�ǰStepid����ִ�е�Default */
};

