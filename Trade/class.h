#pragma once
#include <string>

class INIT {
public:
	int FontHandle;
	int WinX;
	int WinY;
	int GraT;
	int GraBtn, GraBtn2, GraBtn3;
	int GraMW;
	int GraMap;
	int GraCity;
	int GraHer;
	int GraCalender, GraGold, GraIdea, GraFactory;
	int GraCarriage[12];
	int GraShip[12];
	void SetFont();
	void LoadGra();
	void ResetTitle();
	void InitMarket();
	void Cargo();
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
	int BtnX[64], BtnY[64], BtnW[64], BtnH[64], BtnCx[64], BtnCy[64];
	int MouseX, MouseY;
	int MInput,MInput1F;
	int OveredBtn = -1;
	int ClickedBtn = -1;
	int ButtonNumber = 64;
	int SortX[16];
	int SortY[16];
	bool GoodsOn[16];
	bool BtnOn[64];
	int CargoNumber;
	int MWX,MWY;
	long long TempPrice;
	int TempNumber;
	int TalkNumber = 0;
	int ETalkCount = 0;
	int SlotNumber;
	TCHAR CommedValue[64];

	double Angle, Angle2;
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
		Sw_QUEST,
		Sw_PRICES,
		Sw_PRICES2,
		//ここから街
		Sw_CITY,
		Sw_BUY,
		Sw_BUY2,
		Sw_SALE,
		Sw_SALE2,
		Sw_INVEST,
		Sw_MANAGE,
		Sw_TALK,
		Sw_TALK2,
		Sw_EXIT,
	};
	int BtnSwitch = Sw_TITLE;
public:
	bool DebugMode = TRUE;
	bool EventFlag[128];
	int EventSwitch;
	int EventNumber;

	//メインシステム
	void ButtonOver();
	void ButtonSys();
	void DaySys();
	void DrawMessageWindow();
	void DrawWindow(int, int, int, int);
	void InitSys();
	void ResetButton();
	void ResetBtnOn();
	char* AddComma(int);
	void WaitClick();
	void WaitYesNo();
	void SearchEmpty(int);
	void SetTwoBtn();
	void SetFullBtn();
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
	void DrawValue();
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
	void QuestBtnOver(int);
	void QuestBtnOut(int);
	void QuestBtnSys(int);
	void QuestData();
	void PricesBtnOver(int);
	void PricesBtnOut(int);
	void PricesBtnSys(int);
	void PricesData();
	void PricesData2(int);
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
	void InitHer();
	void SpawnHer();
	void Move(int);
	void MoveRoute();
	void WarpHer(int);
	//街
	void SetHerPrices(int);
	void ResetCity();
	void ResetTalk();
	void CityBtnOver(int);
	void CityBtnOut(int);
	void CityBtnSys(int);
	void CityData();
	void BuyBtnOver(int);
	void BuyBtnOut(int);
	void BuyBtnSys(int);
	void DrawBuyString();
	void BuyData();
	void BuySys(int);
	void BuySort(int);
	void SaleBtnOver(int);
	void SaleBtnOut(int);
	void SaleBtnSys(int);
	void SaleData();
	void SaleSys(int);
	void SaleSort(int);
	void InvestBtnOver(int);
	void InvestBtnOut(int);
	void InvestBtnSys(int);
	void InvestData();
	void ManageBtnOver(int);
	void ManageBtnOut(int);
	void ManageBtnSys(int);
	void ManageData();
	void TalkBtnOver(int);
	void TalkBtnOut(int);
	void TalkBtnSys(int);
	void TalkData();
	void Event(int);
	void ExitBtnOver(int);
	void ExitBtnOut(int);
	void ExitBtnSys(int);
};

class HEROINE {
public:
	double X, Y;
	int On;
	int Year, Month, Day;
	long long Money;
	int HiddenID[8];	//スロットに入ってる貿易品のID
	int Cargo[8];
	int CargoPrice[32];
	int CargoWeight;
	int MaxWeight;
	int ShipWeight;
	int ShipMaxWeight;
	int MoveSpeed;
	int ShipMoveSpeed;
	int WTech;
	int WIndustry;
	bool HaveShip = FALSE;
	bool OnShip = FALSE;
};

class GOODS {
public:
	int ID;
	const char* Name;
	int BasePrice;
	double IndImpact;
	double TechImpact;
	int BaseProd;
	double IndProdImpact;
	double TechProdImpact;
	double IndSizeImpact;
	double TechSizeImpact;

	int CalcedPrice;
	int CalcedProd;
	int CalcedSize;

	void InitGoods();
	//ID　名前　基本値　工業影響度　技術影響度　生産基本値　工業生産影響度　技術生産影響度　工業市場規模影響度　技術市場規模影響度
	void SetGoods(int, char*, int, double, double, int, double, double, double, double);
};

class MARKET {
public:
	double Supply;
	double Demand;

	//基本値　倍率　景気　需要　供給　工業　工業影響度　技術　技術影響度　開発度　インフラ
	int CalcPrice(int, double, double, double, double, double, double, double, double, double);
	int SaleCalcPrice(int, double, double, double, double, double, double, double, double, double);

	//品物基本値　品物係数　人口　開発度　技術　技術生産影響度　インフラ　供給　需要　工業　工業生産影響度
	int CalcProduction(int, int);
	int CalcMarketSize(int, int);
	void SetMarket(double, double);
};

class CITY {
public:
	int ID;
	const char* Name;
	const char* Type;
	double Population;
	double Develop;
	double Economy;
	double Technology;
	double Industry;
	double Infra;

	void SetCity(int, const char*, const char*, double, double, double, double, double, double);
	void InitCity();
};