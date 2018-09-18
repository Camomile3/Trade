#pragma once
#include <string>

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

class INITIALIZATION {
public:
	void SetFont();
};