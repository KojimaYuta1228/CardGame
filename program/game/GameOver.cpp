#include"GameOver.h"
#include "SceneMgr.h"
#include"../dxlib_ext/dxlib_ext.h"

extern SceneManager* sceneManager;





GameOverScene::GameOverScene()
{
	back = LoadGraph("graphics/GameOver.jpg");
	srand(time(0));

	int random = rand() % 5;

	drawMessage = MESSAGE[random];
}

GameOverScene::~GameOverScene()
{



}

void GameOverScene::Update(float deltatime)
{
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_Q)) {
		sceneManager->ChangeScene(SceneManager::eScene::eScene_Game);
		return;
	}

}

void GameOverScene::Draw(float deltatime)
{



	SetFontSize(150);
	DrawRotaGraph(1024 / 2, 768 / 2, 1.5, 0, back, true);
	DrawStringEx(70, 150, -1, "GAME OVER");
	SetFontSize(80);
	DrawStringEx(50, 400, 0, "'Qキー'を押して再スタートDA☆");
	DrawStringEx(50, 300, 0, drawMessage.c_str());

	/*if (!rad) {
		sel = rand() % 4 + 1;
		rad = true;
		if (sel == 1) {
			DrawStringEx(50, 300, 0, "運がNAかったようだ...");
			rad = false;
			return;
		}
		else if (sel == 2) {
			DrawStringEx(50, 300, 0, "じゃんけん王への道は遠い...");
			rad = false;
			return;
		}
		else if (sel == 3) {
			DrawStringEx(50, 300, 0, "また負けてしまった...");
			rad = false;
			return;
		}
		else if (sel == 4) {
			DrawStringEx(50, 300, 0, "これは、せんりゃくてきてったい...");
			rad = false;
			return;
		}
	}*/

}
