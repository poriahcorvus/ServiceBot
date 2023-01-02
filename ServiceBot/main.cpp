#include "global.h"
#include "Parse.h"
#include "Test.h"

string user = "";   // 记录用户输入

DWORD WINAPI UserInput(LPVOID lpParameter)  /* 用户输入 */
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
    string filename = "";   // 所选用的脚本名
    cin >> filename;
    parse.ParseInit(filename, sp, sk, ln, bh, se, dt, et);
    parse.ParseRun(sp, sk, ln, bh, se, dt, et);
    //Test(sp, sk, ln, bh, se, dt, et);

    return 0;
}