#pragma once
#include "global.h"

class Branch
{
private:
    vector<int> branchstep;     // Stepid
    vector<string> branchdata;  // Branch跳转的分支
    vector<string> keywords;    // 关键词
public:
    Branch();
    ~Branch();
    void UpdateBranch(string str, int stepid);  /* 更新Branch */
    int FindKey(string user, int stepid);       /* 在用户输入中寻找关键字，返回对应的Stepid */
    string FindNextStep(int idpos);             /* Stepid对应的Proc名 */
    vector<string> GetCurKey(int stepid);       /* 返回当前Step下的所有关键词 */
    //void PrintKey();
};

