#include "Exit.h"

Exit::Exit() {}
Exit::~Exit() {}

void Exit::UpdateExit(int stepid)   /* ����Exit */
{
    (this->exitstep).push_back(stepid);
}

bool Exit::IsExit(int stepid)   /* �жϸ�Stepid���Ƿ�ִ��Exit */
{
    for (int i = 0; i < (this->exitstep).size(); i++) {
        if ((this->exitstep)[i] == stepid)
            return true;
    }
    return false;
}