#include "Default.h"

Default::Default() {}
Default::~Default() {}

void Default::UpdataDefault(string str, int stepid)     /* 更新Default */
{
    (this->defaultstep).push_back(stepid);
    (this->defaultdata).push_back(str);
}

string Default::FindDefault(int stepid)     /* 返回当前Stepid下所执行的Default */
{
    for (int i = 0; i < (this->defaultstep).size(); i++) {
        if ((this->defaultstep)[i] == stepid)
            return (this->defaultdata)[i];
    }
    return SERVICE_BROKEN;
}