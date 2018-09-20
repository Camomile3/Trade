#pragma once
#include <string>

class INIT {
public:
	int FontHandle;
	int WinX;
	int WinY;
	int GraT;
	int GraBtn;
	int GraBtn2;
	int GraMW;
	int GraMap;
	int GraCity;
	int GraHer;
	void SetFont();
	void LoadGra();
	void ResetTitle();
};

class FUN {
public:
	void main();
	enum {
		F_TITLE,
		F_MAIN,
		F_CITY,
		F_ENDING,
		F_END,
	};

	int FStat = F_TITLE;
};

class SYSTEM {
	int BtnX[32], BtnY[32], BtnW[32], BtnH[32], BtnCx[32], BtnCy[32];
	int MouseX, MouseY;
	int MInput,MInput1F;
	int OveredBtn = -1;
	int ButtonNumber;
	int MWX,MWY;
	double Angle;
	bool MOver = FALSE;
	enum {
		Sw_TITLE,
		Sw_NEW,
		Sw_SAVE,
		Sw_LOAD,
		Sw_OPTION,
		Sw_QUIT,
		Sw_MMAP,
		Sw_CARGO,
		Sw_TRANS,
		Sw_FINAN,
		//ここから街
		Sw_CITY,
		Sw_BUY,
		Sw_SALE,
		Sw_INVEST,
		Sw_MANAGE,
		Sw_TALK,
		Sw_EXIT,
	};
	int BtnSwitch = Sw_TITLE;
public:
	bool DebugMode = TRUE;
	//メインシステム
	void ButtonOver();
	void ButtonSys();
	void DrawMessageWindow();
	void DrawWindow(int, int, int, int);
	//タイトル
	void DrawButton();
	void TitleBtnOver(int);
	void TitleBtnOverOut(int);
	void TitleBtnSys(int);
	void QuitBtnOver(int);
	void QuitBtnOut(int);
	void QuitBtnSys(int);
	void QuitBtnReset();
	//メインマップ
	void Fade(int, int);
	void ResetMap();
	void InitMap();
	void SetMapBtn();
	void MapBtnOver(int);
	void MapBtnOut(int);
	void MapBtnSys(int);
	void CargoBtnOver(int);
	void CargoBtnOut(int);
	void CargoBtnSys(int);
	void CargoData();
	void TransBtnOver(int);
	void TransBtnOut(int);
	void TransBtnSys(int);
	void TransData();
	void FinanBtnOver(int);
	void FinanBtnOut(int);
	void FinanBtnSys(int);
	void FinanData();
	void SaveBtnOver(int);
	void SaveBtnOut(int);
	void SaveBtnSys(int);
	void SaveData();
	void LoadBtnOver(int);
	void LoadBtnOut(int);
	void LoadBtnSys(int);
	void LoadData();
	void OptionBtnOver(int);
	void OptionBtnOut(int);
	void OptionBtnSys(int);
	void OptionData();
	void DebugBox();
	void DebugMap();
	void SpawnHer();
	void Move(int);
	void MoveRoute();
	//街
	void ResetCity();
	void CityBtnOver(int);
	void CityBtnOut(int);
	void CityBtnSys(int);
	void CityData();
	void ExitBtnOver(int);
	void ExitBtnOut(int);
	void ExitBtnSys(int);
};

class HEROINE {
public:
	double X, Y;
	int On;
};