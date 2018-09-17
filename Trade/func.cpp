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
	bool LoopEnd = FALSE;

	while (CheckHitKeyAll() == 0) {
		while (CheckHitKeyAll() == 0) {
			GetMousePoint(&MouseX, &MouseY);
			for (int i = 0; i < 4; i++) {
				if (MouseX >= BtnN[i].BtnX && MouseX <= BtnN[i].BtnX + BtnN[i].BtnW) {
					if (MouseY >= BtnN[i].BtnY && MouseY <= BtnN[i].BtnY + BtnN[i].BtnH) {
						GraphFilter(GraBtn, DX_GRAPH_FILTER_INVERT);
						DrawGraph(BtnN[i].BtnX, BtnN[i].BtnY, GraBtn, TRUE);
						LoopEnd = TRUE;
						break;
					}
				}
			}
			if (LoopEnd) { break; }
			WaitTimer(100);
		}

		while (CheckHitKeyAll() == 0) {
			GetMousePoint(&MouseX, &MouseY);
			for (int i = 0; i < 4; i++) {
				if (MouseX >= BtnN[i].BtnX && MouseX <= BtnN[i].BtnX + BtnN[i].BtnW) {
					if (MouseY >= BtnN[i].BtnY && MouseY <= BtnN[i].BtnY + BtnN[i].BtnH) {
					}
					else {
						GraphFilter(GraBtn, DX_GRAPH_FILTER_INVERT);
						DrawGraph(BtnN[i].BtnX, BtnN[i].BtnY, GraBtn, TRUE);
						LoopEnd = TRUE;
						break;
					}
				}
				else {
					GraphFilter(GraBtn, DX_GRAPH_FILTER_INVERT);
					DrawGraph(BtnN[i].BtnX, BtnN[i].BtnY, GraBtn, TRUE);
					LoopEnd = TRUE;
					break;
				}
			}
			if (LoopEnd) { break; }
			WaitTimer(100);
		}
	}
}