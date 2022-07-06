#include "JankenCard.h"
#include"../dxlib_ext/dxlib_ext.h"

JankenCard::JankenCard(int Type)
{
	type_ = Type;

	//グーならグーの画像を読み込む
	if (type_ == 0) {
		gh = LoadGraph("graphics/hogehoge.png");
	}
	//チョキの画像を読み込む
	else if (type_ == 1) {
		gh = LoadGraph("graphics/hogehoge.png");
	}
	//パーの画像を読み込む
	else if (type_ == 2) {
		gh = LoadGraph("graphics/hogehoge.png");
	}


}

JankenCard::~JankenCard()
{
}

void JankenCard::Draw(int X, int Y)
{
	if (type_ == 0) {
		DrawRotaGraph(X, Y, 1, 0, gh, true);
	}
}
