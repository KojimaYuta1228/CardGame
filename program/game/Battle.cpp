#include "SceneMgr.h"
#include "Battle.h"
#include"JankenCard.h"
#include "enemy.h"
#include"Animation.h"
#include "../dxlib_ext/dxlib_ext.h"

extern SceneManager* sceneManager;

Battle::Battle()
{
	el = LoadGraph("graphics/elpa.png");
	hu = LoadGraph("graphics/huma.png");
	an = LoadGraph("graphics/ant.png");
	sup = LoadGraph("graphics/spC.png");
	backCard = LoadGraph("graphics/cardBack.png");
	type = LoadGraph("graphics/type.png");
	resHpber = LoadGraph("graphics/restHp.png");
	empHpber = LoadGraph("graphics/emptyHp.png");
	//slash = LoadGraph("graphics/Tower.png");

	LoadDivGraph("graphics/slashFix.png", 10, 10, 1, 192, 192, gh_slash);
	//LoadDivGraph("graphics/shine.png", 36, 6, 6, 48, 56, gfx_hd1[1]);

	LoadDivGraph("graphics/shineFix.png", 10, 10, 1, 192, 192, gh_shine);

	LoadDivGraph("graphics/fire.png", 10, 1, 10, 640, 528, gh_fire);

	srand(time(0));
	enemy = new Enemy(enemy_type_);
	/*for (int i = 0; i < 3; ++i) {
		jankenCard = new JankenCard(i);
	}*/
}

Battle::~Battle()
{
}


void Battle::handContller()
{

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LEFT) && pos > 1) {
		pos -= 1;

	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RIGHT) && pos < 4) {
		pos += 1;

	}


}

void Battle::enemyHand()
{
	if (!init) {
		while (enGu > 0 || enChi > 0 || enPa > 0)
		{

			enHd = rand() % 3 + 1;

			if ((enHd == 1 && enGu > 0)) {
				enGu -= 1;

				break;
			}
			else if ((enHd == 2 && enChi > 0)) {
				enChi -= 1;

				break;
			}
			else if ((enHd == 3 && enPa > 0)) {
				enPa -= 1;

				break;
			}
		}

		init = true;
	}

	/*else if (enHd == 1 && myHd == 4) {
		enHd == 4;
		spC -= 1;
	}
	else if (enHd == 2 && myHd == 4) {
		enHd == 4;
		spC -= 1;
	}
	else if (enHd == 3 && myHd == 4) {
		enHd == 4;
		spC -= 1;
	}*/


}


void Battle::handDecide(float deltatime)
{
	if (!canSelect)return;
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN))//4種類のカードを選択
	{
		if ((pos == 4)) {
			if (spC <= 0)return;
			//myHd = 4;
			//サポート関数
			suport();
			return;
		}

		if ((pos == 1)) {
			if (gu <= 0)return;//早期return
			myHd = 1;
			gu -= 1;

		}
		else if ((pos == 2)) {
			if (chi <= 0)return;
			myHd = 2;
			chi -= 1;
		}
		else if ((pos == 3)) {
			if (pa <= 0)return;
			myHd = 3;
			pa -= 1;
		}


		enemyHand();
		res = janken(myHd, enHd);
		start = true;
		result(deltatime);
		card_key = false;
		return_card = false;
		card_back = false;

		//カードを選べなくする
		canSelect = false;

	}

	/*if (start == true) {
		timeCounter += deltatime;
		if (timeCounter > 0.1f)reStart();
	}*/

}


void Battle::result(float deltatime)
{
	Animation* newAnim = nullptr;
	if (res == 0) {

		newAnim = new Animation("graphics/fire.png", 11, 1, 11, 640, 480, 512, 384);
		liveAnim.emplace_back(newAnim);

		myHp -= 0;
		enemy->enHp -= 0;
	}
	else if (res == 1) {
		//Animation* newAnim = nullptr;
		//じゃんけん結果によって相手にダメージを与えたい
		switch (myHd)
		{
		case 1://グーが勝ったとき
			newAnim = new Animation("graphics/fire.png", 11, 1, 11, 640, 480, 200, 200);
			liveAnim.emplace_back(newAnim);

			enemy->enHp -= 5;
			break;
		case 2://チーが勝ったとき

			newAnim = new Animation("graphics/fire.png", 11, 1, 11, 640, 480, 200, 200);
			liveAnim.emplace_back(newAnim);
			enemy->enHp -= 3;

			break;
		case 3://パーが勝ったとき

			newAnim = new Animation("graphics/fire.png", 11, 1, 11, 640, 480, 200, 200);
			liveAnim.emplace_back(newAnim);
			enemy->enHp -= 1;

			break;
		}
	}
	else  if (res == 2) {

		//じゃんけん結果によって相手にダメージを与えられたい
		switch (enHd)
		{
		case 1://グーが勝ったとき
			newAnim = new Animation("graphics/fire.png", 11, 1, 11, 640, 480, 512, 600);
			liveAnim.emplace_back(newAnim);

			myHp -= 5;
			break;
		case 2://チーが勝ったとき

			newAnim = new Animation("graphics/fire.png", 11, 1, 11, 640, 480, 512, 600);
			liveAnim.emplace_back(newAnim);
			myHp -= 3;
			break;
		case 3://パーが勝ったとき

			newAnim = new Animation("graphics/fire.png", 11, 1, 11, 640, 480, 512, 600);
			liveAnim.emplace_back(newAnim);
			myHp -= 1;
			break;
		}
	}

	init = false;


}


//問題点
void Battle::reStart()
{
	if ((tnl::Input::IsKeyDownTrigger(eKeys::KB_K))) {
		res -= 1;
		start = false;
		enter = true;
		timeCounter = 0;
	}
}


/*void Battle::damage()
{
	if ((gu == enGu) || (chi == enChi) || (pa == enPa)) {
		myHp -= 0;
		enHp -= 0;
	}
	//else if (myHd > enHp) {//じゃんけん結果によって相手にダメージを与えたい
	switch ((gu == enChi) || (chi == enPa) || (pa == enGu))
	{
	case 1://グーが勝ったとき
		enHp -= 5;
		break;
	case 2://チーが勝ったとき
		enHp -= 3;
		break;
	case 3://パーが勝ったとき
		enHp -= 1;
		break;
	}
	//}else if(myHd < enHd)

	//じゃんけん結果によって相手にダメージを与えられたい
	switch ((gu == enPa) || (chi == enGu) || (pa == enChi))
	{
	case 1://グーが勝ったとき
		myHp -= 5;
		break;
	case 2://チーが勝ったとき
		myHp -= 3;
		break;
	case 3://パーが勝ったとき
		myHp -= 1;
		break;
	}
}*/

void Battle::battleResult()
{
	myAll = (gu + chi + pa);
	enAll = (enGu + enPa + enChi);
	if ((myHp <= 0) || ((myHp > 0 && enemy->enHp > 0) && (myAll <= 0 && enAll <= 0))) {
		SetFontSize(150);
		DrawStringEx(200, 300, 0x000099, "YOU Lose");

	}
	else if (enemy->enHp <= 0) {
		SetFontSize(150);
		DrawStringEx(200, 300, 0xCC0033, "YOU Win");

	}


}

int Battle::janken(int player, int enemy_)
{
	if (player == enemy_)return DRAW;
	if (player == GU && enemy_ == ENCHI) return WIN;
	if (player == CHI && enemy_ == ENPA) return WIN;
	if (player == PA && enemy_ == ENGU) return WIN;
	//if (player == SP && enemy_ == ENSP)return SPCARD;

	return LOSE;
}

int Battle::card()
{
	return 0;
}

int Battle::suport()
{
	//spカード
	if (!suIn) {
		sp = rand() % 7 + 1;
		suIn = true;
		if (sp == 1 && spC >= 0) {
			myHp += 3;
			spC -= 1;
		}
		else if (sp == 2 && spC >= 0) {
			enemy->enHp += 3;
			spC -= 1;
		}
		else if (sp == 3 && spC >= 0) {
			myHp -= 2;
			spC -= 1;
		}
		else if (sp == 4 && spC >= 0) {
			enemy->enHp -= 2;
			spC -= 1;
		}
		else if ((sp == 5 && spC >= 0) && (pa > 0 || enChi > 0)) {
			pa -= 1;
			enChi -= 1;
			spC -= 1;
		}
		else if ((sp == 6 && spC >= 0) && (gu > 0 || enPa > 0)) {
			gu -= 1;
			enPa -= 1;
			spC -= 1;
		}
		else if ((sp == 7 && spC >= 0) && (chi > 0 || enGu > 0)) {
			chi -= 1;
			enGu -= 1;
			spC -= 1;
		}
		suIn = false;
	}

	return 0;
}

void Battle::roll_card()
{
	//bool return_card = false;
	//bool card_key = false;

	//最初から表示されるカードのX座標
	//int CposX1 = 600;
	//int CposX2 = 750;

	//選ばれた手によって表示されるX座標
	//int CposX3 = 675;
	//int CposX4 = 675;
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		card_back = true;
	}


	if (card_back == true) {
		//裏面を閉じる処理
		if (return_card == false) {
			CposX2 -= 2;
			CposX1 += 2;
			/*CposX4++;
			CposX3--;*/

			if (CposX1 >= CposX2) {
				return_card = true;
				card_key = true;
			}
		}
		//カード裏の再展開
		if (card_key == true) {
			CposX2 += 2;
			CposX1 -= 2;
			/*CposX3++;
			CposX4--;*/
			//足され続けないようにする
			if (CposX2 == 750) {
				card_key = false;
			}
		}
	}
}

bool Battle::timelimit(const float deltatime)
{
	count -= deltatime;
	if (count <= 0) {
		//count = 0;
		return true;
	}
	return false;
}



//aaaaaa

void Battle::Update(float deltatime) {

	//タイムリミットが来たら
	if (timelimit(deltatime)) {

		//ゲームオーバー
		sceneManager->ChangeScene(SceneManager::eScene_GameOver);
		return;

	}
	handContller();

	handDecide(deltatime);

	//アニメーションの更新
	for (auto anim : liveAnim) {
		//アニメーションが終わっていれば
		if (anim->UpdateAnimation(deltatime)) {
			//手が選べるようにする
			canSelect = true;
		}
	}


	//再生し終わったアニメーションがあったらリストから消してdeleteする

	//リストの一番最初の要素に矢印(イテレータ)を置く
	auto itr = liveAnim.begin();
	//リストのすべての要素に対して検索する
	for (int i = 0; i < liveAnim.size(); ++i) {
		//リストが空だったらfor文を抜ける
		if (liveAnim.empty())break;
		//もしイテレータが指しているアニメーションのisLiveがfalseなら(アニメーション再生が終わっていれば)
		if ((*itr)->isLive == false) {
			//中身のアニメーションのメモリを開放する
			delete (*itr);
			//リストからそのアニメーションを排除してイテレータを次の要素に移す
			itr = liveAnim.erase(itr);
		}
		else {
			//もし生きているアニメーションを指していれば次の要素にイテレータを移す
			itr++;
		}
	}

	battleResult();
	myAll = (gu + chi + pa);
	enAll = (enGu + enPa + enChi);
	//(myHp <= 0 || enemy->enHp <= 0) ||
	if ((myHp <= 0 || enemy->enHp <= 0) || ((myHp > 0 && enemy->enHp > 0) && (myAll <= 0 && enAll <= 0))) {
		time_count += deltatime;
	}
	if (time_count > 3.0f) {
		if ((enemy->enHp <= 0)) {
			enemy_type_ += 1;
			delete enemy;
			enemy = nullptr;
			sceneManager->ChangeScene(SceneManager::eScene_Game);
			return;
		}
		else if ((myHp <= 0)) {
			sceneManager->ChangeScene(SceneManager::eScene_GameOver);
			return;
		}
		else if ((myHp > 0 && enemy->enHp > 0) && (myHd > 0 && enHd > 0)) {
			sceneManager->ChangeScene(SceneManager::eScene_GameOver);
			return;
		}
	}
}
void Battle::Draw(float deltatime) {
	enemy->enemyDraw();
	roll_card();
	DrawRotaGraph(100, 600, 0.7, 0, el, true);
	DrawRotaGraph(225, 600, 0.7, 0, hu, true);
	DrawRotaGraph(350, 600, 0.7, 0, an, true);
	DrawRotaGraph(500, 600, 3.1, 0, sup, true);



	//   if (pos == 4) {
	   //DrawRotaGraph(700, 600, 3.1, 0, sup, true);
	   //}else if(pos == 1) {	
	   //DrawRotaGraph(700, 600, 0.7, 0, el, true);
	   //}
	   //else if (pos == 2) {
	   //DrawRotaGraph(700, 600, 0.7, 0, hu, true);
	   //}
	   //else if (pos == 3) {
	   //DrawRotaGraph(700, 600, 0.7, 0, an, true);
	   //}

	DrawRotaGraph(1024 / 2, 80, 0.3, 0, type, true);
	DrawStringEx(pos * 100 + 25, 700, 0x0000FF, "↑");



	if (!card_back) {
		DrawExtendGraph(CposX2, 300, CposX1, 100, backCard, true);
	}


	if (!return_card) {
		//カードの裏面
		DrawExtendGraph(CposX2, 300, CposX1, 100, backCard, true);
	}
	else {
		//カードの表面
		if (enHd == 1) {

			DrawExtendGraph(CposX2, 300, CposX1, 100, el, true);

		}
		else if (enHd == 2) {

			DrawExtendGraph(CposX2, 300, CposX1, 100, hu, true);

		}
		else if (enHd == 3) {

			DrawExtendGraph(CposX2, 300, CposX1, 100, an, true);

		}
	}
	//DrawExtendGraph(CposX2, 300, CposX1, 100, backCard, true);

	/*if (CposX2 > CposX1) {

		if (enHd == 1) {

			DrawExtendGraph(CposX4, 300, CposX3, 100, el, true);
			CposX2--;
			CposX1++;
			CposX4++;
			CposX3--;

			if  (CposX4 < CposX3){
				CposX2++;
				CposX1--;
				CposX4--;
				CposX3++;

			}
		}
		else if (enHd == 2) {

			DrawExtendGraph(CposX4, 300, CposX3, 100, hu, true);
			CposX2--;
			CposX1++;
			CposX4++;
			CposX3--;
			if (CposX4 < CposX3){
				CposX2++;
				CposX1--;
				CposX4--;
				CposX3++;

			}
		}
		else if (enHd == 3) {

			DrawExtendGraph(CposX4, 300, CposX3, 100, an, true);
			CposX2--;
			CposX1++;
			CposX4++;
			CposX3--;
			if (CposX4 < CposX3){
				CposX2++;
				CposX1--;
				CposX4--;
				CposX3++;

			}
		}

	}*/

	if (myHd == 1) {
		DrawRotaGraph(680, 500, 0.9, 0, el, true);
	}
	else if (myHd == 2) {
		DrawRotaGraph(680, 500, 0.9, 0, hu, true);
	}
	else if (myHd == 3) {
		DrawRotaGraph(680, 500, 0.9, 0, an, true);
	}

	//アニメーションの描画
	for (auto anim : liveAnim) {
		anim->DrawAnimation(deltatime);
	}

	////ダメージを受けた時のエフェクト
	//gfx_timer += deltatime;
	//if (gfx_timer > 0.25f) {
	//	gfx_timer = 0;
	//	anim_frame++;
	//	//anim_frame = anim_frame % 5;
	//	anim_frame %= 10;

	//	if (enemy->enHp -= 5) {
	//		DrawRotaGraph(200, 200, 2.0f, 0, gh_shine[anim_frame], true);
	//	}
	//	else if (enemy->enHp -= 3) {
	//		DrawRotaGraph(200, 200, 2.0f, 0, gh_shine[anim_frame], true);
	//	}
	//	else if (enemy->enHp -= 1) {
	//		DrawRotaGraph(200, 200, 2.0f, 0, gh_fire[anim_frame], true);
	//	}
	//}
	//それぞれの結果による描画
	SetFontSize(50);
	if (res == DRAW) {
		DrawStringEx(500, 300, -1, "Draw");
		enter = false;
	}
	else if (res == WIN) {
		DrawStringEx(500, 300, 800080, "Lose");
		DrawStringEx(500, 400, 500034, "Win");
		enter = false;
	}
	else if (res == LOSE) {
		DrawStringEx(500, 300, 500034, "Win");
		DrawStringEx(500, 400, 800080, "Lose");
		enter = false;
	}
	//enhpPer = 100 - (enemy->enHp /enemy->maxHp * 100)+300;
	//myhpPer = 100 - (myHp / maxmyHp * 100) +300;
	hoz_myHpber = ((300 / maxmyHp) * myHp);
	hoz_enHpber = ((300 / enemy->maxHp) * enemy->enHp);
	//HPバーが徐々に減っていくようにしたい
	if (hoz_myHpber <= myhpPer) {
		myhpPer -= 1;
	}
	if (hoz_enHpber <= enhpPer) {
		enhpPer--;
	}
	/*else if (res == SPCARD) {
		DrawStringEx(500, 300, -1, "SPCARD");
		enter = false;
	}*/
	SetFontSize(50);

	DrawStringEx(100, 630, -1, "X%d", gu);
	DrawStringEx(225, 630, -1, "X%d", chi);
	DrawStringEx(350, 630, -1, "X%d", pa);
	DrawStringEx(490, 630, -1, "X%d", spC);

	DrawStringEx(700, 0, 0, "てきノのこり手ふだ");
	DrawStringEx(800, 50, 0, "ぞうX%d", enGu);
	DrawStringEx(800, 100, 0, "ひとX%d", enChi);
	DrawStringEx(800, 150, 0, "ありX%d", enPa);

	DrawExtendGraph(0, 400, 300, 420, empHpber, true);
	DrawExtendGraph(0, 20, 300, 0, empHpber, true);
	DrawExtendGraph(0, 400, myhpPer, 420, resHpber, true);//(x1,y1,x2,y2,)
	DrawExtendGraph(0, 20, enhpPer, 0, resHpber, true);
	SetFontSize(20);
	DrawStringEx(0, 400, -1, "のこりHP%d", myHp);
	DrawStringEx(0, 0, -1, "のこりHP%d", enemy->enHp);
	SetFontSize(100);

	DrawStringEx(100, 100, -1, "%.0f", count);
	/*if (canSelect)DrawStringEx(200, 200, -1, "選べるよ");
	else DrawStringEx(200, 200, -1, "選べないよ");*/

}

