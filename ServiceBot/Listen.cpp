#include "Listen.h"

Listen::Listen() {}
Listen::~Listen() {}

void Listen::UpdateListen(string str, int stepid)   /* 更新Listen */
{
    (this->listendata).push_back(stoi(str));
    (this->listenstep).push_back(stepid);
}

int Listen::GetTime(int stepid) /* Listen的时间 */
{
    for (int i = 0; i < (this->listenstep).size(); i++) {
        if ((this->listenstep)[i] == stepid)
            return (this->listendata)[i];
    }
    return -1;
}