#include "global.h"
#include "Parse.h"
#include "Test.h"

string user = "";   // ��¼�û�����

DWORD WINAPI UserInput(LPVOID lpParameter)  /* �û����� */
{
    user = "";
    cin >> user;
    return 0;
}


int main()
{
    Step sp;
    Speak sk;
    Listen ln;
    Branch bh;
    Silence se;
    Default dt;
    Exit et;
    Parse parse;
    string filename = "";   // ��ѡ�õĽű���
    cin >> filename;
    parse.ParseInit(filename, sp, sk, ln, bh, se, dt, et);
    parse.ParseRun(sp, sk, ln, bh, se, dt, et);
    //Test(sp, sk, ln, bh, se, dt, et);

    return 0;
}