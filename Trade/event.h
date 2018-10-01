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
	//		DrawStringToHandle(MWX + 64, MWY + 64, "よう、そこの嬢ちゃん。あんた商人だろ？ちょっと頼まれてくれや。", GetColor(255, 255, 255), init.FontHandle);
	//		WaitClick();	
			EventFunc("よう、そこの嬢ちゃん。あんた商人だろ？ちょっと頼まれてくれや。");
			EventFunc("内容によるわ。");
			EventFunc("なに、ちょっとこいつを買い取って欲しいのさ。");
			EventFunc("これは・・・");
			EventFunc("良い織物だ。でもなんでこれを？");
			EventFunc("得意先が倒れちまってな、売る当てが無いんだ。");
			EventFunc("一箱70レイルで300箱だ、悪くない話だろ？");
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn();

			DrawStringToHandle(MWX + 64, MWY + 64, "どうする？", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[62], BtnY[62], "買う", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[63], BtnY[63], "買わない", GetColor(255, 255, 255), init.FontHandle);
			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc("わかった、一箱65レイルでどう？");
				EventFunc("68だ。それ以上はまけないぞ。");
				EventFunc("交渉成立ね。小切手でいいかしら？");
				EventFunc("ああ、20400レイルきっちりいただいたぜ。ありがとうな。");
				EventFunc("こちらこそ、良い取引ができてよかったわ。また会いましょう。");

				SearchEmpty(16);
				her.CargoPrice[SlotNumber] += 20400;
				her.Cargo[SlotNumber] += 300;
				her.Money -= 20400;
				her.CargoWeight += 300;
				her.HiddenID[SlotNumber] = 16;

				EventEnd(Num);
			}
			else if (EventSwitch == 63) {
				EventFunc("ごめんなさい、今は余裕がないの。他をあたってちょうだい。");
				EventFunc("そうか、悪かったな無理言って。縁があったらそのときはよろしくな。");
				EventFunc("こちらこそよろしく。また会いましょう。");
				
				EventEnd(Num);

			}
			break;
		}
		break;
	}
}