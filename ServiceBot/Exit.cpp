#include "Exit.h"

Exit::Exit() {}
Exit::~Exit() {}

void Exit::UpdateExit(int stepid)   /* 更新Exit */
{
    (this->exitstep).push_back(stepid);
}

bool Exit::IsExit(int stepid)   /* 判断该Stepid下是否执行Exit */
{
    for (int i = 0; i < (this->exitstep).size(); i++) {
        if ((this->exitstep)[i] == stepid)
            return true;
    }
    return false;
}