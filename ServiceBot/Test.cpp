#include "Test.h"

void Test(Step sp, Speak sk, Listen ln, Branch bh, Silence se, Default dt, Exit et)		/* ����׮����ӡ������Ϣ */
{
	for (int i = 0; i < sp.CountStep(); i++) {
		cout << endl;
		cout << sp.FindProc(i) << endl;
		cout << "�ͷ���˵�� " << sk.BotSpeak(i) << endl;
		if (et.IsExit(i))
			cout << "��ת exitProc���˳�" << endl;
		else {
			cout << "�ͷ������û�" << ln.GetTime(i) << "s" << endl;
			cout << "�����û�����" << endl;
			vector<string> curkeylist = bh.GetCurKey(i);
			for (int j = 0; j < curkeylist.size(); j++) {
				cout << "�����⵽ " << curkeylist[j] << " ������ת ";
				int idpos = bh.FindKey(curkeylist[j], i);
				cout << bh.FindNextStep(idpos) << endl;
			}
			if(se.FindSilence(i))
				cout << "����û�δ���룬����Silence����ת silencePro" << endl;
			cout << "����û����벻�������趨�Ĺؼ��ʣ�����Default����ת " << dt.FindDefault(i) << endl;
		}
	}
}