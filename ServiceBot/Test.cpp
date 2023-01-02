#include "Test.h"

void Test(Step sp, Speak sk, Listen ln, Branch bh, Silence se, Default dt, Exit et)		/* 测试桩，打印所有信息 */
{
	for (int i = 0; i < sp.CountStep(); i++) {
		cout << endl;
		cout << sp.FindProc(i) << endl;
		cout << "客服将说出 " << sk.BotSpeak(i) << endl;
		if (et.IsExit(i))
			cout << "跳转 exitProc：退出" << endl;
		else {
			cout << "客服聆听用户" << ln.GetTime(i) << "s" << endl;
			cout << "检索用户输入" << endl;
			vector<string> curkeylist = bh.GetCurKey(i);
			for (int j = 0; j < curkeylist.size(); j++) {
				cout << "如果检测到 " << curkeylist[j] << " ，将跳转 ";
				int idpos = bh.FindKey(curkeylist[j], i);
				cout << bh.FindNextStep(idpos) << endl;
			}
			if(se.FindSilence(i))
				cout << "如果用户未输入，进入Silence，跳转 silencePro" << endl;
			cout << "如果用户输入不包含已设定的关键词，进入Default，跳转 " << dt.FindDefault(i) << endl;
		}
	}
}