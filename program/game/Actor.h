#pragma once

class JankenCard;

class Actor
{
public:
	Actor();
	virtual~Actor() {};

	enum JANKEN
	{
		GUU,
		CHOKI,
		PAH,
		MAX
	};

	//int hoge[JANKEN::MAX] = {};

	JankenCard* hand[3] = {};

	void Draw();

};

