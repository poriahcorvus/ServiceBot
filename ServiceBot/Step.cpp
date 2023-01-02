#include "Step.h"

Step::Step() {}
Step::~Step() {}

void Step::UpdateStep(string str)   /* ����Step */
{
    (this->stepdata).push_back(str);
}

int Step::FindStep(string str)      /* Step��Ӧ��Proc�� ����Ӧ��Stepid */
{
    for (int i = 0; i < (this->stepdata).size(); i++) {
        if ((this->stepdata)[i] == str)
            return i;
    }
    return -1;
}

string Step::FindProc(int stepid)   /* ����Stepid��Ӧ��Step(Proc)���� */
{
    if (stepid < (this->stepdata).size()) {
        return (this->stepdata)[stepid];
    }
    return SERVICE_BROKEN;
}

int Step::CountStep()   /* ���ؽű���Step���� */
{
    return (this->stepdata).size();
}
