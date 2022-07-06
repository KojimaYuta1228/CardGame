#pragma once

class BaseScene;

//enum eScene {
//	eScene_Menu,
//	eScene_Game,
//	eScene_Config,
//	eScene_Gameover
//};

void SceneMgr_Update();

void SceneMgr_Draw();

//引数　nextSceneにシーンを変更する
//void SceneMgr_ChangeScene(eScene nextScene);

class SceneManager
{
public:

	enum eScene {
		eScene_Menu,
		eScene_Game,
		eScene_Battle,
		eScene_Config,
		eScene_GameOver,
		eScene_Opening
	};

	SceneManager();

	~SceneManager();

	//現在選択中のシーンにあるアップデート関数を実行する関数
	void Update(float deltatime);

	//現在選択中のシーンにあるDraw関数を実行する関数
	void Draw(float deltatime);

	//現在のシーンのポインタが入った変数
	BaseScene* baseScene = nullptr;

	void ChangeScene(eScene nextScene);

};
