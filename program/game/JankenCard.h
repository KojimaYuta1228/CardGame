#pragma once

enum myHdcard {
	myGu,
	myChi,
	myPa,
};

class JankenCard
{
public:
	JankenCard(int Type);
	~JankenCard();

	//0:�O�[,1:�`���L,2:�p�[
	int type_ = 0;

	//�摜�n���h��
	int gh = 0;

	void Draw(int X,int Y);

};
