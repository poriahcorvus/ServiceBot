#pragma once
#include "global.h"

class Speak
{
private:
    vector<int> speakstep;      // Stepid
    vector<string> speakdata;   // Speak的内容
public:
    Speak();
    ~Speak();
    void UpdateSpeak(string str, int stepid);   /* 更新Speak */
    string BotSpeak(int stepid);                /* 输出客服说的话 */
    //void PrintSpeak();
};

