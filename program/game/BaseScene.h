#pragma once
//���N���X

class BaseScene
{
public:
	BaseScene() {};
	virtual~BaseScene() {};


	//�������z�֐�
	virtual void Update(float deltatime) = 0;

	virtual void Draw(float deltatime) = 0;

};
