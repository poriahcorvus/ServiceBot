#include "Default.h"

Default::Default() {}
Default::~Default() {}

void Default::UpdataDefault(string str, int stepid)     /* ����Default */
{
    (this->defaultstep).push_back(stepid);
    (this->defaultdata).push_back(str);
}

string Default::FindDefault(int stepid)     /* ���ص�ǰStepid����ִ�е�Default */
{
    for (int i = 0; i < (this->defaultstep).size(); i++) {
        if ((this->defaultstep)[i] == stepid)
            return (this->defaultdata)[i];
    }
    return SERVICE_BROKEN;
}