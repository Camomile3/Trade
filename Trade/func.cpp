#include "DxLib.h"
#include "class.h"

INIT init;
FUN fun;
SYSTEM sys;
MMAP map;

int FontHandle;



void FUN::main() {
	//‰ğ‘œ“xæ“¾
	init.WinX = GetSystemMetrics(SM_CXSCREEN);
	init.WinY = GetSystemMetrics(SM_CYSCREEN);

	//‰ğ‘œ“xƒZƒbƒg
	SetGraphMode(init.WinX, init.WinY, 32, 60);

	//ƒ}ƒEƒX
	SetMouseDispFlag(TRUE);

	//‰Šú‰»
	init.SetFont();
	init.LoadGra();

	//ƒƒCƒ“ƒ‹[ƒv
	while (1) {
		switch (fun.FStat) {
		case S_TITLE:
			init.ResetTitle();
			while (1) {
				sys.DrawButton();
				sys.ButtonSys();
				if (fun.FStat != S_TITLE)
					break;
				WaitTimer(16);
			}
			break;
		case S_MAIN:
			map.DrawMap();
			sys.SetMapBtn();
			sys.DebugBox();
			while (1) {
				sys.MapBtnOver();
				sys.MapBtnSys();
				if (fun.FStat != S_MAIN)
					break;
			}
			break;
		}
		WaitTimer(16);
		if (ProcessMessage() == -1) break;                 //ƒGƒ‰[‚ª‹N‚«‚½‚çI—¹

	}

}

//ƒtƒHƒ“ƒgƒZƒbƒg
void INIT::SetFont() {
	LPCSTR font_path = "Resource/font/JKG-L_3.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) == 0) {
		MessageBox(NULL, "LoadingFontERROR", "", MB_OK);
	}

	FontHandle = CreateFontToHandle("JKƒSƒVƒbƒNL", 24, 0, DX_FONTTYPE_ANTIALIASING_8X8);
	if (FontHandle == 0) {
		MessageBox(NULL, "CreateFontToHandleERROR", "", MB_OK);
	}
}

void INIT::LoadGra() {
	GraT = LoadGraph("Resource/BG_Title.jpg");
	GraMW = LoadGraph("Resource/MW_1.png");
	GraBtn = LoadGraph("Resource/T_Btn1.png");
	GraMap = LoadGraph("Resource/Map.jpg");
	GraHer = LoadGraph("Resource/Heroine.png");
}

void INIT::ResetTitle() {
	DrawExtendGraph(0, 0, WinX, WinY, GraT, TRUE);
	sys.DrawTitleButton();
}

//ƒ{ƒ^ƒ“
void SYSTEM::DrawTitleButton() {

	for (int i = 0; i < 4; i++) {
		BtnX[i] = 200 * i + 580;
		BtnY[i] = 860;
		BtnW[i] = 180;
		BtnH[i] = 42;

		DrawGraph(580, 860, init.GraBtn, TRUE);
		DrawGraph(BtnX[i], BtnY[i], init.GraBtn, TRUE);
	};
	DrawStringToHandle(BtnX[0] + 36, BtnY[0] + 8, "NewGame", GetColor(0, 0, 0), FontHandle);
	DrawStringToHandle(BtnX[1] + 34, BtnY[1] + 8, "LoadGame", GetColor(0, 0, 0), FontHandle);
	DrawStringToHandle(BtnX[2] + 54, BtnY[2] + 8, "Option", GetColor(0, 0, 0), FontHandle);
	DrawStringToHandle(BtnX[3] + 36, BtnY[3] + 8, "QuitGame", GetColor(0, 0, 0), FontHandle);
	ButtonNumber = 4;
}



void SYSTEM::DrawButton() {

	GetMousePoint(&MouseX, &MouseY);
	if (MOver == FALSE) {
		for (int i = 0; i < ButtonNumber; i++) {
			if ((MouseX >= BtnX[i] && MouseX <= BtnX[i] + BtnW[i]) && (MouseY >= BtnY[i] && MouseY <= BtnY[i] + BtnH[i])) {
				switch (BtnSwitch) {
				case S_TITLE:
					TitleBtnOver(i);
					break;
				case S_QUIT:
					QuitBtnOver(i);
					break;
				}
				MOver = TRUE;
				OveredBtn = i;
				printfDx("OverTrue & %d \n", OveredBtn);
				break;
			}
		}
	}

	if (MOver == TRUE) {
		if (!((MouseX >= BtnX[OveredBtn] && MouseX <= BtnX[OveredBtn] + BtnW[OveredBtn]) && (MouseY >= BtnY[OveredBtn] && MouseY <= BtnY[OveredBtn] + BtnH[OveredBtn]))) {
			switch (BtnSwitch) {
			case S_TITLE:
				TitleBtnOverOut(OveredBtn);
				break;
			case S_QUIT:
				QuitBtnOut(OveredBtn);
				break;
			}
			MOver = FALSE;
			printfDx("OutTrue & %d \n", OveredBtn);
			return;
		}
	}
}

void SYSTEM::TitleBtnOver(int i) {
	switch (i) {
	case 0:
		DrawStringToHandle(BtnX[0] + 36, BtnY[0] + 8, "NewGame", GetColor(255, 0, 0), FontHandle);
		break;
	case 1:
		DrawStringToHandle(BtnX[1] + 34, BtnY[1] + 8, "LoadGame", GetColor(255, 0, 0), FontHandle);
		break;
	case 2:
		DrawStringToHandle(BtnX[2] + 54, BtnY[2] + 8, "Option", GetColor(255, 0, 0), FontHandle);
		break;
	case 3:
		DrawStringToHandle(BtnX[3] + 36, BtnY[3] + 8, "QuitGame", GetColor(255, 0, 0), FontHandle);
		break;
	}
}

void SYSTEM::TitleBtnOverOut(int OveredBtn) {
	switch (OveredBtn) {
	case 0:
		DrawStringToHandle(BtnX[0] + 36, BtnY[0] + 8, "NewGame", GetColor(0, 0, 0), FontHandle);
		break;
	case 1:
		DrawStringToHandle(BtnX[1] + 34, BtnY[1] + 8, "LoadGame", GetColor(0, 0, 0), FontHandle);
		break;
	case 2:
		DrawStringToHandle(BtnX[2] + 54, BtnY[2] + 8, "Option", GetColor(0, 0, 0), FontHandle);
		break;
	case 3:
		DrawStringToHandle(BtnX[3] + 36, BtnY[3] + 8, "QuitGame", GetColor(0, 0, 0), FontHandle);
		break;
	}
}

void SYSTEM::ButtonSys() {

	MInput1F = MInput;
	MInput = GetMouseInput();
	if (!(MInput & MOUSE_INPUT_LEFT) && (MInput1F & MOUSE_INPUT_LEFT) == 1) {
		switch (BtnSwitch) {
		case S_TITLE:
			TitleBtnSys(OveredBtn);
			break;
		case S_QUIT:
			QuitBtnSys(OveredBtn);
			break;
		}
		printfDx("MOUSE LEFT ON");
		return;
	}
}

void SYSTEM::TitleBtnSys(int OveredBtn) {
	switch (OveredBtn) {
	case 0:
		fun.FStat = fun.S_MAIN;
		return;
	case 3:
		BtnSwitch = S_QUIT;
		DrawWindow();
		break;
	}
}

void SYSTEM::DrawWindow() {
	MWX = 480;
	MWY = 800;
	DrawGraph(MWX, MWY, init.GraMW, TRUE);

	sys.MOver = FALSE;
	BtnX[0] = MWX + 280;
	BtnY[0] = MWY + 140;
	BtnW[0] = 90;
	BtnH[0] = 42;
	BtnX[1] = MWX + 640;
	BtnY[1] = MWY + 140;
	BtnW[1] = 90;
	BtnH[1] = 42;

	DrawStringToHandle(MWX + 64, MWY + 64, "I—¹‚µ‚Ü‚·‚©H", GetColor(255, 255, 255), FontHandle);
	DrawStringToHandle(BtnX[0], BtnY[0], "‚Í‚¢", GetColor(255, 255, 255), FontHandle);
	DrawStringToHandle(BtnX[1], BtnY[1], "‚¢‚¢‚¦", GetColor(255, 255, 255), FontHandle);
	ButtonNumber = 2;

}

void SYSTEM::QuitBtnOver(int i) {

	switch (i) {
	case 0:
		DrawStringToHandle(BtnX[0], BtnY[0], "‚Í‚¢", GetColor(255, 0, 0), FontHandle);
		break;
	case 1:
		DrawStringToHandle(BtnX[1], BtnY[1], "‚¢‚¢‚¦", GetColor(255, 0, 0), FontHandle);
		break;
	}
}

void SYSTEM::QuitBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		DrawStringToHandle(BtnX[0], BtnY[0], "‚Í‚¢", GetColor(255, 255, 255), FontHandle);
		break;
	case 1:
		DrawStringToHandle(BtnX[1], BtnY[1], "‚¢‚¢‚¦", GetColor(255, 255, 255), FontHandle);
		break;
	}
}

void SYSTEM::QuitBtnSys(int OveredBtn) {

	switch(OveredBtn){
	case 0:
		DxLib_End();
	case 1:
		BtnSwitch = S_TITLE;
		init.ResetTitle();
		return;
	}
}

void MMAP::DrawMap() {
	SetDrawScreen(DX_SCREEN_BACK);
	DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraMap, TRUE);
	ScreenFlip();
	SetDrawScreen(DX_SCREEN_FRONT);
	int x = 640;
	int y = 560;
	DrawExtendGraph(x, y, x+32, y+64, init.GraHer, FALSE);
}

//Å‘å“ss	640, 560
//¼‚Ì“ss1 255, 590
//¼‚Ì“ss2 185, 370
//¼‚Ì“‡	230, 890
//–k“Œ“ss	780, 340
//–k‚Ì“ss	620, 160
//“Œ‚Ì“ss	1080, 420
//“Œ‚Ì“‡	1720, 260
//“ì“Œ‚Ì“‡1	1700, 750
//“ì“Œ‚Ì“‡2	1440, 880
void SYSTEM::SetMapBtn() {
	int x = 64;
	int y = 48;
	BtnX[0] = 595;
	BtnY[0] = 580;
	BtnW[0] = 128;
	BtnH[0] = 80;
	BtnX[1] = 235;
	BtnY[1] = 610;
	BtnW[1] = x;
	BtnH[1] = y;
	BtnX[2] = 170;
	BtnY[2] = 410;
	BtnW[2] = x;
	BtnH[2] = y;
	BtnX[3] = 210;
	BtnY[3] = 920;
	BtnW[3] = x;
	BtnH[3] = y;
	BtnX[4] = 765;
	BtnY[4] = 380;
	BtnW[4] = x;
	BtnH[4] = y;
	BtnX[5] = 600;
	BtnY[5] = 190;
	BtnW[5] = x;
	BtnH[5] = y;
	BtnX[6] = 1065;
	BtnY[6] = 460;
	BtnW[6] = x;
	BtnH[6] = y;
	BtnX[7] = 1710;
	BtnY[7] = 300;
	BtnW[7] = x;
	BtnH[7] = y;
	BtnX[8] = 1690;
	BtnY[8] = 790;
	BtnW[8] = x;
	BtnH[8] = y;
	BtnX[9] = 1430;
	BtnY[9] = 920;
	BtnW[9] = x;
	BtnH[9] = y;

}

void SYSTEM::MapBtnOver() {

	GetMousePoint(&MouseX, &MouseY);
	if (MOver == FALSE) {
		for (int i = 0; i < 10; i++) {
			if ((MouseX >= BtnX[i] && MouseX <= BtnX[i] + BtnW[i]) && (MouseY >= BtnY[i] && MouseY <= BtnY[i] + BtnH[i])) {
				MOver = TRUE;
				OveredBtn = i;
				printfDx("OverTrue & %d \n", OveredBtn);
				break;
			}
		}
	}

	if (MOver == TRUE) {
		if (!((MouseX >= BtnX[OveredBtn] && MouseX <= BtnX[OveredBtn] + BtnW[OveredBtn]) && (MouseY >= BtnY[OveredBtn] && MouseY <= BtnY[OveredBtn] + BtnH[OveredBtn]))) {
			switch (OveredBtn) {
			case 0:
				//Œø‰Ê‰¹‚à‚µ‚­‚ÍƒJ[ƒ\ƒ‹‚ª”½‰‚·‚éˆ—‚ğ“ü‚ê‚é—\’è
				break;
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			}
			MOver = FALSE;
			printfDx("OutTrue & %d \n", OveredBtn);
			return;
		}
	}
}

void SYSTEM::MapBtnSys(){

	MInput1F = MInput;
	MInput = GetMouseInput();
	if (!(MInput & MOUSE_INPUT_LEFT) && (MInput1F & MOUSE_INPUT_LEFT) == 1) {
		switch (OveredBtn) {
		case 0:
			printfDx("%d\n", OveredBtn);
			DxLib_End();
			break;
		case 1:
			printfDx("%d\n", OveredBtn);
			break;
		case 2:
			printfDx("%d\n", OveredBtn);
			break;
		case 3:
			printfDx("%d\n", OveredBtn);
			break;
		case 4:
			printfDx("%d\n", OveredBtn);
			break;
		case 5:
			printfDx("%d\n", OveredBtn);
			break;
		case 6:
			printfDx("%d\n", OveredBtn);
			break;
		case 7:
			printfDx("%d\n", OveredBtn);
			break;
		case 8:
			printfDx("%d\n", OveredBtn);
			break;
		case 9:
			printfDx("%d\n", OveredBtn);
			break;
			printfDx("MOUSE LEFT ON");
			return;
		}
	}
}

void SYSTEM::DebugBox() {
	for (int i = 0; i < 10; i++) {
		DrawBox(BtnX[i], BtnY[i], BtnX[i] + BtnW[i], BtnY[i] + BtnH[i], GetColor(0, 255, 0), FALSE);
	}
}

//Å‘å“ss	640, 560
//¼‚Ì“ss1 255, 590
//¼‚Ì“ss2 185, 370
//¼‚Ì“‡	230, 890
//–k“Œ“ss	780, 340
//–k‚Ì“ss	620, 160
//“Œ‚Ì“ss	1080, 420
//“Œ‚Ì“‡	1720, 260
//“ì“Œ‚Ì“‡1	1700, 750
//“ì“Œ‚Ì“‡2	1440, 880


/*	while (CheckHitKeyAll() == 0) {
		while (MOver[i] == FALSE) {
			GetMousePoint(&MouseX, &MouseY);
			for (int i = 0; i < 4; i++) {
				if (MouseX >= BtnN[i].BtnX && MouseX <= BtnN[i].BtnX + BtnN[i].BtnW) {
					if (MouseY >= BtnN[i].BtnY && MouseY <= BtnN[i].BtnY + BtnN[i].BtnH) {
						GraphFilter(GraBtn, DX_GRAPH_FILTER_INVERT);
						DrawGraph(BtnN[i].BtnX, BtnN[i].BtnY, GraBtn, TRUE);
						LoopEnd = TRUE;
						MOver[i] = TRUE;
						printfDx("OverTrue");
						break;
					}
				}
			}
			if (LoopEnd) { break; }
			WaitTimer(100);
		}
		LoopEnd = FALSE;

		while (MOver[0] == TRUE) {
			GetMousePoint(&MouseX, &MouseY);
			for (int i = 0; i < 4; i++) {
				if (MouseX >= BtnN[i].BtnX && MouseX <= BtnN[i].BtnX + BtnN[i].BtnW) {
					if (MouseY >= BtnN[i].BtnY && MouseY <= BtnN[i].BtnY + BtnN[i].BtnH) {
					}
					else {
						printfDx("%dOut", i);
						GraphFilter(GraBtn, DX_GRAPH_FILTER_INVERT);
						DrawGraph(BtnN[i].BtnX, BtnN[i].BtnY, GraBtn, TRUE);
						LoopEnd = TRUE;
						MOver[i] = FALSE;
						break;
					}
				}
				else {
					GraphFilter(GraBtn, DX_GRAPH_FILTER_INVERT);
					printfDx("%dOut", i);
					DrawGraph(BtnN[i].BtnX, BtnN[i].BtnY, GraBtn, TRUE);
					LoopEnd = TRUE;
					MOver[i] = FALSE;
					break;
				}
			}
			if (LoopEnd) { break; }
			WaitTimer(100);
		}
		LoopEnd = FALSE;
	}*/
