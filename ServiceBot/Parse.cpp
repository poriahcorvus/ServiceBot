#include "Parse.h"

Parse::Parse() {}
Parse::~Parse() {}

void Parse::ParseInit(string filename, Step& sp, Speak& sk, Listen& ln, Branch& bh, Silence& se, Default& dt, Exit& et)     /* ��ʼ���������ű� */
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
        int pos = 0; // ��¼λ��

        // �ҵ� Step
        if (str.find("Step") != -1) {
            pos = str.find("Step");
            str = str.substr(pos + 5);
            sp.UpdateStep(str);
            stepid += 1;
        }

        // �ҵ� Speak
        if (str.find("Speak") != -1) {
            pos = str.find("Speak");
            str = str.substr(pos + 6);
            sk.UpdateSpeak(str, stepid - 1);
        }

        // �ҵ� Listen
        if (str.find("Listen") != -1) {
            pos = str.find("Listen");
            str = str.substr(pos + 7);
            ln.UpdateListen(str, stepid - 1);
        }

        // �ҵ� Branch
        if (str.find("Branch") != -1) {
            pos = str.find("Branch");
            str = str.substr(pos + 7);
            bh.UpdateBranch(str, stepid - 1);
        }

        // �ҵ� Silence
        if (str.find("Silence") != -1) {
            se.UpdateSilence(stepid - 1);
        }

        // �ҵ� Default
        if (str.find("Default") != -1) {
            pos = str.find("Default");
            str = str.substr(pos + 8);
            dt.UpdataDefault(str, stepid - 1);
        }

        // �ҵ� Exit
        if (str.find("Exit") != -1) {
            et.UpdateExit(stepid - 1);
        }
    }
    botfile.close();
}

void Parse::ParseRun(Step sp, Speak sk, Listen ln, Branch bh, Silence se, Default dt, Exit et)  /* �����û��������� */
{
    int stepid = 0;     // ��ʼ״̬Ϊ0
    while (1) {
        cout << "�ͷ���" << sk.BotSpeak(stepid) << endl;

        // �Ƿ���Exit
        if (et.IsExit(stepid) == true)
            break;

        cout << "�ң�";

        // �Ƿ�Silence
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

        // ���ҹؼ���
    }
}

bool Parse::IsInput(int t)  /* ��ʱ���룬��ʱ����ΪSilence */
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