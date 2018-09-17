#pragma once

class BUTTON {
	struct BtnS {
		int BtnX, BtnY, BtnW, BtnH;
	};
	struct BtnS BtnN[4];
	int GraBtn;
public:
	void DrawButton();
	void ButtonOver();
};