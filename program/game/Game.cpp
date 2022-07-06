#include "Game.h"
#include "SceneMgr.h"
#include"Battle.h"
#include"../dxlib_ext/dxlib_ext.h"
#include "enemy.h"
#include"Sound.h"


extern SceneManager* sceneManager;

GameScene::GameScene()
{
	/*LoadDivGraph("graphics/c1_anim_up.png", 4, 4, 1, 128 / 4, 48, gfx_hdl[ANIM_TYPE_UP]);*/
	//LoadDivGraph("graphics/c1_anim_down.png", 4, 4, 1, 128 / 4, 48, gfx_hdl[ANIM_TYPE_DOWN]);
	LoadDivGraph("graphics/c1_anim_right.png", 4, 4, 1, 128 / 4, 48, gfx_hdl[0]);
	LoadDivGraph("graphics/c1_anim_left.png", 4, 4, 1, 128 / 4, 48, gfx_hdl[1]);
	backGround = LoadGraph("graphics/backGround.jpg");
	sympEn1 = LoadGraph("graphics/sympEn1.png");

	
}
GameScene::~GameScene()
{

}
//�X�V
void GameScene::Update(float deltatitme) {
	//esc�������ꂽ��V�[�������j���[�ɕύX
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_0)) {
		sceneManager->ChangeScene(SceneManager::eScene::eScene_Menu);
		return;
	}
	 else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_2)) {
		sceneManager->ChangeScene(SceneManager::eScene::eScene_Config);
		return;
	}
	//�v���C���[������̈ʒu�ɗ�����Battle�V�[���ւ̈ړ�
	if (pos_x >= 500) {
		sceneManager->ChangeScene(SceneManager::eScene_Battle);
		return;
	}
	

	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
		pos_x += speed;
		anim_type = 0;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
		pos_x -= speed;
		anim_type = 1;
	}

	//battle->hogehoge();





}



//�`��
void GameScene::Draw(float deltatime) {
	
	//�w�i

	DrawRotaGraph(1024/2, 768/2, 1.5, 0, backGround, true);
	//�G�̖��Ȃǂ̉摜 
	
	DrawRotaGraph(700,600,1.0,0,sympEn1,true);
	SetFontSize(50);
	DrawStringEx(0, 0, 0, "0:�^�C�g�����߂�");
	DrawStringEx(0, 70, 0, "2:�����Ă����߂�");
	
	
	anim_time_count += deltatime;
	if (0.25f < anim_time_count) {
		anim_time_count = 0;
		anim_frame++;
		anim_frame %= 4;
	}
	
	DrawRotaGraph(pos_x, pos_y, 2.0f, 0, gfx_hdl[anim_type][anim_frame], true);
}

void GameScene::changeBattle()
{
	
}

void GameScene::Sound_hd()
{
	

}




