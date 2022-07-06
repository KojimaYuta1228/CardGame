#include "enemy.h"
#include "../dxlib_ext/dxlib_ext.h"




Enemy::Enemy(int type)
{
	enemy_type_ = type;
	
	if (type == Enemy1) {
		imgEnemy1 = LoadGraph("graphics/enemy1.png");
		back1 = LoadGraph("graphics/Battle1.jpg");
		enHp = 100;
		maxHp = 100;
	}
	else if (type == Enemy2) {
		imgEnemy2 = LoadGraph("graphics/enemy2.png");
		back2 = LoadGraph("graphics/Battle2");
		enHp = 30;
		maxHp = 30;
	}
	else if (type == Enemy3) {
		imgEnemy3 = LoadGraph("graphics/enemy3.png");
		back3 = LoadGraph("graphics/Battle3");
		enHp = 1000;
		maxHp = 1000;
	}
}

Enemy::~Enemy()
{
}



void Enemy::enemyHp()
{
}

void Enemy::enemyDraw()
{
	if (enemy_type_ == Enemy1) {
		DrawRotaGraph(1024/2, 768/2, 1.5, 0, back1, true);
		//DrawExtendGraph
		DrawRotaGraph(200, 200, 3.0, 0, imgEnemy1, true);
	}
	else if (enemy_type_ == Enemy2) {
		DrawRotaGraph(1024 / 2, 768 / 2, 1.5, 0, back2, true);
		DrawRotaGraph(200, 200, 3.0, 0, imgEnemy2, true);
	}
	else if (enemy_type_ == Enemy3) {
		DrawRotaGraph(1024 / 2, 768 / 2, 1.5, 0, back3, true);
		DrawRotaGraph(200, 200, 3.0, 0, imgEnemy3, true);
	}
}
