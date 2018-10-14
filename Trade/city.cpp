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
extern TRANSPORT Trans[8];
extern BUILDING CityBuilding[16][3];
extern BUILDING HerBuilding[16][3][99];
extern COMPANY Comp[16];

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

void SYSTEM::CalcMarket() {

	CalcDemand(her.On);
	CalcSupply(her.On);
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
	Goods[ID].CalcedPrice = Market[her.On][ID].CalcPrice(her.On, ID);
	Goods[ID].CalcedProd = Market[her.On][ID].CalcProduction(her.On, ID);

	if (OveredBtn != ID)
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
	OveredBtn = -1;
	BuyData();
}

void SYSTEM::SaleSort(int ID) {

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

	Goods[ID].CalcedPrice = Market[her.On][ID].SaleCalcPrice(her.On, ID);

	if (OveredBtn != ID)
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
	else if (OveredBtn == 62) {

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
		WaitClick();
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
		WaitClick();

	}
	BtnSwitch = Sw_SALE;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	OveredBtn = -1;
	SaleData();
}

void SYSTEM::InvestBtnOver(int i) {

	switch (BtnSwitch) {
	case Sw_INVEST:
	case Sw_INVESTT:
	case Sw_INVESTB:
	case Sw_INVESTI:
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
	case Sw_INVESTBUYB:
	case Sw_INVESTRENTB:
		if (BtnOn[i] == TRUE) {
			ResetCity();
			if (BtnSwitch == Sw_INVESTBUYB)
				MessageWindowMessage("çwì¸ÇµÇ‹Ç∑Ç©ÅH");
			else
				MessageWindowMessage("å_ñÒÇµÇ‹Ç∑Ç©ÅH");
			SetTwoBtn("ÇÕÇ¢", "Ç¢Ç¢Ç¶");
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(255, 0, 0), init.FontHandle);
		}
		break;
	}
}

void SYSTEM::InvestBtnOut(int i) {

	switch (BtnSwitch) {
	case Sw_INVEST:
	case Sw_INVESTT:
	case Sw_INVESTB:
	case Sw_INVESTI:
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
	case Sw_INVESTBUYB:
	case Sw_INVESTRENTB:
		if (BtnOn[i] == TRUE) {
			ResetCity();
			if (BtnSwitch == Sw_INVESTBUYB)
				MessageWindowMessage("çwì¸ÇµÇ‹Ç∑Ç©ÅH");
			else
				MessageWindowMessage("å_ñÒÇµÇ‹Ç∑Ç©ÅH");
			SetTwoBtn("ÇÕÇ¢", "Ç¢Ç¢Ç¶");
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(255, 255, 255), init.FontHandle);
		}
		break;
	}
}

void SYSTEM::InvestBtnSys(int i) {

	switch (i) {
	case 63:
		BtnSwitch = Sw_CITY;
		ResetCity();
		break;
	case 0:
		BtnSwitch = Sw_INVESTT;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		InvestData(-1);
		break;
	case 1:
		BtnSwitch = Sw_INVESTB;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		InvestData(-1);
		break;
	case 2:
		BtnSwitch = Sw_INVESTI;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		InvestData(-1);
		break;
	}
}

void SYSTEM::InvestData(int Btn) {

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
	case Sw_INVESTT:
		InvestDataT(-1);
		break;
	case Sw_INVESTB:
		InvestDataB(-1);
		break;
	case Sw_INVESTI:
		InvestDataI(-1);
		break;
	}
}

void SYSTEM::InvestBtnSysT(int i) {

	if (i == 63) {
		BtnSwitch = Sw_INVEST;
		ResetCity();
	}
	else if (TransportTech) {
		if (i < 8) {
			BtnSwitch = Sw_INVESTBUYT;
			ResetCity();
			InvestBuySysT(i);
		}
		else if (i >= 8 && i < 16) {
			BtnSwitch = Sw_INVESTSALET;
			ResetCity();
			InvestSaleSysT(i - 8);
		}
	}
}

void SYSTEM::InvestDataT(int Btn) {

	int x = 0;
	int y = 0;
	int i = 0;

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
}

void SYSTEM::InvestBuySysT(int ID) {

	MessageWindowMessage("Ç¢Ç≠Ç¬çwì¸ÇµÇ‹Ç∑Ç©ÅH");

	TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 1000000, 0, FALSE);
	TempPrice = Trans[ID].Price * TempNumber;

	if (TempPrice > her.Money) {
		ResetCity();
		MessageWindowMessage("èäéùã‡Ç™ë´ÇËÇ‹ÇπÇÒÅB");
		WaitClick();
	}
	else if (Trans[ID].Sea == FALSE && TempNumber + her.MaxWeight > 999999999) {
		ResetCity();
		MessageWindowMessage("Ç±ÇÍà»è„îÉÇ¶Ç‹ÇπÇÒÅB");
		WaitClick();
	}
	else if (Trans[ID].Sea == TRUE && TempNumber + her.ShipMaxWeight > 999999999 ) {
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
	BtnSwitch = Sw_INVESTT;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
	printfDx("%d\n", her.Transport[0]);
}

void SYSTEM::InvestSaleSysT(int ID) {

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
		TempPrice = (int)(Trans[ID].Price * TempNumber * 0.8);


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
	BtnSwitch = Sw_INVESTT;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
}

void SYSTEM::InvestBtnSysB(int i) {

	switch (BtnSwitch) {
	case Sw_INVESTB:
		if (i == 63) {
			BtnSwitch = Sw_INVEST;
			ResetCity();
		}
		else {
			if (3 <= i && i <= 5) {
				BtnSwitch = Sw_INVESTRENTB;
				ResetCity();
				InvestRentSysB(i - 3);
			}
			else if (6 <= i && i <= 8) {
				BtnSwitch = Sw_INVESTENDB;
				ResetCity();
				InvestEndSysB(i - 6);
			}
			else if (9 <= i && i <= 11) {
				BtnSwitch = Sw_INVESTBUYB;
				ResetCity();
				InvestBuySysB(i - 9);
			}
			else if (12 <= i && i <= 14) {
				BtnSwitch = Sw_INVESTSALEB;
				ResetCity();
				InvestSaleSysB(i - 12);
			}
		}
		break;
	case Sw_INVESTBUYB:
		if (i == 63) {
			BtnSwitch = Sw_INVESTB;
			ResetCity();
		}
		else if (i == 62) {
			BuyFlag = TRUE;
			InvestBuySysB(0);
		}
		break;
	case Sw_INVESTRENTB:
		if (i == 63) {
			BtnSwitch = Sw_INVESTB;
			ResetCity();
		}
		else if (i == 62) {
			BuyFlag = TRUE;
			InvestRentSysB(0);
		}
		break;
	}
}

void SYSTEM::InvestDataB(int Btn) {

	int x = 0;
	int y = 0;
	char* Temp;

	TempChar[0] = "éÿêî";
	TempChar[1] = "èäóLêî";
	TempChar[2] = "í¿óø";
	TempChar[3] = "îÑâø";

	for (int i = 0; i < 16; i++) {
		if (i <= 9) {
			TempValueX[i] = 650 + x * 50;
			TempValueY[i] = 180 + y * 70;
			MultiResoValue(i);
		}
		else {
			TempValueX[i] = 660 + x * 50;
			TempValueY[i] = 180 + y * 70;
			MultiResoValue(i);
		}

		if (i <= 3) {
			DrawStringToHandle(TempValueX[i], TempValueY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
			x += 2;
		}
		if (i == 3) {
			x = 0;
			y = 1;
		}
		if (i >= 4) {
			if (i >= 4 && i <= 6)
				sprintf_s(TempT, 32, "%d", CityBuilding[her.On][i - 4].RentNumber);
			if (i >= 7 && i <= 9) {
				CountBuilding(i - 7);
				sprintf_s(TempT, 32, "%d", BuildingCount);
				BuildingCount = 0;
			}
			if (i >= 10 && i <= 12) {
				Temp = AddCommaN(CityBuilding[her.On][i - 10].Rent);
				sprintf_s(TempT, 32, "%s", Temp);
			}
			if (i >= 13 && i <= 15){
				Temp = AddCommaN(CityBuilding[her.On][i - 13].Price);
				sprintf_s(TempT, 32, "%s", Temp);
			}
			DrawStringToHandle(TempValueX[i], TempValueY[i], TempT, GetColor(0, 0, 0), init.FontHandle);

			y++;

			if (i == 6 || i == 12) {
				x += 2;
				y = 1;
			}
			if (i == 9) {
				x++;
				y = 1;
			}
		}
	}

	x = 0;
	y = 0;

	TempChar[0] = "éññ±èä";
	TempChar[1] = "ëqå…";
	TempChar[2] = "çHèÍ";
	TempChar[3] = "í¿éÿ";
	TempChar[4] = "í¿éÿ";
	TempChar[5] = "í¿éÿ";
	TempChar[6] = "âñÒ";
	TempChar[7] = "âñÒ";
	TempChar[8] = "âñÒ";
	TempChar[9] = "çwì¸";
	TempChar[10] = "çwì¸";
	TempChar[11] = "çwì¸";
	TempChar[12] = "îÑãp";
	TempChar[13] = "îÑãp";
	TempChar[14] = "îÑãp";

	for (int i = 0; i <= 2; i++) {
	
		BtnX[i] = 550 + x * 95;
		BtnY[i] = 250 + y * 70;
		BtnW[i] = 180;
		BtnH[i] = 42;
		MultiResoBtn(i);

		y++;

		if (Btn != i)
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
	}

	y = 0;

	for (int i = 3; i <= 14; i++) {

		if (i == 6 || i == 9 || i == 12) {
			x++;
			y = 0;
		}

		BtnX[i] = 1030 + x * 100;
		BtnY[i] = 250 + y * 70;
		BtnW[i] = 90;
		BtnH[i] = 42;
		MultiResoBtn(i);

		y++;

		BtnOn[i] = TRUE;

		if (Btn != i)
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
	}
}

void SYSTEM::InvestBuySysB(int ID) {
	
	if (ID == 0 && BuyFlag == FALSE) {
		BtnSwitch = Sw_INVESTBUYB;
		MessageWindowMessage("çwì¸ÇµÇ‹Ç∑Ç©ÅH");
		SetTwoBtn("ÇÕÇ¢", "Ç¢Ç¢Ç¶");
		return;
	}
	else if (ID == 0 && (CountBuilding(ID) >= 1 || CityBuilding[her.On][ID].RentNumber >= 1)) {
		ResetCity();
		MessageWindowMessage("Ç‡Ç§éùÇ¡ÇƒÇ¢Ç‹Ç∑ÅB");
		BuyFlag = FALSE;
		WaitClick();
	}
	else if (BuyFlag == TRUE) {
		TempNumber = 1;
		TempPrice = CityBuilding[her.On][ID].Price;

		for (int i = 0; i < TempNumber; i++) {
			SearchBuildingEmpty(ID);
			HerBuilding[her.On][ID][BuildingSlot].Number++;
		}
		her.Money -= TempPrice;
		ResetCity();
		MessageWindowMessage("çwì¸ÇµÇ‹ÇµÇΩÅB");
		BuyFlag = FALSE;
		WaitClick();
	}
	else {
		MessageWindowMessage("Ç¢Ç≠Ç¬çwì¸ÇµÇ‹Ç∑Ç©ÅH");

		TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 1000000, 0, FALSE);
		TempPrice = CityBuilding[her.On][ID].Price * TempNumber;

		if (TempPrice > her.Money) {
			ResetCity();
			MessageWindowMessage("èäéùã‡Ç™ë´ÇËÇ‹ÇπÇÒÅB");
			WaitClick();
		}
		else if (CountBuilding(ID) + CityBuilding[her.On][ID].RentNumber + TempNumber > 99) {
			ResetCity();
			MessageWindowMessage("ÇªÇÒÇ»Ç…îÉÇ¶Ç‹ÇπÇÒÅB");
			WaitClick();
		}
		else if (TempNumber != 0)
		{
			for (int i = 0; i < TempNumber; i++) {
				SearchBuildingEmpty(ID);
				HerBuilding[her.On][ID][BuildingSlot].Number++;
			}
			her.Money -= TempPrice;
			ResetCity();
			MessageWindowMessage("çwì¸ÇµÇ‹ÇµÇΩÅB");
			WaitClick();
		}
	}
		BtnSwitch = Sw_INVESTB;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		InvestData(-1);
		OveredBtn = -1;
		printfDx("%d\n", CityBuilding[her.On][ID].Number);
	
}

void SYSTEM::InvestSaleSysB(int ID) {

	TCHAR Temp[32];
	if (CountBuilding(ID) == 0) {
		ResetCity();
		MessageWindowMessage("èäéùÇµÇƒÇ¢Ç‹ÇπÇÒÅB");
		WaitClick();
	}
	else {
		MessageWindowMessage("Ç¢Ç≠Ç¬îÑãpÇµÇ‹Ç∑Ç©ÅH");
		sprintf_s(Temp, 32, "0Å`%d", CountBuilding(ID));
		DrawStringToHandle(MultiResoIntX(MWX + 64 + 32 + 256), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);

		TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), CountBuilding(ID), 0, FALSE);
		TempPrice = (int)CalcSellBuilding(ID);


		if (CountBuilding(ID) < TempNumber) {
			ResetCity();
			MessageWindowMessage("èäéùêîÇí¥Ç¶ÇƒÇ¢Ç‹Ç∑ÅB");
			WaitClick();
		}
		else if (TempNumber != 0)
		{
			for (int i = 0; i < TempNumber; i++) {
				SearchCheapestBuilding(ID);
				HerBuilding[her.On][ID][CheapestBuildingID].Reset(ID);
			}
			her.Money += TempPrice;
			ResetCity();
			MessageWindowMessage("îÑãpÇµÇ‹ÇµÇΩÅB");
			WaitClick();
		}
	}
	BtnSwitch = Sw_INVESTB;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
}

void SYSTEM::InvestRentSysB(int ID) {

	TCHAR Temp[64];

	if (ID == 0 && BuyFlag == FALSE) {
		BtnSwitch = Sw_INVESTRENTB;
		MessageWindowMessage("å_ñÒÇµÇ‹Ç∑Ç©ÅH");
		SetTwoBtn("ÇÕÇ¢", "Ç¢Ç¢Ç¶");
		return;
	}
	else if (ID == 0 && (CountBuilding(ID) >= 1 || CityBuilding[her.On][ID].RentNumber >= 1)) {
		ResetCity();
		MessageWindowMessage("Ç‡Ç§éùÇ¡ÇƒÇ¢Ç‹Ç∑ÅB");
		BuyFlag = FALSE;
		WaitClick();
	}
	else if (BuyFlag == TRUE) {

		CityBuilding[her.On][ID].RentNumber++;
		her.Money -= CityBuilding[her.On][ID].Rent * 2;
		ResetCity();
		MessageWindowMessage("å_ñÒÇµÇ‹ÇµÇΩÅB");
		BuyFlag = FALSE;
		WaitClick();
	}
	else {

		sprintf_s(Temp, 64, "Ç¢Ç≠Ç¬å_ñÒÇµÇ‹Ç∑Ç©ÅH(ì™ã‡ÇÕí¿óøÇÃìÒî{Ç≈Ç∑ÅB) 0Å`%d", 99 - CityBuilding[her.On][ID].RentNumber);
		DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);

		TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 99 - CityBuilding[her.On][ID].RentNumber, 0, FALSE);
		TempPrice = CityBuilding[her.On][ID].Rent * TempNumber * 2;

		if (TempPrice > her.Money) {
			ResetCity();
			MessageWindowMessage("èäéùã‡Ç™ë´ÇËÇ‹ÇπÇÒÅB");
			WaitClick();
		}
		else if (CityBuilding[her.On][ID].RentNumber + CountBuilding(ID) + TempNumber > 99) {
			ResetCity();
			MessageWindowMessage("ÇªÇÒÇ»Ç…éÿÇËÇÍÇ‹ÇπÇÒÅB");
			WaitClick();
		}
		else if (TempNumber != 0)
		{
			CityBuilding[her.On][ID].RentNumber += TempNumber;
			her.Money -= TempPrice;
			ResetCity();
			MessageWindowMessage("å_ñÒÇµÇ‹ÇµÇΩÅB");
			WaitClick();
		}
	}
	BtnSwitch = Sw_INVESTB;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
	printfDx("%d\n", CityBuilding[her.On][ID].Number);
}

void SYSTEM::InvestEndSysB(int ID) {

	TCHAR Temp[32];
	if (CityBuilding[her.On][ID].RentNumber == 0) {
		ResetCity();
		MessageWindowMessage("éÿÇËÇƒÇ¢Ç‹ÇπÇÒÅB");
		WaitClick();
	}
	else {
		MessageWindowMessage("Ç¢Ç≠Ç¬âñÒÇµÇ‹Ç∑Ç©ÅH");
		sprintf_s(Temp, 32, "0Å`%d", CityBuilding[her.On][ID].RentNumber);
		DrawStringToHandle(MultiResoIntX(MWX + 64 + 32 + 256), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);

		TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), CityBuilding[her.On][ID].RentNumber, 0, FALSE);

		if (CityBuilding[her.On][ID].RentNumber < TempNumber) {
			ResetCity();
			MessageWindowMessage("å_ñÒêîÇí¥Ç¶ÇƒÇ¢Ç‹Ç∑ÅB");
			WaitClick();
		}
		else if (TempNumber != 0)
		{
			CityBuilding[her.On][ID].RentNumber -= TempNumber;
			ResetCity();
			MessageWindowMessage("âñÒÇµÇ‹ÇµÇΩÅB");
			WaitClick();
		}
	}
	BtnSwitch = Sw_INVESTB;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
}

void SYSTEM::InvestBtnSysI(int i) {

	if (i == 63) {
		BtnSwitch = Sw_CITY;
		ResetCity();
	}
}

void SYSTEM::InvestDataI(int i) {


}

void SYSTEM::InvestBuySysI(int i) {


}

void SYSTEM::InvestSaleSysI(int i) {


}

void SYSTEM::ManageBtnOver(int i) {

	switch (BtnSwitch) {
	case Sw_MANAGE:
	case Sw_MANAGEO:
	case Sw_MANAGEW:
	case Sw_MANAGEWIN:
	case Sw_MANAGEWOUT:
	case Sw_MANAGEF:
		if (i == 63) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			ManageData(i);
			DrawStringToHandle(BtnX[63], BtnY[63], "ñﬂÇÈ", GetColor(255, 0, 0), init.FontHandle);
		}
		else if (BtnOn[i] == TRUE) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			ManageData(i);
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(255, 0, 0), init.FontHandle);
		}
		break;
	}
}

void SYSTEM::ManageBtnOut(int i) {

	switch (BtnSwitch) {
	case Sw_MANAGE:
	case Sw_MANAGEO:
	case Sw_MANAGEW:
	case Sw_MANAGEWIN:
	case Sw_MANAGEWOUT:
	case Sw_MANAGEF:
		if (i == 63) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			ManageData(i);
			DrawStringToHandle(BtnX[63], BtnY[63], "ñﬂÇÈ", GetColor(255, 255, 255), init.FontHandle);
		}
		else if (BtnOn[i] == TRUE) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			ManageData(i);
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
		}
		break;
	}
}

void SYSTEM::ManageBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		BtnSwitch = Sw_CITY;
		ResetCity();
		break;
	case 0:
		BtnSwitch = Sw_MANAGEO;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		ManageDataO(-1);
		break;
	case 1:
		BtnSwitch = Sw_MANAGEW;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		ManageDataW(-1);
		break;
	case 2:
		BtnSwitch = Sw_MANAGEF;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		ManageDataF(-1);
		break;
	}
}

void SYSTEM::ManageData(int Btn) {

	switch (BtnSwitch) {

	case Sw_MANAGE:
		for (int i = 0; i < 3; i++) {
			BtnX[i] = 600;
			BtnY[i] = 200 + i * 70;
			BtnOn[i] = TRUE;
			MultiResoBtn(i);
		}
		TempChar[0] = "éññ±èä";
		TempChar[1] = "ëqå…";
		TempChar[2] = "çHèÍ";

		if (Btn != 0)
			DrawStringToHandle(BtnX[0], BtnY[0], TempChar[0], GetColor(0, 0, 0), init.FontHandle);
		if (Btn != 1)
			DrawStringToHandle(BtnX[1], BtnY[1], TempChar[1], GetColor(0, 0, 0), init.FontHandle);
		if (Btn != 2)
			DrawStringToHandle(BtnX[2], BtnY[2], TempChar[2], GetColor(0, 0, 0), init.FontHandle);
		break;
	case Sw_MANAGEO:
		ManageDataO(Btn);
		break;
	case Sw_MANAGEW:
		ManageDataW(Btn);
		break;
	case Sw_MANAGEWIN:
		ManageDataWIN();
		break;
	case Sw_MANAGEF:
		ManageDataF(Btn);
		break;
	}
}

void SYSTEM::ManageBtnSysO(int i) {

	if (i == 63) {
		BtnSwitch = Sw_MANAGE;
		ResetCity();
	}
	else if (i == 0) {
		BtnSwitch = Sw_MANAGEEMPO;
		ResetCity();
		ManageEmpSysO();
	}
	else if (i == 1) {
		BtnSwitch = Sw_MANAGEENDO;
		ResetCity();
		ManageEmpEndSysO();
	}
}

void SYSTEM::ManageDataO(int Btn) {

	TCHAR Temp[32];
	int x = 0;
	int y = 0;

	SetSingleBtn("ñﬂÇÈ");

	TempChar[0] = "è]ã∆àıêî";
	TempChar[1] = "ñfà’òHàÍóó";

	for (int i = 0; i < 2; i++) {
		TempValueX[i] = 600;
		TempValueY[i] = 200 + i * 84;
		MultiResoValue(i);
		DrawStringToHandle(TempValueX[i], TempValueY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
		y++;
	}
	for (int i = 0; i < 1; i++) {
		TempValueX[i] = 800;
		TempValueY[i] = 200 + i * 42;
		MultiResoValue(i);
		sprintf_s(Temp, 32, "%d", Comp[her.On].OEmployee);
		DrawStringToHandle(TempValueX[i], TempValueY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
		y++;
	}

	y = 0;
	TempChar[0] = "è]ã∆àıåŸóp";
	TempChar[1] = "è]ã∆àıâåŸ";
	TempChar[2] = "ñfà’òHê›íË";

	for (int i = 0; i <= 2; i++) {

		BtnX[i] = 1000;
		BtnY[i] = 200 + y * 42;
		BtnW[i] = 180;
		BtnH[i] = 42;
		MultiResoBtn(i);

		y++;

		if (Btn != i)
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);

		BtnOn[i] = TRUE;
	}
}

void SYSTEM::ManageEmpSysO() {

	TCHAR Temp[64];

	sprintf_s(Temp, 64, "âΩÉZÉbÉgåŸópÇµÇ‹Ç∑Ç©ÅH(1ÉZÉbÉg5êl 0Å`%d", 10 - Comp[her.On].OEmpSet);
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);

	TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 10 - Comp[her.On].OEmpSet, 0, FALSE);

	if (Comp[her.On].OEmpSet + TempNumber > 10) {
		ResetCity();
		MessageWindowMessage("ÇªÇÒÇ»Ç…åŸÇ¶Ç‹ÇπÇÒÅB");
		WaitClick();
	}
	else if (TempNumber != 0)
	{
		Comp[her.On].OEmployee += TempNumber * 5;
		Comp[her.On].OEmpSet += TempNumber;
		ResetCity();
		MessageWindowMessage("åŸópÇµÇ‹ÇµÇΩÅB");
		WaitClick();
	}
	BtnSwitch = Sw_MANAGEO;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	ManageData(-1);
	OveredBtn = -1;
}

void SYSTEM::ManageEmpEndSysO() {

	TCHAR Temp[64];

	sprintf_s(Temp, 64, "âΩÉZÉbÉgâåŸÇµÇ‹Ç∑Ç©ÅH 0Å`%d", Comp[her.On].OEmpSet);
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64 + 32), "ëﬁêEã‡Ç∆ÇµÇƒããóø6Ç©åéï™Çéxï•Ç§ã`ñ±Ç™Ç†ÇËÇ‹Ç∑ÅB", GetColor(255, 255, 255), init.FontHandle);

	TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64 + 64), Comp[her.On].OEmpSet, 0, FALSE);

	if (TempNumber > Comp[her.On].OEmpSet) {
		ResetCity();
		MessageWindowMessage("ÇªÇÒÇ»Ç…åŸÇ¡ÇƒÇ‹ÇπÇÒÅB");
		WaitClick();
	}
	else if (TempNumber != 0)
	{
		Comp[her.On].OEmployee -= TempNumber * 5;
		Comp[her.On].OEmpSet -= TempNumber;
		her.Money -= Comp[her.On].OSalary * 6;
		ResetCity();
		MessageWindowMessage("âåŸÇµÇ‹ÇµÇΩÅB");
		WaitClick();
	}
	BtnSwitch = Sw_MANAGEO;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	ManageData(-1);
	OveredBtn = -1;
}

void SYSTEM::ManageBtnSysW(int i) {

	if (i == 63) {
		BtnSwitch = Sw_MANAGE;
		OveredBtn = -1;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		ManageData(-1);
	}
	else if (i == 0) {
		BtnSwitch = Sw_MANAGEWIN;
		ResetCity();
		ManageDataWIN();
	}
	else if (i == 1) {
		BtnSwitch = Sw_MANAGEWOUT;
		ResetCity();
		ManageWareOutSys();
	}
}

void SYSTEM::ManageDataW(int Btn) {

	TCHAR Temp[32];
	int x = 0;
	int y = 0;

	SetSingleBtn("ñﬂÇÈ");

	TempChar[0] = "ì¸å…";
	TempChar[1] = "èoå…";

	for (int i = 0; i < 2; i++) {
		BtnX[i] = 600;
		BtnY[i] = 200 + i * 84;
		MultiResoBtn(i);
		if (Btn != i)
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
		y++;

		BtnOn[i] = TRUE;
	}
}

void SYSTEM::ManageDataWINSort(int ID) {

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
	TempChar[ID] = Goods[ID].Name;

	DrawStringToHandle(BtnX[ID], BtnY[ID], TempChar[ID], GetColor(0, 0, 0), init.FontHandle);
}

void SYSTEM::ManageDataWIN() {

	DrawWindow(520, 140, 5, 16);

	int X = 560;
	int Y = MultiResoIntY(160);

	DrawStringToHandle(MultiResoIntX(X), Y, "ñºëO", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 190), Y, "àÍå¬ìñîÉíl", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 110), Y, "êîó ", GetColor(0, 0, 0), init.FontHandle);

	MessageWindowMessage("Ç«ÇÍÇì¸å…ÇµÇ‹Ç∑Ç©ÅH");
	SetSingleBtn("ñﬂÇÈ");

	for (int i = 0; i < 8; i++) {
		if (her.HiddenID[i] != -1)
			ManageDataWINSort(her.HiddenID[i]);
	}
}

void SYSTEM::ManageWareInSys(int i) {

	if (i == 63) {
		BtnSwitch = Sw_MANAGEW;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		OveredBtn = -1;
		ManageDataW(-1);
	}
}

void SYSTEM::ManageWareOutSys() {


}

void SYSTEM::ManageDataF(int Btn) {


}

void SYSTEM::TalkBtnOver(int i) {

	switch (i) {
	case 62:
		ResetTalk();

		DrawStringToHandle(BtnX[62], BtnY[62], TempChar[62], GetColor(255, 0, 0), init.FontHandle);
		break;
	case 63:
		ResetTalk();

		DrawStringToHandle(BtnX[63], BtnY[63], TempChar[63], GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::TalkBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 62:
		ResetTalk();

		DrawStringToHandle(BtnX[62], BtnY[62], TempChar[62], GetColor(255, 255, 255), init.FontHandle);
		break;
	case 63:
		ResetTalk();

		DrawStringToHandle(BtnX[63], BtnY[63], TempChar[63], GetColor(255, 255, 255), init.FontHandle);
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