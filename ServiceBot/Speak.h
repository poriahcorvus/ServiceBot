#pragma once
#include "global.h"

class Speak
{
private:
    vector<int> speakstep;      // Stepid
    vector<string> speakdata;   // Speak������
public:
    Speak();
    ~Speak();
    void UpdateSpeak(string str, int stepid);   /* ����Speak */
    string BotSpeak(int stepid);                /* ����ͷ�˵�Ļ� */
    //void PrintSpeak();
};

