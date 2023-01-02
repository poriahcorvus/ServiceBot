#include "Silence.h"

Silence::Silence() {}
Silence::~Silence() {}

void Silence::UpdateSilence(int stepid)     /* 更新Silence */
{
    (this->silencestep).push_back(stepid);
}

bool Silence::FindSilence(int stepid)   /* 该Stepid下是否设置Silence */
{
    for (int i = 0; i < (this->silencestep).size(); i++) {
        if ((this->silencestep)[i] == stepid)
            return true;
    }
    return false;
}