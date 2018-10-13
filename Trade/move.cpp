#include "class.h"
#include "DxLib.h"

extern HEROINE her;
extern FUN fun;
extern INIT init;


void SYSTEM::MoveRoute() {
	switch (her.On) {
	case 0:
		switch (OveredBtn) {
		case 1:
			Move(1);
			her.On = 1;
			break;
		case 2:
			Move(1);
			Move(12);
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(20);
			her.OnShip = TRUE;
			Move(21);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			Move(10);
			Move(11);
			Move(4);
			her.On = 4;
			break;
		case 5:
			Move(10);
			Move(11);
			Move(4);
			Move(13);
			Move(5);
			her.On = 5;
			break;
		case 6:
			Move(10);
			Move(11);
			Move(4);
			Move(14);
			Move(15);
			Move(6);
			her.On = 6;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 1:
		switch (OveredBtn) {
		case 0:
			Move(0);
			her.On = 0;
			break;
		case 2:
			Move(12);
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(0);
			Move(20);
			her.OnShip = TRUE;
			Move(21);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			Move(0);
			Move(10);
			Move(11);
			Move(4);
			her.On = 4;
			break;
		case 5:
			Move(0);
			Move(10);
			Move(11);
			Move(4);
			Move(13);
			Move(5);
			her.On = 5;
			break;
		case 6:
			Move(0);
			Move(10);
			Move(11);
			Move(4);
			Move(14);
			Move(15);
			Move(6);
			her.On = 6;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(0);
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(0);
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(0);
			Move(20);
			her.OnShip = TRUE;
			Move(23);
			Move(24);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 2:
		switch (OveredBtn) {
		case 0:
			Move(12);
			Move(1);
			Move(0);
			her.On = 0;
			break;
		case 1:
			Move(12);
			Move(1);
			her.On = 1;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(30);
			her.OnShip = TRUE;
			Move(31);
			Move(35);
			Move(36);
			Move(37);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			Move(13);
			Move(4);
			her.On = 4;
			break;
		case 5:
			Move(13);
			Move(5);
			her.On = 5;
			break;
		case 6:
			Move(13);
			Move(4);
			Move(14);
			Move(15);
			Move(6);
			her.On = 6;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(30);
			her.OnShip = TRUE;
			Move(31);
			WarpHer(32);
			Move(33);
			Move(34);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(30);
			her.OnShip = TRUE;
			Move(31);
			WarpHer(32);
			Move(33);
			Move(34);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(30);
			her.OnShip = TRUE;
			Move(31);
			WarpHer(32);
			Move(33);
			Move(34);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 3:
		switch (OveredBtn) {
		case 0:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(21);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			her.On = 0;
			break;
		case 1:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(21);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(37);
			Move(36);
			Move(35);
			Move(31);
			Move(30);
			her.OnShip = FALSE;
			Move(2);
			her.On = 2;
			break;
		case 4:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(21);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			Move(10);
			Move(11);
			Move(4);
			her.On = 4;
			break;
		case 5:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(37);
			Move(36);
			Move(35);
			Move(31);
			Move(43);
			Move(42);
			Move(41);
			Move(40);
			her.OnShip = FALSE;
			Move(5);
			her.On = 5;
			break;
		case 6:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(25);
			Move(39);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			her.On = 6;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(25);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(22);
			her.OnShip = TRUE;
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 4:
		switch (OveredBtn) {
		case 0:
			Move(11);
			Move(10);
			Move(0);
			her.On = 0;
			break;
		case 1:
			Move(11);
			Move(10);
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			Move(13);
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(11);
			Move(10);
			Move(0);
			Move(20);
			her.OnShip = TRUE;
			Move(21);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 5:
			Move(13);
			Move(5);
			her.On = 5;
			break;
		case 6:
			Move(14);
			Move(15);
			Move(6);
			her.On = 6;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(14);
			Move(15);
			Move(6);
			Move(38);
			her.OnShip = TRUE;
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(14);
			Move(15);
			Move(6);
			Move(38);
			her.OnShip = TRUE;
			Move(39);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(14);
			Move(15);
			Move(6);
			Move(38);
			her.OnShip = TRUE;
			Move(39);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 5:
		switch (OveredBtn) {
		case 0:
			Move(13);
			Move(4);
			Move(11);
			Move(10);
			Move(0);
			her.On = 0;
			break;
		case 1:
			Move(13);
			Move(4);
			Move(11);
			Move(10);
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			Move(13);
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(40);
			her.OnShip = TRUE;
			Move(41);
			Move(42);
			Move(43);
			Move(31);
			Move(35);
			Move(36);
			Move(37);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			Move(13);
			Move(4);
			her.On = 5;
			break;
		case 6:
			Move(13);
			Move(4);
			Move(14);
			Move(15);
			Move(6);
			her.On = 6;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(40);
			her.OnShip = TRUE;
			Move(41);
			Move(42);
			Move(44);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(40);
			her.OnShip = TRUE;
			Move(41);
			Move(42);
			Move(44);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(40);
			her.OnShip = TRUE;
			Move(41);
			Move(42);
			Move(44);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 6:
		switch (OveredBtn) {
		case 0:
			Move(15);
			Move(14);
			Move(4);
			Move(11);
			Move(10);
			Move(0);
			her.On = 0;
			break;
		case 1:
			Move(15);
			Move(14);
			Move(4);
			Move(11);
			Move(10);
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			Move(15);
			Move(14);
			Move(4);
			Move(13);
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(38);
			her.OnShip = TRUE;
			Move(39);
			Move(25);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			Move(15);
			Move(14);
			Move(4);
			her.On = 4;
			break;
		case 5:
			Move(15);
			Move(14);
			Move(4);
			Move(13);
			Move(5);
			her.On = 5;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(38);
			her.OnShip = TRUE;
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(38);
			her.OnShip = TRUE;
			Move(39);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(38);
			her.OnShip = TRUE;
			Move(39);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 7:
		switch (OveredBtn) {
		case 0:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(25);
			Move(24);
			Move(23);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			her.On = 0;
			break;
		case 1:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(34);
			Move(33);
			Move(32);
			WarpHer(31);
			Move(30);
			her.OnShip = FALSE;
			Move(2);
			Move(12);
			Move(1);
			her.On = 1;
			break;
		case 2:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(34);
			Move(33);
			Move(32);
			WarpHer(31);
			Move(30);
			her.OnShip = FALSE;
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(34);
			Move(33);
			Move(45);
			WarpHer(35);
			Move(36);
			Move(37);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			Move(15);
			Move(14);
			Move(4);
			her.On = 4;
			break;
		case 5:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(44);
			Move(42);
			Move(41);
			Move(40);
			her.OnShip = FALSE;
			Move(5);
			her.On = 5;
			break;
		case 6:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			her.On = 6;
			break;
		case 8:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			her.On = 8;
			break;
		case 9:
			if (her.HaveShip == FALSE)
				return;
			Move(27);
			her.OnShip = TRUE;
			Move(26);
			Move(25);
			Move(28);
			Move(29);
			her.OnShip = FALSE;
			Move(8);
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 8:
		switch (OveredBtn) {
		case 0:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(26);
			Move(24);
			Move(23);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			her.On = 0;
			break;
		case 1:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(24);
			Move(23);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(34);
			Move(33);
			Move(32);
			WarpHer(31);
			Move(30);
			her.OnShip = FALSE;
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(39);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			Move(15);
			Move(14);
			Move(4);
			her.On = 4;
			break;
		case 5:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(44);
			Move(42);
			Move(41);
			Move(40);
			her.OnShip = FALSE;
			Move(5);
			her.On = 5;
			break;
		case 6:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(39);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			her.On = 6;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(26);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 9:
			Move(16);
			Move(9);
			her.On = 9;
			break;
		}
		break;
	case 9:
		switch (OveredBtn) {
		case 0:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(26);
			Move(24);
			Move(23);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			her.On = 0;
			break;
		case 1:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(24);
			Move(23);
			Move(20);
			her.OnShip = FALSE;
			Move(0);
			Move(1);
			her.On = 1;
			break;
		case 2:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(34);
			Move(33);
			Move(32);
			WarpHer(31);
			Move(30);
			her.OnShip = FALSE;
			Move(2);
			her.On = 2;
			break;
		case 3:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(25);
			Move(22);
			her.OnShip = FALSE;
			Move(3);
			her.On = 3;
			break;
		case 4:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(39);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			Move(15);
			Move(14);
			Move(4);
			her.On = 4;
			break;
		case 5:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(44);
			Move(42);
			Move(41);
			Move(40);
			her.OnShip = FALSE;
			Move(5);
			her.On = 5;
			break;
		case 6:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(39);
			Move(38);
			her.OnShip = FALSE;
			Move(6);
			her.On = 6;
			break;
		case 7:
			if (her.HaveShip == FALSE)
				return;
			Move(16);
			Move(8);
			Move(29);
			her.OnShip = TRUE;
			Move(28);
			Move(26);
			Move(26);
			Move(27);
			her.OnShip = FALSE;
			Move(7);
			her.On = 7;
			break;
		case 8:
			Move(16);
			Move(8);
			her.On = 8;
			break;
		}
		break;
	}
	CalcMarket();
	SetHerPrices(OveredBtn);
	Fade(init.GraMap, init.GraCity, "City1");
	fun.FStat = fun.F_CITY;
	BtnSwitch = Sw_CITY;
	InitSys();
	ResetCity();
}