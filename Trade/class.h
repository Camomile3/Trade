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
	int BtnX[32], BtnY[32], BtnW[32], BtnH[32], BtnCx[32], BtnCy[32];
	int MouseX, MouseY;
	int MInput,MInput1F;
	int OveredBtn;
	int ButtonNumber;
	int MWX,MWY;
	double Angle;
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
	//タイトル
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
	//メインマップ
	void Fade(int, int);
	void ResetMap();
	void SetMapBtn();
	void MapBtnOver();
	void MapBtnSys();
	void DebugBox();
	void DebugMap();
	void SpawnHer();
	void Move(int);
	void MoveRoute();
};

class MMAP {
public:
	void DrawMap();

};

class HEROINE {
public:
	double X, Y;
	int On;
};