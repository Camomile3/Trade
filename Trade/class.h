#pragma once
#include <string>

class INIT {
public:
	int WinX;
	int WinY;
	int GraT;
	int GraBtn;
	int GraMW;
	int GraMap;
	int GraHer;
	void SetFont();
	void LoadGra();
	void ResetTitle();
};

class FUN {
public:
	void main();
	enum {
		S_TITLE,
		S_MAIN,
		S_ENDING,
		S_END,
	};

	int FStat = S_TITLE;
};

class SYSTEM {
	int BtnX[16], BtnY[16], BtnW[16], BtnH[16];
	int MouseX, MouseY;
	int MInput,MInput1F;
	int OveredBtn;
	int ButtonNumber;
	int MWX,MWY;
	bool MOver = FALSE;
	enum {
		S_TITLE,
		S_NEW,
		S_LOAD,
		S_OPTION,
		S_QUIT,
	};
	int BtnSwitch = S_TITLE;
public:
	void DrawTitleButton();
	void DrawButton();
	void TitleBtnOver(int);
	void TitleBtnOverOut(int);
	void ButtonSys();
	void TitleBtnSys(int);
	void DrawWindow();
	void QuitBtnOver(int);
	void QuitBtnOut(int);
	void QuitBtnSys(int);
	void SetMapBtn();
	void MapBtnOver();
	void MapBtnSys();
	void DebugBox();
};

class MMAP {
public:
	void DrawMap();

};