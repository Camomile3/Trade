#include "Dxlib.h"
#include "class.h"

extern FUN fun;
extern INIT init;
extern HEROINE her;
extern GOODS Goods[32];
extern CITY City[16];
extern MARKET Market[16][32];
extern MARKET HerMarket[16][32];

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
	DrawButton();
	DrawMessageWindow();
	CityData();
}

void SYSTEM::CityBtnOver(int i) {

	switch (i) {
	case 0:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[0] + 24, BtnY[0] + 8, "Purchase", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[1] + 24, BtnY[1] + 8, "Sale", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 2:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[2] + 24, BtnY[2] + 8, "Invest", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 3:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[3] + 24, BtnY[3] + 8, "Manage", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 4:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[4] + 24, BtnY[4] + 8, "Talk", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 5:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[5] + 24, BtnY[5] + 8, "Exit", GetColor(255, 0, 0), init.FontHandle);
	}
}

void SYSTEM::CityBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[0] + 24, BtnY[0] + 8, "Purchase", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 1:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[1] + 24, BtnY[1] + 8, "Sale", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 2:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[2] + 24, BtnY[2] + 8, "Invest", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 3:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[3] + 24, BtnY[3] + 8, "Manage", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 4:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[4] + 24, BtnY[4] + 8, "Talk", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 5:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[5] + 24, BtnY[5] + 8, "Exit", GetColor(0, 0, 0), init.FontHandle);
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
		InvestData();
		break;
	case 3:
		BtnSwitch = Sw_MANAGE;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		ManageData();
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
		ResetCity();
		TalkNumber++;
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

	DrawStringToHandle(x + 100, y, City[her.On].Name, GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 60, "Feature", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 100, "Population", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 140, "Development", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 180, "Economy", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 220, "Technology", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 260, "Industry", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 300, "Infrastructure", GetColor(0, 0, 0), init.FontHandle);

	sprintf_s(Temp, 32, "%d", City[her.On].Type);
	DrawStringToHandle(x + 200, y + 20 + 40, Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d", City[her.On].Population);
	DrawStringToHandle(x + 200, y + 20 + 40 * 2, Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Develop * 100));
	DrawStringToHandle(x + 200, y + 20 + 40 * 3, Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Economy * 100));
	DrawStringToHandle(x + 200, y + 20 + 40 * 4, Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Technology * 100));
	DrawStringToHandle(x + 200, y + 20 + 40 * 5, Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Industry * 100));
	DrawStringToHandle(x + 200, y + 20 + 40 * 6, Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Infra * 100));
	DrawStringToHandle(x + 200, y + 20 + 40 * 7, Temp, GetColor(0, 0, 0), init.FontHandle);
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
			GoodsOn[i] = TRUE;
			BtnOn[ID] = TRUE;
			break;
		}
	}

	Goods[ID].CalcedPrice = Market[her.On][ID].CalcPrice(Goods[ID].Price, City[her.On].Economy, Market[her.On][ID].Demand, Market[her.On][ID].Supply, (float)1);

	DrawStringToHandle(BtnX[ID], BtnY[ID], Goods[ID].Name, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d", Goods[ID].CalcedPrice);
	DrawStringToHandle(BtnX[ID] + 200, BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
}

//Goods.Nameは品目の名前

void SYSTEM::BuyBtnOver(int i) {

	if (i == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 0, 0), init.FontHandle);
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
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 255, 255), init.FontHandle);
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

	int X = 560;
	int Y = 160;

	DrawStringToHandle(X, Y, "名前", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 200, Y, "値段", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 200 + 160, Y, "売量", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 200 + 160 * 2, Y, "需要", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 200 + 160 * 3, Y, "供給", GetColor(0, 0, 0), init.FontHandle);
}

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

	bool LEnd = FALSE;

	SearchEmpty(ID);

	DrawStringToHandle(MWX + 64, MWY + 64, "いくつ購入しますか？", GetColor(255, 255, 255), init.FontHandle);
	printfDx("SlotNumber=%d\n", SlotNumber);

	TempNumber = KeyInputNumber(MWX + 64, MWY + 96, 9999, 0, FALSE);
	TempPrice = Goods[ID].CalcedPrice * TempNumber;

	printfDx("Price=%d\n", Goods[ID].Price);
	printfDx("BoughtNumber=%d\n", TempNumber);
	printfDx("BoughtPrice=%d\n", TempPrice);
	printfDx("CargoPrice=%d\n", her.CargoPrice[SlotNumber]);

	if (TempPrice > her.Money) {
		ResetCity();
		DrawStringToHandle(MWX + 64, MWY + 64, "所持金が足りません", GetColor(255, 255, 255), init.FontHandle);
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
	else if (TempNumber + her.CargoWeight > her.MaxWeight) {
		ResetCity();
		DrawStringToHandle(MWX + 64, MWY + 64, "重量オーバーです", GetColor(255, 255, 255), init.FontHandle);
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
		her.CargoPrice[SlotNumber] += Goods[ID].CalcedPrice * TempNumber;
		her.Cargo[SlotNumber] += TempNumber;
		her.Money -= TempPrice;
		her.CargoWeight += TempNumber;
		her.HiddenID[SlotNumber] = ID;

		if (her.Cargo[SlotNumber] != 0) {
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "購入しました", GetColor(255, 255, 255), init.FontHandle);
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
			GoodsOn[i] = TRUE;
			BtnOn[ID] = TRUE;
			sprintf_s(Temp, 32, "%d", her.CargoPrice[i] / her.Cargo[i]);	//一個当買値
			DrawStringToHandle(BtnX[ID] + 260, BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.Cargo[i]);	//積荷数量
			DrawStringToHandle(BtnX[ID] + 260 + 110 * 2, BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
			break;
		}
	}

	Goods[ID].CalcedPrice = Market[her.On][ID].SaleCalcPrice(Goods[ID].Price, City[her.On].Economy, Market[her.On][ID].Demand, Market[her.On][ID].Supply, (float)1);

	DrawStringToHandle(BtnX[ID], BtnY[ID], Goods[ID].Name, GetColor(0, 0, 0), init.FontHandle);

	sprintf_s(Temp, 32, "%d", Goods[ID].CalcedPrice);
	DrawStringToHandle(BtnX[ID] + 260 + 110, BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);



	/*
			DrawStringToHandle(BtnX[i + 1], BtnY[i + 1], Goods[her.HiddenID[i]].Name, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.Cargo[i]);
			DrawStringToHandle(BtnX[i + 1] + 200, BtnY[i + 1], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.CargoPrice[i]);
			DrawStringToHandle(BtnX[i + 1] + 400, BtnY[i + 1], Temp, GetColor(0, 0, 0), init.FontHandle);
			*/

}


void SYSTEM::SaleBtnOver(int i) {

	if (i == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 0, 0), init.FontHandle);
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
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 255, 255), init.FontHandle);
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
	int Y = 160;

	DrawStringToHandle(X, Y, "名前", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 190, Y, "一個当買値", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 210 + 110, Y, "売値", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 210 + 110 * 2, Y, "数量", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 210 + 110 * 3, Y, "受入量", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 210 + 110 * 4, Y, "需要", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 210 + 110 * 5, Y, "供給", GetColor(0, 0, 0), init.FontHandle);

	for (int i = 0; i < 8; i++) {
		if (her.HiddenID[i] != -1)
			SaleSort(her.HiddenID[i]);
	}

	/*	for (int i = 0; i < CargoNumber; i++) {
			if (her.Cargo[i] != 0) {
				DrawStringToHandle(BtnX[i], BtnY[i], Goods[her.HiddenID[i]].Name, GetColor(0, 0, 0), init.FontHandle);
				sprintf_s(Temp, 32, "%d", her.Cargo[i]);
				DrawStringToHandle(BtnX[i] + 200, BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
				sprintf_s(Temp, 32, "%d", her.CargoPrice[i] / her.Cargo[i]);
				DrawStringToHandle(BtnX[i] + 600, BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
			}
			else
				break;
		}*/
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

	DrawStringToHandle(MWX + 64, MWY + 64, "いくつ売却しますか？", GetColor(255, 255, 255), init.FontHandle);
	printfDx("SlotNumber=%d\n", SlotNumber);

	TempNumber = KeyInputNumber(MWX + 64, MWY + 96, 9999, 0, FALSE);
	TempPrice = Goods[ID].CalcedPrice * TempNumber;

	printfDx("Price=%d\n", Goods[ID].Price);
	printfDx("BoughtNumber=%d\n", TempNumber);
	printfDx("BoughtPrice=%d\n", TempPrice);
	printfDx("CargoPrice=%d\n", her.CargoPrice[SlotNumber]);

	if (TempNumber > her.Cargo[SlotNumber]) {
		ResetCity();
		DrawStringToHandle(MWX + 64, MWY + 64, "所有量を超えています", GetColor(255, 255, 255), init.FontHandle);
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
		DrawStringToHandle(MWX + 64, MWY + 64, "売却しました", GetColor(255, 255, 255), init.FontHandle);
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

	switch (i) {
	case 63:
		ResetCity();
		BtnSwitch = Sw_INVEST;
		DrawWindow(520, 140, 5, 16);
		InvestData();
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::InvestBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		ResetCity();
		BtnSwitch = Sw_INVEST;
		DrawWindow(520, 140, 5, 16);
		InvestData();
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::InvestBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		BtnSwitch = Sw_CITY;
		ResetCity();
		break;
	case 1:
		break;
	}
}

void SYSTEM::InvestData() {

}


void SYSTEM::ManageBtnOver(int i) {

	switch (i) {
	case 63:
		ResetCity();
		BtnSwitch = Sw_MANAGE;
		DrawWindow(520, 140, 5, 16);
		ManageData();
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 0, 0), init.FontHandle);
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
		ManageData();
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 255, 255), init.FontHandle);
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

void SYSTEM::ManageData() {

}


void SYSTEM::TalkBtnOver(int i) {

	switch (EventNumber) {
	case 0:
		switch (i) {
		case 62:
			ResetTalk();
			SetTwoBtn();
			DrawStringToHandle(BtnX[62], BtnY[62], "買う", GetColor(255, 0, 0), init.FontHandle);
			break;
		case 63:
			ResetTalk();
			SetTwoBtn();
			DrawStringToHandle(BtnX[63], BtnY[63], "買わない", GetColor(255, 0, 0), init.FontHandle);
			break;
		}
		break;
	case 1:
		break;
	}
}

void SYSTEM::TalkBtnOut(int OveredBtn) {

	switch (EventNumber) {
	case 0:
		switch (OveredBtn) {
		case 62:
			ResetTalk();
			SetTwoBtn();
			DrawStringToHandle(BtnX[62], BtnY[62], "買う", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 63:
			ResetTalk();
			SetTwoBtn();
			DrawStringToHandle(BtnX[63], BtnY[63], "買わない", GetColor(255, 255, 255), init.FontHandle);
			break;
		}
		break;
	case 1:
		break;
	}
}

void SYSTEM::TalkBtnSys(int OveredBtn) {

	switch (BtnSwitch) {
	case Sw_TALK:
		ETalkCount++;
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
	DrawButton();
	DrawMessageWindow();
	CityData();
	Event(EventNumber);
}

void SYSTEM::ExitBtnOver(int i) {

	switch (i) {
	case 62:
		ResetCity();
		DrawStringToHandle(BtnX[62], BtnY[62], "はい", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 63:
		ResetCity();
		DrawStringToHandle(BtnX[63], BtnY[63], "いいえ", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::ExitBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 62:
		ResetCity();
		DrawStringToHandle(BtnX[62], BtnY[62], "はい", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 63:
		ResetCity();
		DrawStringToHandle(BtnX[63], BtnY[63], "いいえ", GetColor(255, 255, 255), init.FontHandle);
		break;
	}
}

void SYSTEM::ExitBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 62:
		fun.FStat = fun.F_MAIN;
		BtnSwitch = Sw_MMAP;
		Fade(init.GraCity, init.GraMap);
		ResetMap();
		SpawnHer();
		break;
	case 63:
		BtnSwitch = Sw_CITY;
		ResetCity();
		break;
	}
}