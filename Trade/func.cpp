#include "DxLib.h"
#include "class.h"
#include "goods.h"
#define M_PI	3.14159265358979323846
#define DEG_TO_RAD(deg) (((deg)/360)*2*M_PI)
#define RAD_TO_DEG(rad) (((rad)/2/M_PI)*360)

INIT init;
FUN fun;
SYSTEM sys;
HEROINE her;

void FUN::main() {
	//解像度取得
	init.WinX = GetSystemMetrics(SM_CXSCREEN);
	init.WinY = GetSystemMetrics(SM_CYSCREEN);

	//解像度セット
	SetGraphMode(init.WinX, init.WinY, 32, 60);

	//マウス
	SetMouseDispFlag(TRUE);

	//初期化
	init.SetFont();
	init.LoadGra();
	init.ResetTitle();
	Goods->InitGoods();

	her.Money = 100000;
	her.CargoWeight = 0;


	//メインループ
	if (sys.DebugMode == TRUE) {
		while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
			sys.ButtonOver();
			sys.ButtonSys();
			WaitTimer(16);
			if (ProcessMessage() == -1) break;                 //エラーが起きたら終了
		}
	}
	else {
		while (1) {
			sys.ButtonOver();
			sys.ButtonSys();
			WaitTimer(16);
			if (ProcessMessage() == -1) break;                 //エラーが起きたら終了
		}
	}
}

//フォントセット
void INIT::SetFont() {
	LPCSTR font_path = "Resource/font/JKG-L_3.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) == 0) {
		MessageBox(NULL, "LoadingFontERROR", "", MB_OK);
	}

	FontHandle = CreateFontToHandle("JKゴシックL", 24, 0, DX_FONTTYPE_ANTIALIASING_8X8);
	if (FontHandle == 0) {
		MessageBox(NULL, "CreateFontToHandleERROR", "", MB_OK);
	}
}

void INIT::LoadGra() {
	GraT = LoadGraph("Resource/BG_Title.png");
	GraMW = LoadGraph("Resource/MW_1.png");
	GraBtn = LoadGraph("Resource/Btn1.png");
	GraBtn2 = LoadGraph("Resource/Btn2.png");
	GraBtn3 = LoadGraph("Resource/Btn3.png");
	GraMap = LoadGraph("Resource/Map.jpg");
	GraCity = LoadGraph("Resource/BG_City.png");
	GraHer = LoadGraph("Resource/Heroine.png");
	GraCalender = LoadGraph("Resource/I_Calender.png");
	GraGold = LoadGraph("Resource/I_Gold.png");
	GraIdea = LoadGraph("Resource/I_Idea.png");
	GraFactory = LoadGraph("Resource/I_Factory.png");
	char str[32];
	for (int i = 0; i < 12; i++) {
		sprintf_s(str, 32, "Resource/Carriage%d.png", i);
		GraCarriage[i] = LoadGraph(str);
		sprintf_s(str, 32, "Resource/Ship%d.png",i);
		GraShip[i] = LoadGraph(str);
	}
}

void INIT::ResetTitle() {
	ClearDrawScreen();
	DrawExtendGraph(0, 0, WinX, WinY, GraT, TRUE);
	sys.DrawButton();

}

//ボタンを追加するとき追加

void SYSTEM::DrawButton() {

	switch (fun.FStat) {
	case fun.F_TITLE:
		for (int i = 0; i < 4; i++) {
			BtnX[i] = 200 * i + 580;
			BtnY[i] = 860;
			BtnW[i] = 180;
			BtnH[i] = 42;

			DrawGraph(BtnX[i], BtnY[i], init.GraBtn, TRUE);
		};
		DrawStringToHandle(BtnX[0] + 36, BtnY[0] + 8, "NewGame", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[1] + 34, BtnY[1] + 8, "LoadGame", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[2] + 54, BtnY[2] + 8, "Option", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[3] + 36, BtnY[3] + 8, "QuitGame", GetColor(0, 0, 0), init.FontHandle);
		ButtonNumber = 4;
		break;
	case fun.F_MAIN:
		for (int i = 48; i < 7 + 48; i++) {
			BtnX[i] = 175 * (i - 48);
			BtnY[i] = 0;
			BtnW[i] = 175;
			BtnH[i] = 42;

			DrawGraph(BtnX[i], BtnY[i], init.GraBtn, TRUE);
		};

		DrawStringToHandle(BtnX[48] + 58, BtnY[48] + 8, "Cargo", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[49] + 34, BtnY[49] + 8, "Transport", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[50] + 36, BtnY[50] + 8, "Financial", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[51] + 36, BtnY[51] + 8, "SaveGame", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[52] + 36, BtnY[52] + 8, "LoadGame", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[53] + 54, BtnY[53] + 8, "Option", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[54] + 36, BtnY[54] + 8, "QuitGame", GetColor(0, 0, 0), init.FontHandle);

		ButtonNumber += 7;


		break;
	case fun.F_CITY:
		for (int i = 0; i < 6; i++) {
			BtnX[i] = 180;
			BtnY[i] = 160 + i * 38;
			BtnW[i] = 176;
			BtnH[i] = 38;
		};

		DrawStringToHandle(BtnX[0] + 24, BtnY[0] + 8, "Purchase", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[1] + 24, BtnY[1] + 8, "Sale", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[2] + 24, BtnY[2] + 8, "Invest", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[3] + 24, BtnY[3] + 8, "Manage", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[4] + 24, BtnY[4] + 8, "Talk", GetColor(0, 0, 0), init.FontHandle);
		DrawStringToHandle(BtnX[5] + 24, BtnY[5] + 8, "Exit", GetColor(0, 0, 0), init.FontHandle);

		ButtonNumber = 64;
		break;
	}
}

//ループ内の処理
//ボタン関数を追加した場合下二つに追加
void SYSTEM::ButtonOver() {

	GetMousePoint(&MouseX, &MouseY);

	if (MOver == FALSE) {
		for (int i = 0; i < ButtonNumber; i++) {
			if ((MouseX >= BtnX[i] && MouseX <= BtnX[i] + BtnW[i]) && (MouseY >= BtnY[i] && MouseY <= BtnY[i] + BtnH[i])) {
				switch (BtnSwitch) {
				case Sw_TITLE:
					TitleBtnOver(i);
					break;
				case Sw_QUIT:
					QuitBtnOver(i);
					break;
				case Sw_MMAP:
					MapBtnOver(i);
					break;
				case Sw_CARGO:
					CargoBtnOver(i);
					break;
				case Sw_TRANS:
					TransBtnOver(i);
					break;
				case Sw_FINAN:
					FinanBtnOver(i);
					break;
				case Sw_SAVE:
					SaveBtnOver(i);
					break;
				case Sw_LOAD:
					LoadBtnOver(i);
					break;
				case Sw_OPTION:
					OptionBtnOver(i);
					break;
				case Sw_CITY:
					CityBtnOver(i);
					break;
				case Sw_BUY:
					BuyBtnOver(i);
					break;
				case Sw_SALE:
					SaleBtnOver(i);
					break;
				case Sw_INVEST:
					InvestBtnOver(i);
					break;
				case Sw_MANAGE:
					ManageBtnOver(i);
					break;
				case Sw_TALK:
					TalkBtnOver(i);
					break;
				case Sw_EXIT:
					ExitBtnOver(i);
					break;
				}
				MOver = TRUE;
				OveredBtn = i;
				if (DebugMode == TRUE)
					printfDx("OverTrue & %d \n", OveredBtn);
				break;
			}
		}
	}

	if (MOver == TRUE) {
		if (!((MouseX >= BtnX[OveredBtn] && MouseX <= BtnX[OveredBtn] + BtnW[OveredBtn]) && (MouseY >= BtnY[OveredBtn] && MouseY <= BtnY[OveredBtn] + BtnH[OveredBtn]))) {
			switch (BtnSwitch) {
			case Sw_TITLE:
				TitleBtnOverOut(OveredBtn);
				break;
			case Sw_QUIT:
				QuitBtnOut(OveredBtn);
				break;
			case Sw_MMAP:
				MapBtnOut(OveredBtn);
				break;
			case Sw_CARGO:
				CargoBtnOut (OveredBtn);
				break;
			case Sw_TRANS:
				TransBtnOut(OveredBtn);
				break;
			case Sw_FINAN:
				FinanBtnOut(OveredBtn);
				break;
			case Sw_SAVE:
				SaveBtnOut(OveredBtn);
				break;
			case Sw_LOAD:
				LoadBtnOut(OveredBtn);
				break;
			case Sw_OPTION:
				OptionBtnOut(OveredBtn);
				break;
			case Sw_CITY:
				CityBtnOut(OveredBtn);
				break;
			case Sw_BUY:
				BuyBtnOut(OveredBtn);
				break;
			case Sw_SALE:
				SaleBtnOut(OveredBtn);
				break;
			case Sw_INVEST:
				InvestBtnOut(OveredBtn);
				break;
			case Sw_MANAGE:
				ManageBtnOut(OveredBtn);
				break;
			case Sw_TALK:
				TalkBtnOut(OveredBtn);
				break;
			case Sw_EXIT:
				ExitBtnOut(OveredBtn);
				break;	
			}
			OveredBtn = -1;
			MOver = FALSE;
			if (DebugMode == TRUE)
				printfDx("OutTrue & %d \n", OveredBtn);
			return;
		}
	}
}

void SYSTEM::ButtonSys() {

	MInput1F = MInput;
	MInput = GetMouseInput();
	if (!(MInput & MOUSE_INPUT_LEFT) && (MInput1F & MOUSE_INPUT_LEFT) == 1) {
		switch (BtnSwitch) {
		case Sw_TITLE:
			TitleBtnSys(OveredBtn);
			break;
		case Sw_QUIT:
			QuitBtnSys(OveredBtn);
			break;
		case Sw_MMAP:
			MapBtnSys(OveredBtn);
			break;
		case Sw_CARGO:
			CargoBtnSys(OveredBtn);
			break;
		case Sw_TRANS:
			TransBtnSys(OveredBtn);
			break;
		case Sw_FINAN:
			FinanBtnSys(OveredBtn);
			break;
		case Sw_SAVE:
			SaveBtnSys(OveredBtn);
			break;
		case Sw_LOAD:
			LoadBtnSys(OveredBtn);
			break;
		case Sw_OPTION:
			OptionBtnSys(OveredBtn);
			break;
		case Sw_CITY:
			CityBtnSys(OveredBtn);
			break;
		case Sw_BUY:
			BuyBtnSys(OveredBtn);
			break;
		case Sw_SALE:
			SaleBtnSys(OveredBtn);
			break;
		case Sw_INVEST:
			InvestBtnSys(OveredBtn);
			break;
		case Sw_MANAGE:
			ManageBtnSys(OveredBtn);
			break;
		case Sw_TALK:
			TalkBtnSys(OveredBtn);
			break;
		case Sw_EXIT:
			ExitBtnSys(OveredBtn);
			break;
		}
		if (DebugMode == TRUE)
			printfDx("MOUSE LEFT ON %d \n", OveredBtn);
			printfDx("Cargo = %d\n", her.Cargo[0]);
			printfDx("Cargo2 = %d\n", her.Cargo[1]);
		return;
	}
}

//メッセージ処理を追加するとき追加
void SYSTEM::DrawMessageWindow() {
	MWX = 480;
	MWY = 800;
	DrawGraph(MWX, MWY, init.GraMW, TRUE);

	sys.MOver = FALSE;
	switch (BtnSwitch) {
	case Sw_QUIT:
		BtnX[0] = MWX + 280;
		BtnY[0] = MWY + 140;
		BtnW[0] = 90;
		BtnH[0] = 42;
		BtnX[1] = MWX + 640;
		BtnY[1] = MWY + 140;
		BtnW[1] = 90;
		BtnH[1] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "終了しますか？", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[0], BtnY[0], "はい", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[1], BtnY[1], "いいえ", GetColor(255, 255, 255), init.FontHandle);
		ButtonNumber = 2;
		break;
	case Sw_CARGO:
		BtnX[0] = MWX + 640;
		BtnY[0] = MWY + 140;
		BtnW[0] = 90;
		BtnH[0] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "積荷の説明文を表示する予定です", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_TRANS:
		BtnX[0] = MWX + 640;
		BtnY[0] = MWY + 140;
		BtnW[0] = 90;
		BtnH[0] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "輸送手段の説明文を表示する予定です", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_FINAN:
		BtnX[0] = MWX + 640;
		BtnY[0] = MWY + 140;
		BtnW[0] = 90;
		BtnH[0] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "財務状況の解説をさせる予定です", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_SAVE:
		BtnX[0] = MWX + 640;
		BtnY[0] = MWY + 140;
		BtnW[0] = 90;
		BtnH[0] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "セーブするスロットを選んでね", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_LOAD:
		BtnX[0] = MWX + 640;
		BtnY[0] = MWY + 140;
		BtnW[0] = 90;
		BtnH[0] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "ロードするスロットを選んでね", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_OPTION:
		BtnX[0] = MWX + 640;
		BtnY[0] = MWY + 140;
		BtnW[0] = 90;
		BtnH[0] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "オプション項目の説明をさせる予定です", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_CITY:
		DrawStringToHandle(MWX + 64, MWY + 64, "景気がよく非常に活気がある。", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_BUY:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "購入する貿易品を選んでください", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_SALE:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "売却する貿易品を選んでください", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_EXIT:
		BtnX[0] = MWX + 280;
		BtnY[0] = MWY + 140;
		BtnW[0] = 90;
		BtnH[0] = 42;
		BtnX[1] = MWX + 640;
		BtnY[1] = MWY + 140;
		BtnW[1] = 90;
		BtnH[1] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "街を出ますか？", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[0], BtnY[0], "はい", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[1], BtnY[1], "いいえ", GetColor(255, 255, 255), init.FontHandle);
		ButtonNumber = 2;
		break;
	}

}

void SYSTEM::DrawWindow(int X, int Y, int W, int H) {
	int i = 0;
	int n = 0;

	while (1) {
		DrawGraph(X + n * 176, Y + i * 38, init.GraBtn2, TRUE);
		i++;
		if (i == H) {
			n++;
			i = 0;
		}
		if (n >= W)
			break;
	}
}

void GOODS::InitGoods() {
	Goods[0].SetGoods(0, (char*)"石炭", 60);
	Goods[1].SetGoods(1, (char*)"鉱石", 80);
	Goods[2].SetGoods(2, (char*)"レアメタル", 100);
	Goods[3].SetGoods(3, (char*)"食料", 100);
	Goods[4].SetGoods(4, (char*)"木材", 100);
	Goods[5].SetGoods(5, (char*)"石油", 100);
	Goods[6].SetGoods(6, (char*)"金属", 100);
	Goods[7].SetGoods(7, (char*)"缶詰", 100);
	Goods[8].SetGoods(8, (char*)"銃火器", 100);
	Goods[9].SetGoods(9, (char*)"紙", 100);
	Goods[10].SetGoods(10, (char*)"書籍", 100);
	Goods[11].SetGoods(11, (char*)"東洋贅沢品", 100);
	Goods[12].SetGoods(12, (char*)"西洋贅沢品", 100);
	Goods[13].SetGoods(13, (char*)"農業贅沢品", 100);
}

void SYSTEM::DrawValue() {
	int ValueX[5], ValueY[5], ValueW[5], ValueH[5];

	for (int i = 0; i < 5; i++) {
		ValueX[i] = 175 * i;
		ValueY[i] = 38;
		ValueW[i] = 180;
		ValueH[i] = 32;
		DrawExtendGraph(ValueX[i], ValueY[i], ValueX[i] + ValueW[i], ValueY[i] + ValueH[i], init.GraBtn3, TRUE);
	}
	TCHAR Temp[64];
	int x, y;
	x = 8;
	y = 42;

	her.Year = 3;
	her.Month = 9;
	her.Day = 25;
	DrawExtendGraph(x, y, x + 24, y + 24, init.GraCalender, TRUE);
	sprintf_s(Temp, 32, "%2d/%d/%d", her.Year, her.Month, her.Day);
	DrawStringToHandle(x + 28, 42, Temp, GetColor(0, 0, 0), init.FontHandle);

	DrawExtendGraph(x + 128+32, 42, x + 128+32 + 24, 42 + 24, init.GraGold, TRUE);
	if (her.Money >= 1000000000000) {
		sprintf_s(Temp, 64, "%2lld,%03lld,%03lld,%03lld,%03lld", her.Money / 1000000000000, (her.Money - her.Money / 1000000000000 * 1000000000000) / 1000000000, (her.Money - her.Money / 1000000000 * 1000000000) / 1000000, (her.Money - her.Money / 1000000 * 1000000) / 1000, her.Money - (her.Money / 1000) * 1000);
	}
	else if (her.Money >= 1000000000) {
		sprintf_s(Temp, 64, "%6lld,%03lld,%03lld,%03lld", her.Money / 1000000000, (her.Money - her.Money / 1000000000 * 1000000000) / 1000000, (her.Money - her.Money / 1000000 * 1000000) / 1000, her.Money - (her.Money / 1000) * 1000);
	}
	else if (her.Money >= 1000000) {
		sprintf_s(Temp, 64, "%9lld,%03lld,%03lld", her.Money / 1000000, (her.Money - her.Money/1000000 * 1000000) / 1000, her.Money - (her.Money / 1000) * 1000);
	}
	else if (her.Money >= 1000) {
		sprintf_s(Temp, 64, "%13lld,%03lld", her.Money/1000, her.Money - (her.Money / 1000) * 1000);
	}
	else
		sprintf_s(Temp, 64, "%16lld", her.Money);
	DrawStringToHandle(x + 128+64 + 28, 42, Temp, GetColor(0, 0, 0), init.FontHandle);

	her.MaxWeight = 100;
	DrawExtendGraph(x + 512-64, 42, x + 512-64 + 24, 42 + 24, init.GraCarriage[6], TRUE);
	sprintf_s(Temp, 32, "%d/%d", her.CargoWeight, her.MaxWeight);
	DrawStringToHandle(x + 512-64 + 28, 42, Temp, GetColor(0, 0, 0), init.FontHandle);

	her.WTech = 14;
	DrawExtendGraph(x + 512 + 175 + 64, 42, x + 512 + 175 + 64 + 24, 42 + 24, init.GraIdea, TRUE);
	sprintf_s(Temp, 32, "%d", her.WTech);
	DrawStringToHandle(x + 512 + 64 + 175 + 28, 42, Temp, GetColor(0, 0, 0), init.FontHandle);

	her.WIndustry = 12;
	DrawExtendGraph(x + 512 + 123 + 175, 42, x + 512 + 123 + 175 + 24, 42 + 24, init.GraFactory, TRUE);
	sprintf_s(Temp, 32, "%d", her.WIndustry);
	DrawStringToHandle(x + 512 + 123 + 175 + 28, 42, Temp, GetColor(0, 0, 0), init.FontHandle);
}

void SYSTEM::TitleBtnOver(int i) {
	switch (i) {
	case 0:
		init.ResetTitle();
		DrawStringToHandle(BtnX[0] + 36, BtnY[0] + 8, "NewGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		init.ResetTitle();
		DrawStringToHandle(BtnX[1] + 34, BtnY[1] + 8, "LoadGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 2:
		init.ResetTitle();
		DrawStringToHandle(BtnX[2] + 54, BtnY[2] + 8, "Option", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 3:
		init.ResetTitle();
		DrawStringToHandle(BtnX[3] + 36, BtnY[3] + 8, "QuitGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::TitleBtnOverOut(int OveredBtn) {
	switch (OveredBtn) {
	case 0:
		init.ResetTitle();
		DrawStringToHandle(BtnX[0] + 36, BtnY[0] + 8, "NewGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 1:
		init.ResetTitle();
		DrawStringToHandle(BtnX[1] + 34, BtnY[1] + 8, "LoadGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 2:
		init.ResetTitle();
		DrawStringToHandle(BtnX[2] + 54, BtnY[2] + 8, "Option", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 3:
		init.ResetTitle();
		DrawStringToHandle(BtnX[3] + 36, BtnY[3] + 8, "QuitGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::TitleBtnSys(int OveredBtn) {
	switch (OveredBtn) {
	case 0:
		fun.FStat = fun.F_MAIN;
		InitMap();
		break;
	case 1:
		BtnSwitch = Sw_LOAD;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		LoadData();
		break;
	case 2:
		BtnSwitch = Sw_OPTION;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		OptionData();
		break;
	case 3:
		BtnSwitch = Sw_QUIT;
		DrawMessageWindow();
		break;
	}
}

void SYSTEM::QuitBtnOver(int i) {

	switch (i) {
	case 0:
		QuitBtnReset();
		DrawStringToHandle(BtnX[0], BtnY[0], "はい", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		QuitBtnReset();
		DrawStringToHandle(BtnX[1], BtnY[1], "いいえ", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::QuitBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		QuitBtnReset();
		DrawStringToHandle(BtnX[0], BtnY[0], "はい", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		QuitBtnReset();
		DrawStringToHandle(BtnX[1], BtnY[1], "いいえ", GetColor(255, 255, 255), init.FontHandle);
		break;
	}
}

void SYSTEM::QuitBtnReset() {

	switch (fun.FStat) {
	case fun.F_TITLE:
		init.ResetTitle();
		BtnSwitch = Sw_QUIT;
		DrawMessageWindow();
		break;
	case fun.F_MAIN:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_QUIT;
		DrawMessageWindow();
		break;
	}
}

void SYSTEM::QuitBtnSys(int OveredBtn) {
	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (OveredBtn) {
		case 0:
			DxLib_End();
		case 1:
			BtnSwitch = Sw_TITLE;
			init.ResetTitle();
			break;
		}
	case fun.F_MAIN:
		switch (OveredBtn) {
		case 0:
			DxLib_End();
		case 1:
			BtnSwitch = Sw_MMAP;
			ResetMap();
			SpawnHer();
			break;
		}
	}
}

void SYSTEM::MapBtnOver(int i) {

	switch (i) {
	case 0:
		//効果音もしくはカーソルが反応する処理を入れる予定
		break;
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 48:
		DrawStringToHandle(BtnX[48] + 58, BtnY[48] + 8, "Cargo", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 49:
		DrawStringToHandle(BtnX[49] + 34, BtnY[49] + 8, "Transport", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 50:
		DrawStringToHandle(BtnX[50] + 36, BtnY[50] + 8, "Financial", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 51:
		DrawStringToHandle(BtnX[51] + 36, BtnY[51] + 8, "SaveGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 52:
		DrawStringToHandle(BtnX[52] + 36, BtnY[52] + 8, "LoadGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 53:
		DrawStringToHandle(BtnX[53] + 54, BtnY[53] + 8, "Option", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 54:
		DrawStringToHandle(BtnX[54] + 36, BtnY[54] + 8, "QuitGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::MapBtnOut(int OveredBtn) {
	switch (OveredBtn) {
	case 48:
		DrawStringToHandle(BtnX[48] + 58, BtnY[48] + 8, "Cargo", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 49:
		DrawStringToHandle(BtnX[49] + 34, BtnY[49] + 8, "Transport", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 50:
		DrawStringToHandle(BtnX[50] + 36, BtnY[50] + 8, "Financial", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 51:
		DrawStringToHandle(BtnX[51] + 36, BtnY[51] + 8, "SaveGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 52:
		DrawStringToHandle(BtnX[52] + 36, BtnY[52] + 8, "LoadGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 53:
		DrawStringToHandle(BtnX[53] + 54, BtnY[53] + 8, "Option", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 54:
		DrawStringToHandle(BtnX[54] + 36, BtnY[54] + 8, "QuitGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	}
}


//ボタンを追加するとき追加
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
		BtnSwitch = Sw_SAVE;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		SaveData();
		break;
	case 52:
		BtnSwitch = Sw_LOAD;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		LoadData();
		break;
	case 53:
		BtnSwitch = Sw_OPTION;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		OptionData();
		break;
	case 54:
		BtnSwitch = Sw_QUIT;
		DrawMessageWindow();
		break;
	}
}

void SYSTEM::CargoBtnOver(int i) {

	switch (i) {
	case 0:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_CARGO;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		CargoData();
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::CargoBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_CARGO;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		CargoData();
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::CargoBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
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
	DrawStringToHandle(580, 160, "名前", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(780, 160, "数量", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(980, 160, "買値", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(1180, 160, "一個当たり買値", GetColor(0, 0, 0), init.FontHandle);

	for (int i = 1; i < 8; i++) {
		BtnX[i] = 580;
		BtnY[i] = 200 + i * 42;
	}
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
	case 0:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_TRANS;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		TransData();
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::TransBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_TRANS;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		TransData();
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::TransBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		BtnSwitch = Sw_MMAP;
		ResetMap();
		SpawnHer();
		break;
	case 1:
		break;
	}
}

void SYSTEM::TransData() {

	DrawStringToHandle(580, 160, "名前", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(740, 160, "数量", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(900, 160, "輸送力", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(1060, 160, "合計", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(1220, 160, "移動タイプ", GetColor(0, 0, 0), init.FontHandle);
	BtnX[1] = 580;
	BtnY[1] = 200;
	DrawStringToHandle(BtnX[1], BtnY[1], "馬車", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(BtnX[1] + 160, BtnY[1], "1", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(BtnX[1] + 160 * 2, BtnY[1], "50", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(BtnX[1] + 160 * 3, BtnY[1], "50", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(BtnX[1] + 160 * 4, BtnY[1], "陸", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(BtnX[1], BtnY[1] + 100, "全て定数のダミーです", GetColor(0, 0, 0), init.FontHandle);

}

void SYSTEM::FinanBtnOver(int i) {

	switch (i) {
	case 0:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_FINAN;
		DrawWindow(60, 140, 5, 16);
		DrawWindow(980, 140, 5, 16);
		DrawMessageWindow();
		FinanData();
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::FinanBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_FINAN;
		DrawWindow(60, 140, 5, 16);
		DrawWindow(980, 140, 5, 16);
		DrawMessageWindow();
		FinanData();
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::FinanBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
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

	DrawStringToHandle(410, 160, "貸借対照表", GetColor(0, 0, 0), init.FontHandle);

	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "現金", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "商品", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "流動資産合計", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "建物", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "土地", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "備品", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "車両運搬具", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "固定資産合計", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "資産合計", GetColor(0, 0, 0), init.FontHandle); y++;
	x++; y = 0;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "借入金", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "未払金", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "負債合計", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "資本金", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "当期純利益", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "純資産合計", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 416 + 100, y * 32 + 240, "負債純資産合計", GetColor(0, 0, 0), init.FontHandle);
	x = 0; y = 0;
	DrawStringToHandle(1350, 160, "損益計算書", GetColor(0, 0, 0), init.FontHandle);

	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "売上高", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "売上原価", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "販売費及び一般管理費", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "税引前当期純利益", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "当期純利益", GetColor(0, 0, 0), init.FontHandle);
	x++; y = 0;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "期首商品棚卸高", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "当期商品仕入高", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "期末商品棚卸高", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "給料", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "支払家賃", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "減価償却費", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "", GetColor(0, 0, 0), init.FontHandle); y++;
	DrawStringToHandle(x * 128 + 1024, y * 32 + 240, "法人税等", GetColor(0, 0, 0), init.FontHandle); y++;
}

void SYSTEM::SaveBtnOver(int i) {

	switch (i) {
	case 0:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_SAVE;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		SaveData();
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::SaveBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_SAVE;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		SaveData();
		DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::SaveBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
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
		printfDx("F_TITLE");
		switch (i) {
		case 0:
			init.ResetTitle();
			BtnSwitch = Sw_LOAD;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			LoadData();
			DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 0, 0), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (i) {
		case 0:
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_LOAD;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			LoadData();
			DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 0, 0), init.FontHandle);
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
		case 0:
			init.ResetTitle();
			BtnSwitch = Sw_LOAD;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			LoadData();
			DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (OveredBtn) {
		case 0:
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_LOAD;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			LoadData();
			DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
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
		case 0:
			BtnSwitch = Sw_TITLE;
			init.ResetTitle();
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (OveredBtn) {
		case 0:
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

void SYSTEM::OptionBtnOver(int i) {

	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (i) {
		case 0:
			init.ResetTitle();
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			OptionData();
			DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 0, 0), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (i) {
		case 0:
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			OptionData();
			DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 0, 0), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	}
}

void SYSTEM::OptionBtnOut(int OveredBtn) {

	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (OveredBtn) {
		case 0:
			init.ResetTitle();
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			OptionData();
			DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (OveredBtn) {
		case 0:
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			OptionData();
			DrawStringToHandle(BtnX[0], BtnY[0], "閉じる", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	}
}

void SYSTEM::OptionBtnSys(int OveredBtn) {

	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (OveredBtn) {
		case 0:
			BtnSwitch = Sw_TITLE;
			init.ResetTitle();
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (OveredBtn) {
		case 0:
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

void SYSTEM::OptionData() {

}

void SYSTEM::InitMap() {
	OveredBtn = -1;
	SetMapBtn();
	if (DebugMode == TRUE) {
		DebugMap();
		DebugBox();
		clsDx();
	}
	else
		sys.Fade(init.GraT, init.GraMap);
	DrawButton();
	DrawValue();
	InitHer();

}

void SYSTEM::ResetMap() {
	ClearDrawScreen();
	SetMapBtn();
	DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraMap, TRUE);
	DrawButton();
	DrawValue();
	//DrawExtendGraph((int)her.X - 32, (int)her.Y - 64, (int)her.X + 32, (int)her.Y, init.GraCarriage[0], TRUE);
	//DrawExtendGraph((int)her.X - 16, (int)her.Y - 64, (int)her.X + 16, (int)her.Y, init.GraHer, FALSE);
	if (DebugMode == TRUE) {
		DebugBox();
		for (int i = 0; i < ButtonNumber; i++) {
			BtnCx[i] = BtnX[i] + BtnW[i] / 2;
			BtnCy[i] = BtnY[i] + BtnH[i] / 2;
			DrawCircle(BtnCx[i], BtnCy[i], 2, GetColor(0, 255, 0), TRUE);
		}
		clsDx();
		printfDx("Money=%lld\n", her.Money);
	}
}

//最大都市	640, 560
//西の都市1 255, 590
//西の都市2 185, 370
//西の島	230, 890
//北東都市	780, 340
//北の都市	620, 160
//東の都市	1080, 420
//東の島	1720, 260
//南東の島1	1700, 750
//南東の島2	1440, 880
void SYSTEM::SetMapBtn() {
	BtnSwitch = Sw_MMAP;
	int x = 64;
	int y = 48;
	BtnX[0] = 595;	//最大都市
	BtnY[0] = 580;
	BtnW[0] = 128;
	BtnH[0] = 80;
	BtnX[1] = 235;	//西1
	BtnY[1] = 610;
	BtnW[1] = x;
	BtnH[1] = y;
	BtnX[2] = 170;	//西2
	BtnY[2] = 410;
	BtnW[2] = x;
	BtnH[2] = y;
	BtnX[3] = 210;	//西島
	BtnY[3] = 920;
	BtnW[3] = x;
	BtnH[3] = y;
	BtnX[4] = 765;	//北東
	BtnY[4] = 380;
	BtnW[4] = x;
	BtnH[4] = y;
	BtnX[5] = 600;	//北
	BtnY[5] = 190;
	BtnW[5] = x;
	BtnH[5] = y;
	BtnX[6] = 1065;	//東
	BtnY[6] = 460;
	BtnW[6] = x;
	BtnH[6] = y;
	BtnX[7] = 1710;	//東島
	BtnY[7] = 300;
	BtnW[7] = x;
	BtnH[7] = y;
	BtnX[8] = 1690;	//南東島1
	BtnY[8] = 790;
	BtnW[8] = x;
	BtnH[8] = y;
	BtnX[9] = 1430;	//南東島2
	BtnY[9] = 920;
	BtnW[9] = x;
	BtnH[9] = y;
	BtnX[10] = 730;	//北東経路1
	BtnY[10] = 550;
	BtnW[10] = x;
	BtnH[10] = y;
	BtnX[11] = 765;	//北東経路2
	BtnY[11] = 480;
	BtnW[11] = x;
	BtnH[11] = y;
	BtnX[12] = 170;	//西路
	BtnY[12] = 470;
	BtnW[12] = x;
	BtnH[12] = y;
	BtnX[13] = 650;	//北路
	BtnY[13] = 300;
	BtnW[13] = x;
	BtnH[13] = y;
	BtnX[14] = 880;	//東路
	BtnY[14] = 390;
	BtnW[14] = x;
	BtnH[14] = y;
	BtnX[15] = 970;	//東路2
	BtnY[15] = 450;
	BtnW[15] = x;
	BtnH[15] = y;

	BtnX[20] = 605;	//港1
	BtnY[20] = 660;
	BtnW[20] = x;
	BtnH[20] = y;
	BtnX[21] = 530; //海路1
	BtnY[21] = 790;
	BtnW[21] = x;
	BtnH[21] = y;
	BtnX[22] = 285;	//港2
	BtnY[22] = 880;
	BtnW[22] = x;
	BtnH[22] = y;

	ButtonNumber = 48;
	for (int i = 0; i < ButtonNumber; i++) {
		BtnCx[i] = BtnX[i] + BtnW[i] / 2;
		BtnCy[i] = BtnY[i] + BtnH[i] / 2;
	}
}


void SYSTEM::DebugBox() {

	for (int i = 0; i < ButtonNumber; i++) {
		DrawBox(BtnX[i], BtnY[i], BtnX[i] + BtnW[i], BtnY[i] + BtnH[i], GetColor(0, 255, 0), FALSE);
		DrawCircle(BtnCx[i], BtnCy[i], 2, GetColor(0, 255, 0), TRUE);
	}
}

void SYSTEM::Fade(int before, int after) {

	SetDrawScreen(DX_SCREEN_BACK);
	if (fun.FStat == fun.F_TITLE) {
		for (int i = 0; i < 320; i++) {
			if (i >= 0 && i < 128) {
				SetDrawBright(255 - (i * 2), 255 - (i * 2), 255 - (i * 2));
				DrawExtendGraph(0, 0, init.WinX, init.WinY, before, TRUE);
			}
			if (i >= 128 && i < 192)
				SetDrawBright(0, 0, 0);

			if (i >= 192 && i < 320) {
				SetDrawBright((i - 192) * 2, (i - 192) * 2, (i - 192) * 2);
				DrawExtendGraph(0, 0, init.WinX, init.WinY, after, TRUE);
			}
			if (ProcessMessage() == -1) break;

			ScreenFlip();
		}
	}
	else {
		for (int i = 0; i < 160; i++) {
			if (i >= 0 && i < 64) {
				SetDrawBright(255 - (i * 4), 255 - (i * 4), 255 - (i * 4));
				DrawExtendGraph(0, 0, init.WinX, init.WinY, before, TRUE);
			}
			if (i >= 64 && i < 96)
				SetDrawBright(0, 0, 0);

			if (i >= 96 && i < 160) {
				SetDrawBright((i - 96) * 4, (i - 96) * 4, (i - 96) * 4);
				DrawExtendGraph(0, 0, init.WinX, init.WinY, after, TRUE);
			}
			if (ProcessMessage() == -1) break;

			ScreenFlip();
		}
	}
	SetDrawScreen(DX_SCREEN_FRONT);

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
	//DrawExtendGraph(BtnCx[0] - 16, BtnCy[0] - 64, BtnCx[0] + 16, BtnCy[0], init.GraHer, FALSE);
}

void SYSTEM::Move(int MoveTo) {

	Angle = atan2(BtnCy[MoveTo] - her.Y, BtnCx[MoveTo] - her.X);

	while (!(((her.X > BtnCx[MoveTo] - 6) && (her.X <= BtnCx[MoveTo] + 6)) && ((her.Y > BtnCy[MoveTo] - 6) && (her.Y <= BtnCy[MoveTo] + 6)))) {

		her.X += 1 * cos(Angle);
		her.Y += 1 * sin(Angle);

		ResetMap();

		//DrawExtendGraph((int)her.X - 16, (int)her.Y - 64, (int)her.X + 16, (int)her.Y, init.GraHer, FALSE);

		Angle2 = RAD_TO_DEG(Angle);



		if (DebugMode == TRUE) {
			clsDx();
			printfDx("%lf\n", Angle);
			printfDx("%lf°", RAD_TO_DEG(Angle));
			printfDx("%lf°", Angle2);
		}

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
		WaitTimer(8);
	}
}

void SYSTEM::MoveRoute() {
	switch (her.On) {
	case 0:
		switch (OveredBtn) {
		case 1:
			Move(1);
			her.On = 1;
			break;
		case 2:
			Move(1);
			Move(12);
			Move(2);
			her.On = 2;
			break;
		case 3:
			Move(3);
			her.On = 3;
			break;
		case 4:
			Move(10);
			Move(11);
			Move(4);
			her.On = 4;
			break;
		case 5:
			Move(10);
			Move(11);
			Move(4);
			Move(13);
			Move(5);
			her.On = 5;
			break;
		case 6:
			Move(10);
			Move(11);
			Move(4);
			Move(14);
			Move(15);
			Move(6);
			her.On = 6;
			break;
		}
		break;
	case 1:
		switch (OveredBtn) {
		case 0:
			Move(0);
			her.On = 0;
			break;
		case 2:
			Move(12);
			Move(2);
			her.On = 2;
			break;
		case 4:
			Move(0);
			Move(10);
			Move(11);
			Move(4);
			her.On = 4;
			break;
		case 5:
			Move(0);
			Move(10);
			Move(11);
			Move(4);
			Move(13);
			Move(5);
			her.On = 5;
			break;
		case 6:
			Move(0);
			Move(10);
			Move(11);
			Move(4);
			Move(14);
			Move(15);
			Move(6);
			her.On = 6;
			break;
		}
		break;
	case 2:
		switch (OveredBtn) {
		case 0:
			Move(12);
			Move(1);
			Move(0);
			her.On = 0;
			break;
		case 1:
			Move(12);
			Move(1);
			her.On = 1;
			break;
		case 4:
			Move(12);
			Move(1);
			Move(0);
			Move(10);
			Move(11);
			Move(4);
			her.On = 4;
			break;
		case 5:
			Move(12);
			Move(1);
			Move(0);
			Move(10);
			Move(11);
			Move(4);
			Move(13);
			Move(5);
			her.On = 5;
			break;
		case 6:
			Move(12);
			Move(1);
			Move(0);
			Move(10);
			Move(11);
			Move(4);
			Move(14);
			Move(15);
			Move(6);
			her.On = 6;
			break;
		}
		break;
	case 3:

	case 4:
		switch (OveredBtn) {
		case 0:
			Move(11);
			Move(10);
			Move(0);
			her.On = 0;
			break;
		case 1:
			Move(11);
			Move(10);
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			Move(11);
			Move(10);
			Move(0);
			Move(1);
			Move(12);
			Move(2);
			her.On = 2;
			break;
		case 5:
			Move(13);
			Move(5);
			her.On = 5;
			break;
		case 6:
			Move(14);
			Move(15);
			Move(6);
			her.On = 6;
			break;
		}
		break;
	case 5:
		switch (OveredBtn) {
		case 0:
			Move(13);
			Move(4);
			Move(11);
			Move(10);
			Move(0);
			her.On = 0;
			break;
		case 1:
			Move(13);
			Move(4);
			Move(11);
			Move(10);
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			Move(13);
			Move(4);
			Move(11);
			Move(10);
			Move(0);
			Move(1);
			Move(12);
			Move(2);
			her.On = 2;
			break;
		case 4:
			Move(13);
			Move(4);
			her.On = 5;
			break;
		case 6:
			Move(13);
			Move(4);
			Move(14);
			Move(15);
			Move(6);
			her.On = 6;
			break;
		}
		break;
	case 6:
		switch (OveredBtn) {
		case 0:
			Move(15);
			Move(14);
			Move(4);
			Move(11);
			Move(10);
			Move(0);
			her.On = 0;
			break;
		case 1:
			Move(15);
			Move(14);
			Move(4);
			Move(11);
			Move(10);
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			Move(15);
			Move(14);
			Move(4);
			Move(11);
			Move(10);
			Move(0);
			Move(1);
			Move(12);
			Move(2);
			her.On = 2;
			break;
		case 4:
			Move(15);
			Move(14);
			Move(4);
			her.On = 5;
			break;
		case 5:
			Move(15);
			Move(14);
			Move(4);
			Move(13);
			Move(5);
			her.On = 6;
			break;
		}
		break;
	}
	Fade(init.GraMap, init.GraCity);
	fun.FStat = fun.F_CITY;
	BtnSwitch = Sw_CITY;
	InitSys();
	ResetCity();
}

void SYSTEM::InitSys() {

	OveredBtn = -1;
	MInput1F = -1;
	MInput = -1;
	for (int i = 0; i < 64; i++) {
		GoodsOn[i] = FALSE;
		BtnX[i] = -1;
		BtnY[i] = -1;
	}

}

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
		ResetCity();
		ResetButton();
		DrawWindow(520, 140, 5, 16);
		BuyData();
		break;
	case 1:
		BtnSwitch = Sw_SALE;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		break;
	case 5:
		BtnSwitch = Sw_EXIT;
		ResetCity();
		break;
	}
}

void SYSTEM::CityData() {
	int x = 1500;
	int y = 140;
	DrawStringToHandle(x + 100, y, "〜ロイア〜", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 60, "Feature", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 100, "Population", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 140, "Development", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 180, "Economy", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 220, "Technology", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 260, "Industry", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(x, y + 300, "Infrastructure", GetColor(0, 0, 0), init.FontHandle);

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

	DrawStringToHandle(BtnX[ID], BtnY[ID], Goods[ID].Name, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d", Goods[ID].Price);
	DrawStringToHandle(BtnX[ID] + 200, BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
}

//Goods.Nameは品目の名前

void SYSTEM::BuyBtnOver(int i) {

	if (i == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		BuyData();
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 0, 0), init.FontHandle);
	}
	else if (BtnOn[i] == TRUE) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		BuyData();
		DrawStringToHandle(BtnX[i], BtnY[i], Goods[i].Name, GetColor(255, 0, 0), init.FontHandle);
	}
}

void SYSTEM::BuyBtnOut(int OveredBtn) {

	if (OveredBtn == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		BuyData();
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 255, 255), init.FontHandle);
	}
	else if (BtnOn[OveredBtn] == TRUE) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		BuyData();
		DrawStringToHandle(BtnX[OveredBtn], BtnY[OveredBtn], Goods[OveredBtn].Name, GetColor(0, 0, 0), init.FontHandle);
	}
}

void SYSTEM::BuyBtnSys(int OveredBtn) {

	if (OveredBtn == 63) {
		BtnSwitch = Sw_CITY;
		ResetCity();
		ButtonNumber = 6;
	}
	else if (OveredBtn != -1) {
		BtnSwitch = Sw_BUY2;
		ResetCity();
		BuySys(OveredBtn);
	}
}
/*	Goods[0].SetGoods(0, (char*)"石炭", 60);
	Goods[1].SetGoods(1, (char*)"鉱石", 80);
	Goods[2].SetGoods(2, (char*)"レアメタル", 100);
	Goods[3].SetGoods(3, (char*)"食料", 100);
	Goods[4].SetGoods(4, (char*)"木材", 100);
	Goods[5].SetGoods(5, (char*)"石油", 100);
	Goods[6].SetGoods(6, (char*)"金属", 100);
	Goods[7].SetGoods(7, (char*)"缶詰", 100);
	Goods[8].SetGoods(8, (char*)"銃火器", 100);
	Goods[9].SetGoods(9, (char*)"紙", 100);
	Goods[10].SetGoods(10, (char*)"書籍", 100);
	Goods[11].SetGoods(11, (char*)"東洋贅沢品", 100);
	Goods[12].SetGoods(12, (char*)"西洋贅沢品", 100);
	Goods[13].SetGoods(13, (char*)"農業贅沢品", 100);*/
void SYSTEM::BuyData() {

	int X = 560;
	int Y = 160;

	DrawStringToHandle(X, Y, "名前", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 200, Y, "値段", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 200 + 160, Y, "売量", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 200 + 160 * 2, Y, "需要", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 200 + 160 * 3, Y, "供給", GetColor(0, 0, 0), init.FontHandle);

	switch (her.On) {
	case 0:
		BuySort(0);
		BuySort(3);
		BuySort(6);
		BuySort(7);
		BuySort(8);
		BuySort(12);
	}
}

void SYSTEM::BuySys(int ID) {

	int SlotNumber;
	bool LEnd = FALSE;

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

	DrawStringToHandle(MWX + 64, MWY + 64, "いくつ購入しますか？", GetColor(255, 255, 255), init.FontHandle);
	printfDx("SlotNumber=%d\n", SlotNumber);

	BoughtNumber = KeyInputNumber(MWX + 64, MWY + 96, 9999, 0, FALSE);
	her.CargoPrice[SlotNumber] += Goods[ID].Price * BoughtNumber;
	BoughtPrice = Goods[ID].Price * BoughtNumber;

	printfDx("Price=%d\n", Goods[ID].Price);
	printfDx("BoughtNumber=%d\n", BoughtNumber);
	printfDx("BoughtPrice=%d\n", BoughtPrice);
	printfDx("CargoPrice=%d\n", her.CargoPrice[SlotNumber]);

	if (BoughtPrice > her.Money) {
		ResetCity();
		DrawStringToHandle(MWX + 64, MWY + 64, "所持金が足りません", GetColor(255, 255, 255), init.FontHandle);
		while (1) {
			MInput1F = MInput;
			MInput = GetMouseInput();
			if (CheckHitKey(KEY_INPUT_NUMPADENTER) == 0) {
				if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
					while (1) {
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
	else if (BoughtNumber + her.CargoWeight > her.MaxWeight) {
		ResetCity();
		DrawStringToHandle(MWX + 64, MWY + 64, "重量オーバーです", GetColor(255, 255, 255), init.FontHandle);
		while (1) {
			MInput1F = MInput;
			MInput = GetMouseInput();
			if (CheckHitKey(KEY_INPUT_NUMPADENTER) == 0) {
				if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
					while (1) {
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
	else if (BoughtNumber != 0)
	{
		her.Cargo[SlotNumber] += BoughtNumber;
		her.Money -= BoughtPrice;
		her.CargoWeight += BoughtNumber;
		her.HiddenID[SlotNumber] = ID;

		if (her.Cargo[SlotNumber] != 0) {
			ResetCity();
			DrawStringToHandle(MWX + 64, MWY + 64, "購入しました", GetColor(255, 255, 255), init.FontHandle);
			while (1) {
				MInput1F = MInput;
				MInput = GetMouseInput();
				if (CheckHitKey(KEY_INPUT_NUMPADENTER) == 0) {
					if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
						while (1) {
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
		BuyData();
		OveredBtn = -1;
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

	switch (OveredBtn) {
	case 63:
		BtnSwitch = Sw_CITY;
		ResetCity();
		ButtonNumber = 6;
		break;
	case 1:
		break;
	}
}

void SYSTEM::SaleData() {

	char Temp[32];
	int X = 560;
	int Y = 160;

	DrawStringToHandle(X, Y, "名前", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 190, Y, "一個当買値", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 210 + 110, Y, "売値", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 210 + 110 * 2, Y, "数量", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 210 + 110 * 3, Y, "受入量", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 210 + 110 * 4, Y, "需要", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(X + 210 + 110 * 5, Y, "供給", GetColor(0, 0, 0), init.FontHandle);

	for (int i = 1; i < 8; i++) {
		BtnX[i] = 580;
		BtnY[i] = 200 + i * 42;
	}

	for (int i = 0; i < 8; i++) {
		if (her.Cargo[i] != 0) {
			DrawStringToHandle(BtnX[i + 1], BtnY[i + 1], Goods[her.HiddenID[i]].Name, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.Cargo[i]);
			DrawStringToHandle(BtnX[i + 1] + 200, BtnY[i + 1], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.CargoPrice[i] / her.Cargo[i]);
			DrawStringToHandle(BtnX[i + 1] + 600, BtnY[i + 1], Temp, GetColor(0, 0, 0), init.FontHandle);
		}
		else
			break;
	}
}


void SYSTEM::InvestBtnOver(int i) {

	switch (i) {
	case 0:
		ResetCity();
		BtnSwitch = Sw_INVEST;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		BuyData();
		DrawStringToHandle(BtnX[0], BtnY[0], "戻る", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::InvestBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		ResetCity();
		BtnSwitch = Sw_INVEST;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		BuyData();
		DrawStringToHandle(BtnX[0], BtnY[0], "戻る", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::InvestBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
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
	case 0:
		ResetCity();
		BtnSwitch = Sw_MANAGE;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		BuyData();
		DrawStringToHandle(BtnX[0], BtnY[0], "戻る", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::ManageBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		ResetCity();
		BtnSwitch = Sw_MANAGE;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		BuyData();
		DrawStringToHandle(BtnX[0], BtnY[0], "戻る", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::ManageBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
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

	switch (i) {
	case 0:
		ResetCity();
		BtnSwitch = Sw_TALK;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		BuyData();
		DrawStringToHandle(BtnX[0], BtnY[0], "戻る", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::TalkBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		ResetCity();
		BtnSwitch = Sw_TALK;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		BuyData();
		DrawStringToHandle(BtnX[0], BtnY[0], "戻る", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		break;
	}
}

void SYSTEM::TalkBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		BtnSwitch = Sw_CITY;
		ResetCity();
		break;
	case 1:
		break;
	}
}

void SYSTEM::TalkData() {

}

void SYSTEM::ExitBtnOver(int i) {

	switch (i) {
	case 0:
		ResetCity();
		DrawStringToHandle(BtnX[0], BtnY[0], "はい", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		ResetCity();
		DrawStringToHandle(BtnX[1], BtnY[1], "いいえ", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::ExitBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		ResetCity();
		DrawStringToHandle(BtnX[0], BtnY[0], "はい", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 1:
		ResetCity();
		DrawStringToHandle(BtnX[1], BtnY[1], "いいえ", GetColor(255, 255, 255), init.FontHandle);
		break;
	}
}

void SYSTEM::ExitBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		fun.FStat = fun.F_MAIN;
		BtnSwitch = Sw_MMAP;
		Fade(init.GraCity, init.GraMap);
		ResetMap();
		SpawnHer();
		break;
	case 1:
		BtnSwitch = Sw_CITY;
		ResetCity();
		break;
	}
}


//最大都市	640, 560
//西の都市1 255, 590
//西の都市2 185, 370
//西の島	230, 890
//北東都市	780, 340
//北の都市	620, 160
//東の都市	1080, 420
//東の島	1720, 260
//南東の島1	1700, 750
//南東の島2	1440, 880