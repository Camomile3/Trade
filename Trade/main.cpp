#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int Gra;
	void Test();
	void ButtonOver();

	if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
	{
		return -1;    // エラーが起きたら直ちに終了
	}
	//解像度取得
	int WinX = GetSystemMetrics(SM_CXSCREEN);
	int WinY = GetSystemMetrics(SM_CYSCREEN);

	//解像度セット
	SetGraphMode(WinX, WinY, 32, 60);

	//タイトル画像表示
	Gra = LoadGraph("Resouce/BG_Title.jpg");

	DrawExtendGraph(0, 0, WinX, WinY, Gra, TRUE);

	//マウス
	SetMouseDispFlag(TRUE);

	//関数
	ButtonOver();

	Test();

	// 読み込んだ画像のグラフィックハンドルを削除
	DeleteGraph(Gra);

	WaitKey();        // 結果を見るためにキー待ち(『WaitKey』を使用)

	DxLib_End();        // ＤＸライブラリ使用の終了処理

	return 0;        // ソフトの終了
}


//ボタン
void ButtonOver() {
	int GraBtn1;
	int MouseX, MouseY;

	GraBtn1 = LoadGraph("Resouce/T_Btn1.png");

	DrawGraph(870, 800, GraBtn1, TRUE);
	while (CheckHitKeyAll() == 0) {
		while (CheckHitKeyAll() == 0) {
			GetMousePoint(&MouseX, &MouseY);
			if (MouseX >= 870 && MouseX <= 870 + 180) {
				if (MouseY >= 800 && MouseY <= 800 + 42) {
					GraphFilter(GraBtn1, DX_GRAPH_FILTER_INVERT);
					DrawGraph(870, 800, GraBtn1, TRUE);
					break;
				}
			}
			WaitTimer(100);
		}
		while (CheckHitKeyAll() == 0) {
			GetMousePoint(&MouseX, &MouseY);
			if (MouseX >= 870 && MouseX <= 870 + 180) {
				if (MouseY >= 800 && MouseY <= 800 + 42) {
				}
				else {
					GraphFilter(GraBtn1, DX_GRAPH_FILTER_INVERT);
					DrawGraph(870, 800, GraBtn1, TRUE);
					break;
				}
			}
			else {
				GraphFilter(GraBtn1, DX_GRAPH_FILTER_INVERT);
				DrawGraph(870, 800, GraBtn1, TRUE);
				break;
			}
			WaitTimer(100);
		}
	}
}

void Test()
{
	char StrBuf[128], StrBuf2[32];
	int StringCr, BoxCr;
	int MouseX, MouseY;

	// 白色の値を取得
	StringCr = GetColor(255, 255, 255);

	// 黒の値を取得
	BoxCr = GetColor(0, 0, 0);

	// キーが押されるまでループ
	while (CheckHitKeyAll() == 0)
	{
		// マウスの位置を取得
		GetMousePoint(&MouseX, &MouseY);

		// 表示する文字列を作成
		{
			lstrcpy(StrBuf, "座標 Ｘ"); // 文字列"座標 Ｘ"をStrBufにコピー	
			_itoa_s(MouseX, StrBuf2, 10); // MouseXの値を文字列にしてStrBuf2に格納
			lstrcat(StrBuf, StrBuf2); // StrBufの内容にStrBuf2の内容を付け足す
			lstrcat(StrBuf, "　Ｙ "); // StrBufの内容に文字列"Ｙ"を付け足す
			_itoa_s(MouseY, StrBuf2, 10); // MouseYの値を文字列にしてStrBuf2に格納
			lstrcat(StrBuf, StrBuf2); // StrBufの内容にStrBuf2の内容を付け足す
		}

		// 画面左上の領域に黒い四角を描き前に描いてあった
		// 文字列を消す
		DrawBox(0, 0, 200, 32, BoxCr, TRUE);

		// 座標文字列を描く
		DrawString(0, 0, StrBuf, StringCr);

		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが起きたらループを抜ける
		}

		// 一定時間待つ
		WaitTimer(100);
	}
}