#include "Config.h"
#include "SceneMgr.h"
#include "../dxlib_ext/dxlib_ext.h"

extern SceneManager* sceneManager;

ConfigScene::ConfigScene()
{
	el = LoadGraph("graphics/elpa.png");
	hu = LoadGraph("graphics/huma.png");
	an = LoadGraph("graphics/ant.png");
	backGr = LoadGraph("graphics/backGr.jpg");
	type = LoadGraph("graphics/type.png");
}
ConfigScene::~ConfigScene()
{

}

//�X�V
void ConfigScene::Update(float deltatime) {
	//esc�������ꂽ��V�[�������j���[�ɕύX
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_0)) {
		sceneManager->ChangeScene(SceneManager::eScene::eScene_Menu);
		return;
	}
	else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_1)) {
		sceneManager->ChangeScene(SceneManager::eScene::eScene_Game);
		return;
	}
}


//�`��
void ConfigScene::Draw(float deltatime) {
	DrawRotaGraph(1024 / 2, 768 / 2, 1.5, 0, backGr, true);
	DrawRotaGraph(830, 200, 0.7, 0, type, true);
	SetFontSize(70);
	DrawStringEx(320, 0,0xFFD700, "�����Ă��K��");
	SetFontSize(50);
	DrawStringEx(0, 50,-1,"0:�^�C�g���K��");
	DrawStringEx(0, 100,-1,"1:�Q�[���K��");
	SetFontSize(80);
	DrawStringEx(350, 160, 0xFF0000, "�����ѕ�");
	SetFontSize(30);
	DrawStringEx(0, 250, 0xFAEBD7, "�P�C�o�g�����n�܂�����'�����L�['�ŏo�������J�[�h���G���ڂ��I�I");
	DrawStringEx(0, 310, 0xFAEBD7, "�Q�C��D�����܂�����'Enter�L�['�����Ă��ł��悤�I�I");
	DrawStringEx(0, 370, 0xFAEBD7, "�R�C��ɑ����HP��0�ɂ����ق�����������I�I(��D��0�}�C�ɂȂ��Ă��܂�����)");
	SetFontSize(80);
	DrawStringEx(280, 400, 0xFF0000, "�J�[�h�̃V���E��");
	SetFontSize(30);
	DrawStringEx(0, 510, 0xFAEBD7, "�A���J�[�h�c�g�q�g�h�ɂ̓J���P�ɓ|����Ă��܂����ǁA�ǂ��Łg�]�E�h���J���P�ɂ������Ă��܂���");
	DrawStringEx(0, 570, 0xFAEBD7, "�q�g�J�[�h�c�g�]�E�h�ɂ͂؂���񂱂ɂ���Ă��܂����ǁA�g�A���h���J���P�ɂ؂���񂱂����");
	DrawStringEx(0, 630, 0xFAEBD7, "�]�E�J�[�h�c�g�A���h�ɂ͓łœ|����Ă��܂����ǁA�g�q�g�h���J���P�ɂӂ݂Ԃ��Ă��܂���");
	DrawStringEx(0, 690, 0xFAEBD7, "�H�J�[�h�c���������邩�킩��Ȃ��A���������Ă邩�悭���Ă݂悤");
	
	/*DrawRotaGraph(600, 550, 1.0, 0, el, true);
	DrawRotaGraph(700, 550, 1.0, 0, hu, true);
	DrawRotaGraph(600, 550, 1.0, 0, an, true);*/


}