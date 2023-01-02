#include "Branch.h"

Branch::Branch() {}
Branch::~Branch() {}

void Branch::UpdateBranch(string str, int stepid)   /* ����Branch */
{
    int p = str.find(",");
    string key = str.substr(0, p);      // �û�����Ĺؼ���
    string proc = str.substr(p + 1);    // ��ת��Step
    (this->keywords).push_back(key);
    (this->branchdata).push_back(proc);
    (this->branchstep).push_back(stepid);
}

int Branch::FindKey(string user, int stepid)    /* ���û�������Ѱ�ҹؼ��֣����ض�Ӧ��Stepid */
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

string Branch::FindNextStep(int idpos)  /* Stepid��Ӧ��Proc�� */
{
    return (this->branchdata)[idpos];
}

vector<string> Branch::GetCurKey(int stepid)    /* ���ص�ǰStep�µ����йؼ��� */
{
    vector<string> curkeylist;
    for (int i = 0; i < (this->keywords).size(); i++) {
        if ((this->branchstep)[i] == stepid)
            curkeylist.push_back((this->keywords)[i]);
    }
    return curkeylist;
}