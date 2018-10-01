#pragma once
#include "class.h"
#include "DxLib.h"

extern INIT init;

void SYSTEM::EventFunc(const char* string) {

	ResetCity();
	DrawStringToHandle(MWX + 64, MWY + 64, string, GetColor(255, 255, 255), init.FontHandle);
	WaitClick();
}

void SYSTEM::EventEnd(int Num) {

	ETalkCount = 0;
	EventFlag[Num] = FALSE;
	Stopper = TRUE;
	BtnSwitch = Sw_CITY;
	ResetCity();
}

void SYSTEM::Event(int Num) {

	switch (Num) {

	case 0:
		switch (ETalkCount) {
		case 0:
	//		ResetCity();
	//		DrawStringToHandle(MWX + 64, MWY + 64, "�悤�A�����̏삿���B���񂽏��l����H������Ɨ��܂�Ă����B", GetColor(255, 255, 255), init.FontHandle);
	//		WaitClick();	
			EventFunc("�悤�A�����̏삿���B���񂽏��l����H������Ɨ��܂�Ă����B");
			EventFunc("���e�ɂ���B");
			EventFunc("�ȂɁA������Ƃ����𔃂�����ė~�����̂��B");
			EventFunc("����́E�E�E");
			EventFunc("�ǂ��D�����B�ł��Ȃ�ł�����H");
			EventFunc("���Ӑ悪�|�ꂿ�܂��ĂȁA���铖�Ă������񂾁B");
			EventFunc("�ꔠ70���C����300�����A�����Ȃ��b����H");
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn();

			DrawStringToHandle(MWX + 64, MWY + 64, "�ǂ�����H", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[62], BtnY[62], "����", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[63], BtnY[63], "����Ȃ�", GetColor(255, 255, 255), init.FontHandle);
			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc("�킩�����A�ꔠ65���C���łǂ��H");
				EventFunc("68���B����ȏ�͂܂��Ȃ����B");
				EventFunc("�������ˁB���؎�ł���������H");
				EventFunc("�����A20400���C���������肢�����������B���肪�Ƃ��ȁB");
				EventFunc("�����炱���A�ǂ�������ł��Ă悩������B�܂���܂��傤�B");

				SearchEmpty(16);
				her.CargoPrice[SlotNumber] += 20400;
				her.Cargo[SlotNumber] += 300;
				her.Money -= 20400;
				her.CargoWeight += 300;
				her.HiddenID[SlotNumber] = 16;

				EventEnd(Num);
			}
			else if (EventSwitch == 63) {
				EventFunc("���߂�Ȃ����A���͗]�T���Ȃ��́B�����������Ă��傤�����B");
				EventFunc("�������A���������Ȗ��������āB�����������炻�̂Ƃ��͂�낵���ȁB");
				EventFunc("�����炱����낵���B�܂���܂��傤�B");
				
				EventEnd(Num);

			}
			break;
		}
		break;
	}
}