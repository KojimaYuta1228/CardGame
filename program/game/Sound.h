#pragma once
#include<vector>
#include"../dxlib_ext/dxlib_ext.h"

class Sound
{
public:
	Sound();
	~Sound();

	int titleBgm = 0;
	int battleBgm = 0;
	int gameoverBgm = 0;
	int moveBgm = 0;

	int changeSe = 0;
	int cursorSe = 0;
	int decideSe = 0;
	int breakSe = 0;
	int efectSe1 = 0;
	int efectSe2 = 0;
	int efectSe3 = 0;
	int efectSe4 = 0;

	std::vector<int>bgm;
	std::vector<int>se;



	enum class BGM :uint32_t {
		TITLE,
		BATTLE,
		GAMEOVER,
		MOVE,
		MAX
	};

	//ç°ó¨ÇÍÇƒÇ¢ÇÈBGM
	int nowPlayBGM = 0;

	enum class SE :uint32_t {
		CHANGE,
		CURSOR,
		DECIDE,
		BREAK,
		EFFECT1,
		EFFECT2,
		EFFECT3,
		EFFECT4,
		MAX
	};

	bool soundHd1 = false;

	void SoundBgm(int num);
	void SoundSe(int num);

	void StopBgm();
};
