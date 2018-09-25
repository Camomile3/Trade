#pragma once
#include "class.h"
#include "DxLib.h"

GOODS::GOODS(void){
	
	Name = "";
	Price = 0;
}

GOODS Goods[32];

void GOODS::SetGoods(char* n, int p) {
	Name = n;
	Price = p;
}

char* GOODS::GetGoodsName() {
	return (char*)Name;
}

int GOODS::GetGoodsPrice() {
	return Price;
}

void GOODS::PrintInfo() {
	printfDx("%s_%d", Name, Price);
}