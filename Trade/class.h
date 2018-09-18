#pragma once
#include <string>

class BUTTON {
	int BtnX[16], BtnY[16], BtnW[16], BtnH[16];
	int MouseX, MouseY;
	int MInput,MInput1F;
	int OveredBtn;
	bool MOver = FALSE;
public:
	void DrawButton();
	void ButtonOver();
	void QuitWindow();
};

class MWINDOW {
public:
	int MWX;
	int MWY;
	void DrawWindow();
};

class INIT {
public:
	int WinX;
	int WinY;
	int GraT;
	int GraBtn;
	int GraMW;
	void SetFont();
	void LoadGra();
	void ResetTitle();
};

class FUN {
public:
	void main();
};