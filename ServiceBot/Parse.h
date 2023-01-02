#pragma once
#include "global.h"
#include "Step.h"
#include "Speak.h"
#include "Listen.h"
#include "Branch.h"
#include "Silence.h"
#include "Default.h"
#include "Exit.h"

class Parse
{
public:
    Parse();
    ~Parse();
    void ParseInit(string filename, Step& sp, Speak& sk, Listen& ln, Branch& bh, Silence& se, Default& dt, Exit& et);   /* ��ʼ���������ű� */
    void ParseRun(Step sp, Speak sk, Listen ln, Branch bh, Silence se, Default dt, Exit et);                            /* �����û��������� */
    bool IsInput(int t);                                                                                                /* ��ʱ���룬��ʱ����ΪSilence */
};

