#pragma once
#include"BaseScene.h"
//�X�V
void Config_Update();

//�`��
void Config_Draw();


class ConfigScene:public BaseScene
{
public:
	ConfigScene();
	~ConfigScene();
	
	int el = 0;
	int an = 0;
	int hu = 0;
	int backGr = 0;
	int type = 0;
	void Update(float deltatime)override;

	void Draw(float deltatime)override;

};

