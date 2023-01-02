#include "Speak.h"

Speak::Speak() {}
Speak::~Speak() {}

void Speak::UpdateSpeak(string str, int stepid)     /* ����Speak */
{
    (this->speakdata).push_back(str);
    (this->speakstep).push_back(stepid);
}

string Speak::BotSpeak(int stepid)      /* ����ͷ�˵�Ļ� */
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
