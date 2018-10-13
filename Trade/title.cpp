#include "DxLib.h"
#include "class.h"

extern INIT init;
extern FUN fun;

void SYSTEM::ResetTitle() {

	switch (BtnSwitch) {
	case Sw_TITLE:
	case Sw_QUIT:
		ClearDrawScreen();
		DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraT, TRUE);
		DrawButton(OveredBtn);
		break;
	case Sw_SAVE:
	case Sw_LOAD:
	case Sw_OPTION:
		ClearDrawScreen();
		DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraT, TRUE);
		DrawButton(OveredBtn);
		if (BtnSwitch == Sw_OPTION)
			DrawOptionString();
		break;
	}
}


void SYSTEM::TitleBtnOver(int i) {
	switch (i) {
	case 0:
		ResetTitle();
		DrawStringToHandle(BtnX[0] + MultiResoIntX(36), BtnY[0] + MultiResoIntY(8), "NewGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		ResetTitle();
		DrawStringToHandle(BtnX[1] + MultiResoIntX(34), BtnY[1] + MultiResoIntY(8), "LoadGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 2:
		ResetTitle();
		DrawStringToHandle(BtnX[2] + MultiResoIntX(54), BtnY[2] + MultiResoIntY(8), "Option", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 3:
		ResetTitle();
		DrawStringToHandle(BtnX[3] + MultiResoIntX(36), BtnY[3] + MultiResoIntY(8), "QuitGame", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::TitleBtnOverOut(int OveredBtn) {

	int y = 8;

	switch (OveredBtn) {
	case 0:
		ResetTitle();
		DrawStringToHandle(BtnX[0] + MultiResoIntX(36), BtnY[0] + MultiResoIntY(y), "NewGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 1:
		ResetTitle();
		DrawStringToHandle(BtnX[1] + MultiResoIntX(34), BtnY[1] + MultiResoIntY(y), "LoadGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 2:
		ResetTitle();
		DrawStringToHandle(BtnX[2] + MultiResoIntX(54), BtnY[2] + MultiResoIntY(y), "Option", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 3:
		ResetTitle();
		DrawStringToHandle(BtnX[3] + MultiResoIntX(36), BtnY[3] + MultiResoIntY(y), "QuitGame", GetColor(0, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::TitleBtnSys(int OveredBtn) {
	switch (OveredBtn) {
	case 0:
		fun.FStat = fun.F_MAIN;
		BtnSwitch = Sw_MMAP;
		InitMap();
		break;
	case 1:
		BtnSwitch = Sw_LOAD;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		LoadData();
		break;
	case 2:
		BtnSwitch = Sw_OPTION;
		DrawWindow(520, 140, 5, 16);
		DrawMessageWindow();
		DrawOptionString();
		OptionData();
		break;
	case 3:
		BtnSwitch = Sw_QUIT;
		DrawMessageWindow();
		break;
	}
}

void SYSTEM::QuitBtnOver(int i) {

	switch (i) {
	case 62:
		QuitBtnReset();
		DrawStringToHandle(BtnX[62], BtnY[62], "‚Í‚¢", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 63:
		QuitBtnReset();
		DrawStringToHandle(BtnX[63], BtnY[63], "‚¢‚¢‚¦", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::QuitBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 62:
		QuitBtnReset();
		DrawStringToHandle(BtnX[62], BtnY[62], "‚Í‚¢", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 63:
		QuitBtnReset();
		DrawStringToHandle(BtnX[63], BtnY[63], "‚¢‚¢‚¦", GetColor(255, 255, 255), init.FontHandle);
		break;
	}
}

void SYSTEM::QuitBtnReset() {

	switch (fun.FStat) {
	case fun.F_TITLE:
		ResetTitle();
		BtnSwitch = Sw_QUIT;
		DrawMessageWindow();
		break;
	case fun.F_MAIN:
		ResetMap();
		SpawnHer();
		BtnSwitch = Sw_QUIT;
		DrawMessageWindow();
		break;
	}
}

void SYSTEM::QuitBtnSys(int OveredBtn) {
	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (OveredBtn) {
		case 62:
			DxLib_End();
		case 63:
			BtnSwitch = Sw_TITLE;
			ResetTitle();
			break;
		}
		break;
	case fun.F_MAIN:
		switch (OveredBtn) {
		case 62:
			DxLib_End();
		case 63:
			BtnSwitch = Sw_MMAP;
			ResetMap();
			SpawnHer();
			break;
		}
		break;
	}
}

void SYSTEM::OptionBtnOver(int i) {

	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (i) {
		case 63:
			ResetTitle();
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			DrawOptionString();
			DrawOptionBtn();
			DrawStringToHandle(BtnX[63], BtnY[63], "•Â‚¶‚é", GetColor(255, 0, 0), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (i) {
		case 63:
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			DrawOptionString();
			DrawOptionBtn();
			DrawStringToHandle(BtnX[63], BtnY[63], "•Â‚¶‚é", GetColor(255, 0, 0), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	}
}

void SYSTEM::OptionBtnOut(int OveredBtn) {

	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (OveredBtn) {
		case 63:
			ResetTitle();
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			DrawOptionString();
			DrawOptionBtn();
			DrawStringToHandle(BtnX[63], BtnY[63], "•Â‚¶‚é", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (OveredBtn) {
		case 63:
			ResetMap();
			SpawnHer();
			BtnSwitch = Sw_OPTION;
			DrawWindow(520, 140, 5, 16);
			DrawMessageWindow();
			DrawOptionString();
			DrawOptionBtn();
			DrawStringToHandle(BtnX[63], BtnY[63], "•Â‚¶‚é", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 1:
			break;
		}
		break;
	}
}

void SYSTEM::OptionBtnSys(int OveredBtn) {

	switch (fun.FStat) {
	case fun.F_TITLE:
		switch (OveredBtn) {
		case 63:
			BtnSwitch = Sw_TITLE;
			ResetTitle();
			break;
		case 1:
			break;
		}
		break;
	case fun.F_MAIN:
		switch (OveredBtn) {
		case 63:
			BtnSwitch = Sw_MMAP;
			ResetMap();
			SpawnHer();
			break;
		case 1:
			break;
		}
		break;
	}
}

void SYSTEM::OptionData() {

	BtnX[60] = VolumeBGM * 2 + 800;
	BtnY[60] = 240;
	BtnW[60] = 16;
	BtnH[60] = 32;

	MultiResoBtn(60);

	BtnX[61] = VolumeSE * 2 + 800;
	BtnY[61] = 350;
	BtnW[61] = 16;
	BtnH[61] = 32;

	MultiResoBtn(61);

	DrawExtendGraph(BtnX[60], BtnY[60], BtnX[60] + BtnW[60], BtnY[60] + BtnH[60], init.GraBtn4, TRUE);
	DrawExtendGraph(BtnX[61], BtnY[61], BtnX[61] + BtnW[61], BtnY[61] + BtnH[61], init.GraBtn4, TRUE);
}

void SYSTEM::DrawOptionBtn() {

	DrawExtendGraph(BtnX[60], BtnY[60], BtnX[60] + BtnW[60], BtnY[60] + BtnH[60], init.GraBtn4, TRUE);
	DrawExtendGraph(BtnX[61], BtnY[61], BtnX[61] + BtnW[61], BtnY[61] + BtnH[61], init.GraBtn4, TRUE);
}

void SYSTEM::DrawOptionString() {

	TempValueX[0] = 808;
	TempValueY[0] = 256;
	TempValueX[1] = 808 + 512;
	TempValueY[1] = 256;

	TempValueX[2] = 808;
	TempValueY[2] = 366;
	TempValueX[3] = 808 + 512;
	TempValueY[3] = 366;

	for (int i = 0; i < 4; i++) {
		MultiResoValue(i);
	}

	DrawStringToHandle(MultiResoIntX(640), MultiResoIntY(240), "BGM", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(640), MultiResoIntY(350), "SE", GetColor(0, 0, 0), init.FontHandle);

	DrawLineAA((float)TempValueX[0], (float)TempValueY[0], (float)TempValueX[1], (float)TempValueY[1], GetColor(0, 0, 0));
	DrawLineAA((float)TempValueX[2], (float)TempValueY[2], (float)TempValueX[3], (float)TempValueY[3], GetColor(0, 0, 0));

}