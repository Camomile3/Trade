#pragma once
#include "class.h"
#include "DxLib.h"

GOODS Goods[32];
CITY City[16];
MARKET Market[16][32];
MARKET HerMarket[16][32];
extern HEROINE her;
extern SYSTEM sys;
extern INIT init;

//メッセージ処理を追加するとき追加
void SYSTEM::DrawMessageWindow() {

	TCHAR Temp[64];
	MWX = 480;
	MWY = 800;
	DrawGraph(MWX, MWY, init.GraMW, TRUE);

	sys.MOver = FALSE;
	switch (BtnSwitch) {
	case Sw_QUIT:
		BtnX[62] = MWX + 280;
		BtnY[62] = MWY + 140;
		BtnW[62] = 90;
		BtnH[62] = 42;
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "終了しますか？", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[62], BtnY[62], "はい", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "いいえ", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_CARGO:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "積荷の説明文を表示する予定です", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_TRANS:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "輸送手段の説明文を表示する予定です", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_FINAN:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "財務状況の解説をさせる予定です", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_QUEST:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "メインクエストとかサブとか", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_PRICES:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "相場を見る街を選んでね", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_PRICES2:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		sprintf_s(Temp, 64, "%sの相場です", City[ClickedBtn].Name);
		DrawStringToHandle(MWX + 64, MWY + 64, Temp, GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_SAVE:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "セーブするスロットを選んでね", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_LOAD:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "ロードするスロットを選んでね", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_OPTION:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "オプション項目の説明をさせる予定です", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "閉じる", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_CITY:
		switch (TalkNumber) {
		case 0:
			DrawStringToHandle(MWX + 64, MWY + 64, "景気がよく非常に活気がある。", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 1:
			DrawStringToHandle(MWX + 64, MWY + 64, "こんにちな！ここはモヘミンチョだよ！", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 2:
			DrawStringToHandle(MWX + 64, MWY + 64, "おはよう　ダメージ。もう　あさがよい。", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 3:
			DrawStringToHandle(MWX + 64, MWY + 64, "あれ　テイデンかミ", GetColor(255, 255, 255), init.FontHandle);
			break;
		case 4:
			DrawStringToHandle(MWX + 64, MWY + 64, "景気がよく非常に活気がある。", GetColor(255, 255, 255), init.FontHandle);
			TalkNumber = 0;
			break;
		}
		break;
	case Sw_BUY:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "購入する貿易品を選んでください", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_SALE:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "売却する貿易品を選んでください", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_INVEST:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "投資画面です", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_MANAGE:
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "経営画面です", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "戻る", GetColor(255, 255, 255), init.FontHandle);
		break;
	case Sw_TALK2:

		break;
	case Sw_EXIT:
		BtnX[62] = MWX + 280;
		BtnY[62] = MWY + 140;
		BtnW[62] = 90;
		BtnH[62] = 42;
		BtnX[63] = MWX + 640;
		BtnY[63] = MWY + 140;
		BtnW[63] = 90;
		BtnH[63] = 42;

		DrawStringToHandle(MWX + 64, MWY + 64, "街を出ますか？", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[62], BtnY[62], "はい", GetColor(255, 255, 255), init.FontHandle);
		DrawStringToHandle(BtnX[63], BtnY[63], "いいえ", GetColor(255, 255, 255), init.FontHandle);
		break;
	}

}

//ID　名前　基本値　係数　工業影響度　技術影響度　生産基本値　生産係数　工業生産影響度　技術生産影響度　工業市場規模影響度　技術市場規模影響度
void GOODS::SetGoods(int i, char* n, int b, double ind, double tech, int bp, double ipi, double tpi, double isi, double tsi) {
	ID = i;
	Name = n;
	BasePrice = b;
	IndImpact = ind;
	TechImpact = tech;
	BaseProd = bp;
	IndProdImpact = ipi;
	TechProdImpact = tpi;
	IndSizeImpact = isi;
	TechSizeImpact = tsi;
}

//ID　名前　基本値　工業影響度　技術影響度　生産基本値　工業生産影響度　技術生産影響度　工業市場規模影響度　技術市場規模影響度
void GOODS::InitGoods() {
	Goods[0].SetGoods(0, (char*)"食料", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[1].SetGoods(1, (char*)"石炭", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[2].SetGoods(2, (char*)"鉱石", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[3].SetGoods(3, (char*)"レアメタル", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[4].SetGoods(4, (char*)"木材", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[5].SetGoods(5, (char*)"金属", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[6].SetGoods(6, (char*)"缶詰", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[7].SetGoods(7, (char*)"銃火器", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[8].SetGoods(8, (char*)"紙", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[9].SetGoods(9, (char*)"書籍", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[10].SetGoods(10, (char*)"東洋贅沢品", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[11].SetGoods(11, (char*)"西洋贅沢品", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[12].SetGoods(12, (char*)"農業贅沢品", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[13].SetGoods(13, (char*)"綿花", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[14].SetGoods(14, (char*)"生糸", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[15].SetGoods(15, (char*)"綿織物", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[16].SetGoods(16, (char*)"絹織物", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[17].SetGoods(17, (char*)"石油", 100, 1, 1, 100, 1, 1, 1, 1);
}


//基本値　倍率　景気　需要　供給　工業　工業影響度　技術　技術影響度　開発度　インフラ
int MARKET::CalcPrice(int b, double e, double d, double s, double i, double indimp, double t, double techimp, double dev, double inf) {

	double CalclatedPrice = b * ((e + (d / s) * (d / s) + (i * indimp) + (t * techimp) + (-0.05 * dev + 1) + (-0.1 * inf + 1)) / 6);

//	double CalclatedPrice = b + p * e * d / s * (i * indimp) * (t * techimp) * (-0.05 * dev + 1) * (-0.1 * inf + 1);

	return (int)CalclatedPrice;
}

int MARKET::SaleCalcPrice(int b, double e, double d, double s, double i, double indimp, double t,  double techimp, double dev, double inf) {

	double CalclatedPrice = (b * ((e + (d / s) * (d / s) + (i * indimp) + (t * techimp) + (-0.05 * dev + 1) + (-0.1 * inf + 1)) / 6)) * 0.8;

	return (int)CalclatedPrice;
}

//品物基本値　人口　開発度　技術　技術生産影響度　インフラ　供給　需要　工業　工業生産影響度
int MARKET::CalcProduction(int ID, int herOn) {

	int bp = Goods[ID].BaseProd;
	double p = City[herOn].Population;
	double dev = City[herOn].Develop;
	double tech = City[herOn].Technology;
	double techimp = Goods[ID].TechProdImpact;
	double inf = City[herOn].Infra;
	double d = Market[herOn][ID].Demand;
	double s = Market[herOn][ID].Supply;
	double ind = City[herOn].Industry;
	double indimp = Goods[ID].IndProdImpact;

	double CalclatedProduction = bp * ((p / 10000000) + dev + tech * techimp + inf + std::pow(s, 4.0) + (0.1*d + 1) + (0.1*ind*indimp + 1) / 7);

	//double CalclatedProduction = bp + (((p / 10000000) + dev + tech * techimp + inf + s * 2 + (0.1*d+1) + (0.1*ind*indimp+1)) * pm) / 8;

	return (int)CalclatedProduction;
}

int MARKET::CalcMarketSize(int ID, int herOn) {

	int bp = Goods[ID].BaseProd;
	double p = City[herOn].Population;
	double dev = City[herOn].Develop;
	double tech = City[herOn].Technology;
	double techimp = Goods[ID].TechSizeImpact;
	double inf = City[herOn].Infra;
	double d = Market[herOn][ID].Demand;
	double s = Market[herOn][ID].Supply;
	double ind = City[herOn].Industry;
	double indimp = Goods[ID].IndSizeImpact;

	double CalclatedMarketSize = bp * ((p / 10000000) + dev + tech * techimp + inf + d * d + (0.1*s + 1) + (0.1*ind*indimp + 1) / 7);

	return (int)CalclatedMarketSize;
}

void MARKET::SetMarket(double D, double S) {

	Demand = D;
	Supply = S;
}

void INIT::InitMarket() {

	Market[0][0].SetMarket(1.3, 0.5);
	Market[0][1].SetMarket(1.4, 0.4);
	Market[0][2].SetMarket(0.5, 0.1);
	Market[0][3].SetMarket(1.3, 1.0);
	Market[0][4].SetMarket(1.3, 0.95);
	Market[0][5].SetMarket(0.01, 0.01);
	Market[0][6].SetMarket(1.3, 1.0);
	Market[0][7].SetMarket(1.3, 0.8);
	Market[0][8].SetMarket(1.3, 0.5);
	Market[0][9].SetMarket(1.3, 0.5);
	Market[0][10].SetMarket(1.3, 0.5);
	Market[0][11].SetMarket(1.0, 1.7);
	Market[0][12].SetMarket(0.8, 1.2);
	Market[0][13].SetMarket(1.3, 0.5);

	Market[1][0].SetMarket(1.3, 0.5);
	Market[1][1].SetMarket(1.4, 0.4);
	Market[1][2].SetMarket(0.5, 0.1);
	Market[1][3].SetMarket(1.3, 1.0);
	Market[1][4].SetMarket(1.3, 0.95);
	Market[1][5].SetMarket(0.01, 0.01);
	Market[1][6].SetMarket(1.3, 1.0);
	Market[1][7].SetMarket(1.3, 0.8);
	Market[1][8].SetMarket(1.3, 0.5);
	Market[1][9].SetMarket(1.3, 0.5);
	Market[1][10].SetMarket(1.3, 0.5);
	Market[1][11].SetMarket(1.3, 0.5);
	Market[1][12].SetMarket(1.5, 0.3);
	Market[1][13].SetMarket(1.3, 0.5);
}

void CITY::SetCity(int I, const char* T, const char* N, double P, double D, double E, double Tech, double Ind, double Inf) {

	ID = I;
	Type = T;
	Name = N;
	Population = P;
	Develop = D;
	Economy = E;
	Technology = Tech;
	Industry = Ind;
	Infra = Inf;
}

void CITY::InitCity() {

	//ID タイプ 名前　人口　開発度　景気　技術　工業　インフラ
	City[0].SetCity(0, "帝都", "ロイア", 8000000, 0.7, 1.3, 0.2, 0.2, 0.2);
	City[1].SetCity(0, "貴族の町", "セカンド", 8000000, 0.7, 1.0, 0.2, 0.2, 0.2);
	City[2].SetCity(0, "", "ロイア", 8000000, 0.7, 1.3, 0.2, 0.2, 0.2);
	City[3].SetCity(0, "", "セカンド", 8000000, 0.7, 1.0, 0.2, 0.2, 0.2);
	City[4].SetCity(0, "", "ロイア", 8000000, 0.7, 1.3, 0.2, 0.2, 0.2);
	City[5].SetCity(0, "", "セカンド", 8000000, 0.7, 1.0, 0.2, 0.2, 0.2);
	City[6].SetCity(0, "", "ロイア", 8000000, 0.7, 1.3, 0.2, 0.2, 0.2);
	City[7].SetCity(0, "", "セカンド", 8000000, 0.7, 1.0, 0.2, 0.2, 0.2);
	City[8].SetCity(0, "", "ロイア", 8000000, 0.7, 1.3, 0.2, 0.2, 0.2);
	City[9].SetCity(0, "", "セカンド", 8000000, 0.7, 1.0, 0.2, 0.2, 0.2);
}

void SYSTEM::SetHerPrices(int ID) {

	for (int i = 0; i < 32; i++) {
		HerMarket[ID][i].Demand = Market[ID][i].Demand;
		HerMarket[ID][i].Supply = Market[ID][i].Supply;
	}
}

/*	Goods[0].SetGoods(0, (char*)"石炭", 60);
	Goods[1].SetGoods(1, (char*)"鉱石", 80);
	Goods[2].SetGoods(2, (char*)"レアメタル", 100);
	Goods[3].SetGoods(3, (char*)"食料", 100);
	Goods[4].SetGoods(4, (char*)"木材", 100);
	Goods[5].SetGoods(5, (char*)"石油", 100);
	Goods[6].SetGoods(6, (char*)"金属", 100);
	Goods[7].SetGoods(7, (char*)"缶詰", 100);
	Goods[8].SetGoods(8, (char*)"銃火器", 100);
	Goods[9].SetGoods(9, (char*)"紙", 100);
	Goods[10].SetGoods(10, (char*)"書籍", 100);
	Goods[11].SetGoods(11, (char*)"東洋贅沢品", 100);
	Goods[12].SetGoods(12, (char*)"西洋贅沢品", 100);
	Goods[13].SetGoods(13, (char*)"農業贅沢品", 100);*/

void SYSTEM::BuyData() {

	switch (her.On) {
	case 0:
		BuySort(0);
		BuySort(3);
		BuySort(6);
		BuySort(7);
		BuySort(8);
		BuySort(11);
		break;
	case 1:
		BuySort(0);
		BuySort(1);
		BuySort(4);
		BuySort(5);
		BuySort(6);
		BuySort(12);
	}
}