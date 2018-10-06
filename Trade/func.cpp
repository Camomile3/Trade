#include "DxLib.h"
#include "class.h"
#include "datas.h"
#include "event.h"

#define M_PI	3.14159265358979323846
#define DEG_TO_RAD(deg) (((deg)/360)*2*M_PI)
#define RAD_TO_DEG(rad) (((rad)/2/M_PI)*360)

INIT init;
FUN fun;
SYSTEM sys;
HEROINE her;

void FUN::main() {
	//âëúìxéÊìæ
	init.WinX = GetSystemMetrics(SM_CXSCREEN);
	init.WinY = GetSystemMetrics(SM_CYSCREEN);

	//âëúìxÉZÉbÉg
	SetGraphMode(init.WinX, init.WinY, 32, 60);

	//É}ÉEÉX
	SetMouseDispFlag(TRUE);

	//èâä˙âª
	sys.Volume = 100;
	sys.LoopMusic("Title");
	init.SetFont();
	init.LoadGra();
	sys.ResetTitle();
	init.Cargo();
	Goods->InitGoods();
	City->InitCity();
	init.InitMarket();
	trans->InitTrans();

	if (sys.DebugMode == TRUE) {
		her.Money = 10000000;
		her.CargoWeight = 0;
		her.Transport[0] = 1;
		for (int i = 1; i < 8; i++)
			her.Transport[i] = 0;
		her.HaveShip = TRUE;
		her.MaxWeight = 900000000;
		her.CargoWeight = 500000000;
		her.ShipMaxWeight = 800000000;
		her.ShipWeight = 700000000;
		her.MoveSpeed = 30;
		her.ShipMoveSpeed = 50;

		her.Year = 3;
		her.Month = 9;
		her.Day = 25;

		sys.EventFlag[3] = TRUE;
	}

	//ÉÅÉCÉìÉãÅ[Év

	while (CheckHitKey(KEY_INPUT_DELETE) == 0 && (CheckHitKey(KEY_INPUT_LALT) == 0 || CheckHitKey(KEY_INPUT_F4) == 0)) {
		sys.ButtonOver();
		sys.ButtonSys();
		sys.DragSys();
		sys.DaySys();
		WaitTimer(16);
		if (ProcessMessage() == -1) break;                 //ÉGÉâÅ[Ç™ãNÇ´ÇΩÇÁèIóπ
	}

}

//ÉtÉHÉìÉgÉZÉbÉg
void INIT::SetFont() {
	LPCSTR font_path = "Resource/font/JKG-L_3.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) == 0) {
		MessageBox(NULL, "LoadingFontERROR", "", MB_OK);
	}

	FontHandle = CreateFontToHandle("JKÉSÉVÉbÉNL", sys.MultiResoIntX(24), 0, DX_FONTTYPE_ANTIALIASING_8X8);
	if (FontHandle == 0) {
		MessageBox(NULL, "CreateFontToHandleERROR", "", MB_OK);
	}
}

void INIT::LoadGra() {
	GraT = LoadGraph("Resource/BG/Title.png");
	GraMW = LoadGraph("Resource/Graphic/MW_1.png");
	GraBtn = LoadGraph("Resource/Graphic/Btn1.png");
	GraBtn2 = LoadGraph("Resource/Graphic/Btn2.png");
	GraBtn3 = LoadGraph("Resource/Graphic/Btn3.png");
	GraBtn4 = LoadGraph("Resource/Graphic/Btn4.png");
	GraMap = LoadGraph("Resource/Graphic/Map.jpg");
	GraCity = LoadGraph("Resource/BG/City.png");
	GraHer = LoadGraph("Resource/Heroine.png");
	GraCalender = LoadGraph("Resource/Graphic/I_Calender.png");
	GraGold = LoadGraph("Resource/Graphic/I_Gold.png");
	GraIdea = LoadGraph("Resource/Graphic/I_Idea.png");
	GraFactory = LoadGraph("Resource/Graphic/I_Factory.png");
	char str[32];
	for (int i = 0; i < 12; i++) {
		sprintf_s(str, 32, "Resource/Graphic/Carriage%d.png", i);
		GraCarriage[i] = LoadGraph(str);
		sprintf_s(str, 32, "Resource/Graphic/Ship%d.png",i);
		GraShip[i] = LoadGraph(str);
	}
}

void SYSTEM::DaySys() {

	if (her.Day > 31 && (her.Month == 1 || her.Month == 3 || her.Month == 5 || her.Month == 7 || her.Month == 8 || her.Month == 10 || her.Month == 12 )) {
		her.Day = 1;
		her.Month++;
	}
	else if(her.Day > 30 && (her.Month == 4 || her.Month == 6 || her.Month == 9 || her.Month == 11)){
		her.Day = 1;
		her.Month++;
	}
	else if (her.Day > 28 && her.Month == 2) {
		her.Day = 1;
		her.Month++;
	}

	if (her.Month > 12) {
		her.Month = 1;
		her.Year++;
	}
}

void INIT::Cargo() {
	for (int i = 0; i < 8; i++) {
		her.HiddenID[i] = -1;
	}
}

void SYSTEM::ResetTitle() {

	switch (BtnSwitch) {
	case Sw_TITLE:
	case Sw_QUIT:
		ClearDrawScreen();
		DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraT, TRUE);
		DrawButton(OveredBtn);
		break;
	case Sw_SAVE:
	case Sw_LOAD:
	case Sw_OPTION:
		ClearDrawScreen();
		DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraT, TRUE);
		DrawButton(OveredBtn);
		if (BtnSwitch == Sw_OPTION)
			DrawOptionString();
		break;
	}
}

void SYSTEM::ResetBtnOn() {

	for (int i = 0; i < 64; i++) {
		sys.BtnOn[i] = FALSE;
	}
}

void SYSTEM::SetTwoBtn() {

	BtnX[62] = MWX + 280;
	BtnY[62] = MWY + 140;
	BtnW[62] = 90;
	BtnH[62] = 42;
	BtnX[63] = MWX + 640;
	BtnY[63] = MWY + 140;
	BtnW[63] = 90;
	BtnH[63] = 42;

	MultiResoBtn(62);
	MultiResoBtn(63);
}

void SYSTEM::SetFullBtn() {

	BtnX[58] = 0;
	BtnY[58] = 0;
	BtnW[58] = 1920;
	BtnH[58] = 1080;

	MultiResoBtn(58);
}

void SYSTEM::LoopMusic(const char* string) {

	TCHAR Temp[64];
	double x = 1;

	sprintf_s(Temp, 64, "Resource/BGM/%s.mp3", string);
	PlayMusic(Temp, DX_PLAYTYPE_LOOP);
	x = GetVolumeMulti(string);
	SetVolumeMusic((int)(Volume * x));

}

double SYSTEM::GetVolumeMulti(const char* string) {

	printfDx("%s\n", string);

	if (!strcmp(string, "Title"))
		return 1;

	else if (!strcmp(string, "Field"))
		return 0.9;

	else if (!strcmp(string, "City1"))
		return 0.60;
	else
		return 1;
}

void SYSTEM::MultiResoBtn(int i) {

		BtnX[i] = (int)(BtnX[i] * (init.WinX / 1920.0));
		BtnY[i] = (int)(BtnY[i] * (init.WinY / 1080.0));
		BtnW[i] = (int)(BtnW[i] * (init.WinX / 1920.0));
		BtnH[i] = (int)(BtnH[i] * (init.WinY / 1080.0));
		BtnCx[i] = (int)(BtnCx[i] * (init.WinX / 1920.0));
		BtnCy[i] = (int)(BtnCy[i] * (init.WinY / 1080.0));
}

int SYSTEM::MultiResoIntX(int x) {

	int y = (int)(x * (init.WinX / 1920.0));
	return y;
}

int SYSTEM::MultiResoIntY(int x) {

	int y = (int)(x * (init.WinY / 1080.0));
	return y;
}

SYSTEM::QuadS SYSTEM::MultiResoIntQuad(int a, int b, int c, int d) {

	Quad.a = (int)(a * (init.WinX / 1920.0));
	Quad.b = (int)(b * (init.WinY / 1080.0));
	Quad.c = (int)(c * (init.WinX / 1920.0));
	Quad.d = (int)(d * (init.WinY / 1080.0));

	return Quad;
}

//É{É^ÉìÇí«â¡Ç∑ÇÈÇ∆Ç´í«â¡

void SYSTEM::DrawButton(int OveredBtn) {

	int y = MultiResoIntY(8);

	switch (fun.FStat) {
	case fun.F_TITLE:
		for (int i = 0; i < 4; i++) {
			BtnX[i] = 200 * i + 580;
			BtnY[i] = 860;
			BtnW[i] = 180;
			BtnH[i] = 42;

			MultiResoBtn(i);
		}



		for (int i = 0; i < 4; i++) {
			DrawExtendGraph(BtnX[i], BtnY[i], BtnX[i] + BtnW[i], BtnY[i] + BtnH[i], init.GraBtn, TRUE);
		}

		if (OveredBtn != 0)
			DrawStringToHandle(BtnX[0] + MultiResoIntX(36), BtnY[0] + MultiResoIntY(8), "NewGame", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 1)
			DrawStringToHandle(BtnX[1] + MultiResoIntX(34), BtnY[1] + MultiResoIntY(8), "LoadGame", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 2)
			DrawStringToHandle(BtnX[2] + MultiResoIntX(54), BtnY[2] + MultiResoIntY(8), "Option", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 3)
			DrawStringToHandle(BtnX[3] + MultiResoIntX(36), BtnY[3] + MultiResoIntY(8), "QuitGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	case fun.F_MAIN:
		for (int i = 48; i < 9 + 48; i++) {
			BtnX[i] = 175 * (i - 48);
			BtnY[i] = 0;
			BtnW[i] = 175;
			BtnH[i] = 42;

			MultiResoBtn(i);
		}



		for (int i = 48; i < 9 + 48; i++) {
			DrawExtendGraph(BtnX[i], BtnY[i], BtnX[i] + MultiResoIntX(180), BtnY[i] + MultiResoIntY(42), init.GraBtn, TRUE);
		}

		if (OveredBtn != 48)
		DrawStringToHandle(BtnX[48] + MultiResoIntX(58), BtnY[48] + y, "Cargo", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 49)
		DrawStringToHandle(BtnX[49] + MultiResoIntX(34), BtnY[49] + y, "Transport", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 50)
		DrawStringToHandle(BtnX[50] + MultiResoIntX(36), BtnY[50] + y, "Financial", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 51)
		DrawStringToHandle(BtnX[51] + MultiResoIntX(58), BtnY[51] + y, "Quest", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 52)
		DrawStringToHandle(BtnX[52] + MultiResoIntX(54), BtnY[52] + y, "Prices", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 53)
		DrawStringToHandle(BtnX[53] + MultiResoIntX(36), BtnY[53] + y, "SaveGame", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 54)
		DrawStringToHandle(BtnX[54] + MultiResoIntX(36), BtnY[54] + y, "LoadGame", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 55)
		DrawStringToHandle(BtnX[55] + MultiResoIntX(54), BtnY[55] + y, "Option", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 56)
		DrawStringToHandle(BtnX[56] + MultiResoIntX(36), BtnY[56] + y, "QuitGame", GetColor(0, 0, 0), init.FontHandle);

		break;
	case fun.F_CITY:
		for (int i = 0; i < 6; i++) {
			BtnX[i] = 180;
			BtnY[i] = 160 + i * 38;
			BtnW[i] = 176;
			BtnH[i] = 38;

			MultiResoBtn(i);
		};



		if (OveredBtn != 0)
			DrawStringToHandle(BtnX[0] + MultiResoIntX(24), BtnY[0] + y, "Purchase", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 1)
			DrawStringToHandle(BtnX[1] + MultiResoIntX(24), BtnY[1] + y, "Sale", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 2)
			DrawStringToHandle(BtnX[2] + MultiResoIntX(24), BtnY[2] + y, "Invest", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 3)
			DrawStringToHandle(BtnX[3] + MultiResoIntX(24), BtnY[3] + y, "Manage", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 4)
			DrawStringToHandle(BtnX[4] + MultiResoIntX(24), BtnY[4] + y, "Talk", GetColor(0, 0, 0), init.FontHandle);
		if (OveredBtn != 5)
			DrawStringToHandle(BtnX[5] + MultiResoIntX(24), BtnY[5] + y, "Exit", GetColor(0, 0, 0), init.FontHandle);

		break;
	}
}

//ÉãÅ[Évì‡ÇÃèàóù
//É{É^Éìä÷êîÇí«â¡ÇµÇΩèÍçáâ∫ìÒÇ¬Ç…í«â¡
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
				case Sw_QUEST:
					QuestBtnOver(i);
					break;
				case Sw_PRICES:
					PricesBtnOver(i);
					break;
				case Sw_PRICES2:
					PricesBtnOver(i);
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
				case Sw_INVEST2:
				case Sw_INVEST3:
				case Sw_INVEST4:
					InvestBtnOver(i);
					break;
				case Sw_MANAGE:
					ManageBtnOver(i);
					break;
				case Sw_TALK2:
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
			case Sw_QUEST:
				QuestBtnOut(OveredBtn);
				break;
			case Sw_PRICES:
				PricesBtnOut(OveredBtn);
				break;
			case Sw_PRICES2:
				PricesBtnOut(OveredBtn);
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
			case Sw_INVEST2:
			case Sw_INVEST3:
			case Sw_INVEST4:
				InvestBtnOut(OveredBtn);
				break;
			case Sw_MANAGE:
				ManageBtnOut(OveredBtn);
				break;
			case Sw_TALK2:
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
	if (!(MInput & MOUSE_INPUT_LEFT) && (MInput1F & MOUSE_INPUT_LEFT) == 1 || CheckHitKey(KEY_INPUT_ESCAPE) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1 || CheckHitKey(KEY_INPUT_NUMPADENTER) == 1) {
		if (OveredBtn == -1)
			return;
		else if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			OveredBtn = 63;
		else if (CheckHitKey(KEY_INPUT_RETURN) == 1 || CheckHitKey(KEY_INPUT_NUMPADENTER) == 1)
			OveredBtn = 62;
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
		case Sw_QUEST:
			QuestBtnSys(OveredBtn);
			break;
		case Sw_PRICES:
			PricesBtnSys(OveredBtn);
			break;
		case Sw_PRICES2:
			PricesBtnSys(OveredBtn);
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
		case Sw_INVEST2:
		case Sw_INVEST3:
		case Sw_INVEST4:
			InvestBtnSys(OveredBtn);
			break;
		case Sw_MANAGE:
			ManageBtnSys(OveredBtn);
			break;
		case Sw_TALK:
			TalkBtnSys(OveredBtn);
			break;
		case Sw_TALK2:
			TalkBtnSys(OveredBtn);
			break;
		case Sw_EXIT:
			ExitBtnSys(OveredBtn);
			break;
		}
		if (DebugMode == TRUE)
			printfDx("MOUSE LEFT ON %d \n", OveredBtn);
		return;
	}
}

void SYSTEM::DragSys() {

	switch (BtnSwitch) {
	case Sw_OPTION:
		if ((OveredBtn == 16) || OveredBtn == 17) {
			while ((MInput & MOUSE_INPUT_LEFT) == 1) {
				MInput = GetMouseInput();
				GetMousePoint(&MouseX, &MouseY);

				BtnX[OveredBtn] = MouseX - (BtnW[OveredBtn] / 2);

				//èâä˙âª
				ResetTitle();
				DrawButton(OveredBtn);
				DrawMessageWindow();
				DrawWindow(520, 140, 5, 16);
				DrawOptionString();
				DrawExtendGraph(BtnX[16], BtnY[16], BtnX[16] + BtnW[16], BtnY[16] + BtnH[16], init.GraBtn4, TRUE);
				WaitTimer(16);
				if (ProcessMessage() == -1) break;
			}
		}
		break;
	}
}

void SYSTEM::DrawWindow(int X, int Y, int W, int H) {
	int i = 0;
	int n = 0;

	X = MultiResoIntX(X);
	Y = MultiResoIntY(Y);

	while (1) {
		DrawExtendGraph(X + n * MultiResoIntX(176), Y + i * MultiResoIntY(38), X + n * MultiResoIntX(176) + MultiResoIntX(180), Y + i * MultiResoIntY(38) + MultiResoIntY(44), init.GraBtn2, TRUE);
		i++;
		if (i == H) {
			n++;
			i = 0;
		}
		if (n >= W)
			break;
	}
}

void SYSTEM::DrawValue() {
	int ValueX[7], ValueY[7], ValueW[7], ValueH[7];

	for (int i = 0; i < 7; i++) {
		ValueX[i] = MultiResoIntX(175 * i);
		ValueY[i] = MultiResoIntY(38);
		ValueW[i] = MultiResoIntX(180);
		ValueH[i] = MultiResoIntY(32);
		DrawExtendGraph(ValueX[i], ValueY[i], ValueX[i] + ValueW[i], ValueY[i] + ValueH[i], init.GraBtn3, TRUE);
	}
	TCHAR Temp[64];
	char* Temp2;
	char* Temp3;
	int a = 0;
	int x, y;
	x = 8;
	y = 42;

	MultiResoIntQuad(x, y, x + 24, y + 24);
	DrawExtendGraph(Quad.a, Quad.b, Quad.c, Quad.d, init.GraCalender, TRUE);

	sprintf_s(Temp, 32, "%2d/%d/%d", her.Year, her.Month, her.Day);
	DrawStringToHandle(MultiResoIntX(x + 28), MultiResoIntY(42), Temp, GetColor(0, 0, 0), init.FontHandle);

	MultiResoIntQuad(x + 128 + 32, 42, x + 128 + 32 + 24, 42 + 24);
	DrawExtendGraph(Quad.a, Quad.b, Quad.c, Quad.d, init.GraGold, TRUE);
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

	DrawStringToHandle(MultiResoIntX(x + 128 + 32 + 28), MultiResoIntY(42), Temp, GetColor(0, 0, 0), init.FontHandle);

	MultiResoIntQuad(x + 512 - 64 - 10, 32, x + 512 - 64 + 24, 42 + 24);
	DrawExtendGraph(Quad.a, Quad.b, Quad.c, Quad.d, init.GraCarriage[6], TRUE);
	Temp2 = AddComma(her.CargoWeight);
	Temp3 = AddComma(her.MaxWeight);
	//sprintf_s(Temp, 32, "%d/%d", her.CargoWeight, her.MaxWeight);

	DrawStringToHandle(MultiResoIntX(x + 512 - 128 + 28 - 5), MultiResoIntY(42), Temp2, GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x + 512 - 64 + 28 + 150 - 5), MultiResoIntY(42), "/", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x + 512 + 28 + 30 - 5), MultiResoIntY(42), Temp3, GetColor(0, 0, 0), init.FontHandle);

	MultiResoIntQuad(x + 512 + 270, 42, x + 512 + 24 + 280, 42 + 24);
	DrawExtendGraph(Quad.a, Quad.b, Quad.c, Quad.d, init.GraShip[6], TRUE);
	Temp2 = AddComma(her.ShipWeight);
	Temp3 = AddComma(her.ShipMaxWeight);
	DrawStringToHandle(MultiResoIntX(x + 512 + 28 + 200), MultiResoIntY(42), Temp2, GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x + 512 + 28 + 270 + 140), MultiResoIntY(42), "/", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x + 512 + 28 + 270 + 80), MultiResoIntY(42), Temp3, GetColor(0, 0, 0), init.FontHandle);

	her.WTech = 14;
	MultiResoIntQuad(x + 512 + 525 + 64, 42, x + 512 + 525 + 64 + 24, 42 + 24);
	DrawExtendGraph(Quad.a, Quad.b, Quad.c, Quad.d, init.GraIdea, TRUE);
	sprintf_s(Temp, 32, "%d", her.WTech);
	DrawStringToHandle(MultiResoIntX(x + 512 + 64 + 525 + 28), MultiResoIntY(42), Temp, GetColor(0, 0, 0), init.FontHandle);

	her.WIndustry = 12;
	MultiResoIntQuad(x + 512 + 123 + 525, 42, x + 512 + 123 + 525 + 24, 42 + 24);
	DrawExtendGraph(Quad.a, Quad.b, Quad.c, Quad.d, init.GraFactory, TRUE);
	sprintf_s(Temp, 32, "%d", her.WIndustry);
	DrawStringToHandle(MultiResoIntX(x + 512 + 123 + 525 + 28), MultiResoIntY(42), Temp, GetColor(0, 0, 0), init.FontHandle);
}



char* SYSTEM::AddComma(int Value) {

/*	if (Value >= 1000000000) {
		sprintf_s(CommedValue, 64, "%6d,%03d,%03d,%03d", Value / 1000000000, (Value - Value / 1000000000 * 1000000000) / 1000000, (Value - Value / 1000000 * 1000000) / 1000, Value - (Value / 1000) * 1000);
	}
	else 
*/	
	if (Value >= 1000000) {
		sprintf_s(CommedValue, 64, "%9d,%03d,%03d", Value / 1000000, (Value - Value / 1000000 * 1000000) / 1000, Value - (Value / 1000) * 1000);
	}
	else if (Value >= 1000) {
		sprintf_s(CommedValue, 64, "%13d,%03d", Value / 1000, Value - (Value / 1000) * 1000);
	}
	else
		sprintf_s(CommedValue, 64, "%16d", Value);

	return CommedValue;
}

void SYSTEM::WaitClick() {

	while (CheckHitKey(KEY_INPUT_DELETE) == 0 && (CheckHitKey(KEY_INPUT_LALT) == 0 || CheckHitKey(KEY_INPUT_F4) == 0)) {
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
					if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
						LEnd = TRUE;
					WaitTimer(16);
					if (LEnd) { break; }
				}
			}
		}
		WaitTimer(16);
		if (LEnd) {
			LEnd = FALSE;
			break;
		}
	}
}

void SYSTEM::WaitYesNo() {
	while (CheckHitKey(KEY_INPUT_DELETE) == 0) {
		sys.ButtonOver();
		sys.ButtonSys();
		WaitTimer(16);
		if (ProcessMessage() == -1) break;
	}
}

void SYSTEM::TitleBtnOver(int i) {
	switch (i) {
	case 0:
		ResetTitle();
		DrawStringToHandle(BtnX[0] + MultiResoIntX(36), BtnY[0] + MultiResoIntY(8), "NewGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		ResetTitle();
		DrawStringToHandle(BtnX[1] + MultiResoIntX(34), BtnY[1] + MultiResoIntY(8), "LoadGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 2:
		ResetTitle();
		DrawStringToHandle(BtnX[2] + MultiResoIntX(54), BtnY[2] + MultiResoIntY(8), "Option", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 3:
		ResetTitle();
		DrawStringToHandle(BtnX[3] + MultiResoIntX(36), BtnY[3] + MultiResoIntY(8), "QuitGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::TitleBtnOverOut(int OveredBtn) {

	int y = 8;

	switch (OveredBtn) {
	case 0:
		ResetTitle();
		DrawStringToHandle(BtnX[0] + MultiResoIntX(36), BtnY[0] + MultiResoIntY(y), "NewGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 1:
		ResetTitle();
		DrawStringToHandle(BtnX[1] + MultiResoIntX(34), BtnY[1] + MultiResoIntY(y), "LoadGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 2:
		ResetTitle();
		DrawStringToHandle(BtnX[2] + MultiResoIntX(54), BtnY[2] + MultiResoIntY(y), "Option", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 3:
		ResetTitle();
		DrawStringToHandle(BtnX[3] + MultiResoIntX(36), BtnY[3] + MultiResoIntY(y), "QuitGame", GetColor(0, 0, 0), init.FontHandle);
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
		DrawOptionString();
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
	case 62:
		QuitBtnReset();
		DrawStringToHandle(BtnX[62], BtnY[62], "ÇÕÇ¢", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 63:
		QuitBtnReset();
		DrawStringToHandle(BtnX[63], BtnY[63], "Ç¢Ç¢Ç¶", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::QuitBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 62:
		QuitBtnReset();
		DrawStringToHandle(BtnX[62], BtnY[62], "ÇÕÇ¢", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 63:
		QuitBtnReset();
		DrawStringToHandle(BtnX[63], BtnY[63], "Ç¢Ç¢Ç¶", GetColor(255, 255, 255), init.FontHandle);
		break;
	}
}

void SYSTEM::QuitBtnReset() {

	switch (fun.FStat) {
	case fun.F_TITLE:
		ResetTitle();
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
		case 62:
			DxLib_End();
		case 63:
			BtnSwitch = Sw_TITLE;
			ResetTitle();
			break;
		}
		break;
	case fun.F_MAIN:
		switch (OveredBtn) {
		case 62:
			DxLib_End();
		case 63:
			BtnSwitch = Sw_MMAP;
			ResetMap();
			SpawnHer();
			break;
		}
		break;
	}
}

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
			sprintf_s(Temp, 32, "%s", trans[i].Name);
			DrawStringToHandle(BtnX[i], BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.Transport[i]);
			DrawStringToHandle(BtnX[i] + MultiResoIntX(160), BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", trans[i].Capacity);
			DrawStringToHandle(BtnX[i] + MultiResoIntX(160 * 2), BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.Transport[i] * trans[i].Capacity);
			DrawStringToHandle(BtnX[i] + MultiResoIntX(160 * 3), BtnY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
			if (trans[i].Sea == FALSE)
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

	DrawStringToHandle(1350, 160, "ëπâvåvéZèë", GetColor(0, 0, 0), init.FontHandle);

	Temp[24] = "îÑè„çÇ";
	Temp[25] = "";
	Temp[26] = "îÑè„å¥âø";
	Temp[27] = "";
	Temp[28] = "";
	Temp[29] = "";
	Temp[30] = "îÃîÑîÔãyÇ—àÍî ä«óùîÔ";
	Temp[31] = "";
	Temp[32] = "";
	Temp[33] = "";
	Temp[34] = "ê≈à¯ëOìñä˙èÉóòâv";
	Temp[35] = "";
	Temp[36] = "ìñä˙èÉóòâv";

	Temp[37] = "";
	Temp[38] = "";
	Temp[39] = "";
	Temp[40] = "ä˙éÒè§ïiíIâµçÇ";
	Temp[41] = "ìñä˙è§ïiédì¸çÇ";
	Temp[42] = "ä˙ññè§ïiíIâµçÇ";
	Temp[43] = "";
	Temp[44] = "ããóø";
	Temp[45] = "éxï•â∆í¿";
	Temp[46] = "å∏âøèûãpîÔ";
	Temp[47] = "";
	Temp[48] = "ñ@êlê≈ìô";

	while (i <= 48) {

		DrawStringToHandle(MultiResoIntX(x * 128 + 1024), MultiResoIntY(y * 32 + 240), Temp[i], GetColor(0, 0, 0), init.FontHandle); y++;
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

void SYSTEM::OptionBtnOver(int i) {

	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (i) {
		case 63:
			ResetTitle();
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			DrawOptionString();
			OptionData();
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
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			DrawOptionString();
			OptionData();
			DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 0, 0), init.FontHandle);
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
		case 63:
			ResetTitle();
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			DrawOptionString();
			OptionData();
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
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			DrawOptionString();
			OptionData();
			DrawStringToHandle(BtnX[63], BtnY[63], "ï¬Ç∂ÇÈ", GetColor(255, 255, 255), init.FontHandle);
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

void SYSTEM::OptionData() {

	BtnX[16] = 700;
	BtnY[16] = 200;
	BtnW[16] = 16;
	BtnH[16] = 32;

	MultiResoBtn(16);

	DrawExtendGraph(BtnX[16], BtnY[16], BtnX[16] + BtnW[16], BtnY[16] + BtnH[16], init.GraBtn4, TRUE);
}

void SYSTEM::DrawOptionString() {

	DrawStringToHandle(MultiResoIntX(640), MultiResoIntY(200), "BGM", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(640), MultiResoIntY(280), "SE", GetColor(0, 0, 0), init.FontHandle);
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
	BtnSwitch = Sw_MMAP;
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


void SYSTEM::DebugBox() {

	for (int i = 0; i < ButtonNumber; i++) {
		DrawBox(BtnX[i], BtnY[i], BtnX[i] + BtnW[i], BtnY[i] + BtnH[i], GetColor(0, 255, 0), FALSE);
		DrawCircle(BtnCx[i], BtnCy[i], 2, GetColor(0, 255, 0), TRUE);
	}
}

void SYSTEM::Fade(int before, int after, const char* Music) {


	SetDrawScreen(DX_SCREEN_BACK);
	if (fun.FStat == fun.F_TITLE) {
		for (int i = 0; i < 320; i++) {
			if (i >= 0 && i < 128) {
				SetDrawBright(255 - (i * 2), 255 - (i * 2), 255 - (i * 2));
				DrawExtendGraph(0, 0, init.WinX, init.WinY, before, TRUE);
			}

			if (i == 128)
				LoopMusic(Music);
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
		for (int i = 0; i < 102; i++) {
			if (i >= 0 && i < 43) {
				SetDrawBright(255 - (i * 6), 255 - (i * 6), 255 - (i * 6));
				DrawExtendGraph(0, 0, init.WinX, init.WinY, before, TRUE);
			}

			if (i == 43)
				LoopMusic(Music);
			if (i >= 43 && i < 59)
				SetDrawBright(0, 0, 0);

			if (i >= 59 && i < 102) {
				SetDrawBright((i - 59) * 6, (i - 59) * 6, (i - 59) * 6);
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

	int MoveCount = 0;

	Angle = atan2(BtnCy[MoveTo] - her.Y, BtnCx[MoveTo] - her.X);

	while (!(((her.X > BtnCx[MoveTo] - 2) && (her.X <= BtnCx[MoveTo] + 2)) && ((her.Y > BtnCy[MoveTo] - 2) && (her.Y <= BtnCy[MoveTo] + 2)))) {

		her.X += 1 * cos(Angle);
		her.Y += 1 * sin(Angle);

		ResetMap();

		//DrawExtendGraph((int)her.X - 16, (int)her.Y - 64, (int)her.X + 16, (int)her.Y, init.GraHer, FALSE);

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
			if (her.HaveShip == FALSE)
				return;
			Move(20);
			her.OnShip = TRUE;
			Move(21);
			Move(22);
			her.OnShip = FALSE;
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
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
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
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(0);
			Move(20);
			her.OnShip = TRUE;
			Move(21);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
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
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(0);
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(0);
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(0);
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
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
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(30);
			her.OnShip = TRUE;
			Move(31);
			Move(35);
			Move(36);
			Move(37);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			Move(13);
			Move(4);
			her.On = 4;
			break;
		case 5:
			Move(13);
			Move(5);
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
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(30);
			her.OnShip = TRUE;
			Move(31);
			WarpHer(32);
			Move(33);
			Move(34);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(30);
			her.OnShip = TRUE;
			Move(31);
			WarpHer(32);
			Move(33);
			Move(34);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(30);
			her.OnShip = TRUE;
			Move(31);
			WarpHer(32);
			Move(33);
			Move(34);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 3:
		switch (OveredBtn) {
		case 0:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(21);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			her.On = 0;
			break;
		case 1:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(21);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(37);
			Move(36);
			Move(35);
			Move(31);
			Move(30);
			her.OnShip = FALSE;
			Move(2);
			her.On = 2;
			break;
		case 4:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(21);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			Move(10);
			Move(11);
			Move(4);
			her.On = 4;
			break;
		case 5:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(37);
			Move(36);
			Move(35);
			Move(31);
			Move(43);
			Move(42);
			Move(41);
			Move(40);
			her.OnShip = FALSE;
			Move(5);
			her.On = 5;
			break;
		case 6:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(25);
			Move(39);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			her.On = 6;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(25);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
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
			Move(13);
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(11);
			Move(10);
			Move(0);
			Move(20);
			her.OnShip = TRUE;
			Move(21);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
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
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(14);
			Move(15);
			Move(6);
			Move(38);
			her.OnShip = TRUE;
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(14);
			Move(15);
			Move(6);
			Move(38);
			her.OnShip = TRUE;
			Move(39);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(14);
			Move(15);
			Move(6);
			Move(38);
			her.OnShip = TRUE;
			Move(39);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
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
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(40);
			her.OnShip = TRUE;
			Move(41);
			Move(42);
			Move(43);
			Move(31);
			Move(35);
			Move(36);
			Move(37);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
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
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(40);
			her.OnShip = TRUE;
			Move(41);
			Move(42);
			Move(44);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(40);
			her.OnShip = TRUE;
			Move(41);
			Move(42);
			Move(44);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(40);
			her.OnShip = TRUE;
			Move(41);
			Move(42);
			Move(44);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
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
			Move(13);
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(38);
			her.OnShip = TRUE;
			Move(39);
			Move(25);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			Move(15);
			Move(14);
			Move(4);
			her.On = 4;
			break;
		case 5:
			Move(15);
			Move(14);
			Move(4);
			Move(13);
			Move(5);
			her.On = 5;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(38);
			her.OnShip = TRUE;
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(38);
			her.OnShip = TRUE;
			Move(39);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(38);
			her.OnShip = TRUE;
			Move(39);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 7:
		switch (OveredBtn) {
		case 0:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(25);
			Move(24);
			Move(23);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			her.On = 0;
			break;
		case 1:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(34);
			Move(33);
			Move(32);
			WarpHer(31);
			Move(30);
			her.OnShip = FALSE;
			Move(2);
			Move(12);
			Move(1);
			her.On = 1;
			break;
		case 2:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(34);
			Move(33);
			Move(32);
			WarpHer(31);
			Move(30);
			her.OnShip = FALSE;
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(34);
			Move(33);
			Move(45);
			WarpHer(35);
			Move(36);
			Move(37);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			Move(15);
			Move(14);
			Move(4);
			her.On = 4;
			break;
		case 5:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(44);
			Move(42);
			Move(41);
			Move(40);
			her.OnShip = FALSE;
			Move(5);
			her.On = 5;
			break;
		case 6:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			her.On = 6;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 8:
		switch (OveredBtn) {
		case 0:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(26);
			Move(24);
			Move(23);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			her.On = 0;
			break;
		case 1:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(24);
			Move(23);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(34);
			Move(33);
			Move(32);
			WarpHer(31);
			Move(30);
			her.OnShip = FALSE;
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(39);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			Move(15);
			Move(14);
			Move(4);
			her.On = 4;
			break;
		case 5:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(44);
			Move(42);
			Move(41);
			Move(40);
			her.OnShip = FALSE;
			Move(5);
			her.On = 5;
			break;
		case 6:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(39);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			her.On = 6;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(26);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 9:
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 9:
		switch (OveredBtn) {
		case 0:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(26);
			Move(24);
			Move(23);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			her.On = 0;
			break;
		case 1:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(24);
			Move(23);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(34);
			Move(33);
			Move(32);
			WarpHer(31);
			Move(30);
			her.OnShip = FALSE;
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(39);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			Move(15);
			Move(14);
			Move(4);
			her.On = 4;
			break;
		case 5:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(44);
			Move(42);
			Move(41);
			Move(40);
			her.OnShip = FALSE;
			Move(5);
			her.On = 5;
			break;
		case 6:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(39);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			her.On = 6;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(26);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			Move(16);
			Move(8);
			her.On = 8;
			break;
		}
		break;
	}
	SetHerPrices(OveredBtn);
	Fade(init.GraMap, init.GraCity, "City1");
	fun.FStat = fun.F_CITY;
	BtnSwitch = Sw_CITY;
	InitSys();
	ResetCity();
}

void SYSTEM::InitSys() {

	OveredBtn = -1;
	MInput1F = 0;
	MInput = 0;
	for (int i = 0; i < 64; i++) {
		GoodsOn[i] = FALSE;
		BtnX[i] = -1;
		BtnY[i] = -1;
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