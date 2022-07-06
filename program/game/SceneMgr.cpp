#include "DxLib.h"
#include "Config.h"
#include "Game.h"
#include"Battle.h"
#include "Menu.h"
#include "SceneMgr.h"
#include"BaseScene.h"
#include"GameOver.h"
#include"OpeningScene.h"

//static eScene Scene = eScene_Menu;//シーン管理変数
//
//void SceneMgr_Update() {
//	//シーンによって処理を分岐現在の画面がメニューなら更新
//	switch (Scene) {
//	case eScene_Menu:
//		Menu_Update();
//		break;
//	case eScene_Game:
//		Game_Update();
//		break;
//	case eScene_Config:
//		Config_Update();
//		break;
//
//	}
//}
//
//void SceneMgr_Draw() {
//	//シーンによって処理を分岐現在の画面がメニューなら描画
//	switch (Scene) {
//	case eScene_Menu:
//		Menu_Draw();
//		break;
//	case eScene_Game:
//		Game_Draw();
//		break;
//	case eScene_Config:
//		Config_Draw();
//		break;
//	}
//}
//
//void SceneMgr_ChangeScene(eScene NextScene) {
//	Scene = NextScene;
//}

SceneManager::SceneManager()
{
	baseScene = new MenuScene();
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update(float deltatime)
{
	baseScene->Update(deltatime);

}

void SceneManager::Draw(float deltatime)
{
	baseScene->Draw(deltatime);
}

void SceneManager::ChangeScene(eScene nextScene)
{
	//今あるシーンのインスタンスの破棄
	if (baseScene != nullptr) {
		delete baseScene;
		baseScene = nullptr;
	}

	//シーンの切り替え 新しくインスタンスを生成し、ベースシーンポインタ変数に代入
	switch (nextScene) {
	case eScene_Menu:
		baseScene = new MenuScene();
		break;
	case eScene_Game:
		baseScene = new GameScene();
		break;
	case eScene_Battle :
		baseScene = new Battle();
		break;
	case eScene_Config:
		baseScene = new ConfigScene();
		break;
	case eScene_GameOver:
		baseScene = new GameOverScene();
		break;
	case eScene_Opening:
		baseScene = new OpeningScene();
		break;

	}

}
