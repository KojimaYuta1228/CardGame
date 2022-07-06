#pragma once
#include"BaseScene.h"
#include<list>

class Enemy;
class JankenCard;
class Animation;

class Battle :public BaseScene
{
public:
	Battle();
	~Battle();


	Enemy* enemy = nullptr;
	JankenCard* jankenCard = nullptr;

	float time_count = 0;

	//手札を選ぶカーソルを動かす関数(左右キー)0357341575
	void handContller();

	//敵の手
	void enemyHand();


	//手札を決定する関数(選んだ手札がどれなのか保存したい）
	void handDecide(float deltatime);
	int select = 0;

	//カードの勝負結果を求める関数(じゃんけん)
	void result(float deltatime);

	//ゲームを再スタートする関数
	void reStart();


	//ダメージを与える関数
	//void damage();

	//ゲームの勝負結果を求める関数
	void battleResult();

	//じゃんけんの結果を返す関数
	int janken(int player, int enemy);

	//カードを回す関数
	int card();

	//サポートカードの結果を返す関数
	int suport();

	void roll_card();

	//制限時間
	bool timelimit(const float deltatime);

	std::list<Animation*> liveAnim;

	//handを選べるフラグ
	bool canSelect = true;

	bool init = false;
	bool suIn = false;
	bool enter = true;
	bool return_card = false;
	bool card_key = false;
	bool card_back = false;

	float gfx_timer = 0;
	float timeCounter = 0;
	float timer = 0;
	int pos = 1;//100
	int myHd = 0;//照らし合わせ用の自分の手札　　idを振りたい→配列を使いたい→どこに書いていいかわからない
	int enHd = 0;//照らし合わせ用の相手の手札
	int myAll = 0;//自分の手札の合計
	int enAll = 0;
	int sp = 0;//sp
	int maxmyHp = 10;
	int myHp = 100;
	int myPos = myHp;
	int enPos = 0;
	int anim_frame = 0;
	int anim_type = 0;
	//int gfx_hd1[2][10]= { 0 };



	int gh_shine[10] = {};

	int gh_slash[10] = {};

	int gh_fire[10] = {};
	int gfx_hd2[1][10] = { 0 };

	//最初から表示されるカードのX座標
	int CposX1 = 600;
	int CposX2 = 750;

	//選ばれた手によって表示されるX座標
	int CposX3 = 675;
	int CposX4 = 675;

	int gu = 4;
	int chi = 4;
	int pa = 4;
	int spC = 9;
	int enGu = 4;
	int enChi = 4;
	int enPa = 4;
	int res = -1;
	int backPosX = 700;
	int backPosY = 200;
	const int GU = 1;
	const int CHI = 2;
	const int PA = 3;
	const int SP = 4;
	const int ENGU = 1;
	const int ENCHI = 2;
	const int ENPA = 3;
	const int ENSP = 4;
	const int DRAW = 0;
	const int WIN = 1;
	const int LOSE = 2;
	const int SPCARD = 3;

	//制限時間
	const float TIMELIMIT = 3;

	float count = TIMELIMIT;

	int resHpber = 0;
	int empHpber = 0;
	int hoz_myHpber = 0;
	int hoz_enHpber = 0;
	int enhpPer = 300;
	int myhpPer = 300;
	int el = 0;
	int an = 0;
	int hu = 0;
	int sup = 0;
	int backCard = 0;
	int type = 0;
	int slash = 0;


	bool start = false;


	void Update(float deltatime)override;

	void Draw(float deltatime)override;
};
