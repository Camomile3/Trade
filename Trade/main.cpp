#include "DxLib.h"
#include "class.h"

FUN Mfun;
extern INIT init;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
	{
		return -1;    // エラーが起きたら直ちに終了
	}

	//解像度取得
	init.WinX = GetSystemMetrics(SM_CXSCREEN);
	init.WinY = GetSystemMetrics(SM_CYSCREEN);

	//解像度セット
	SetGraphMode(init.WinX, init.WinY, 32, 60);

	//マウス
	SetMouseDispFlag(TRUE);

	//メイン
	Mfun.main();

	DxLib_End();        // ＤＸライブラリ使用の終了処理

	return 0;        // ソフトの終了
}