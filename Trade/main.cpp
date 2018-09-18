#include "DxLib.h"
#include "class.h"

FUN fun;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	void Test();

	if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
	{
		return -1;    // エラーが起きたら直ちに終了
	}


	//関数
	fun.main();



	WaitKey();        // 結果を見るためにキー待ち(『WaitKey』を使用)

	DxLib_End();        // ＤＸライブラリ使用の終了処理

	return 0;        // ソフトの終了
}