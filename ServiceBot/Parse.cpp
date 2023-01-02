#include "Parse.h"

Parse::Parse() {}
Parse::~Parse() {}

void Parse::ParseInit(string filename, Step& sp, Speak& sk, Listen& ln, Branch& bh, Silence& se, Default& dt, Exit& et)     /* 初始化，解析脚本 */
{
    ifstream botfile;
    botfile.open(filename, ios::in);

    if (!botfile.is_open()) {
        cout << SYSTEM_ERROR << endl;
        exit(0);
    }

    string str = "";
    int stepid = 0;
    while (getline(botfile, str)) {
        int pos = 0; // 记录位置

        // 找到 Step
        if (str.find("Step") != -1) {
            pos = str.find("Step");
            str = str.substr(pos + 5);
            sp.UpdateStep(str);
            stepid += 1;
        }

        // 找到 Speak
        if (str.find("Speak") != -1) {
            pos = str.find("Speak");
            str = str.substr(pos + 6);
            sk.UpdateSpeak(str, stepid - 1);
        }

        // 找到 Listen
        if (str.find("Listen") != -1) {
            pos = str.find("Listen");
            str = str.substr(pos + 7);
            ln.UpdateListen(str, stepid - 1);
        }

        // 找到 Branch
        if (str.find("Branch") != -1) {
            pos = str.find("Branch");
            str = str.substr(pos + 7);
            bh.UpdateBranch(str, stepid - 1);
        }

        // 找到 Silence
        if (str.find("Silence") != -1) {
            se.UpdateSilence(stepid - 1);
        }

        // 找到 Default
        if (str.find("Default") != -1) {
            pos = str.find("Default");
            str = str.substr(pos + 8);
            dt.UpdataDefault(str, stepid - 1);
        }

        // 找到 Exit
        if (str.find("Exit") != -1) {
            et.UpdateExit(stepid - 1);
        }
    }
    botfile.close();
}

void Parse::ParseRun(Step sp, Speak sk, Listen ln, Branch bh, Silence se, Default dt, Exit et)  /* 根据用户输入运行 */
{
    int stepid = 0;     // 初始状态为0
    while (1) {
        cout << "客服：" << sk.BotSpeak(stepid) << endl;

        // 是否在Exit
        if (et.IsExit(stepid) == true)
            break;

        cout << "我：";

        // 是否Silence
        if (IsInput(ln.GetTime(stepid)) == false) {
            cout << endl;
            stepid = sp.FindStep("silenceProc");
        }
        else {
            int idpos = bh.FindKey(user, stepid);
            if (idpos != -1) {
                string nextstep = bh.FindNextStep(idpos);
                if (sp.FindStep(nextstep) != -1)
                    stepid = sp.FindStep(nextstep);
            }
            else {
                string nextstep = dt.FindDefault(stepid);
                stepid = sp.FindStep(nextstep);
            }
        }

        // 查找关键词
    }
}

bool Parse::IsInput(int t)  /* 限时输入，超时则认为Silence */
{
    HANDLE hThread = CreateThread(NULL, 0, UserInput, NULL, 0, NULL);
    int signal = WaitForSingleObject(hThread, t * 1000);
    if (signal != WAIT_OBJECT_0)
        TerminateProcess(hThread, -1);
    if (user.length() != 0)
        return true;
    else
        return false;
}