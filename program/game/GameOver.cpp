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
	DrawStringEx(50, 400, 0, "'Q�L�['�������čăX�^�[�gDA��");
	DrawStringEx(50, 300, 0, drawMessage.c_str());

	/*if (!rad) {
		sel = rand() % 4 + 1;
		rad = true;
		if (sel == 1) {
			DrawStringEx(50, 300, 0, "�^��NA�������悤��...");
			rad = false;
			return;
		}
		else if (sel == 2) {
			DrawStringEx(50, 300, 0, "����񂯂񉤂ւ̓��͉���...");
			rad = false;
			return;
		}
		else if (sel == 3) {
			DrawStringEx(50, 300, 0, "�܂������Ă��܂���...");
			rad = false;
			return;
		}
		else if (sel == 4) {
			DrawStringEx(50, 300, 0, "����́A�����Ⴍ�Ă��Ă�����...");
			rad = false;
			return;
		}
	}*/

}
