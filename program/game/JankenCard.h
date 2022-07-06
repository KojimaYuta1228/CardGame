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

	//0:グー,1:チョキ,2:パー
	int type_ = 0;

	//画像ハンドル
	int gh = 0;

	void Draw(int X,int Y);

};
