#include "Branch.h"

Branch::Branch() {}
Branch::~Branch() {}

void Branch::UpdateBranch(string str, int stepid)   /* 更新Branch */
{
    int p = str.find(",");
    string key = str.substr(0, p);      // 用户输入的关键词
    string proc = str.substr(p + 1);    // 跳转的Step
    (this->keywords).push_back(key);
    (this->branchdata).push_back(proc);
    (this->branchstep).push_back(stepid);
}

int Branch::FindKey(string user, int stepid)    /* 在用户输入中寻找关键字，返回对应的Stepid */
{
    for (int i = 0; i < (this->branchdata).size(); i++) {
        if (user.find((this->keywords)[i]) != -1 && (this->branchstep)[i] == stepid) {
            return i;
        }
    }
    return -1;
}

/*
void Branch::PrintKey()
{
    for (int i = 0; i < (this->keywords).size(); i++)
        cout << (this->keywords)[i] << endl;
}
*/

string Branch::FindNextStep(int idpos)  /* Stepid对应的Proc名 */
{
    return (this->branchdata)[idpos];
}

vector<string> Branch::GetCurKey(int stepid)    /* 返回当前Step下的所有关键词 */
{
    vector<string> curkeylist;
    for (int i = 0; i < (this->keywords).size(); i++) {
        if ((this->branchstep)[i] == stepid)
            curkeylist.push_back((this->keywords)[i]);
    }
    return curkeylist;
}