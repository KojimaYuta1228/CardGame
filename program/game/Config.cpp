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

//更新
void ConfigScene::Update(float deltatime) {
	//escが押されたらシーンをメニューに変更
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_0)) {
		sceneManager->ChangeScene(SceneManager::eScene::eScene_Menu);
		return;
	}
	else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_1)) {
		sceneManager->ChangeScene(SceneManager::eScene::eScene_Game);
		return;
	}
}


//描画
void ConfigScene::Draw(float deltatime) {
	DrawRotaGraph(1024 / 2, 768 / 2, 1.5, 0, backGr, true);
	DrawRotaGraph(830, 200, 0.7, 0, type, true);
	SetFontSize(70);
	DrawStringEx(320, 0,0xFFD700, "せっていガ面");
	SetFontSize(50);
	DrawStringEx(0, 50,-1,"0:タイトルガ面");
	DrawStringEx(0, 100,-1,"1:ゲームガ面");
	SetFontSize(80);
	DrawStringEx(350, 160, 0xFF0000, "あそび方");
	SetFontSize(30);
	DrawStringEx(0, 250, 0xFAEBD7, "１，バトルが始まったら'←→キー'で出したいカードをエラぼう！！");
	DrawStringEx(0, 310, 0xFAEBD7, "２，手札が決まったら'Enterキー'けっていでしよう！！");
	DrawStringEx(0, 370, 0xFAEBD7, "３，先に相手のHPを0にしたほうがかちだよ！！(手札が0マイになってもまけだよ)");
	SetFontSize(80);
	DrawStringEx(280, 400, 0xFF0000, "カードのショウ介");
	SetFontSize(30);
	DrawStringEx(0, 510, 0xFAEBD7, "アリカード…“ヒト”にはカン単に倒されてしまうけど、どくで“ゾウ”をカン単にたおしてしまうよ");
	DrawStringEx(0, 570, 0xFAEBD7, "ヒトカード…“ゾウ”にはぺしゃんこにされてしまうけど、“アリ”をカン単にぺしゃんこするよ");
	DrawStringEx(0, 630, 0xFAEBD7, "ゾウカード…“アリ”には毒で倒されてしまうけど、“ヒト”をカン単にふみつぶしてしまうよ");
	DrawStringEx(0, 690, 0xFAEBD7, "？カード…何がおこるかわからない、何がおきてるかよく見てみよう");
	
	/*DrawRotaGraph(600, 550, 1.0, 0, el, true);
	DrawRotaGraph(700, 550, 1.0, 0, hu, true);
	DrawRotaGraph(600, 550, 1.0, 0, an, true);*/


}