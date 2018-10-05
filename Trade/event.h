#pragma once
#include "class.h"
#include "DxLib.h"

extern INIT init;

void SYSTEM::EventFunc(const char* Name, const char* string) {

	ResetCity();
	DrawStringToHandle(MWX + 64 + 32, MWY + 64 - 16, Name, GetColor(255, 255, 255), init.FontHandle);
	DrawStringToHandle(MWX + 64 + 32, MWY + 64 + 16, string, GetColor(255, 255, 255), init.FontHandle);
	WaitClick();
}

void SYSTEM::EventFunc2(const char* Name, const char* string, const char* string2) {

	ResetCity();
	DrawStringToHandle(MWX + 64 + 32, MWY + 64 - 16, Name, GetColor(255, 255, 255), init.FontHandle);
	DrawStringToHandle(MWX + 64 + 32, MWY + 64 + 16, string, GetColor(255, 255, 255), init.FontHandle);
	DrawStringToHandle(MWX + 64 + 32, MWY + 64 + 16 + 32, string2, GetColor(255, 255, 255), init.FontHandle);
	WaitClick();
}

void SYSTEM::EventMessage(const char* string) {

	ResetCity();
	DrawStringToHandle(MWX + 64 + 32, MWY + 64, string, GetColor(255, 255, 255), init.FontHandle);
	WaitClick();
}

void SYSTEM::EventEnd(int Num) {

	ETalkCount = 0;
	EventFlag[Num] = FALSE;
	Stopper = TRUE;
	BtnSwitch = Sw_CITY;
	ResetCity();
}

void SYSTEM::Event(int Num) {

	switch (Num) {

	case 0:
		switch (ETalkCount) {
		case 0:
			//ヒロイン　リネット
			//幼馴染ユリシーズ　主人公→ユリ　家族等→リス
			//雨のなか墓の前に無言で佇む主人公
			//無言で去る
			//場面転換
			EventFunc("リネット", "お父さん、死んじゃった・・・");
			EventFunc("リネット", "残ったのは馬車だけ・・・");
			EventFunc("リネット", "ユリ・・・これからどうしたらいいのかな・・・");
			EventFunc("ユリ", "・・・");
			EventFunc("リネット", "お母さんも体が悪いし、私が頑張らないと・・・");
			EventFunc("ユリ", "無理したら駄目だよ。");
			EventFunc("ユリ", "今は疲れてるんだ。");
			EventFunc("リネット", "そうね・・・ありがとう。");
			//場面転換
			EventFunc("リネット", "貿易するわよ！");
			EventFunc("ユリ", "はぁ！？");
			EventFunc("リネット", "簡単なことだったのよ！");
			EventFunc("リネット", "お父さんの仕事を継げばいいんだわ！");
			EventFunc("ユリ", "いやいやそんなこと言ったって");
			EventFunc("リネット", "大丈夫！少しだけ手伝ったこともあるから！");
			EventFunc("ユリ", "貿易っていったって買って売るだけじゃないんだよ！？");
			EventFunc("ユリ", "きちんと書類なんかも作成しないといけないし。");
			EventFunc("ユリ", "・・・まさか。");
			EventFunc("リネット", "ユリ出来るでしょ？");
			EventFunc("リネット", "ちょうど仕事もないわよね？");
			EventFunc("ユリ", "ちょうどってなんだよ！ないけどさ！");
			EventFunc("リネット", "いいでしょ？");
			EventFunc("ユリ", "・・・わかった、やるよ。");
			EventFunc("ユリ", "やるからには容赦しないからな。");
			EventFunc("リネット", "な、なによ容赦って。");
			EventFunc("ユリ", "腐ってもリネットが社長だからね、最低限のことは覚えてもらわないと俺も巻き添えだ。");
			EventFunc("リネット", "巻き添えって・・・");
			EventFunc("ユリ", "容赦しないってこうゆうことだよ、俺も生活がかかってるからね。");
			EventFunc("リネット", "・・・わかったわよ、やってやるわ。");
			EventFunc("リネット", "なんでもきなさい、私だって覚悟があるわ。");
			EventFunc("ユリ", "よし、契約成立だ。よろしくお願いしますよ、社長？");
			EventFunc("リネット", "冗談やめてよ気色悪い。リネットでいいわ。");
			EventFunc("ユリ", "容赦しないって言っただろ？");
			//場面転換
			EventFunc("リネット", "じゃあ行くわよ。");
			EventFunc("ユリ", "行くってどこに？");
			EventFunc("リネット", "決まってるじゃない、市場よ。");
			EventFunc("ユリ", "そんないきなり・・・");
			EventFunc("リネット", "貿易ルートは調査済みよ。");
			EventFunc("リネット", "ここで西洋贅沢品を買って[街の名前]で売ればいいわ。");
			EventFunc("ユリ", "いつの間に！？");
			EventFunc("リネット", "ほら行くわよ。");
			//チュートリアル演出
			//Purchase誘導
			//西洋贅沢品誘導
			//半角で数字を入力してEnterを押してください
			EventFunc("リネット", "買えたわね。じゃあ[街の名前]まで出発！");
			EventFunc("ユリ", "大丈夫かな･･･");
			//移動後
			EventFunc("リネット", "市場はこっちよ！");
			//sale誘導
			//西洋贅沢品誘導
			//購入時と同じようにしてn個売却してください。
			EventFunc("リネット", "よし、これで利益が・・・あれ？");
			EventFunc("リネット", "何で買ったときより手持ちが減ってるの・・・？");
			EventFunc("ユリ", "帳簿を付けておいてよかった。");
			EventFunc("ユリ", "これを見て。");
			//財務チュートリアル
			EventFunc("リネット", "帳簿？これに答えが書いてあるのね？");
			EventFunc("ユリ", "その通り。こことここ、経費が売り上げを上回ってる。");
			EventFunc("リネット", "え？じゃあもっと儲かる貿易路を探さないといけないの？");
			EventFunc("ユリ", "いや、結論から言うと馬車が一杯になるぐらい貿易品を積み込めばいい。");
			EventFunc("ユリ", "変動費と固定費って言うんだけど説明する？");
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn();

			DrawStringToHandle(BtnX[62], BtnY[62], "してほしい", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[63], BtnY[63], "結論だけで十分", GetColor(255, 255, 255), init.FontHandle);
			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc2("ユリ", "変動費っていうのは売れば売るほど増える経費のことだよ。", "色々あるけど仕入れ費用が代表かな。");
				EventFunc2("ユリ", "固定費は商売をしなくてもかかる経費のことだ。", "俺たちの月給とか馬の餌代、その他各種維持費なんかがこれだね。");
				EventFunc("ユリ", "この固定費を賄えるように積み荷を一杯積む必要があるんだ。");
				EventFunc("リネット", "でも一杯積み荷を積んだらその、変動費も増えるんじゃない？");
				EventFunc2("ユリ", "確かにそうだけど、費用全体の固定費の割合は下がる。", "そして、変動費の割合は変わらないんだ。");
				EventFunc("リネット", "ああ！それなら結果的に商品1個あたりにかかる経費が実質安くなるのね！");
				EventFunc2("ユリ", "その通り。今は商品1個あたりの経費が上回ってる状態だから、", "それを解消するために事業を拡大する必要があるんだ。");
			}
			else if (EventSwitch == 63) {
				EventFunc2("ユリ", "そうだね、やることは変わらない。", "事業を拡大すればいい。");

				EventEnd(Num);

			}
			ETalkCount++;
		case 2:
			EventFunc("リネット", "でもそんなお金どこにも・・・");
			EventFunc("ユリ", "借りるしかないだろうね。");
			EventFunc("リネット", "銀行ね。でも貸してくれるかしら？");
			EventFunc("ユリ", "うーん･･･行くだけ行ってみようか。");
			EventMessage("1時間後");
			EventFunc("ユリ", "駄目だったね･･･");
			EventFunc("リネット", "どうするの！？いきなり倒産はいやだわ！");
			EventFunc("ユリ", "俺の両親をあたってみよう。");
		//クエストチュートリアル
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			break;
		}

		break;
	case 1:
		switch (ETalkCount) {
		case 0:
		EventFunc("リネット", "調子はどう？");
		EventFunc("工場長", "社長じゃないですか、ぼちぼちですよ。");
		EventFunc("リネット", "そのわりには利益が出ていないようだけど？");
		EventFunc("工場長", "あー、それがですね。設備の調子が悪くて生産が落ち込んでるんです。");
		EventFunc("リネット", "修理はできないの？");
		EventFunc("工場長", "出来るには出来るんですが元が取れそうにないんです。");
		EventFunc("リネット", "新しい設備を導入したらどれぐらいで元が取れる？");
		EventFunc("工場長", "3年はかかりますね・・・");
		ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn();

			DrawStringToHandle(MWX + 64 + 32, MWY + 64, "じゃあ・・・", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[62], BtnY[62], "設備投資するわ", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[63], BtnY[63], "そのまま頑張って", GetColor(255, 255, 255), init.FontHandle);
			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc("工場長", "いいんですか？それは助かります。");
				EventFunc("工場長", "直ちに必要な書類を作成して事務所のほうに送りますね。");
/*
備品増加
負債増加

減価償却費100,000　備品500,000
現金　　　300,000
備品売却損100,000

備品　1,500,000　未払金1,500,000
*/
				EventEnd(Num);
			}
			else if (EventSwitch == 63) {
				EventFunc("工場長", "わかりました、これからも良いものを作りますよ！");
			
				EventEnd(Num);

			}
			break;
		}
		break;
	case 2:
		//不景気時
		switch (ETalkCount) {
		case 0:
			EventFunc("リネット", "最近不景気ね。");
			EventFunc("ユリ", "こればっかりはしょうがないな、景気には波がある。");
			EventFunc("リネット", "景気が悪いときでもどこかに儲かる話は転がってそうだけど。");
			EventFunc("ユリ", "そんなうまい話・・・");
			EventFunc("街の男", "お願いします！nレイルでいいんで！");
			EventFunc("商人", "だめだめ、今の景気じゃ買っても捌けないよ。");
			EventFunc("リネット", "あったわね？");
			EventFunc("リネット", "ちょっといいかしら？何を買っても捌けないって？");
			EventFunc2("街の男", "あなた商人ですか！？お願いします！aをnレイルでi個買ってください！", "もう売るあてが無いんです！");
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn();

			DrawStringToHandle(BtnX[62], BtnY[62], "買う", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[63], BtnY[63], "買わない", GetColor(255, 255, 255), init.FontHandle);
			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc("街の男", "ほんとですか！ありがとうございます！");
				//いろいろ処理
				EventEnd(Num);
			}
			else if (EventSwitch == 63) {
				EventFunc("街の男", "そうですか・・・他をあたります・・・");

				EventEnd(Num);

			}
			break;
		}
		break;
	case 3:
		//条件未定
		switch (ETalkCount) {
		case 0:
			EventFunc("リネット", "ようやく会社らしくなってきたわね。");
			EventFunc("ユリ", "そうだね、これからもっと大きくなるよ。");
			EventFunc("ユリ", "そのためにも利益をあげなきゃね。");
			EventFunc("リネット", "情報を集めましょう、市場に行くわよ。");
			//暗転
			//背景変更
			EventFunc("市場の人", "そういえば新しく機織り工場が出来るんだってな、知ってたか？");
			EventFunc("市場の人", "なんでも機械でぶわーって作るらしいんだけどな。");
			EventFunc("市場の人", "俺は端正込めて作られた工房の服が好きだな。");
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn();

			DrawStringToHandle(MWX + 64 + 32, MWY + 64, "工場ね・・・", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[62], BtnY[62], "行ってみる", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[63], BtnY[63], "興味無い", GetColor(255, 255, 255), init.FontHandle);

			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {

				EventFunc("リネット", "ちょっと見てこようかしら。");
				//暗転
				EventFunc("営業担当", "ようこそいらっしゃいました。");
				EventFunc2("営業担当", "当社工場ではお得意様を募集中でして、", "小売店様から大船団様まで幅広くご契約いただいております。");
				EventFunc("営業担当", "まずは商品をご覧いただけますか？");
				//暗転のみ
				EventFunc("リネット", "丈夫な服ね、デザインは気に入らないけど。");
				EventFunc2("リネット", "需要は十分ありそうだわ。", "条件は？");
				//条件提示
				EventFunc("営業担当", "いかがいたしますか？");
				ETalkCount++;
		case 2:
			Stopper = TRUE;
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn();

			DrawStringToHandle(BtnX[62], BtnY[62], "契約する", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[63], BtnY[63], "契約しない", GetColor(255, 255, 255), init.FontHandle);

			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc("営業担当", "ありがとうございます、ではこちらにサインを。");

				EventEnd(Num);
			}
			else if (EventSwitch == 63) {
				EventFunc("営業担当", "わかりました、ご縁がありましたらそのときはよろしくお願いします。");

				EventEnd(Num);
			}
			}
			else if (EventSwitch == 63) {
				EventFunc("市場の人", "そうだろ？やっぱり手作りだよな！");

				EventEnd(Num);

			}
			break;
		}
		break;
	case 4:
		switch (ETalkCount) {
		case 0:
			//工業一定以下
			//技術一定以上

			//市場にて

			//効果音
			//それっぽい背景
			EventFunc("リネット", "いい服ね、どこのものかしら。");
			EventFunc("店主", "お客さんお目が高いね。");
			EventFunc("店主", "これはローラット工房の品だ。");
			EventFunc("ユリ", "でも・・・高いね。");
			EventFunc2("店主", "ああ、品はいいんだがなかなか売れないんだよな。", "仕入れを取り止めようかと思うぐらいだ。");
			EventFunc("ユリ", "・・・");
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn();

			DrawStringToHandle(BtnX[62], BtnY[62], "これ試着できるかしら？", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[63], BtnY[63], "こっちの工場製の服を買うわ。", GetColor(255, 255, 255), init.FontHandle);

			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}
			if (EventSwitch == 63) {
				EventFunc("店主", "まいど！そちらも似合うと思いますよ。");
				EventEnd(Num);
			}
			else if (EventSwitch == 62) {

				EventFunc("店主", "もちろん。そこを使ってくれ。");
				//暗転
				EventFunc("リネット", "どう？");
				EventFunc("ユリ", "似合う！似合うよリネット！");
				EventFunc("店主", "ああ、よく似合ってる。");
				EventFunc("リネット", "気に入ったわ、これくださる？");
				//暗転
				//背景転換
				EventFunc("ユリ", "ごめんくださーい。");
				//効果音
				EventFunc("ローラット夫人", "あらあら。お客さんかしら、どんなご用件？");
				EventFunc("ユリ", "実はこの工房の");
				EventFunc("ローラット夫人", "あら！それうちの服ね！わざわざ挨拶にきてくれたのね！上がって上がって！お茶を淹れてくるわね！");
				EventFunc("ユリ", "いやその");
				EventFunc("リネット", "お邪魔します。");
				//暗転
				EventFunc("ローラット夫人", "それでうちの旦那がね―――");
				EventFunc("リネット", "それは―――");
				EventFunc("ユリ", "ははは・・・");
				//効果音
				EventFunc("ローラット", "客か。");
				EventFunc("ローラット夫人", "そうなのよ！うちの服が気に入ってわざわざ―――");
				EventFunc("ローラット", "あんた商人だな？");
				EventFunc("ローラット夫人", "え？");
				EventFunc("リネット", "ええ、この工房の服を仕入れたいの。");
				EventFunc("ローラット", "仕入れたところで買い手がいないだろう。");
				EventFunc("ローラット", "高くて売れないからともうどこも仕入れやしない。");
				EventFunc("ローラット", "一体何を企んでる？");
				EventFunc("リネット", "私はこの工房の服が気に入っただけよ。");
				EventFunc("リネット", "こんな素敵な服が世に出ないのは惜しい。");
				EventFunc("ローラット", "だから仕入れるって？それで売れるなら苦労はしない。");
				EventFunc("リネット", "勝算ならあるわ。");
				EventFunc("ローラット", "何？");
				EventFunc("リネット", "設備投資させて。単価を下げれば必ず売れるわ。");
				EventFunc("ローラット", "馬鹿馬鹿しい。オモチャで俺の服が作れるか。");
				EventFunc("リネット", "作れるわ。この国の技術は素晴らしい。");
				EventFunc("リネット", "最高の機械職人が一杯いる。");
				EventFunc("リネット", "もちろんローラットさんの全面的な協力が必要になるけど。");
				EventFunc("ローラット", "・・・わかったよ。どうせこのままじゃ店じまいだ、最後に賭けてみるのも悪くない。");
				EventFunc("ローラット", "負けても損するのは投資したあんただけだ。");
				EventFunc("リネット", "その通りよ。じゃあこれが契約書。");
				EventFunc("ローラット", "ほらよ。さて、最後に一頑張りするか。");
				EventFunc("リネット", "最後じゃないわ。");
				EventFunc("ローラット", "何？");
				EventFunc("リネット", "これから始まるのよ。");
				//初期投資処理
				//数ヶ月後に結果が出る
				EventEnd(Num);
			}
		}
		break;
	case 5:
		switch (ETalkCount) {
		case 0:
			EventFunc("街の男","よう、そこの嬢ちゃん。あんた商人だろ？ちょっと頼まれてくれや。");
			EventFunc("リネット", "内容によるわ。");
			EventFunc("街の男","なに、ちょっとこいつを買い取って欲しいのさ。");
			EventFunc("リネット", "これは・・・");
			EventFunc("ユリ","良い織物だ。でもなんでこれを？");
			EventFunc("街の男","得意先が倒れちまってな、売る当てが無いんだ。");
			EventFunc("街の男","一箱70レイルで300箱だ、悪くない話だろ？");
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn();

			DrawStringToHandle(MWX + 64 + 32, MWY + 64 , "どうする？", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[62], BtnY[62], "買う", GetColor(255, 255, 255), init.FontHandle);
			DrawStringToHandle(BtnX[63], BtnY[63], "買わない", GetColor(255, 255, 255), init.FontHandle);
			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc("リネット", "わかった、一箱65レイルでどう？");
				EventFunc("街の男","68だ。それ以上はまけないぞ。");
				EventFunc("リネット", "交渉成立ね。小切手でいいかしら？");
				EventFunc("街の男","ああ、20400レイルきっちりいただいたぜ。ありがとうな。");
				EventFunc("リネット", "こちらこそ、良い取引ができてよかったわ。また会いましょう。");

				SearchEmpty(16);
				her.CargoPrice[SlotNumber] += 20400;
				her.Cargo[SlotNumber] += 300;
				her.Money -= 20400;
				her.CargoWeight += 300;
				her.HiddenID[SlotNumber] = 16;

				EventEnd(Num);
			}
			else if (EventSwitch == 63) {
				EventFunc("リネット", "ごめんなさい、今は余裕がないの。他をあたってちょうだい。");
				EventFunc("街の男","そうか、悪かったな無理言って。縁があったらそのときはよろしくな。");
				EventFunc("リネット", "こちらこそよろしく。また会いましょう。");
				
				EventEnd(Num);

			}
			break;
		}
		break;
	case 6:

		//年数一定以上？
		//ユリシーズ過去回
		//技術一定

		//馬車がガタゴト効果音
		EventFunc("リネット", "すぅ・・・すぅ・・・");
		EventFunc("ユリ", "相変わらずよく寝るな、まるで子供みたいに。");
		EventFunc("ユリ", "出逢ったときからそうだったな・・・");
		//暗転
		//背景転換
		//セピアから少しずつ色付く
		EventFunc2("ユリシーズ", "こんなもんか、一休みしていくかな。", "あの木の陰とかちょうどよさそうだ。");
		EventFunc("ユリシーズ", "あれ？あんなところに置物が・・・");
		EventFunc("ユリシーズ", "いや、人だ！人が倒れてる！");
		//駈け足効果音
		EventFunc("少女", "すぅ・・・すぅ・・・");
		EventFunc("ユリシーズ", "なんだ・・・寝てるだけか。");
		EventFunc("ユリシーズ", "おい、そんなところで寝てると悪魔に襲われちゃうぞ。");
		EventFunc("少女", "ぅんう？");
		EventFunc("少女", "あなただぁれ？");
		EventFunc("ユリシーズ", "俺はユリシーズ。リスって呼んで―――");
		EventFunc("少女", "わたしリネット！ユリシーズだからユリって呼ぶね！");
		EventFunc("ユリ", "え・・・まあいいか。");
		EventFunc("リネット", "よろしくね！ユリ！");
		EventFunc("リネット", "ユリもここがお気に入りなの？");
		EventFunc("ユリ", "いや、学校の課題で植物を調べていたんだ。");
		EventFunc("リネット", "なんだ・・・ここが好きなわけじゃないんだ・・・");
		EventFunc("ユリ", "そんなことないよ、初めて来たけどいいところだ。気に入ったよ。");
		EventFunc("リネット", "えへへ。そうよね！こっちに来て！すごく景色がいいの！");
		EventFunc("ユリ", "あ、おい！");
		//暗転
		//夕方
		EventFunc("リネット", "あ、もうこんな時間、早く帰らないとお父さんに怒られちゃうわ。");
		EventFunc("リネット", "ユリのおうちはどっち？");
		EventFunc("ユリ", "ガラス工房の近くだよ。");
		EventFunc("リネット", "結構近いじゃない！今度遊びに行くね！");
		EventFunc("ユリ", "本当？じゃあ、母さんに言っておかないとな。");
		EventFunc("リネット", "えへへ。楽しみね、じゃあ一緒に帰りましょ！");
		//暗転
		//夕方の街
		EventFunc("リネット", "お父さんただいまー！");
		EventFunc("リネット父", "お帰りリネット。お友達かい？");
		EventFunc("リネット", "そうなの！ユリっていうんだよ！");
		EventFunc("ユリ", "ユリシーズといいます。");
		EventFunc("リネット父", "ユリシーズか。リスじゃないのかい？");
		EventFunc("ユリ", "えーと・・・");
		EventFunc("リネット", "ユリはユリだよ？変なお父さん。");
		EventFunc("リネット父", "ははは！そうかユリか。よろしくなユリ。");
		EventFunc("ユリ", "はい、よろしくお願いします。");
		EventFunc("リネット父", "もう遅い、送っていくよ。");
		EventFunc("ユリ", "いえそんな・・・");
		//スズムシ的な効果音
		EventFunc("ユリ", "わかりました、じゃあお言葉に甘えて。");
		//暗転
		EventFunc("リネット父", "ユリは将来何になるのかな？");
		EventFunc2("ユリ", "大学に行って勉強しようと思います。", "そして人の役に立つことをしたいです。");
		EventFunc("リネット父", "大学か！そいつは大きく出たな。");
		EventFunc("リネット父", "頑張れよ。並大抵のことではないからな。");
		EventFunc("ユリ", "はい。");
		//足音
		EventFunc("ユリ", "あ、ここです。");
		EventFunc("リネット父", "よし、挨拶していくか。");
		//ノック音
		//ドア音
		EventFunc("ユリ母", "どなた？");
		EventFunc2("リネット父", "私はユリシーズ君の友達の父です。", "遅かったので送らせてもらいました。");
		EventFunc("ユリ母", "あらあら。わざわざありがとうございます。");
		EventFunc("ユリ", "母さんただいま。");
		EventFunc("ユリ母", "おかえりなさい、リス。夕飯できてるわよ。");
		EventFunc("リネット父", "では私はこのへんで。");
		EventFunc("ユリ母", "はい、お気をつけて。");
		//ドア音
		EventFunc("ユリ", "母さんあのね―――");
		//暗転
		//馬車ガタゴト
		//馬が止まる感じの音
		EventFunc("ユリ", "リネット、着いたよ。");
		EventFunc("リネット", "ぅんう？あら、寝ちゃってたのね。");
		EventFunc("ユリ", "ふふっ。");
		EventFunc("リネット", "何よ？");
		EventFunc("ユリ", "何でもないよ。ちょっと昔のことを思い出してただけだ。");
		EventFunc2("リネット", "？", "まあいいわ。さ、行くわよ。");
		EventFunc("ユリ", "ああ、今回も大変そうだ。");
		break;
	}
}