#include"Sound.h"

Sound::Sound()
{
	//サウンドのロード
	titleBgm = LoadSoundMem("sound/TitleBgm.mp3");
	moveBgm = LoadSoundMem("sound/moveBgm.mp3");
	battleBgm = LoadSoundMem("sound/Battle.mp3");
	gameoverBgm = LoadSoundMem("sound/gameoverBgm.mp3");

	bgm.emplace_back(titleBgm);
	bgm.emplace_back(moveBgm);
	bgm.emplace_back(battleBgm);
	bgm.emplace_back(gameoverBgm);

	changeSe = LoadSoundMem("sound/system_se.mp3");
	cursorSe = LoadSoundMem("sound/cursorSe.mp3");
	decideSe = LoadSoundMem("sound/decideSe.mp3");
	breakSe = LoadSoundMem("sound/breakSe.mp3");
	efectSe1 = LoadSoundMem("sound/slash.mp3");
	efectSe2 = LoadSoundMem("sound/fire.mp3");
	efectSe3 = LoadSoundMem("sound/flash.mp3");
	efectSe4 = LoadSoundMem("sound/drawSe.mp3");

	se.emplace_back(changeSe);
	se.emplace_back(cursorSe);
	se.emplace_back(decideSe);
	se.emplace_back(breakSe);
	se.emplace_back(efectSe1);
	se.emplace_back(efectSe2);
	se.emplace_back(efectSe3);
	se.emplace_back(efectSe4);
}

Sound::~Sound()
{
}

void Sound::SoundBgm(int num)
{
	PlaySoundMem(bgm[num], DX_PLAYTYPE_LOOP, true);
	nowPlayBGM = bgm[num];
}

void Sound::SoundSe(int num)
{
	PlaySoundMem(se[num], DX_PLAYTYPE_BACK, true);
}

void Sound::StopBgm()
{
	StopSoundMem(nowPlayBGM);
}

//sound->SoundBGM(static_cast<uint32_t>(Sound::BGM::TITLE));
//sound->SoundBGM(Sound::BGM::TITLE);