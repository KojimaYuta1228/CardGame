#pragma once
#include"Battle.h"

enum EnemyType {
	Enemy1,
	Enemy2,
	Enemy3
};

static int enemy_type_ = Enemy1;


class Enemy
{
public:
		Enemy(int type);
	~Enemy();
	/*int enemy1 = 0;
	int enemy2 = 0;
	int enemy3 = 0;*/
	int imgEnemy1 = 0;
	int imgEnemy2 = 0;
	int imgEnemy3 = 0;
	int enHp = 2;
	int maxHp = 0;
	int back1 = 0;
	int back2 = 0;
	int back3 = 0;
	
	//“G‚ÌHP‚ÌŠÇ—
	void enemyHp();

	void enemyDraw();
};