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
	int KInput, KInput1F, KInput2, KInput1F2;
	int OveredBtn = -1;
	int ButtonNumber;
	int SortX[16];
	int SortY[16];
	bool GoodsOn[16];
	bool BtnOn[64];
	int CargoNumber;
	int MWX,MWY;
	long long TempPrice;
	int TempNumber;

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
		//��������X
		Sw_CITY,
		Sw_BUY,
		Sw_BUY2,
		Sw_SALE,
		Sw_SALE2,
		Sw_INVEST,
		Sw_MANAGE,
		Sw_TALK,
		Sw_EXIT,
	};
	int BtnSwitch = Sw_TITLE;
public:
	bool DebugMode = TRUE;
	//���C���V�X�e��
	void ButtonOver();
	void ButtonSys();
	void DrawMessageWindow();
	void DrawWindow(int, int, int, int);
	void InitSys();
	void ResetButton();
	//�^�C�g��
	void DrawButton();
	void TitleBtnOver(int);
	void TitleBtnOverOut(int);
	void TitleBtnSys(int);
	void QuitBtnOver(int);
	void QuitBtnOut(int);
	void QuitBtnSys(int);
	void QuitBtnReset();
	//���C���}�b�v
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
	//�X
	void ResetCity();
	void CityBtnOver(int);
	void CityBtnOut(int);
	void CityBtnSys(int);
	void CityData();
	void BuyBtnOver(int);
	void BuyBtnOut(int);
	void BuyBtnSys(int);
	void DrawBuyWindow();
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
	int HiddenID[8];	//�X���b�g�ɓ����Ă�f�Օi��ID
	int Cargo[8];
	int CargoPrice[32];
	int CargoWeight;
	int MaxWeight;
	int WTech;
	int WIndustry;
};

class GOODS {
public:
	int ID;
	const char* Name;
	int Price;
	int CalcedPrice;

	void InitGoods();
	void SetGoods(int, char*, int);
};

class MARKET {
public:
	float Supply;
	float Demand;

	//�ŗL�l�@�i�C�@���v�@�����@�H��
	int CalcPrice(int, float, float, float, float);
	int SaleCalcPrice(int, float, float, float, float);
	void SetMarket(float, float);
};

class CITY {
public:
	int ID;
	const char* Name;
	int Type;
	int Population;
	float Develop;
	float Economy;
	float Technology;
	float Industry;
	float Infra;

	void SetCity(int, int, const char*, int, float, float, float, float, float);
	void InitCity();
};