#pragma once
#include "class.h"
#include "DxLib.h"

extern INIT init;

void SYSTEM::Event(int Num) {

	switch (Num) {

	case 0:
		switch (ETalkCount) {
		case 0:
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "�悤�A�����̏삿���B���񂽏��l����H������Ɨ��܂�Ă����B", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();		
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "���e�ɂ���B", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "�ȂɁA������Ƃ����𔃂�����ė~�����̂��B", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "����́E�E�E", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "�ǂ��D�����B�ł��Ȃ�ł�����H", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "���Ӑ悪�|�ꂿ�܂��ĂȁA���铖�Ă������񂾁B", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "�ꔠ70���C����300�����A�����Ȃ��b����H", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn();

			DrawStringToHandle(MWX + 64, MWY + 64, "�ǂ�����H", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[62], BtnY[62], "����", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[63], BtnY[63], "����Ȃ�", GetColor(255, 255, 255), init.FontHandle);

			if (EventSwitch == 62) {
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "�킩�����A�ꔠ65���C���łǂ��H", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "68���B����ȏ�͂܂��Ȃ����B", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "�������ˁB���؎�ł���������H", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "�����A20400���C���������肢�����������B���肪�Ƃ��ȁB", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "�����炱���A�ǂ�������ł��Ă悩������B�܂���܂��傤�B", GetColor(255, 255, 255), init.FontHandle);

				SearchEmpty(16);
				her.CargoPrice[SlotNumber] += 20400;
				her.Cargo[SlotNumber] += 300;
				her.Money -= 20400;
				her.CargoWeight += 300;
				her.HiddenID[SlotNumber] = 16;

				WaitClick();
				ETalkCount = 0;
				EventFlag[0] = FALSE;
				BtnSwitch = Sw_CITY;
				ResetCity();
			}
			else if (EventSwitch == 63) {
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "���߂�Ȃ����A���͗]�T���Ȃ��́B�����������Ă��傤�����B", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "�������A���������Ȗ��������āB�����������炻�̂Ƃ��͂�낵���ȁB", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "�����炱����낵���B�܂���܂��傤�B", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ETalkCount = 0;
				EventFlag[0] = FALSE;
				BtnSwitch = Sw_CITY;
				ResetCity();

			}
			break;
		}
		break;
	}
}