#pragma once
#include<string>
#include"BaseScene.h"

class GameOverScene :public BaseScene {

public:
	GameOverScene();
	~GameOverScene();

	void Update(float deltatime) override;

	void Draw(float deltatime) override;

	int back = 0;
	int sel = 0;

	bool rad = false;


	const std::string MESSAGE[5] = {"これは、せんりゃくてきてったい...","しゅぎょうしろ！","hogehoge","あばばば","ひーはー"};

	std::string drawMessage = "";
};


//リスタート