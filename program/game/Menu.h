#pragma once
#include"BaseScene.h"

//XV
void Menu_Update();

//•`‰æ
void Menu_Draw();

class Sound;

class MenuScene :public BaseScene
{
public:
	MenuScene();
	~MenuScene();

	void MenuSound();

	void Update(float deltatime)override;

	void Draw(float deltatime)override;
	
	Sound* sound = nullptr;

	int chara = 0;
	int backCard = 0;
	int titleBack = 0;
	int el = 0;
	int pX1 = 150;
	int pY1 = 200;
	int pX2 = 150;
	int pY2 = 100;
	int title_se = 0;
	int se_id = 0;
	/*int sound_id = 0;
	int se_id = 0;*/
	bool init = false;
	
	//soundŒn
	int sound1 = 0;
	bool sound_hd = false;
};

