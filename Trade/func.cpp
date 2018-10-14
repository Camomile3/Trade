#include "DxLib.h"
#include "class.h"
#include "datas.h"
#include "event.h"
#include <fstream>
#include <direct.h>


INIT init;
FUN fun;
SYSTEM sys;
HEROINE her;

void FUN::main() {

	//システムロード
	_mkdir("Save");
	std::ifstream ifs("Save/sys.txt");
	if (!ifs) {
		std::ofstream ofs("Save/sys.txt");
	}

	//初期化
	ifs >> sys.VolumeBGM;
	ifs >> sys.VolumeSE;
	sys.LoopMusic("Title");
	init.SetFont();
	init.LoadGra();
	sys.ResetTitle();
	init.Cargo();
	Goods->InitGoods();
	City->InitCity();
	init.InitMarket();
	Trans->InitTrans();
	init.InitBuilding();

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

	//メインループ

	while (CheckHitKey(KEY_INPUT_DELETE) == 0 && (CheckHitKey(KEY_INPUT_LALT) == 0 || CheckHitKey(KEY_INPUT_F4) == 0)) {
		sys.ButtonOver();
		sys.ButtonSys();
		sys.DragSys();
		sys.DaySys();
		WaitTimer(16);
		if (ProcessMessage() == -1) break;                 //エラーが起きたら終了
	}

}

//フォントセット
void INIT::SetFont() {
	LPCSTR font_path = "Resource/font/JKG-L_3.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) == 0) {
		MessageBox(NULL, "LoadingFontERROR", "", MB_OK);
	}

	FontHandle = CreateFontToHandle("JKゴシックL", sys.MultiResoIntX(24), 0, DX_FONTTYPE_ANTIALIASING_8X8);
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

void INIT::LoadSE() {

	SHandle = 0;
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

void SYSTEM::ResetBtnOn() {

	for (int i = 0; i < 64; i++) {
		sys.BtnOn[i] = FALSE;
	}
}

void SYSTEM::SetSingleBtn(const char* a) {

	BtnX[63] = MWX + 640;
	BtnY[63] = MWY + 140;
	BtnW[63] = 90;
	BtnH[63] = 42;

	MultiResoBtn(63);

	if (OveredBtn != 63)
		DrawStringToHandle(BtnX[63], BtnY[63], a, GetColor(255, 255, 255), init.FontHandle);

	BtnOn[63] = TRUE;
}

void SYSTEM::SetTwoBtn(const char* a, const char* b) {

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

	TempChar[62] = a;
	TempChar[63] = b;

	if (OveredBtn != 62)
		DrawStringToHandle(BtnX[62], BtnY[62], a, GetColor(255, 255, 255), init.FontHandle);
	if (OveredBtn != 63)
		DrawStringToHandle(BtnX[63], BtnY[63], b, GetColor(255, 255, 255), init.FontHandle);

	BtnOn[62] = TRUE;
	BtnOn[63] = TRUE;
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

	sprintf_s(Temp, 64, "Resource/BGM/%s.mp3", string);
	PlayMusic(Temp, DX_PLAYTYPE_LOOP);
	VolumeMulti = GetVolumeMulti(string);
	SetVolumeMusic((int)(VolumeBGM * VolumeMulti));

}

double SYSTEM::GetVolumeMulti(const char* string) {

	if (!strcmp(string, "Title"))
		return 1;

	else if (!strcmp(string, "Field"))
		return 0.9;

	else if (!strcmp(string, "City1"))
		return 0.60;
	else
		return 1;
}

void SYSTEM::SetSEVolume() {

	ChangeVolumeSoundMem((int)(VolumeSE * VolumeMultiSE), init.SHandle);
}

void SYSTEM::MultiResoBtn(int i) {

		BtnX[i] = (int)(BtnX[i] * (init.WinX / 1920.0));
		BtnY[i] = (int)(BtnY[i] * (init.WinY / 1080.0));
		BtnW[i] = (int)(BtnW[i] * (init.WinX / 1920.0));
		BtnH[i] = (int)(BtnH[i] * (init.WinY / 1080.0));
		BtnCx[i] = (int)(BtnCx[i] * (init.WinX / 1920.0));
		BtnCy[i] = (int)(BtnCy[i] * (init.WinY / 1080.0));
}

void SYSTEM::MultiResoValue(int i) {

	TempValueX[i] = (int)(TempValueX[i] * (init.WinX / 1920.0));
	TempValueY[i] = (int)(TempValueY[i] * (init.WinY / 1080.0));
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

//ボタンを追加するとき追加

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
				case Sw_INVESTT:
				case Sw_INVESTB:
				case Sw_INVESTI:
				case Sw_INVESTBUYB:
				case Sw_INVESTRENTB:
					InvestBtnOver(i);
					break;
				case Sw_MANAGE:
				case Sw_MANAGEO:
				case Sw_MANAGEW:
				case Sw_MANAGEWIN:
				case Sw_MANAGEWOUT:
				case Sw_MANAGEF:
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
			case Sw_INVESTT:
			case Sw_INVESTB:
			case Sw_INVESTI:
			case Sw_INVESTBUYB:
			case Sw_INVESTRENTB:
				InvestBtnOut(OveredBtn);
				break;
			case Sw_MANAGE:
			case Sw_MANAGEO:
			case Sw_MANAGEW:
			case Sw_MANAGEWIN:
			case Sw_MANAGEWOUT:
			case Sw_MANAGEF:
				ManageBtnOut(OveredBtn);
				break;
			case Sw_TALK2:
				TalkBtnOut(OveredBtn);
				break;
			case Sw_EXIT:
				ExitBtnOut(OveredBtn);
				break;	
			}
			if (DebugMode == TRUE) {
				printfDx("OutTrue & %d \n", OveredBtn);
				printfDx("PressedBtn=%d\n", PressedBtn);
			}
			OveredBtn = -1;
			MOver = FALSE;
			return;
		}
	}
}

void SYSTEM::ButtonSys() {

	MInput1F = MInput;
	MInput = GetMouseInput();
	KeyInput1F = KeyInput;
	KeyInput = CheckHitKeyAll();

	if (!(MInput & MOUSE_INPUT_LEFT) && (MInput1F & MOUSE_INPUT_LEFT) == 1 || CheckHitKey(KEY_INPUT_ESCAPE) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1 || CheckHitKey(KEY_INPUT_NUMPADENTER) == 1) {
		if ( (KeyInput == 1 && KeyInput1F == 0) || !(MInput & MOUSE_INPUT_LEFT) && (MInput1F & MOUSE_INPUT_LEFT) == 1) {
			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
				OveredBtn = 63;
			}
			else if (CheckHitKey(KEY_INPUT_RETURN) == 1 || CheckHitKey(KEY_INPUT_NUMPADENTER) == 1)
				OveredBtn = 62;
			else if (OveredBtn == -1)
				return;
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
				InvestBtnSys(OveredBtn);
				break;
			case Sw_INVESTT:
				InvestBtnSysT(OveredBtn);
				break;
			case Sw_INVESTB:
			case Sw_INVESTBUYB:
			case Sw_INVESTRENTB:
				InvestBtnSysB(OveredBtn);
				break;
			case Sw_INVESTI:
				InvestBtnSysI(OveredBtn);
				break;
			case Sw_MANAGE:
				ManageBtnSys(OveredBtn);
				break;
			case Sw_MANAGEO:
				ManageBtnSysO(OveredBtn);
				break;
			case Sw_MANAGEW:
				ManageBtnSysW(OveredBtn);
				break;
			case Sw_MANAGEWIN:
				ManageWareInSys(OveredBtn);
				break;
			case Sw_MANAGEWOUT:
				break;
			case Sw_MANAGEF:
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
			if (DebugMode == TRUE) {
				printfDx("MOUSE LEFT ON %d \n", OveredBtn);
			}
			return;
		}
	}
}

void SYSTEM::DragSys() {

	switch (BtnSwitch) {
	case Sw_OPTION:

		std::ofstream ofs("Save/sys.txt");

		if ((OveredBtn == 60) || OveredBtn == 61) {
			while ((MInput & MOUSE_INPUT_LEFT) == 1) {
				MInput = GetMouseInput();
				GetMousePoint(&MouseX, &MouseY);

				if (MultiResoIntX(800) <= BtnX[OveredBtn] && BtnX[OveredBtn] <= MultiResoIntX(800 + 512) && DragStopper == FALSE) {
					if (MultiResoIntX(800) <= MouseX - (BtnW[OveredBtn] / 2) && MouseX - (BtnW[OveredBtn] / 2) <= MultiResoIntX(800 + 512)) {
						BtnX[OveredBtn] = MouseX - (BtnW[OveredBtn] / 2);
					}
				}
				
				VolumeBGM = (BtnX[60] - MultiResoIntX(800)) / 2;
				SetVolumeMusic((int)(VolumeBGM * VolumeMulti));

				VolumeSE = (BtnX[61] - MultiResoIntX(800)) / 2;
				SetSEVolume();

				//初期化
				switch (fun.FStat) {
				case fun.F_TITLE:
					ResetTitle();
					DrawButton(OveredBtn);
					break;
				case fun.F_MAIN:
					ResetMap();
					SpawnHer();
					break;
				}

				DrawMessageWindow();
				DrawWindow(520, 140, 5, 16);
				DrawOptionString();
				DrawExtendGraph(BtnX[60], BtnY[60], BtnX[60] + BtnW[60], BtnY[60] + BtnH[60], init.GraBtn4, TRUE);
				DrawExtendGraph(BtnX[61], BtnY[61], BtnX[61] + BtnW[61], BtnY[61] + BtnH[61], init.GraBtn4, TRUE);
				WaitTimer(16);
				if (ProcessMessage() == -1) break;
			}
		}
		ofs << VolumeBGM << std::endl;
		ofs << VolumeSE << std::endl;
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

char* SYSTEM::AddCommaN(int Value) {

	if (Value >= 1000) {
		sprintf_s(CommedValue, 64, "%3d,%03d", Value / 1000, Value - (Value / 1000) * 1000);
	}
	else
		sprintf_s(CommedValue, 64, "%6d", Value);

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
		if (ProcessMessage() == -1) break;
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

void SYSTEM::SearchBuildingEmpty(int ID) {

	for (int i = 0; i < 99; i++) {
		if (HerBuilding[her.On][ID][i].Number == 0) {
			BuildingSlot = i;
			break;
		}
	}
}

void SYSTEM::SearchCheapestBuilding(int ID) {

	for (int i = 0; i < 99; i++) {
		if (HerBuilding[her.On][ID][i].Number != 0 && ( (HerBuilding[her.On][ID][CheapestBuildingID].Price <= HerBuilding[her.On][ID][i].Price || i == 0) ) ) {

			CheapestBuildingID = i;
		}
	}
}

int SYSTEM::GetCheapest() {

	return CheapestBuildingID;
}

int SYSTEM::CalcSellBuilding(int ID) {

	for (int i = 0; i < 99; i++) {
		SearchCheapestBuilding(ID);
		TempPrice += HerBuilding[her.On][ID][CheapestBuildingID].Price;

	}
	return (int)TempPrice;
}

int SYSTEM::CountBuilding(int ID) {

	for (int i = 0; i < 99; i++) {
		if (HerBuilding[her.On][ID][i].Number != 0) {
			BuildingCount++;
		}
	}
	return BuildingCount;
}



void BUILDING::Reset(int ID) {

	HerBuilding[her.On][ID][sys.GetCheapest()].Price = 0;
	HerBuilding[her.On][ID][sys.GetCheapest()].Maint = 0;
	HerBuilding[her.On][ID][sys.GetCheapest()].Number = 0;
	HerBuilding[her.On][ID][sys.GetCheapest()].Rent = 0;
	HerBuilding[her.On][ID][sys.GetCheapest()].RentNumber = 0;
}