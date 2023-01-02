#pragma once
#include "global.h"

class Step
{
private:
    vector<string> stepdata;    // Proc

public:
    Step();
    ~Step();
    void UpdateStep(string str);    /* ����Step */
    int FindStep(string str);       /* Step��Ӧ��Proc�� ����Ӧ��Stepid */
    string FindProc(int stepid);    /* ����Stepid��Ӧ��Step(Proc)���� */
    int CountStep();                /* ���ؽű���Step���� */
};

