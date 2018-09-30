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
			DrawStringToHandle(MWX + 64, MWY + 64, "よう、そこの嬢ちゃん。あんた商人だろ？ちょっと頼まれてくれや。", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();		
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "内容によるわ。", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "なに、ちょっとこいつを買い取って欲しいのさ。", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "これは・・・", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "良い織物だ。でもなんでこれを？", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "得意先が倒れちまってな、売る当てが無いんだ。", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "一箱70レイルで300箱だ、悪くない話だろ？", GetColor(255, 255, 255), init.FontHandle);
			WaitClick();
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn();

			DrawStringToHandle(MWX + 64, MWY + 64, "どうする？", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[62], BtnY[62], "買う", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[63], BtnY[63], "買わない", GetColor(255, 255, 255), init.FontHandle);

			if (EventSwitch == 62) {
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "わかった、一箱65レイルでどう？", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "68だ。それ以上はまけないぞ。", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "交渉成立ね。小切手でいいかしら？", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "ああ、20400レイルきっちりいただいたぜ。ありがとうな。", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "こちらこそ、良い取引ができてよかったわ。また会いましょう。", GetColor(255, 255, 255), init.FontHandle);

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
				DrawStringToHandle(MWX + 64, MWY + 64, "ごめんなさい、今は余裕がないの。他をあたってちょうだい。", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "そうか、悪かったな無理言って。縁があったらそのときはよろしくな。", GetColor(255, 255, 255), init.FontHandle);
				WaitClick();
				ResetCity();
				DrawStringToHandle(MWX + 64, MWY + 64, "こちらこそよろしく。また会いましょう。", GetColor(255, 255, 255), init.FontHandle);
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