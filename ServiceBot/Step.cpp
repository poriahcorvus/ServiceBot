#include "Step.h"

Step::Step() {}
Step::~Step() {}

void Step::UpdateStep(string str)   /* 更新Step */
{
    (this->stepdata).push_back(str);
}

int Step::FindStep(string str)      /* Step对应的Proc名 所对应的Stepid */
{
    for (int i = 0; i < (this->stepdata).size(); i++) {
        if ((this->stepdata)[i] == str)
            return i;
    }
    return -1;
}

string Step::FindProc(int stepid)   /* 返回Stepid对应的Step(Proc)名字 */
{
    if (stepid < (this->stepdata).size()) {
        return (this->stepdata)[stepid];
    }
    return SERVICE_BROKEN;
}

int Step::CountStep()   /* 返回脚本中Step总数 */
{
    return (this->stepdata).size();
}
