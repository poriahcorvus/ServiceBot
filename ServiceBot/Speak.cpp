#include "Speak.h"

Speak::Speak() {}
Speak::~Speak() {}

void Speak::UpdateSpeak(string str, int stepid)     /* 更新Speak */
{
    (this->speakdata).push_back(str);
    (this->speakstep).push_back(stepid);
}

string Speak::BotSpeak(int stepid)      /* 输出客服说的话 */
{
    for (int i = 0; i < (this->speakstep).size(); i++) {
        if ((this->speakstep)[i] == stepid)
            return (this->speakdata)[i];
    }
    return SERVICE_BUSY;
}

/*
void Speak::PrintSpeak()
{
    for (int i = 0; i < (this->speakdata).size(); i++) {
        cout << (this->speakdata)[i] << endl;
    }
}
*/
