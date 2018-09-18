#include "DxLib.h"
#include "class.h"

MWINDOW mw;
INIT init;
BUTTON btn;
int FontHandle;



void FUN::main() {
	//解像度取得
	init.WinX = GetSystemMetrics(SM_CXSCREEN);
	init.WinY = GetSystemMetrics(SM_CYSCREEN);

	//解像度セット
	SetGraphMode(init.WinX, init.WinY, 32, 60);

	//マウス
	SetMouseDispFlag(TRUE);

	init.SetFont();
	init.LoadGra();
	init.ResetTitle();

	btn.ButtonOver();
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
	GraT = LoadGraph("Resource/BG_Title.jpg");
	GraMW = LoadGraph("Resource/MW_1.png");
	GraBtn = LoadGraph("Resource/T_Btn1.png");
}

//ボタン
void BUTTON::DrawButton() {

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
}

void BUTTON::ButtonOver() {

	while (1) {
		while (MOver == FALSE) {
			GetMousePoint(&MouseX, &MouseY);
			for (int i = 0; i < 4; i++) {
				if ((MouseX >= BtnX[i] && MouseX <= BtnX[i] + BtnW[i]) && (MouseY >= BtnY[i] && MouseY <= BtnY[i] + BtnH[i])) {
					switch(i) {
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
					MOver = TRUE;
					OveredBtn = i;
					printfDx("OverTrue & %d \n", OveredBtn);
					break;
				}
			}
		WaitTimer(16);
		}
		
		while (MOver == TRUE) {
			GetMousePoint(&MouseX, &MouseY);
			MInput1F = MInput;
			MInput = GetMouseInput();
			if (!(MInput & MOUSE_INPUT_LEFT) && (MInput1F & MOUSE_INPUT_LEFT) == 1) {
				if (OveredBtn == 3) {
					mw.DrawWindow();
					QuitWindow();
				}
				printfDx("MOUSE LEFT ON");
				break;
			}
			if (!((MouseX >= BtnX[OveredBtn] && MouseX <= BtnX[OveredBtn] + BtnW[OveredBtn]) && (MouseY >= BtnY[OveredBtn] && MouseY <= BtnY[OveredBtn] + BtnH[OveredBtn]))) {
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
				MOver = FALSE;
				printfDx("OutTrue & %d \n", OveredBtn);
				break;
			}
		WaitTimer(16);
		}
	WaitTimer(16);
	}
}

void MWINDOW::DrawWindow() {
	MWX = 480;
	MWY = 800;
	DrawGraph(MWX, MWY, init.GraMW, TRUE);
}

void BUTTON::QuitWindow() {

	MOver = FALSE;
	BtnX[4] = mw.MWX + 280;
	BtnY[4] = mw.MWY + 140;
	BtnW[4] = 90;
	BtnH[4] = 42;
	BtnX[5] = mw.MWX + 640;
	BtnY[5] = mw.MWY + 140;
	BtnW[5] = 90;
	BtnH[5] = 42;

	DrawStringToHandle(mw.MWX + 64, mw.MWY + 64, "終了しますか？", GetColor(255, 255, 255), FontHandle);
	DrawStringToHandle(BtnX[4], BtnY[4], "はい", GetColor(255, 255, 255), FontHandle);
	DrawStringToHandle(BtnX[5], BtnY[5], "いいえ", GetColor(255, 255, 255), FontHandle);

	while (1) {
		while (MOver == FALSE) {
			GetMousePoint(&MouseX, &MouseY);
			for (int i = 4; i < 6; i++) {
				if ((MouseX >= BtnX[i] && MouseX <= BtnX[i] + BtnW[i]) && (MouseY >= BtnY[i] && MouseY <= BtnY[i] + BtnH[i])) {
					switch (i) {
					case 4:
						DrawStringToHandle(BtnX[4], BtnY[4], "はい", GetColor(255, 0, 0), FontHandle);
						break;
					case 5:
						DrawStringToHandle(BtnX[5], BtnY[5], "いいえ", GetColor(255, 0, 0), FontHandle);
						break;
					}
					MOver = TRUE;
					OveredBtn = i;
					printfDx("OverTrue & %d \n", OveredBtn);
					break;
				}
			}
		WaitTimer(16);
		}

		while (MOver == TRUE) {
			GetMousePoint(&MouseX, &MouseY);
			MInput1F = MInput;
			MInput = GetMouseInput();
			if (!(MInput & MOUSE_INPUT_LEFT) && (MInput1F & MOUSE_INPUT_LEFT) == 1) {
				if (OveredBtn == 4) {
					DxLib_End();
				}
				if (OveredBtn == 5) {
					init.ResetTitle();
					return;
				}
				printfDx("MOUSE LEFT ON");
				break;
			}
			if (!((MouseX >= BtnX[OveredBtn] && MouseX <= BtnX[OveredBtn] + BtnW[OveredBtn]) && (MouseY >= BtnY[OveredBtn] && MouseY <= BtnY[OveredBtn] + BtnH[OveredBtn]))) {
				switch (OveredBtn) {
				case 4:
					DrawStringToHandle(BtnX[4], BtnY[4], "はい", GetColor(0, 0, 0), FontHandle);
					break;
				case 5:
					DrawStringToHandle(BtnX[5], BtnY[5], "いいえ", GetColor(0, 0, 0), FontHandle);
					break;
				}
				MOver = FALSE;
				printfDx("OutTrue & %d \n", OveredBtn);
				break;
			}
		WaitTimer(16);
		}
	WaitTimer(16);
	}
}
void INIT::ResetTitle() {
	DrawExtendGraph(0, 0, WinX, WinY, GraT, TRUE);
	btn.DrawButton();
}


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
