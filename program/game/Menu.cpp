#include "Menu.h"
#include "SceneMgr.h"
#include"../dxlib_ext/dxlib_ext.h"
#include"Sound.h"

/*
//更新
void Menu_Update() {
	//1が押されたらシーンをゲーム画面に変更
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_1)) {
		SceneMgr_ChangeScene(eScene_Game);
	}
	
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_2)) {
		SceneMgr_ChangeScene(eScene_Config);
	}
	//
}

int chara = 0;
int tower = 0;
//描画
void Menu_Draw() {
	SetFontSize(50);
	DrawString(400, 25, "aaa", GetColor(255, 0, 0));
	DrawString(50, 100, "1:ゲーム画面", GetColor(255, 255, 255));
	DrawString(50, 150, "2:設定画面", GetColor(255, 255, 255));
	chara = LoadGraph(  "graphics/15768111792.png");
	DrawRotaGraph(50, 550, 1.0, 0, chara, true);
	//tower = LoadGraph("graphics/Tower.png");
	//DrawRotaGraph(500, 550, 1.0, 0, tower, true);

}
*/

extern SceneManager* sceneManager;

MenuScene::MenuScene()
{
	sound = new Sound();
	el = LoadGraph("graphics/elpa.png");
	chara = LoadGraph("graphics/pri.png");
	backCard = LoadGraph("graphics/cardBack.png");
	
	MenuSound();

	//titleBack = LoadGraph("graphics/titleBack.png");
}

MenuScene::~MenuScene()
{
	//StopSoundMem(sound->titleBgm);
	//deleteは最後
	sound->StopBgm();
	delete sound;
}
//音楽を再生
//BGMを再生/止めるときはupdateで行わない
void MenuScene::MenuSound()
{
	sound->SoundBgm(static_cast<uint32_t>(Sound::BGM::TITLE));
}

void MenuScene::Update(float deltatime)
{
	

	
	//1が押されたらシーンをゲーム画面に変更
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_1)) {
		sound->SoundSe(static_cast<uint32_t>(Sound::SE::CHANGE));
		sceneManager->ChangeScene(SceneManager::eScene::eScene_Game);
		return;
	}
	
	else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_2)) {

		sceneManager->ChangeScene(SceneManager::eScene::eScene_Config);
		return;
	}
	////if (!init) {
	//	sound_id = LoadSoundMem("sound/TitleBgm.mp3");
	//	//se_id = LoadSoundMem("sound/test_se.wav");
	//	init = true;
	//}
}

void MenuScene::Draw(float deltatime)

{
	SetFontSize(100);
	//DrawRotaGraph(500, 500, 1.0, 0, titleBack, true);

	LPCSTR font_path = "./graphics/font.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
	ChangeFont("Nikkyou Sans", DX_CHARSET_DEFAULT);
	DrawRotaGraph(600, 600, 1.0, 0, chara, true);
	DrawStringEx(270, 100, -1, "ムツキンワ“");
	SetFontSize(70);
	DrawStringEx(100, 300, -1, "1:ゲームスタート");
	DrawStringEx(100, 360, -1, "2:あそび方");
	//カードをめくるように見せる練習
	DrawExtendGraph(pY1, 200, pY2, 100, backCard, true);
	DrawExtendGraph(pX2, 100, pX1, 200, el, true);
	if (pY1 > pY2) {
		pX1+=1;
		pX2-=1;
		pY1-=1;
		pY2+=1;
	}
	//DrawRotaGraph(50, 550, 1.0, 0, chara, true);
	
	
}
