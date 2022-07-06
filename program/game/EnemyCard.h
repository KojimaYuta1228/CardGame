#pragma once

class EnemyCard
{
public:
	EnemyCard();
	~EnemyCard();

	int draw1 = 0;
	int draw2 = 0;
	int draw3 = 0;
	int enemy = 0;
	int el = 0;
	int an = 0;
	int hu = 0;
	bool start = false;
	bool init = false;
	void Draw();
};
