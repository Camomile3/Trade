#include "DxLib.h"
#include "class.h"

FUN Mfun;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	void Test();

	if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
	{
		return -1;    // エラーが起きたら直ちに終了
	}

	//関数
	Mfun.main();

	DxLib_End();        // ＤＸライブラリ使用の終了処理

	return 0;        // ソフトの終了
}