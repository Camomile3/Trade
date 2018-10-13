#include "DxLib.h"
#include "class.h"

#define M_PI	3.14159265358979323846
#define DEG_TO_RAD(deg) (((deg)/360)*2*M_PI)
#define RAD_TO_DEG(rad) (((rad)/2/M_PI)*360)

extern INIT init;
extern FUN fun;
extern SYSTEM sys;
extern HEROINE her;
extern GOODS Goods[32];
extern CITY City[16];
extern MARKET Market[16][32];
extern MARKET HerMarket[16][32];
extern TRANSPORT Trans[8];

void SYSTEM::MapBtnOver(int i) {

	int y = MultiResoIntY(8);

	switch (i) {
	case 0:
		//å¯â âπÇ‡ÇµÇ≠ÇÕÉJÅ[É\ÉãÇ™îΩâûÇ∑ÇÈèàóùÇì¸ÇÍÇÈó\íË
		break;
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 48:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[48] + MultiResoIntX(58), BtnY[48] + y, "Cargo", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 49:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[49] + MultiResoIntX(34), BtnY[49] + y, "Transport", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 50:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[50] + MultiResoIntX(36), BtnY[50] + y, "Financial", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 51:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[51] + MultiResoIntX(58), BtnY[51] + y, "Quest", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 52:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[52] + MultiResoIntX(54), BtnY[52] + y, "Prices", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 53:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[53] + MultiResoIntX(36), BtnY[53] + y, "SaveGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 54:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[54] + MultiResoIntX(36), BtnY[54] + y, "LoadGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 55:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[55] + MultiResoIntX(54), BtnY[55] + y, "Option", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 56:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[56] + MultiResoIntX(36), BtnY[56] + y, "QuitGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::MapBtnOut(int OveredBtn) {

	int y = MultiResoIntY(8);

	switch (OveredBtn) {
	case 48:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[48] + MultiResoIntX(58), BtnY[48] + y, "Cargo", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 49:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[49] + MultiResoIntX(34), BtnY[49] + y, "Transport", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 50:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[50] + MultiResoIntX(36), BtnY[50] + y, "Financial", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 51:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[51] + MultiResoIntX(58), BtnY[51] + y, "Quest", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 52:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[52] + MultiResoIntX(54), BtnY[52] + y, "Prices", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 53:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[53] + MultiResoIntX(36), BtnY[53] + y, "SaveGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 54:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[54] + MultiResoIntX(36), BtnY[54] + y, "LoadGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 55:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[55] + MultiResoIntX(54), BtnY[55] + y, "Option", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 56:
		ResetMap();
		SpawnHer();
		DrawStringToHandle(BtnX[56] + MultiResoIntX(36), BtnY[56] + y, "QuitGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	}
}


//É{É^ÉìÇí«â¡Ç∑ÇÈÇ∆Ç´í«â¡
void SYSTEM::MapBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		MoveRoute();
		break;
	case 48:
		BtnSwitch = Sw_CARGO;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		CargoData();
		break;
	case 49:
		BtnSwitch = Sw_TRANS;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		TransData();
		break;
	case 50:
		BtnSwitch = Sw_FINAN;
		DrawWindow(60, 140, 5, 16);
		DrawWindow(980, 140, 5, 16);
		DrawMessageWindow();
		FinanData();
		break;
	case 51:
		BtnSwitch = Sw_QUEST;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		QuestData();
		break;
	case 52:
		BtnSwitch = Sw_PRICES;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		PricesData();
		break;
	case 53:
		BtnSwitch = Sw_SAVE;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		SaveData();
		break;
	case 54:
		BtnSwitch = Sw_LOAD;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		LoadData();
		break;
	case 55:
		BtnSwitch = Sw_OPTION;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		DrawOptionString();
		OptionData();
		break;
	case 56:
		BtnSwitch = Sw_QUIT;
		DrawMessageWindow();
		break;
	}
}

void SYSTEM::CargoBtnOver(int i) {

	switch (i) {
	case 63:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_CARGO;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		CargoData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::CargoBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_CARGO;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		CargoData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::CargoBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		BtnSwitch = Sw_MMAP;
		ResetMap();
		SpawnHer();
		break;
	case 1:
		break;
	}
}

void SYSTEM::CargoData() {

	char Temp[32];
	int y = MultiResoIntY(160);

	DrawStringToHandle(MultiResoIntX(580), y, "ñºëO", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(780), y, "êîó ", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(980), y, "îÉíl", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(1180), y, "àÍå¬ìñÇΩÇËîÉíl", GetColor(0, 0, 0), init.FontHandle);

	for (int i = 1; i < 8; i++) {
		BtnX[i] = 580;
		BtnY[i] = 200 + i * 42;
	}

	BtnX[63] = MWX + 640;
	BtnY[63] = MWY + 140;
	BtnW[63] = 90;
	BtnH[63] = 42;

	MultiResoBtn(63);

	DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 255, 255), init.FontHandle);

	for (int i = 0; i < 8; i++) {
		if (her.Cargo[i] != 0) {
			DrawStringToHandle(BtnX[i + 1], BtnY[i + 1], Goods[her.HiddenID[i]].Name, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.Cargo[i]);
			DrawStringToHandle(BtnX[i + 1] + 200, BtnY[i + 1], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.CargoPrice[i]);
			DrawStringToHandle(BtnX[i + 1] + 400, BtnY[i + 1], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.CargoPrice[i] / her.Cargo[i]);
			DrawStringToHandle(BtnX[i + 1] + 600, BtnY[i + 1], Temp, GetColor(0, 0, 0), init.FontHandle);
		}
		else
			break;
	}
}

void SYSTEM::TransBtnOver(int i) {

	switch (i) {
	case 63:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_TRANS;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		TransData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::TransBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_TRANS;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		TransData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::TransBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		BtnSwitch = Sw_MMAP;
		ResetMap();
		SpawnHer();
		break;
	case 1:
		break;
	}
}

void SYSTEM::TransData() {

	TCHAR Temp[32];
	int x = 0;
	int y = 0;
	int z = MultiResoIntY(160);

	DrawStringToHandle(MultiResoIntX(580), z, "ñºëO", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(740), z, "êîó ", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(900), z, "óAëóóÕ", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(1060), z, "çáåv", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(1220), z, "à⁄ìÆÉ^ÉCÉv", GetColor(0, 0, 0), init.FontHandle);

	for (int i = 0; i < 8; i++) {
		BtnX[i] = 580;
		BtnY[i] = 200 + i * 64;
		MultiResoBtn(i);
	}
	for (int i = 0; i < 8; i++) {
		if (her.Transport[i] != 0) {
			sprintf_s(Temp, 32, "%s", Trans[i].Name);
			DrawStringToHandle(BtnX[i], BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.Transport[i]);
			DrawStringToHandle(BtnX[i] + MultiResoIntX(160), BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", Trans[i].Capacity);
			DrawStringToHandle(BtnX[i] + MultiResoIntX(160 * 2), BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.Transport[i] * Trans[i].Capacity);
			DrawStringToHandle(BtnX[i] + MultiResoIntX(160 * 3), BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
			if (Trans[i].Sea == FALSE)
				DrawStringToHandle(BtnX[i] + MultiResoIntX(160 * 4), BtnY[i], "ó§", GetColor(0, 0, 0), init.FontHandle);
			else
				DrawStringToHandle(BtnX[i] + MultiResoIntX(160 * 4), BtnY[i], "äC", GetColor(0, 0, 0), init.FontHandle);
		}
	}
}

void SYSTEM::FinanBtnOver(int i) {

	switch (i) {
	case 63:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_FINAN;
		DrawWindow(60, 140, 5, 16);
		DrawWindow(980, 140, 5, 16);
		DrawMessageWindow();
		FinanData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::FinanBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_FINAN;
		DrawWindow(60, 140, 5, 16);
		DrawWindow(980, 140, 5, 16);
		DrawMessageWindow();
		FinanData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::FinanBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		BtnSwitch = Sw_MMAP;
		ResetMap();
		SpawnHer();
		break;
	case 1:
		break;
	}
}

void SYSTEM::FinanData() {

	int x = 0;
	int y = 0;
	const char* Temp[64];
	int i = 0;

	DrawStringToHandle(MultiResoIntX(410), MultiResoIntY(160), "ë›éÿëŒè∆ï\", GetColor(0, 0, 0), init.FontHandle);

	Temp[0] = "åªã‡";
	Temp[1] = "è§ïi";
	Temp[2] = "";
	Temp[3] = "ó¨ìÆéëéYçáåv";
	Temp[4] = "";
	Temp[5] = "åöï®";
	Temp[6] = "ìyín";
	Temp[7] = "îıïi";
	Temp[8] = "é‘óºâ^î¿ãÔ";
	Temp[9] = "";
	Temp[10] = "å≈íËéëéYçáåv";
	Temp[11] = "éëéYçáåv";

	Temp[12] = "éÿì¸ã‡";
	Temp[13] = "ñ¢ï•ã‡";
	Temp[14] = "";
	Temp[15] = "ïâç¬çáåv";
	Temp[16] = "";
	Temp[17] = "éëñ{ã‡";
	Temp[18] = "";
	Temp[19] = "";
	Temp[20] = "ìñä˙èÉóòâv";
	Temp[21] = "";
	Temp[22] = "èÉéëéYçáåv";
	Temp[23] = "ïâç¬èÉéëéYçáåv";
	while (i <= 23) {

		DrawStringToHandle(MultiResoIntX(x * 416 + 100), MultiResoIntY(y * 32 + 240), Temp[i], GetColor(0, 0, 0), init.FontHandle); y++;
		if (i == 11) {
			x++;
			y = 0;
		}
		else if (i == 23) {
			x = 0;
			y = 0;
		}
		i++;
	}

	DrawStringToHandle(MultiResoIntX(1350), MultiResoIntY(160), "ëπâvåvéZèë", GetColor(0, 0, 0), init.FontHandle);

	Temp[24] = "îÑè„çÇ";
	Temp[25] = "îÑè„å¥âø";
	Temp[26] = "";
	Temp[27] = "îÃîÑîÔãyÇ—àÍî ä«óùîÔ";
	Temp[28] = "";
	Temp[29] = "";
	Temp[30] = "";
	Temp[31] = "";
	Temp[32] = "âcã∆äOëπâv";
	Temp[33] = "";
	Temp[34] = "";
	Temp[35] = "ì¡ï ëπâv";
	Temp[36] = "";

	Temp[37] = "";
	Temp[38] = "";
	Temp[39] = "îÑè„ëçóòâv";
	Temp[40] = "";
	Temp[41] = "ããóø";
	Temp[42] = "éxï•â∆í¿";
	Temp[43] = "å∏âøèûãpîÔ";
	Temp[44] = "âcã∆óòâv";
	Temp[45] = "";
	Temp[46] = "éxï•óòëß";
	Temp[47] = "åoèÌóòâv";
	Temp[48] = "";
	Temp[49] = "ê≈à¯ëOìñä˙èÉóòâv";
	Temp[50] = "ñ@êlê≈ìô";
	Temp[51] = "ìñä˙èÉóòâv";

	while (i <= 51) {

		DrawStringToHandle(MultiResoIntX(x * 128 + 1024 + 64), MultiResoIntY(y * 30 + 240), Temp[i], GetColor(0, 0, 0), init.FontHandle); y++;
		if (i == 36) {
			x++;
			y = 0;
		}
		i++;
	}
}

void SYSTEM::QuestBtnOver(int i) {

	switch (i) {
	case 63:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_QUEST;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		QuestData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::QuestBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_QUEST;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		QuestData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::QuestBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		BtnSwitch = Sw_MMAP;
		ResetMap();
		SpawnHer();
		break;
	case 1:
		break;
	}
}

void SYSTEM::QuestData() {

}

void SYSTEM::PricesBtnOver(int i) {

	switch (BtnSwitch) {
	case Sw_PRICES:
		printfDx("PRICES");
		if (i == 63) {
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_PRICES;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			PricesData();
			DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 0, 0), init.FontHandle);
		}
		else if (BtnOn[i] == TRUE) {
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_PRICES;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			PricesData();
			DrawStringToHandle(BtnX[i], BtnY[i], City[i].Name, GetColor(255, 0, 0), init.FontHandle);
		}
		break;
	case Sw_PRICES2:
		printfDx("PRICES2");
		if (i == 63) {
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_PRICES2;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			PricesData2(ClickedBtn, i);
			DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 0, 0), init.FontHandle);
		}
		else if (BtnOn[i] == TRUE) {
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_PRICES2;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			PricesData2(ClickedBtn, i);
			DrawStringToHandle(BtnX[i], BtnY[i], Goods[i].Name, GetColor(255, 0, 0), init.FontHandle);
		}
		break;
	}
}

void SYSTEM::PricesBtnOut(int OveredBtn) {

	switch (BtnSwitch) {
	case Sw_PRICES:
		if (OveredBtn == 63) {
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_PRICES;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			PricesData();
			DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 255, 255), init.FontHandle);
		}
		else if (BtnOn[OveredBtn] == TRUE) {
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_PRICES;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			PricesData();
			DrawStringToHandle(BtnX[OveredBtn], BtnY[OveredBtn], City[OveredBtn].Name, GetColor(0, 0, 0), init.FontHandle);
		}
		break;
	case Sw_PRICES2:
		if (OveredBtn == 63) {
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_PRICES2;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			PricesData2(ClickedBtn, OveredBtn);
			DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 255, 255), init.FontHandle);
		}
		else if (BtnOn[OveredBtn] == TRUE) {
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_PRICES2;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			PricesData2(ClickedBtn, OveredBtn);
			DrawStringToHandle(BtnX[OveredBtn], BtnY[OveredBtn], Goods[OveredBtn].Name, GetColor(0, 0, 0), init.FontHandle);
		}
		break;
	}
}

void SYSTEM::PricesBtnSys(int OveredBtn) {

	if (OveredBtn == 63) {
		BtnSwitch = Sw_MMAP;
		ResetMap();
		SpawnHer();
	}
	else if (BtnOn[OveredBtn] == TRUE) {
		ResetBtnOn();
		ResetMap();
		BtnSwitch = Sw_PRICES2;
		ClickedBtn = OveredBtn;
		SpawnHer();
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		PricesData2(OveredBtn, -1);
	}
}

void SYSTEM::PricesData() {

	int x = 0;

	for (int i = 0; i < 10; i++) {
		BtnX[i] = 580;
		BtnY[i] = 200 + i * 42;
		BtnW[i] = 80;
		BtnH[i] = 42;
	}

	for (int i = 0; i < 10; i++) {
		DrawStringToHandle(BtnX[i], BtnY[i], City[i].Name, GetColor(0, 0, 0), init.FontHandle);
		BtnOn[i] = TRUE;
	}

}

void SYSTEM::PricesData2(int ClickedBtn, int OveredBtn) {

	int x = 0;
	int y = 0;
	TCHAR Temp[64];

	for (int i = 0; i <= 17; i++) {
		BtnX[i] = 580 + x * 400;
		BtnY[i] = 240 + y * 38;
		BtnW[i] = 140;
		BtnH[i] = 38;
		y++;
		if (i == 12) {
			x++;
			y = 0;
		}
		if (x >= 2)
			break;
	}

	DrawStringToHandle(580, 160, "ñºëO", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(580 + 140, 160, "é˘óv", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(580 + 260, 160, "ãüãã", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(580 + 400, 160, "ñºëO", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(580 + 400 + 140, 160, "é˘óv", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(580 + 400 + 260, 160, "ãüãã", GetColor(0, 0, 0), init.FontHandle);

	for (int i = 0; i <= 17; i++) {
		if (OveredBtn != i) {
			DrawStringToHandle(BtnX[i], BtnY[i], Goods[i].Name, GetColor(0, 0, 0), init.FontHandle);
		}
		sprintf_s(Temp, 64, "%3.0lf%%", HerMarket[ClickedBtn][i].Demand * 100);
		DrawStringToHandle(BtnX[i] + 140, BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
		sprintf_s(Temp, 64, "%3.0lf%%", HerMarket[ClickedBtn][i].Supply * 100);
		DrawStringToHandle(BtnX[i] + 260, BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
		BtnOn[i] = TRUE;
	}
}

void SYSTEM::SaveBtnOver(int i) {

	switch (i) {
	case 63:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_SAVE;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		SaveData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::SaveBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_SAVE;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		SaveData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::SaveBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		BtnSwitch = Sw_MMAP;
		ResetMap();
		SpawnHer();
		break;
	case 1:
		break;
	}
}

void SYSTEM::SaveData() {

}

void SYSTEM::LoadBtnOver(int i) {

	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (i) {
		case 63:
			ResetTitle();
			BtnSwitch = Sw_LOAD;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			LoadData();
			DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 0, 0), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (i) {
		case 63:
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_LOAD;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			LoadData();
			DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 0, 0), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	}
}

void SYSTEM::LoadBtnOut(int OveredBtn) {

	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (OveredBtn) {
		case 63:
			ResetTitle();
			BtnSwitch = Sw_LOAD;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			LoadData();
			DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (OveredBtn) {
		case 63:
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_LOAD;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			LoadData();
			DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	}
}

void SYSTEM::LoadBtnSys(int OveredBtn) {

	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (OveredBtn) {
		case 63:
			BtnSwitch = Sw_TITLE;
			ResetTitle();
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (OveredBtn) {
		case 63:
			BtnSwitch = Sw_MMAP;
			ResetMap();
			SpawnHer();
			break;
		case 1:
			break;
		}
		break;
	}
}

void SYSTEM::LoadData() {

}

void SYSTEM::InitMap() {
	OveredBtn = -1;
	SetMapBtn();
	if (DebugMode == TRUE) {
		LoopMusic("Field");
		DebugMap();
		DrawButton(-1);
		DrawValue();
		DebugBox();
		clsDx();
	}
	else {
		sys.Fade(init.GraT, init.GraMap, "Field");
		DrawButton(-1);
		DrawValue();
	}
	InitHer();

}

void SYSTEM::ResetMap() {

	ClearDrawScreen();
	SetMapBtn();
	DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraMap, TRUE);
	DrawButton(OveredBtn);
	DrawValue();
	if (DebugMode == TRUE) {
		DebugBox();
		clsDx();
	}
}

//ç≈ëÂìsés	640, 560
//êºÇÃìsés1 255, 590
//êºÇÃìsés2 185, 370
//êºÇÃìá	230, 890
//ñkìåìsés	780, 340
//ñkÇÃìsés	620, 160
//ìåÇÃìsés	1080, 420
//ìåÇÃìá	1720, 260
//ìÏìåÇÃìá1	1700, 750
//ìÏìåÇÃìá2	1440, 880
void SYSTEM::SetMapBtn() {
	int x = 64;
	int y = 48;
	BtnX[0] = 595;	//ç≈ëÂìsés
	BtnY[0] = 580;
	BtnW[0] = 128;
	BtnH[0] = 80;
	BtnX[1] = 235;	//êº1
	BtnY[1] = 610;
	BtnW[1] = x;
	BtnH[1] = y;
	BtnX[2] = 170;	//êº2
	BtnY[2] = 410;
	BtnW[2] = x;
	BtnH[2] = y;
	BtnX[3] = 210;	//êºìá
	BtnY[3] = 920;
	BtnW[3] = x;
	BtnH[3] = y;
	BtnX[4] = 765;	//ñkìå
	BtnY[4] = 380;
	BtnW[4] = x;
	BtnH[4] = y;
	BtnX[5] = 600;	//ñk
	BtnY[5] = 190;
	BtnW[5] = x;
	BtnH[5] = y;
	BtnX[6] = 1065;	//ìå
	BtnY[6] = 460;
	BtnW[6] = x;
	BtnH[6] = y;
	BtnX[7] = 1710;	//ìåìá
	BtnY[7] = 300;
	BtnW[7] = x;
	BtnH[7] = y;
	BtnX[8] = 1690;	//ìÏìåìá1
	BtnY[8] = 790;
	BtnW[8] = x;
	BtnH[8] = y;
	BtnX[9] = 1430;	//ìÏìåìá2
	BtnY[9] = 920;
	BtnW[9] = x;
	BtnH[9] = y;
	BtnX[10] = 730;	//ñkìååoòH1
	BtnY[10] = 550;
	BtnW[10] = x;
	BtnH[10] = y;
	BtnX[11] = 765;	//ñkìååoòH2
	BtnY[11] = 480;
	BtnW[11] = x;
	BtnH[11] = y;
	BtnX[12] = 170;	//êºòH
	BtnY[12] = 470;
	BtnW[12] = x;
	BtnH[12] = y;
	BtnX[13] = 650;	//ñkòH
	BtnY[13] = 280;
	BtnW[13] = x;
	BtnH[13] = y;
	BtnX[14] = 880;	//ìåòH
	BtnY[14] = 390;
	BtnW[14] = x;
	BtnH[14] = y;
	BtnX[15] = 970;	//ìåòH2
	BtnY[15] = 450;
	BtnW[15] = x;
	BtnH[15] = y;
	BtnX[16] = 1685;	//ìáòH
	BtnY[16] = 860;
	BtnW[16] = x;
	BtnH[16] = y;

	BtnX[20] = 605;	//ç`1
	BtnY[20] = 680;
	BtnW[20] = x;
	BtnH[20] = y;
	BtnX[21] = 530; //äCòH1
	BtnY[21] = 810;
	BtnW[21] = x;
	BtnH[21] = y;
	BtnX[22] = 285;	//ç`2
	BtnY[22] = 900;
	BtnW[22] = x;
	BtnH[22] = y;
	BtnX[23] = 600; //äCòH2
	BtnY[23] = 730;
	BtnW[23] = x;
	BtnH[23] = y;
	BtnX[24] = 680; //äCòH3
	BtnY[24] = 820;
	BtnW[24] = x;
	BtnH[24] = y;
	BtnX[25] = 1300; //äCòH4
	BtnY[25] = 720;
	BtnW[25] = x;
	BtnH[25] = y;
	BtnX[26] = 1500; //äCòH5
	BtnY[26] = 280;
	BtnW[26] = x;
	BtnH[26] = y;
	BtnX[27] = 1620; //ç`3
	BtnY[27] = 290;
	BtnW[27] = x;
	BtnH[27] = y;
	BtnX[28] = 1440; //äCòH6
	BtnY[28] = 790;
	BtnW[28] = x;
	BtnH[28] = y;
	BtnX[29] = 1590; //ç`4
	BtnY[29] = 790;
	BtnW[29] = x;
	BtnH[29] = y;
	BtnX[30] = 110;	//êºç`
	BtnY[30] = 410;
	BtnW[30] = x;
	BtnH[30] = y;
	BtnX[31] = 0;	//êºäCòH
	BtnY[31] = 520;
	BtnW[31] = 0;
	BtnH[31] = 0;
	BtnX[32] = 1920;	//ìåäCòH
	BtnY[32] = 520;
	BtnW[32] = 0;
	BtnH[32] = 0;
	BtnX[33] = 1780;	//ìåäCòH2
	BtnY[33] = 570;
	BtnW[33] = x;
	BtnH[33] = y;
	BtnX[34] = 1680;	//ìåäCòH3
	BtnY[34] = 570;
	BtnW[34] = x;
	BtnH[34] = y;
	BtnX[35] = 0;	//êºäCòH2
	BtnY[35] = 740;
	BtnW[35] = 0;
	BtnH[35] = 0;
	BtnX[36] = 160;	//êºäCòH3
	BtnY[36] = 830;
	BtnW[36] = x;
	BtnH[36] = y;
	BtnX[37] = 320;	//êºäCòH4
	BtnY[37] = 840;
	BtnW[37] = x;
	BtnH[37] = y;
	BtnX[38] = 1130;	//ìåç`
	BtnY[38] = 455;
	BtnW[38] = x;
	BtnH[38] = y;
	BtnX[39] = 1330;	//ìåäCòH4
	BtnY[39] = 420;
	BtnW[39] = x;
	BtnH[39] = y;
	BtnX[40] = 680;	//ñkç`
	BtnY[40] = 225;
	BtnW[40] = x;
	BtnH[40] = y;
	BtnX[41] = 715;	//ñkì¸ÇËç]
	BtnY[41] = 170;
	BtnW[41] = x;
	BtnH[41] = y;
	BtnX[42] = 715;	//ñkèoå˚
	BtnY[42] = 100;
	BtnW[42] = x;
	BtnH[42] = y;
	BtnX[43] = 200;	//ñkäCòHñ¶
	BtnY[43] = 60;
	BtnW[43] = x;
	BtnH[43] = y;
	BtnX[44] = 1200;	//ñkäCòH
	BtnY[44] = 120;
	BtnW[44] = x;
	BtnH[44] = y;
	BtnX[45] = 1920;	//ÉèÅ[Év2
	BtnY[45] = 740;
	BtnW[45] = 0;
	BtnH[45] = 0;

	for (int i = 0; i <= 45; i++) {
		MultiResoBtn(i);
	}
	for (int i = 0; i < ButtonNumber; i++) {
		BtnCx[i] = BtnX[i] + BtnW[i] / 2;
		BtnCy[i] = BtnY[i] + BtnH[i] / 2;
	}
}

void SYSTEM::DebugMap() {
	SetDrawScreen(DX_SCREEN_BACK);
	DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraMap, TRUE);
	ScreenFlip();
	SetDrawScreen(DX_SCREEN_FRONT);
}

void SYSTEM::InitHer() {
	her.X = BtnCx[0];
	her.Y = BtnCy[0];
	her.On = 0;

	DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[0], TRUE);
}

void SYSTEM::SpawnHer() {

	DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[0], TRUE);
}

void SYSTEM::Move(int MoveTo) {

	int MoveCount = 0;

	Angle = atan2(BtnCy[MoveTo] - her.Y, BtnCx[MoveTo] - her.X);

	while (!(((her.X > BtnCx[MoveTo] - 2) && (her.X <= BtnCx[MoveTo] + 2)) && ((her.Y > BtnCy[MoveTo] - 2) && (her.Y <= BtnCy[MoveTo] + 2)))) {

		her.X += 1 * cos(Angle);
		her.Y += 1 * sin(Angle);

		ResetMap();

		Angle2 = RAD_TO_DEG(Angle);


		if (DebugMode == TRUE) {
			clsDx();
			printfDx("%lf\n", Angle);
			printfDx("%lfÅã", RAD_TO_DEG(Angle));
			printfDx("%lfÅã\n", Angle2);
			printfDx("%d\n", her.Day);
		}

		if (her.OnShip == FALSE) {
			if (MoveCount < 50) {
				if (Angle2 < 45 && Angle2 > -45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[6], TRUE);
				}
				else if (Angle2 < 135 && Angle2 > 45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[0], TRUE);
				}
				else if (Angle2 < -45 && Angle2 > -135) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[9], TRUE);
				}
				else {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[3], TRUE);
				}
			}
			else if (MoveCount < 100) {
				if (Angle2 < 45 && Angle2 > -45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[7], TRUE);
				}
				else if (Angle2 < 135 && Angle2 > 45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[1], TRUE);
				}
				else if (Angle2 < -45 && Angle2 > -135) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[10], TRUE);
				}
				else {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[4], TRUE);
				}
			}
			else if (MoveCount < 150) {
				if (Angle2 < 45 && Angle2 > -45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[8], TRUE);
				}
				else if (Angle2 < 135 && Angle2 > 45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[2], TRUE);
				}
				else if (Angle2 < -45 && Angle2 > -135) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[11], TRUE);
				}
				else {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[5], TRUE);
				}
			}
		}
		else if (her.OnShip == TRUE) {
			if (MoveCount < 50) {
				if (Angle2 < 45 && Angle2 > -45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[6], TRUE);
				}
				else if (Angle2 < 135 && Angle2 > 45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[0], TRUE);
				}
				else if (Angle2 < -45 && Angle2 > -135) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[9], TRUE);
				}
				else {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[3], TRUE);
				}
			}
			else if (MoveCount < 100) {
				if (Angle2 < 45 && Angle2 > -45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[7], TRUE);
				}
				else if (Angle2 < 135 && Angle2 > 45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[1], TRUE);
				}
				else if (Angle2 < -45 && Angle2 > -135) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[10], TRUE);
				}
				else {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[4], TRUE);
				}
			}
			else if (MoveCount < 150) {
				if (Angle2 < 45 && Angle2 > -45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[8], TRUE);
				}
				else if (Angle2 < 135 && Angle2 > 45) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[2], TRUE);
				}
				else if (Angle2 < -45 && Angle2 > -135) {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[11], TRUE);
				}
				else {
					DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraShip[5], TRUE);
				}
			}
		}

		if (her.OnShip == FALSE) {
			if (MoveCount % her.MoveSpeed == 0)
				her.Day++;
		}
		else if (her.OnShip == TRUE) {
			if (MoveCount % her.ShipMoveSpeed == 0)
				her.Day++;
		}

		sys.DaySys();

		MoveCount++;
		if (MoveCount >= 150)
			MoveCount = 0;

		WaitTimer(8);
	}
}

void SYSTEM::WarpHer(int WarpTo) {

	her.X = BtnCx[WarpTo];
	her.Y = BtnCy[WarpTo];
}

