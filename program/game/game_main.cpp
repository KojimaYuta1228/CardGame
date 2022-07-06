#include "DxLib.h"
#include"SceneMgr.h"

//typedef enum {
//	eScene_Menu,//メニュー画面
//	eScene_Game,//ゲーム画面
//	eScene_Config,//設定画面
//}eScene;
//
//static int Scene = eScene_Menu;  //現在のシーン

bool init = false;
SceneManager* sceneManager = nullptr;

void gameMain(float delta_time) {

	if (init == false) {

		sceneManager = new SceneManager();
		init = true;
	}

	sceneManager->Update(delta_time);

	sceneManager->Draw(delta_time);

	/*switch (Scene)
	{

	case eScene_Menu:
		Menu();
		break;
	case eScene_Game:
		Game();
		break;
	case eScene_Config:
		Config();
		break;
	}*/

	/*
	SceneMgr_Update();
	SceneMgr_Draw();

	*/
	//UpdateScene();//シーンを更新


}
//シーンを更新する
//void UpdateScene() {
//	DrawString(0, 20, "1でゲームスタート、２で設定、3でメニュー画面。", GetColor(255, 255, 255));
//	if (CheckHitKey(KEY_INPUT_1) != 0) {
//		Scene = eScene_Game;
//	}
//	if (CheckHitKey(KEY_INPUT_2) != 0) {
//		Scene = eScene_Config;
//	}
//	if (CheckHitKey(KEY_INPUT_3) != 0) {
//		Scene = eScene_Menu;
//	}
//}

//メニュー画面
//void Menu() {
//	DrawString(0, 0, "メニュー画面", GetColor(255, 255, 255));
//}
////ゲーム画面
//void Game() {
//	DrawString(0, 0, "ゲーム画面", GetColor(255, 255, 255));
//}
////設定画面
//void Config() {
//	DrawString(0, 0, "設定画面", GetColor(255, 25, 255));
//}

//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
//	////ウィンドウモード変更と初期化と裏画面設定
//	//ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
//
//	while (ScreenFlip() == 0 && ProcessMessage() && ClearDrawScreen() == 0) {
//		switch (Scene)
//		{
//
//		case eScene_Menu:
//			Menu();
//			break;
//		case eScene_Game:
//			Game();
//			break;
//		case eScene_Config:
//			Config();
//			break;
//		}
//
//	}
//	UpdateScene();//シーンを更新
//
//
//	return 0;
//}