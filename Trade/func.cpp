#include "DxLib.h"
#include "class.h"

//ƒ{ƒ^ƒ“
void BUTTON::DrawButton() {

}

void BUTTON::ButtonOver() {
	int MouseX, MouseY;

	GraBtn = LoadGraph("Resouce/T_Btn1.png");

	DrawGraph(870, 800, GraBtn, TRUE);
	while (CheckHitKeyAll() == 0) {
		while (CheckHitKeyAll() == 0) {
			GetMousePoint(&MouseX, &MouseY);
			if (MouseX >= 870 && MouseX <= 870 + 180) {
				if (MouseY >= 800 && MouseY <= 800 + 42) {
					GraphFilter(GraBtn, DX_GRAPH_FILTER_INVERT);
					DrawGraph(870, 800, GraBtn, TRUE);
					break;
				}
			}
			WaitTimer(100);
		}
		while (CheckHitKeyAll() == 0) {
			GetMousePoint(&MouseX, &MouseY);
			if (MouseX >= 870 && MouseX <= 870 + 180) {
				if (MouseY >= 800 && MouseY <= 800 + 42) {
				}
				else {
					GraphFilter(GraBtn, DX_GRAPH_FILTER_INVERT);
					DrawGraph(870, 800, GraBtn, TRUE);
					break;
				}
			}
			else {
				GraphFilter(GraBtn, DX_GRAPH_FILTER_INVERT);
				DrawGraph(870, 800, GraBtn, TRUE);
				break;
			}
			WaitTimer(100);
		}
	}
}