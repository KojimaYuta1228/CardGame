#pragma once
#include"BaseScene.h"
////çXêV
//void Game_Update();
//
////ï`âÊ
//void Game_Draw();

class Battle;
class Enemy;

class GameScene :public BaseScene
{
public:

	int enemy1 = 0;
	/*const int ANIM_TYPE_UP = 0;
	const int ANIM_TYPE_DOWN = 1;
	const int ANIM_TYPE_RIGHT = 2;
	const int ANIM_TYPE_LEFT = 3;
	const int ANIM_TYPE_MAX = 4;

	const int ANIM_FRAME_MAX = 4;*/
	float anim_time_count = 0;
	int anim_frame = 0;
	int anim_type = 0;
	int gfx_hdl[2][4] = { 0 };
	int sympEn1 = 0;
	int backGround = 0;

	

	float pos_x = 100.0f;
	float pos_y = 600.0f;
	float speed = 3.0f;

	Battle* battle = nullptr;
	Enemy* enemy = nullptr;

	GameScene();
	~GameScene();

	void Update(float deltatime)override;

	void Draw(float deltatime)override;

	void changeBattle();

	void Sound_hd();


};


