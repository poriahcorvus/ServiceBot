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
    void ParseInit(string filename, Step& sp, Speak& sk, Listen& ln, Branch& bh, Silence& se, Default& dt, Exit& et);   /* 初始化，解析脚本 */
    void ParseRun(Step sp, Speak sk, Listen ln, Branch bh, Silence se, Default dt, Exit et);                            /* 根据用户输入运行 */
    bool IsInput(int t);                                                                                                /* 限时输入，超时则认为Silence */
};

