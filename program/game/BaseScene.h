#pragma once
//Šî’êƒNƒ‰ƒX

class BaseScene
{
public:
	BaseScene() {};
	virtual~BaseScene() {};


	//ƒˆ‰¼‘zŠÖ”
	virtual void Update(float deltatime) = 0;

	virtual void Draw(float deltatime) = 0;

};
