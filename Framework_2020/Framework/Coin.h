#pragma once
#include "GameObject.h"
#include "AnimationInfo.h"
#include "SheetAnimation.h"

class Coin : public GameObject
{
public:
	Coin(AnimationInfo* animInfo);
	~Coin();

	AnimationInfo* animRenderer;
	SheetAnimation* coinAnimList[];	// TODO: �ִϸ��̼� �ѹ��� ����ǰ� �ٲٱ�

	virtual void Update();
	void SwitchCoin();
};

