#include "JankenCard.h"
#include"../dxlib_ext/dxlib_ext.h"

JankenCard::JankenCard(int Type)
{
	type_ = Type;

	//�O�[�Ȃ�O�[�̉摜��ǂݍ���
	if (type_ == 0) {
		gh = LoadGraph("graphics/hogehoge.png");
	}
	//�`���L�̉摜��ǂݍ���
	else if (type_ == 1) {
		gh = LoadGraph("graphics/hogehoge.png");
	}
	//�p�[�̉摜��ǂݍ���
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
