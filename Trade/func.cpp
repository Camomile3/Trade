#include "DxLib.h"
#include "class.h"

//ƒ{ƒ^ƒ“

void BUTTON::DrawButton() {

	GraBtn = LoadGraph("Resouce/T_Btn1.png");

	for (int i = 0; i < 4; i++) {
		BtnN[i].BtnX = 200 * i + 580;
		BtnN[i].BtnY = 800;
		BtnN[i].BtnW = 180;
		BtnN[i].BtnH = 42;

		DrawGraph(BtnN[i].BtnX, BtnN[i].BtnY, GraBtn, TRUE);
	};

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
					GraphFilter(GraBtn, DX_GRAPH_FILTER_INVERT);
					DrawGraph(BtnN[i].BtnX, BtnN[i].BtnY, GraBtn, TRUE);
					MOver = TRUE;
					OveredBtn = i;
					printfDx("OverTrue & %d \n", OveredBtn);
					break;
				}
			}
		}
		WaitTimer(16);

		while (MOver == TRUE) {
			GetMousePoint(&MouseX, &MouseY);
			printfDx("MOverMTRUE");
			if (!((MouseX >= BtnN[OveredBtn].BtnX && MouseX <= BtnN[OveredBtn].BtnX + BtnN[OveredBtn].BtnW) && (MouseY >= BtnN[OveredBtn].BtnY && MouseY <= BtnN[OveredBtn].BtnY + BtnN[OveredBtn].BtnH))) {
				GraphFilter(GraBtn, DX_GRAPH_FILTER_INVERT);
				DrawGraph(BtnN[OveredBtn].BtnX, BtnN[OveredBtn].BtnY, GraBtn, TRUE);
				MOver = FALSE;
				printfDx("OutTrue & %d \n", OveredBtn);
				break;
			}
			WaitTimer(16);
		}WaitTimer(16);
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
