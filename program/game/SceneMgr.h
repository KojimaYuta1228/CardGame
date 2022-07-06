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

//�����@nextScene�ɃV�[����ύX����
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

	//���ݑI�𒆂̃V�[���ɂ���A�b�v�f�[�g�֐������s����֐�
	void Update(float deltatime);

	//���ݑI�𒆂̃V�[���ɂ���Draw�֐������s����֐�
	void Draw(float deltatime);

	//���݂̃V�[���̃|�C���^���������ϐ�
	BaseScene* baseScene = nullptr;

	void ChangeScene(eScene nextScene);

};
