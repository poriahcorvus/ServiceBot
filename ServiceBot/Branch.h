#pragma once
#include "global.h"

class Branch
{
private:
    vector<int> branchstep;     // Stepid
    vector<string> branchdata;  // Branch��ת�ķ�֧
    vector<string> keywords;    // �ؼ���
public:
    Branch();
    ~Branch();
    void UpdateBranch(string str, int stepid);  /* ����Branch */
    int FindKey(string user, int stepid);       /* ���û�������Ѱ�ҹؼ��֣����ض�Ӧ��Stepid */
    string FindNextStep(int idpos);             /* Stepid��Ӧ��Proc�� */
    vector<string> GetCurKey(int stepid);       /* ���ص�ǰStep�µ����йؼ��� */
    //void PrintKey();
};

