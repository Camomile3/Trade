#include "DxLib.h"
#include "class.h"

int FontHandle;

//フォントセット
void INITIALIZATION::SetFont() {
	LPCSTR font_path = "Resource/font/JKG-L_3.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) == 0) {
		MessageBox(NULL, "LoadingFontERROR", "", MB_OK);
	}

	FontHandle = CreateFontToHandle("JKゴシックL", 24, 0, DX_FONTTYPE_ANTIALIASING_8X8);
	if (FontHandle == 0) {
		MessageBox(NULL, "CreateFontToHandleERROR", "", MB_OK);
	}

}

//ボタン

void BUTTON::DrawButton() {

	GraBtn = LoadGraph("Resource/T_Btn1.png");

	for (int i = 0; i < 4; i++) {
		BtnN[i].BtnX = 200 * i + 580;
		BtnN[i].BtnY = 860;
		BtnN[i].BtnW = 180;
		BtnN[i].BtnH = 42;

		DrawGraph(BtnN[i].BtnX, BtnN[i].BtnY, GraBtn, TRUE);
	};
	DrawStringToHandle(BtnN[0].BtnX + 36, BtnN[0].BtnY + 8, "NewGame", GetColor(0, 0, 0), FontHandle);
	DrawStringToHandle(BtnN[1].BtnX + 34, BtnN[1].BtnY + 8, "LoadGame", GetColor(0, 0, 0), FontHandle);
	DrawStringToHandle(BtnN[2].BtnX + 54, BtnN[2].BtnY + 8, "Option", GetColor(0, 0, 0), FontHandle);
	DrawStringToHandle(BtnN[3].BtnX + 36, BtnN[3].BtnY + 8, "QuitGame", GetColor(0, 0, 0), FontHandle);

}

void BUTTON::ButtonOver() {
	int MouseX, MouseY;
	int OveredBtn;
	bool MOver = FALSE;

	while (CheckHitKeyAll() == 0) {

		while (MOver == FALSE) {
			GetMousePoint(&MouseX, &MouseY);
			for (int i = 0; i < 4; i++) {
				if ((MouseX >= BtnN[i].BtnX && MouseX <= BtnN[i].BtnX + BtnN[i].BtnW) && (MouseY >= BtnN[i].BtnY && MouseY <= BtnN[i].BtnY + BtnN[i].BtnH)) {
					switch(i) {
						case 0:
							DrawStringToHandle(BtnN[0].BtnX + 36, BtnN[0].BtnY + 8, "NewGame", GetColor(255, 0, 0), FontHandle);
							break;
						case 1:
							DrawStringToHandle(BtnN[1].BtnX + 34, BtnN[1].BtnY + 8, "LoadGame", GetColor(255, 0, 0), FontHandle);
							break;
						case 2:
							DrawStringToHandle(BtnN[2].BtnX + 54, BtnN[2].BtnY + 8, "Option", GetColor(255, 0, 0), FontHandle);
							break;
						case 3:
							DrawStringToHandle(BtnN[3].BtnX + 36, BtnN[3].BtnY + 8, "QuitGame", GetColor(255, 0, 0), FontHandle);
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
			printfDx("MOverTRUE");
			if (!((MouseX >= BtnN[OveredBtn].BtnX && MouseX <= BtnN[OveredBtn].BtnX + BtnN[OveredBtn].BtnW) && (MouseY >= BtnN[OveredBtn].BtnY && MouseY <= BtnN[OveredBtn].BtnY + BtnN[OveredBtn].BtnH))) {
				switch (OveredBtn) {
				case 0:
					DrawStringToHandle(BtnN[0].BtnX + 36, BtnN[0].BtnY + 8, "NewGame", GetColor(0, 0, 0), FontHandle);
					break;
				case 1:
					DrawStringToHandle(BtnN[1].BtnX + 34, BtnN[1].BtnY + 8, "LoadGame", GetColor(0, 0, 0), FontHandle);
					break;
				case 2:
					DrawStringToHandle(BtnN[2].BtnX + 54, BtnN[2].BtnY + 8, "Option", GetColor(0, 0, 0), FontHandle);
					break;
				case 3:
					DrawStringToHandle(BtnN[3].BtnX + 36, BtnN[3].BtnY + 8, "QuitGame", GetColor(0, 0, 0), FontHandle);
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
