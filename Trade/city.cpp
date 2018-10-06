#include "Dxlib.h"
#include "class.h"

#define TransportTech (i == 0) || (i == 1 && City[her.On].Technology * 100 >= 30) || (i == 2 && City[her.On].Technology * 100 >= 30) || (i == 3 && City[her.On].Technology * 100 >= 40) || (i == 4 && City[her.On].Technology * 100 >= 70) || (i == 5 && City[her.On].Technology * 100 >= 80) || (i == 6 && City[her.On].Technology * 100 >= 90) || (i == 7 && City[her.On].Technology * 100 >= 100) || (i == 8) || (i == 9 && City[her.On].Technology * 100 >= 30) || (i == 10 && City[her.On].Technology * 100 >= 30) || (i == 11 && City[her.On].Technology * 100 >= 40) || (i == 12 && City[her.On].Technology * 100 >= 70) || (i == 13 && City[her.On].Technology * 100 >= 80) || (i == 14 && City[her.On].Technology * 100 >= 90) || (i == 15 && City[her.On].Technology * 100 >= 100) || (i == 16) || (i == 17 && City[her.On].Technology * 100 >= 30) || (i == 18 && City[her.On].Technology * 100 >= 30) || (i == 19 && City[her.On].Technology * 100 >= 40) || (i == 20 && City[her.On].Technology * 100 >= 70) || (i == 21 && City[her.On].Technology * 100 >= 80) || (i == 22 && City[her.On].Technology * 100 >= 90) || (i == 23 && City[her.On].Technology * 100 >= 100)

extern FUN fun;
extern INIT init;
extern HEROINE her;
extern GOODS Goods[32];
extern CITY City[16];
extern MARKET Market[16][32];
extern MARKET HerMarket[16][32];
extern TRANSPORT trans[7];

void SYSTEM::ResetCity() {

	for (int i = 0; i < 64; i++) {
		GoodsOn[i] = FALSE;
		BtnX[i] = -1;
		BtnY[i] = -1;
	}
	ClearDrawScreen();
	DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraCity, TRUE);
	DrawWindow(160, 120, 1, 8);
	DrawWindow(1480, 120, 2, 12);
	DrawButton(-1);
	DrawMessageWindow();
	CityData();
	if (DebugMode == TRUE) {
		DebugBox();
	}
}

void SYSTEM::CityBtnOver(int i) {

	int x = MultiResoIntX(24);
	int y = MultiResoIntY(8);

	switch (i) {
	case 0:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[0] + x, BtnY[0] + y, "Purchase", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[1] + x, BtnY[1] + y, "Sale", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 2:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[2] + x, BtnY[2] + y, "Invest", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 3:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[3] + x, BtnY[3] + y, "Manage", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 4:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[4] + x, BtnY[4] + y, "Talk", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 5:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[5] + x, BtnY[5] + y, "Exit", GetColor(255, 0, 0), init.FontHandle);
	}
}

void SYSTEM::CityBtnOut(int OveredBtn) {

	int x = MultiResoIntX(24);
	int y = MultiResoIntY(8);

	switch (OveredBtn) {
	case 0:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[0] + x, BtnY[0] + y, "Purchase", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 1:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[1] + x, BtnY[1] + y, "Sale", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 2:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[2] + x, BtnY[2] + y, "Invest", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 3:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[3] + x, BtnY[3] + y, "Manage", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 4:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[4] + x, BtnY[4] + y, "Talk", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 5:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[5] + x, BtnY[5] + y, "Exit", GetColor(0, 0, 0), init.FontHandle);
	}
}


void SYSTEM::CityBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		BtnSwitch = Sw_BUY;
		ResetButton();
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		if (DebugMode == TRUE) {
			DebugBox();
		}
		break;
	case 1:
		BtnSwitch = Sw_SALE;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		break;
	case 2:
		BtnSwitch = Sw_INVEST;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		InvestData(-1);
		break;
	case 3:
		BtnSwitch = Sw_MANAGE;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		ManageData(-1);
		break;
	case 4:

		for (int i = 0; i < 128; i++) {
			if (EventFlag[i] == TRUE) {
				BtnSwitch = Sw_TALK;
				EventNumber = i;
				Event(EventNumber);
				return;
			}
		}
		TalkNumber++;
		ResetCity();
		break;
	case 5:
		BtnSwitch = Sw_EXIT;
		ResetCity();
		break;
	}
}

void SYSTEM::CityData() {

	TCHAR Temp[32];
	int x = 1500;
	int y = 140;

	DrawStringToHandle(MultiResoIntX(x + 100), MultiResoIntY(y), City[her.On].Name, GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 60), "Feature", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 100), "Population", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 140), "Development", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 180), "Economy", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 220), "Technology", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 260), "Industry", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 300), "Infrastructure", GetColor(0, 0, 0), init.FontHandle);

	sprintf_s(Temp, 32, "%s", City[her.On].Type);
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%.0lf", City[her.On].Population);
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 2), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Develop * 100));
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 3), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Economy * 100));
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 4), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Technology * 100));
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 5), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Industry * 100));
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 6), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Infra * 100));
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 7), Temp, GetColor(0, 0, 0), init.FontHandle);
}

void SYSTEM::ResetButton() {
	for (int i = 0; i < 64; i++) {
		GoodsOn[i] = FALSE;
		BtnX[i] = -1;
		BtnY[i] = -1;
	}
	OveredBtn = -1;
}

void SYSTEM::BuySort(int ID) {

	TCHAR Temp[32];

	for (int i = 0; i < 16; i++) {
		SortX[i] = 560;
		SortY[i] = 240 + i * 42;
	}

	for (int i = 0; i < 63; i++) {
		if (GoodsOn[i] == FALSE) {
			BtnX[ID] = SortX[i];
			BtnY[ID] = SortY[i];
			BtnW[ID] = 150;
			BtnH[ID] = 42;
			GoodsOn[i] = TRUE;
			BtnOn[ID] = TRUE;
			MultiResoBtn(ID);
			break;
		}
	}
	Goods[ID].CalcedPrice = Market[her.On][ID].CalcPrice(Goods[ID].BasePrice, City[her.On].Economy, Market[her.On][ID].Demand, Market[her.On][ID].Supply, City[her.On].Industry, Goods[ID].IndImpact, City[her.On].Technology, Goods[ID].TechImpact, City[her.On].Develop, City[her.On].Infra);
	Goods[ID].CalcedProd = Market[her.On][ID].CalcProduction(ID, her.On);

	DrawStringToHandle(BtnX[ID], BtnY[ID], Goods[ID].Name, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d", Goods[ID].CalcedPrice);
	DrawStringToHandle(BtnX[ID] + MultiResoIntX(200), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d", Goods[ID].CalcedProd);
	DrawStringToHandle(BtnX[ID] + MultiResoIntX(360), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%3.0lf%%", Market[her.On][ID].Demand * 100);
	DrawStringToHandle(BtnX[ID] + MultiResoIntX(520), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%3.0lf%%", Market[her.On][ID].Supply * 100);
	DrawStringToHandle(BtnX[ID] + MultiResoIntX(520 + 160), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
}



//Goods.NameÇÕïiñ⁄ÇÃñºëO

void SYSTEM::BuyBtnOver(int i) {

	if (i == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ñﬂÇÈ", GetColor(255, 0, 0), init.FontHandle);
	}
	else if (BtnOn[i] == TRUE) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		DrawStringToHandle(BtnX[i], BtnY[i], Goods[i].Name, GetColor(255, 0, 0), init.FontHandle);
	}
}

void SYSTEM::BuyBtnOut(int OveredBtn) {

	if (OveredBtn == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ñﬂÇÈ", GetColor(255, 255, 255), init.FontHandle);
	}
	else if (BtnOn[OveredBtn] == TRUE) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		DrawStringToHandle(BtnX[OveredBtn], BtnY[OveredBtn], Goods[OveredBtn].Name, GetColor(0, 0, 0), init.FontHandle);
	}
}

void SYSTEM::BuyBtnSys(int OveredBtn) {

	if (OveredBtn == 63) {
		BtnSwitch = Sw_CITY;
		ResetCity();
	}
	else if (OveredBtn != -1) {
		BtnSwitch = Sw_BUY2;
		ResetCity();
		BuySys(OveredBtn);
	}
}

void SYSTEM::DrawBuyString() {

	BtnX[63] = MWX + 640;
	BtnY[63] = MWY + 140;
	BtnW[63] = 90;
	BtnH[63] = 42;

	MultiResoBtn(63);

	DrawStringToHandle(BtnX[63], BtnY[63], "ñﬂÇÈ", GetColor(255, 255, 255), init.FontHandle);

	int X = 560;
	int Y = MultiResoIntY(160);

	DrawStringToHandle(MultiResoIntX(X), Y, "ñºëO", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 200), Y, "ílíi", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 200 + 160), Y, "îÑó ", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 200 + 160 * 2), Y, "é˘óv", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 200 + 160 * 3), Y, "ãüãã", GetColor(0, 0, 0), init.FontHandle);
}

//BuyDataÇÕdatas.hÇ÷à⁄ìÆ

void SYSTEM::SearchEmpty(int ID) {

	for (int i = 0; i < 64; i++) {
		if (her.HiddenID[i] == ID) {
			SlotNumber = i;
			break;
		}
		else if (her.Cargo[i] == 0) {
			SlotNumber = i;
			break;
		}
	}
}

void SYSTEM::BuySys(int ID) {

	if (ID < 0 || OveredBtn == 63 || OveredBtn == 62) {
		BtnSwitch = Sw_BUY;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		OveredBtn = -1;
		return;
	}
	SearchEmpty(ID);

	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64) , "Ç¢Ç≠Ç¬çwì¸ÇµÇ‹Ç∑Ç©ÅH", GetColor(255, 255, 255), init.FontHandle);
	printfDx("SlotNumber=%d\n", SlotNumber);

	TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 9999, 0, FALSE);
	TempPrice = Goods[ID].CalcedPrice * TempNumber;

	printfDx("BoughtNumber=%d\n", TempNumber);
	printfDx("BoughtPrice=%d\n", TempPrice);
	printfDx("CargoPrice=%d\n", her.CargoPrice[SlotNumber]);

	if (TempPrice > her.Money) {
		ResetCity();
		MessageWindowMessage("èäéùã‡Ç™ë´ÇËÇ‹ÇπÇÒ");
		WaitClick();
	}
	else if (TempNumber + her.CargoWeight > her.MaxWeight) {
		ResetCity();
		MessageWindowMessage("èdó ÉIÅ[ÉoÅ[Ç≈Ç∑");
		WaitClick();
	}
	else if (TempNumber != 0)
	{
		her.CargoPrice[SlotNumber] += Goods[ID].CalcedPrice * TempNumber;
		her.Cargo[SlotNumber] += TempNumber;
		her.Money -= TempPrice;
		her.CargoWeight += TempNumber;
		her.HiddenID[SlotNumber] = ID;

		if (her.Cargo[SlotNumber] != 0) {
			ResetCity();
			MessageWindowMessage("çwì¸ÇµÇ‹ÇµÇΩ");
			WaitClick();
		}
	}
	BtnSwitch = Sw_BUY;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	DrawBuyString();
	BuyData();
	OveredBtn = -1;
}

void SYSTEM::SaleSort(int ID) {

	//BtnX[1] = 560;
	//BtnY[1] = 180;

	TCHAR Temp[32];

	for (int i = 0; i < 16; i++) {
		SortX[i] = 560;
		SortY[i] = 240 + i * 42;
	}

	for (int i = 0; i < 63; i++) {
		if (GoodsOn[i] == FALSE) {
			BtnX[ID] = SortX[i];
			BtnY[ID] = SortY[i];
			BtnW[ID] = 150;
			BtnH[ID] = 42;
			BtnOn[ID] = TRUE;
			GoodsOn[i] = TRUE;

			MultiResoBtn(ID);

			sprintf_s(Temp, 32, "%d", her.CargoPrice[i] / her.Cargo[i]);	//àÍå¬ìñîÉíl
			DrawStringToHandle(BtnX[ID] + MultiResoIntX(190), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.Cargo[i]);	//êœâ◊êîó 
			DrawStringToHandle(BtnX[ID] + MultiResoIntX(210 + 110 * 2), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
			break;
		}
	}

	Goods[ID].CalcedPrice = Market[her.On][ID].SaleCalcPrice(Goods[ID].BasePrice, City[her.On].Economy, Market[her.On][ID].Demand, Market[her.On][ID].Supply, City[her.On].Industry, Goods[ID].IndImpact, City[her.On].Technology, Goods[ID].TechImpact, City[her.On].Develop, City[her.On].Infra);

	DrawStringToHandle(BtnX[ID], BtnY[ID], Goods[ID].Name, GetColor(0, 0, 0), init.FontHandle);

	sprintf_s(Temp, 32, "%d", Goods[ID].CalcedPrice); //îÑíl
	DrawStringToHandle(BtnX[ID] + MultiResoIntX(210 + 110), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);

}


void SYSTEM::SaleBtnOver(int i) {

	if (i == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ñﬂÇÈ", GetColor(255, 0, 0), init.FontHandle);
	}
	else if (BtnOn[i] == TRUE) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		DrawStringToHandle(BtnX[i], BtnY[i], Goods[i].Name, GetColor(255, 0, 0), init.FontHandle);
	}
}

void SYSTEM::SaleBtnOut(int OveredBtn) {

	if (OveredBtn == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		DrawStringToHandle(BtnX[63], BtnY[63], "ñﬂÇÈ", GetColor(255, 255, 255), init.FontHandle);
	}
	else if (BtnOn[OveredBtn] == TRUE) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		DrawStringToHandle(BtnX[OveredBtn], BtnY[OveredBtn], Goods[OveredBtn].Name, GetColor(0, 0, 0), init.FontHandle);
	}
}

void SYSTEM::SaleBtnSys(int OveredBtn) {

	if (OveredBtn == 63) {
		BtnSwitch = Sw_CITY;
		ResetCity();
	}
	else if (OveredBtn != -1) {
		BtnSwitch = Sw_SALE2;
		ResetCity();
		SaleSys(OveredBtn);
	}
}

void SYSTEM::SaleData() {

	int X = 560;
	int Y = MultiResoIntY(160);

	DrawStringToHandle(MultiResoIntX(X), Y, "ñºëO", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 190), Y, "àÍå¬ìñîÉíl", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 110), Y, "îÑíl", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 110 * 2), Y, "êîó ", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 110 * 3), Y, "éÛì¸ó ", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 110 * 4), Y, "é˘óv", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 110 * 5), Y, "ãüãã", GetColor(0, 0, 0), init.FontHandle);

	for (int i = 0; i < 8; i++) {
		if (her.HiddenID[i] != -1)
			SaleSort(her.HiddenID[i]);
	}
}

void SYSTEM::SaleSys(int ID) {

	int SlotNumber;
	bool LEnd = FALSE;

	for (int i = 0; i < 64; i++) {
		if (her.HiddenID[i] == ID) {
			SlotNumber = i;
			break;
		}
	}

	MessageWindowMessage("Ç¢Ç≠Ç¬îÑãpÇµÇ‹Ç∑Ç©ÅH");
	printfDx("SlotNumber=%d\n", SlotNumber);

	TempNumber = KeyInputNumber(MWX + 64 + 32, MWY + 96, 9999, 0, FALSE);
	TempPrice = Goods[ID].CalcedPrice * TempNumber;

	printfDx("BoughtNumber=%d\n", TempNumber);
	printfDx("BoughtPrice=%d\n", TempPrice);
	printfDx("CargoPrice=%d\n", her.CargoPrice[SlotNumber]);

	if (TempNumber > her.Cargo[SlotNumber]) {
		ResetCity();
		MessageWindowMessage("èäóLó Çí¥Ç¶ÇƒÇ¢Ç‹Ç∑");
		while (1) {
			if (CheckHitKey(KEY_INPUT_NUMPADENTER) == 0) {
				if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
					while (1) {
						MInput1F = MInput;
						MInput = GetMouseInput();
						if (!(MInput & MOUSE_INPUT_LEFT) && (MInput1F & MOUSE_INPUT_LEFT) == 1)
							LEnd = TRUE;
						if (CheckHitKey(KEY_INPUT_RETURN) == 1)
							LEnd = TRUE;
						if (CheckHitKey(KEY_INPUT_NUMPADENTER) == 1)
							LEnd = TRUE;
						WaitTimer(16);
						if (LEnd) { break; }
					}
				}
			}
			WaitTimer(16);
			if (LEnd) { break; }
		}
	}
	else if (TempNumber != 0)
	{
		her.CargoPrice[SlotNumber] -= her.CargoPrice[SlotNumber] / her.Cargo[SlotNumber] * TempNumber;
		her.Cargo[SlotNumber] -= TempNumber;
		her.Money += TempPrice;
		her.CargoWeight -= TempNumber;
		if (her.Cargo[SlotNumber] == 0)
			her.HiddenID[SlotNumber] = -1;

		ResetCity();
		MessageWindowMessage("îÑãpÇµÇ‹ÇµÇΩ");
		while (1) {
			if (CheckHitKey(KEY_INPUT_NUMPADENTER) == 0) {
				if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
					while (1) {
						MInput1F = MInput;
						MInput = GetMouseInput();
						if (!(MInput & MOUSE_INPUT_LEFT) && (MInput1F & MOUSE_INPUT_LEFT) == 1)
							LEnd = TRUE;
						if (CheckHitKey(KEY_INPUT_RETURN) == 1)
							LEnd = TRUE;
						if (CheckHitKey(KEY_INPUT_NUMPADENTER) == 1)
							LEnd = TRUE;
						WaitTimer(16);
						if (LEnd) { break; }
					}
				}
			}
			WaitTimer(16);
			if (LEnd) { break; }
		}

	}
	BtnSwitch = Sw_SALE;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	SaleData();
	OveredBtn = -1;
}

void SYSTEM::InvestBtnOver(int i) {

	switch (BtnSwitch) {
	case Sw_INVEST:
	case Sw_INVEST2:
	case Sw_INVEST3:
	case Sw_INVEST4:
		if (i == 63) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			InvestData(i);
			DrawStringToHandle(BtnX[63], BtnY[63], "ñﬂÇÈ", GetColor(255, 0, 0), init.FontHandle);
		}
		else if (BtnOn[i] == TRUE) {
			if (TransportTech) {
				ResetCity();
				DrawWindow(520, 140, 5, 16);
				InvestData(i);
				DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(255, 0, 0), init.FontHandle);
			}
		}
		break;
	}
}

void SYSTEM::InvestBtnOut(int i) {

	switch (BtnSwitch) {
	case Sw_INVEST:
	case Sw_INVEST2:
	case Sw_INVEST3:
	case Sw_INVEST4:
		if (i == 63) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			InvestData(i);
			DrawStringToHandle(BtnX[63], BtnY[63], "ñﬂÇÈ", GetColor(255, 255, 255), init.FontHandle);
		}
		else if (BtnOn[i] == TRUE) {
			if (TransportTech) {
				ResetCity();
				DrawWindow(520, 140, 5, 16);
				InvestData(i);
				DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
			}
		}
		break;
	}
}

void SYSTEM::InvestBtnSys(int i) {

	switch (BtnSwitch) {
	case Sw_INVEST:
		switch (i) {
		case 63:
			BtnSwitch = Sw_CITY;
			ResetCity();
			break;
		case 0:
			ResetCity();
			BtnSwitch = Sw_INVEST2;
			DrawWindow(520, 140, 5, 16);
			InvestData(-1);
			break;
		case 1:
			ResetCity();
			BtnSwitch = Sw_INVEST3;
			DrawWindow(520, 140, 5, 16);
			InvestData(-1);
			break;
		case 2:
			ResetCity();
			BtnSwitch = Sw_INVEST4;
			DrawWindow(520, 140, 5, 16);
			InvestData(-1);
			break;
		}
		break;
	case Sw_INVEST2:
		if (i == 63){
			BtnSwitch = Sw_CITY;
			ResetCity();
			break;
		}
		else if (TransportTech) {
			if (i < 8) {
				BtnSwitch = Sw_INVESTBUY;
				ResetCity();
				InvestBuySys(i);
			}
			else if (i >= 8 && i < 16) {
				BtnSwitch = Sw_INVESTSALE;
				ResetCity();
				InvestSaleSys(i - 8);
			}
		}
		break;
	case Sw_INVEST3:
		break;
	case Sw_INVEST4:
		break;
	}
}

void SYSTEM::InvestData(int Btn) {

	int x = 0;
	int y = 0;
	int i = 0;

	switch (BtnSwitch) {
	case Sw_INVEST:
		for (int i = 0; i < 3; i++) {
			BtnX[i] = 600;
			BtnY[i] = 200 + i * 70;
			BtnOn[i] = TRUE;
			MultiResoBtn(i);
		}
		TempChar[0] = "óAëóéËíiîÑîÉ";
		TempChar[1] = "åöï®îÑîÉ";
		TempChar[2] = "ìäéë";

		if (Btn != 0)
			DrawStringToHandle(BtnX[0], BtnY[0], TempChar[0], GetColor(0, 0, 0), init.FontHandle);
		if (Btn != 1)
			DrawStringToHandle(BtnX[1], BtnY[1], TempChar[1], GetColor(0, 0, 0), init.FontHandle);
		if (Btn != 2)
			DrawStringToHandle(BtnX[2], BtnY[2], TempChar[2], GetColor(0, 0, 0), init.FontHandle);
		break;
	case Sw_INVEST2:

		TempChar[0] = "çwì¸";
		TempChar[1] = "çwì¸";
		TempChar[2] = "çwì¸";
		TempChar[3] = "çwì¸";
		TempChar[4] = "çwì¸";
		TempChar[5] = "çwì¸";
		TempChar[6] = "çwì¸";
		TempChar[7] = "çwì¸";
		TempChar[8] = "îÑãp";
		TempChar[9] = "îÑãp";
		TempChar[10] = "îÑãp";
		TempChar[11] = "îÑãp";
		TempChar[12] = "îÑãp";
		TempChar[13] = "îÑãp";
		TempChar[14] = "îÑãp";
		TempChar[15] = "îÑãp";
		TempChar[16] = "îné‘";
		TempChar[17] = "îøëD";
		TempChar[18] = "ëÂå^îné‘";
		TempChar[19] = "ëÂå^îøëD";
		TempChar[20] = "ÉgÉâÉbÉN";
		TempChar[21] = "èˆãCëD";
		TempChar[22] = "ëÂå^ÉgÉâÉbÉN";
		TempChar[23] = "ëÂå^èˆãCëD";

		//0îné‘0Å@1îøëD30Å@2ëÂå^îné‘30Å@3ëÂå^îøëD40Å@4ÉgÉâÉbÉN70Å@5èˆãCëD80Å@6ëÂå^ÉgÉâÉbÉN90Å@7ëÂå^èˆãCëD100
		while (i < 24) {
			BtnX[i] = 1000 + x * 200;
			BtnY[i] = 180 + y * 50;
			BtnW[i] = 180;
			BtnH[i] = 42;
			MultiResoBtn(i);
			if (i < 16)
				BtnOn[i] = TRUE;
			if (Btn != i)
				if (TransportTech)
				DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
			y++;
			i++;
			if (i == 8) {
				x++;
				y = 0;
			}
			if (i == 16) {
				x = -2;
				y = 0;
			}
		}

		break;
	case Sw_INVEST3:
		break;
	case Sw_INVEST4:
		break;
	}
}

void SYSTEM::InvestBuySys(int ID) {

	MessageWindowMessage("Ç¢Ç≠Ç¬çwì¸ÇµÇ‹Ç∑Ç©ÅH");

	TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 1000000, 0, FALSE);
	TempPrice = trans[ID].Price * TempNumber;

	if (TempPrice > her.Money) {
		ResetCity();
		MessageWindowMessage("èäéùã‡Ç™ë´ÇËÇ‹ÇπÇÒÅB");
		WaitClick();
	}
	else if (trans[ID].Sea == FALSE && TempNumber + her.MaxWeight > 999999999) {
		ResetCity();
		MessageWindowMessage("Ç±ÇÍà»è„îÉÇ¶Ç‹ÇπÇÒÅB");
		WaitClick();
	}
	else if (trans[ID].Sea == TRUE && TempNumber + her.ShipMaxWeight > 999999999 ) {
		ResetCity();
		MessageWindowMessage("Ç±ÇÍà»è„îÉÇ¶Ç‹ÇπÇÒÅB");
		WaitClick();
	}
	else if (TempNumber != 0)
	{
		her.Transport[ID] += TempNumber;
		her.Money -= TempPrice;
		ResetCity();
		MessageWindowMessage("çwì¸ÇµÇ‹ÇµÇΩÅB");
		WaitClick();
	}
	BtnSwitch = Sw_INVEST;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
	printfDx("%d\n", her.Transport[0]);
}

void SYSTEM::InvestSaleSys(int ID) {

	TCHAR Temp[32];
	if (her.Transport[ID] == 0) {
		ResetCity();
		MessageWindowMessage("èäéùÇµÇƒÇ¢Ç‹ÇπÇÒÅB");
		WaitClick();
	}
	else {
		MessageWindowMessage("Ç¢Ç≠Ç¬îÑãpÇµÇ‹Ç∑Ç©ÅH");
		sprintf_s(Temp, 32, "0Å`%d", her.Transport[ID]);
		DrawStringToHandle(MultiResoIntX(MWX + 64 + 32 + 256), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);

		TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 1000000, 0, FALSE);
		TempPrice = (int)(trans[ID].Price * TempNumber * 0.8);


		if (her.Transport[ID] < TempNumber) {
			ResetCity();
			MessageWindowMessage("èäéùêîÇí¥Ç¶ÇƒÇ¢Ç‹Ç∑ÅB");
			WaitClick();
		}
		else if (TempNumber != 0)
		{
			her.Transport[ID] -= TempNumber;
			her.Money += TempPrice;
			ResetCity();
			MessageWindowMessage("îÑãpÇµÇ‹ÇµÇΩÅB");
			WaitClick();
		}
	}
	BtnSwitch = Sw_INVEST;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
}

void SYSTEM::ManageBtnOver(int i) {

	switch (i) {
	case 63:
		ResetCity();
		BtnSwitch = Sw_MANAGE;
		DrawWindow(520, 140, 5, 16);
		ManageData(i);
		DrawStringToHandle(BtnX[63], BtnY[63], "ñﬂÇÈ", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::ManageBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		ResetCity();
		BtnSwitch = Sw_MANAGE;
		DrawWindow(520, 140, 5, 16);
		ManageData(OveredBtn);
		DrawStringToHandle(BtnX[63], BtnY[63], "ñﬂÇÈ", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::ManageBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		BtnSwitch = Sw_CITY;
		ResetCity();
		break;
	case 1:
		break;
	}
}

void SYSTEM::ManageData(int i) {

}


void SYSTEM::TalkBtnOver(int i) {

	switch (i) {
	case 62:
		ResetTalk();
		SetTwoBtn();
		DrawStringToHandle(BtnX[62], BtnY[62], SelectString[0], GetColor(255, 0, 0), init.FontHandle);
		break;
	case 63:
		ResetTalk();
		SetTwoBtn();
		DrawStringToHandle(BtnX[63], BtnY[63], SelectString[1], GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::TalkBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 62:
		ResetTalk();
		SetTwoBtn();
		DrawStringToHandle(BtnX[62], BtnY[62], SelectString[0], GetColor(255, 255, 255), init.FontHandle);
		break;
	case 63:
		ResetTalk();
		SetTwoBtn();
		DrawStringToHandle(BtnX[63], BtnY[63], SelectString[1], GetColor(255, 255, 255), init.FontHandle);
		break;
	}
}

void SYSTEM::TalkBtnSys(int OveredBtn) {

	switch (BtnSwitch) {
	case Sw_TALK:
		Event(EventNumber);
		break;
	case Sw_TALK2:
		EventSwitch = OveredBtn;
		Event(EventNumber);
		break;
	}
}

void SYSTEM::TalkData() {

}

void SYSTEM::ResetTalk() {

	for (int i = 0; i < 64; i++) {
		GoodsOn[i] = FALSE;
		BtnX[i] = -1;
		BtnY[i] = -1;
	}
	ClearDrawScreen();
	DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraCity, TRUE);
	DrawWindow(160, 120, 1, 8);
	DrawWindow(1480, 120, 2, 12);
	DrawButton(-1);
	DrawMessageWindow();
	CityData();
	Event(EventNumber);
}

void SYSTEM::ExitBtnOver(int i) {

	switch (i) {
	case 62:
		ResetCity();
		DrawStringToHandle(BtnX[62], BtnY[62], "ÇÕÇ¢", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 63:
		ResetCity();
		DrawStringToHandle(BtnX[63], BtnY[63], "Ç¢Ç¢Ç¶", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::ExitBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 62:
		ResetCity();
		DrawStringToHandle(BtnX[62], BtnY[62], "ÇÕÇ¢", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 63:
		ResetCity();
		DrawStringToHandle(BtnX[63], BtnY[63], "Ç¢Ç¢Ç¶", GetColor(255, 255, 255), init.FontHandle);
		break;
	}
}

void SYSTEM::ExitBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 62:
		fun.FStat = fun.F_MAIN;
		BtnSwitch = Sw_MMAP;
		Fade(init.GraCity, init.GraMap, "Field");
		ResetMap();
		SpawnHer();
		break;
	case 63:
		BtnSwitch = Sw_CITY;
		ResetCity();
		break;
	}
}