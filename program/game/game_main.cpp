#include "DxLib.h"
#include"SceneMgr.h"

//typedef enum {
//	eScene_Menu,//���j���[���
//	eScene_Game,//�Q�[�����
//	eScene_Config,//�ݒ���
//}eScene;
//
//static int Scene = eScene_Menu;  //���݂̃V�[��

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
	//UpdateScene();//�V�[�����X�V


}
//�V�[�����X�V����
//void UpdateScene() {
//	DrawString(0, 20, "1�ŃQ�[���X�^�[�g�A�Q�Őݒ�A3�Ń��j���[��ʁB", GetColor(255, 255, 255));
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

//���j���[���
//void Menu() {
//	DrawString(0, 0, "���j���[���", GetColor(255, 255, 255));
//}
////�Q�[�����
//void Game() {
//	DrawString(0, 0, "�Q�[�����", GetColor(255, 255, 255));
//}
////�ݒ���
//void Config() {
//	DrawString(0, 0, "�ݒ���", GetColor(255, 25, 255));
//}

//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
//	////�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
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
//	UpdateScene();//�V�[�����X�V
//
//
//	return 0;
//}