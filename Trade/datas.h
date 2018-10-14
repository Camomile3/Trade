#pragma once
#include "class.h"
#include "DxLib.h"

GOODS Goods[32];
CITY City[16];
MARKET Market[16][32];
MARKET HerMarket[16][32];
TRANSPORT Trans[8];
BUILDING CityBuilding[16][3];
BUILDING HerBuilding[16][3][99];
COMPANY Comp[16];
extern HEROINE her;
extern SYSTEM sys;
extern INIT init;

void SYSTEM::MessageWindowMessage(const char* String) {

	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64), String, GetColor(255, 255, 255), init.FontHandle);
}

//メッセージ処理を追加するとき追加
void SYSTEM::DrawMessageWindow() {

	TCHAR Temp[64];
	MWX = 480;
	MWY = 800;
	DrawExtendGraph(MultiResoIntX(MWX), MultiResoIntY(MWY), MultiResoIntX(MWX + 960), MultiResoIntY(MWY +200), init.GraMW, TRUE);

	sys.MOver = FALSE;
	switch (BtnSwitch) {
	case Sw_QUIT:
		MessageWindowMessage("終了しますか？");
		SetTwoBtn("はい", "いいえ");
		break;
	case Sw_CARGO:

		MessageWindowMessage("積荷の説明文を表示する予定です");

		break;
	case Sw_TRANS:
		MessageWindowMessage("輸送手段の説明文を表示する予定です");
		SetSingleBtn("閉じる");
		break;
	case Sw_FINAN:
		MessageWindowMessage("財務状況の解説をさせる予定です");
		SetSingleBtn("閉じる");
		break;
	case Sw_QUEST:
		MessageWindowMessage("メインクエストとかサブとか");
		SetSingleBtn("閉じる");
		break;
	case Sw_PRICES:
		MessageWindowMessage("相場を見る街を選んでね");
		SetSingleBtn("閉じる");
		break;
	case Sw_PRICES2:
		sprintf_s(Temp, 64, "%sの相場です", City[ClickedBtn].Name);
		MessageWindowMessage(Temp);
		SetSingleBtn("閉じる");
		break;
	case Sw_SAVE:
		MessageWindowMessage("セーブするスロットを選んでね");
		SetSingleBtn("閉じる");
		break;
	case Sw_LOAD:
		MessageWindowMessage("ロードするスロットを選んでね");
		SetSingleBtn("閉じる");
		break;
	case Sw_OPTION:
		MessageWindowMessage("オプション項目の説明をさせる予定です");
		SetSingleBtn("閉じる");
		break;
	case Sw_CITY:
		switch (TalkNumber) {
		case 0:
			MessageWindowMessage("景気がよく非常に活気がある。");
			break;
		case 1:
			MessageWindowMessage("こんにちな！ここはモヘミンチョだよ！");
			break;
		case 2:
			MessageWindowMessage("おはよう　ダメージ。もう　あさがよい。");
			break;
		case 3:
			MessageWindowMessage("あれ　テイデンかミ");
			break;
		case 4:
			MessageWindowMessage("景気がよく非常に活気がある。");
			TalkNumber = 0;
			break;
		}
		break;
	case Sw_BUY:

		MessageWindowMessage("購入する貿易品を選んでください");

		break;
	case Sw_SALE:
		MessageWindowMessage("売却する貿易品を選んでください");
		SetSingleBtn("戻る");
		break;
	case Sw_INVEST:
	case Sw_INVESTT:
	case Sw_INVESTB:
		MessageWindowMessage("投資画面です");
		SetSingleBtn("戻る");
		break;
	case Sw_INVESTI:
		MessageWindowMessage("未実装よ");
		SetSingleBtn("戻る");
		break;
	case Sw_MANAGE:
		MessageWindowMessage("経営画面です");
		SetSingleBtn("戻る");
		break;
	case Sw_TALK2:

		break;
	case Sw_EXIT:
		MessageWindowMessage("街を出ますか？");
		SetTwoBtn("はい", "いいえ");
		break;
	}

}

//ID　名前　基本値　係数　工業影響度　技術影響度　生産基本値　生産係数　工業生産影響度　技術生産影響度
void GOODS::SetGoods(int i, char* n, int b, double ind, double tech, int bp, double ipi, double tpi, int bs) {
	ID = i;
	Name = n;
	BasePrice = b;
	IndIDemandmpact = ind;
	TechDemandImpact = tech;
	BaseProd = bp;
	IndSupplyImpact = ipi;
	TechSupplyImpact = tpi;
	BaseSize = bs;
}

//ID　名前　基本値　工業影響度　技術影響度　生産基本値　工業生産影響度　技術生産影響度　工業市場規模影響度　技術市場規模影響度
void GOODS::InitGoods() {
	Goods[0].SetGoods(0, (char*)"食料", 100, 1, 1, 100, 1, 1, 100);
	Goods[1].SetGoods(1, (char*)"石炭", 100, 1, 1, 100, 1, 1, 100);
	Goods[2].SetGoods(2, (char*)"鉱石", 100, 1, 1, 100, 1, 1, 100);
	Goods[3].SetGoods(3, (char*)"レアメタル", 100, 1, 1, 100, 1, 1, 100);
	Goods[4].SetGoods(4, (char*)"木材", 100, 1, 1, 100, 1, 1, 100);
	Goods[5].SetGoods(5, (char*)"金属", 100, 1, 1, 100, 1, 1, 100);
	Goods[6].SetGoods(6, (char*)"缶詰", 100, 1, 1, 100, 1, 1, 100);
	Goods[7].SetGoods(7, (char*)"銃火器", 100, 1, 1, 100, 1, 1, 100);
	Goods[8].SetGoods(8, (char*)"紙", 100, 1, 1, 100, 1, 1, 100);
	Goods[9].SetGoods(9, (char*)"書籍", 100, 1, 1, 100, 1, 1, 100);
	Goods[10].SetGoods(10, (char*)"東洋贅沢品", 100, 1, 1, 100, 1, 1, 100);
	Goods[11].SetGoods(11, (char*)"西洋贅沢品", 100, 1, 1, 100, 1, 1, 100);
	Goods[12].SetGoods(12, (char*)"農業贅沢品", 100, 1, 1, 100, 1, 1, 100);
	Goods[13].SetGoods(13, (char*)"綿花", 100, 1, 1, 100, 1, 1, 100);
	Goods[14].SetGoods(14, (char*)"生糸", 100, 1, 1, 100, 1, 1, 100);
	Goods[15].SetGoods(15, (char*)"綿織物", 100, 1, 1, 100, 1, 1, 100);
	Goods[16].SetGoods(16, (char*)"絹織物", 100, 1, 1, 100, 1, 1, 100);
	Goods[17].SetGoods(17, (char*)"石油", 100, 1, 1, 100, 1, 1, 100);
}


//基本値　需要　供給　開発度　インフラ
int MARKET::CalcPrice(int herOn, int ID) {

	int b = Goods[ID].BasePrice;
	double d = Market[herOn][ID].Demand;
	double s = Market[herOn][ID].Supply;
	double dev = City[herOn].Develop; 
	double inf = City[herOn].Infra;

	double CalclatedPrice = b * ((std::pow(d / s, 2) + (-0.05 * dev + 1) + (-0.1 * inf + 1)) / 3);

//	double CalclatedPrice = b * ((e + (d / s) * (d / s) + (i * indimp) + (t * techimp) + (-0.05 * dev + 1) + (-0.1 * inf + 1)) / 6);

//	double CalclatedPrice = b + p * e * d / s * (i * indimp) * (t * techimp) * (-0.05 * dev + 1) * (-0.1 * inf + 1);

	return (int)CalclatedPrice;
}

int MARKET::SaleCalcPrice(int herOn, int ID) {

	int b = Goods[ID].BasePrice;
	double d = Market[herOn][ID].Demand;
	double s = Market[herOn][ID].Supply;
	double dev = City[herOn].Develop;
	double inf = City[herOn].Infra;

	double CalclatedPrice = (b * ((std::pow(d / s, 2) + (-0.05 * dev + 1) + (-0.1 * inf + 1)) / 3) ) * 0.8;

	return (int)CalclatedPrice;
}

//品物基本値　供給　人口　開発度　需要
int MARKET::CalcProduction(int herOn, int ID) {

	int bp = Goods[ID].BaseProd;
	double p = City[herOn].Population;
	double dev = City[herOn].Develop;
	double d = Market[herOn][ID].Demand;
	double s = Market[herOn][ID].Supply;

	double CalclatedProduction = bp * (( std::pow(s, 2.0) + (p / 10000000) + dev + (0.1 * d + 1)) / 4);

	//double CalclatedProduction = bp * ((p / 10000000) + dev + tech * techimp + inf + std::pow(s, 4.0) + (0.1*d + 1) + (0.1*ind*indimp + 1) / 7);

	//double CalclatedProduction = bp + (((p / 10000000) + dev + tech * techimp + inf + s * 2 + (0.1*d+1) + (0.1*ind*indimp+1)) * pm) / 8;

	return (int)CalclatedProduction;
}

int MARKET::CalcMarketSize(int ID, int herOn) {

	int bp = Goods[ID].BaseProd;
	double p = City[herOn].Population;
	double dev = City[herOn].Develop;
	double d = Market[herOn][ID].Demand;
	double s = Market[herOn][ID].Supply;

	double CalclatedMarketSize = bp * ((std::pow(d, 2.0) + (p / 10000000) + dev + (0.1 * s + 1)) / 4);

	//double CalclatedMarketSize = bp * ((p / 10000000) + dev + tech * techimp + inf + d * d + (0.1*s + 1) + (0.1*ind*indimp + 1) / 7);

	return (int)CalclatedMarketSize;
}

void SYSTEM::CalcDemand(int herOn) {

	double bd;
	double t = City[herOn].Technology;
	double timp;
	double ind = City[herOn].Industry;
	double iimp;
	double e = City[herOn].Economy;

	for (int i = 0; i < 17; i++) {
		bd = Market[herOn][i].BaseDemand;
		timp = Goods[i].TechDemandImpact;
		iimp = Goods[i].IndIDemandmpact;

		Market[herOn][i].Demand = bd + (((t * timp) + (ind * iimp) + e) / 3);
	}

}

void SYSTEM::CalcSupply(int herOn) {

	double bs;
	double t = City[herOn].Technology;
	double timp;
	double ind = City[herOn].Industry;
	double iimp;
	double inf = City[herOn].Infra;

	for (int i = 0; i < 17; i++) {
		bs = Market[herOn][i].BaseSupply;
		timp = Goods[i].TechSupplyImpact;
		iimp = Goods[i].IndSupplyImpact;

		Market[herOn][i].Supply = bs + (((t * timp) + (ind * iimp) + inf) / 3);
	}

}

void MARKET::SetMarket(double D, double S) {

	BaseDemand = D;
	BaseSupply = S;
}

/*
	Goods[0].SetGoods(0, (char*)"食料", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[1].SetGoods(1, (char*)"石炭", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[2].SetGoods(2, (char*)"鉱石", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[3].SetGoods(3, (char*)"レアメタル", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[4].SetGoods(4, (char*)"木材", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[5].SetGoods(5, (char*)"金属", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[6].SetGoods(6, (char*)"缶詰", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[7].SetGoods(7, (char*)"銃火器", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[8].SetGoods(8, (char*)"紙", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[9].SetGoods(9, (char*)"書籍", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[10].SetGoods(10, (char*)"東洋贅沢品", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[11].SetGoods(11, (char*)"西洋贅沢品", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[12].SetGoods(12, (char*)"農業贅沢品", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[13].SetGoods(13, (char*)"綿花", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[14].SetGoods(14, (char*)"生糸", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[15].SetGoods(15, (char*)"綿織物", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[16].SetGoods(16, (char*)"絹織物", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[17].SetGoods(17, (char*)"石油", 100, 1, 1, 100, 1, 1, 100, 1, 1);
*/

void INIT::InitMarket() {

	Market[0][0].SetMarket(1.3, 0.5);
	Market[0][1].SetMarket(1.4, 0.4);
	Market[0][2].SetMarket(0.5, 0.1);
	Market[0][3].SetMarket(1.3, 1.0);
	Market[0][4].SetMarket(1.3, 0.95);
	Market[0][5].SetMarket(1.8, 1.4);
	Market[0][6].SetMarket(1.3, 1.0);
	Market[0][7].SetMarket(1.3, 0.8);
	Market[0][8].SetMarket(1.3, 0.5);
	Market[0][9].SetMarket(1.3, 0.5);
	Market[0][10].SetMarket(1.3, 0.5);
	Market[0][11].SetMarket(1.0, 1.7);
	Market[0][12].SetMarket(0.8, 1.2);
	Market[0][13].SetMarket(1.3, 0.5);
	Market[0][14].SetMarket(1.3, 0.5);
	Market[0][15].SetMarket(1.3, 0.5);
	Market[0][16].SetMarket(1.0, 1.7);
	Market[0][17].SetMarket(0.8, 1.2);

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
	Market[1][14].SetMarket(1.3, 0.5);
	Market[1][15].SetMarket(1.3, 0.5);
	Market[1][16].SetMarket(1.0, 1.7);
	Market[1][17].SetMarket(0.8, 1.2);
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
	City[0].SetCity(0, "帝都", "ロイア", 8000000, 0.7, 1.3, 1.0, 0.2, 0.2);
	City[1].SetCity(0, "貴族の町", "セカンド", 8000000, 0.5, 1.0, 0.2, 0.2, 0.2);
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

/*
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
*/

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

void TRANSPORT::SetTrans(int i, const char* n, int c, int p, bool s) {

	ID = i;
	Name = n;
	Capacity = c;
	Price = p;
	Sea = s;
}

void TRANSPORT::InitTrans() {

	Trans[0].SetTrans(0, "馬車", 50, 500, FALSE);
	Trans[1].SetTrans(1, "帆船", 200, 5000, TRUE);
	Trans[2].SetTrans(2, "大型馬車", 100, 1500, FALSE);
	Trans[3].SetTrans(3, "大型帆船", 300, 10000, TRUE);
	Trans[4].SetTrans(4, "トラック", 50, 500, FALSE);
	Trans[5].SetTrans(5, "蒸気船", 50, 500, TRUE);
	Trans[6].SetTrans(6, "大型トラック", 50, 500, FALSE);
	Trans[7].SetTrans(7, "大型蒸気船", 50, 500, TRUE);
}

void BUILDING::SetBuilding(int p, int m , int r) {

	Price = p;
	Maint = m;
	Rent = r;
}

//[街番号][0事務所 1倉庫 2工場]
//値段, 維持費, 家賃

void INIT::InitBuilding() {

	CityBuilding[0][0].SetBuilding(20000, 200, 1000);
	CityBuilding[0][1].SetBuilding(30000, 400, 1500);
	CityBuilding[0][2].SetBuilding(100000, 2000, 5000);
	CityBuilding[1][0].SetBuilding(20000, 200, 1000);
	CityBuilding[1][1].SetBuilding(20000, 200, 1000);
	CityBuilding[1][2].SetBuilding(20000, 200, 1000);
	CityBuilding[2][0].SetBuilding(20000, 200, 1000);
	CityBuilding[2][1].SetBuilding(20000, 200, 1000);
	CityBuilding[2][2].SetBuilding(20000, 200, 1000);
	CityBuilding[3][0].SetBuilding(20000, 200, 1000);
	CityBuilding[3][1].SetBuilding(20000, 200, 1000);
	CityBuilding[3][2].SetBuilding(20000, 200, 1000);
	CityBuilding[4][0].SetBuilding(20000, 200, 1000);
	CityBuilding[4][1].SetBuilding(20000, 200, 1000);
	CityBuilding[4][2].SetBuilding(20000, 200, 1000);
	CityBuilding[5][0].SetBuilding(20000, 200, 1000);
	CityBuilding[5][1].SetBuilding(20000, 200, 1000);
	CityBuilding[5][2].SetBuilding(20000, 200, 1000);
	CityBuilding[6][0].SetBuilding(20000, 200, 1000);
	CityBuilding[6][1].SetBuilding(20000, 200, 1000);
	CityBuilding[6][2].SetBuilding(20000, 200, 1000);
	CityBuilding[7][0].SetBuilding(20000, 200, 1000);
	CityBuilding[7][1].SetBuilding(20000, 200, 1000);
	CityBuilding[7][2].SetBuilding(20000, 200, 1000);
	CityBuilding[8][0].SetBuilding(20000, 200, 1000);
	CityBuilding[8][1].SetBuilding(20000, 200, 1000);
	CityBuilding[8][2].SetBuilding(20000, 200, 1000);
	CityBuilding[9][0].SetBuilding(20000, 200, 1000);
	CityBuilding[9][1].SetBuilding(20000, 200, 1000);
	CityBuilding[9][2].SetBuilding(20000, 200, 1000);
}