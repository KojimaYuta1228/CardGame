#pragma once
#include"BaseScene.h"

class OpeningScene :public BaseScene {

public:
	OpeningScene();
	~OpeningScene();

	void Update(float deltatime)override;

	void Draw(float deltatime)override;

	
	int i;

};