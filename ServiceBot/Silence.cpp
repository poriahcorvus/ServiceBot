#include "Silence.h"

Silence::Silence() {}
Silence::~Silence() {}

void Silence::UpdateSilence(int stepid)     /* ����Silence */
{
    (this->silencestep).push_back(stepid);
}

bool Silence::FindSilence(int stepid)   /* ��Stepid���Ƿ�����Silence */
{
    for (int i = 0; i < (this->silencestep).size(); i++) {
        if ((this->silencestep)[i] == stepid)
            return true;
    }
    return false;
}