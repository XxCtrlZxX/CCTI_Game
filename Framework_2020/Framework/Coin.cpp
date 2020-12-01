#include "stdafx.h"
#include "Coin.h"
#include "InputManager.h"

Coin::Coin(AnimationInfo* animInfo)
	: GameObject(animInfo)
{
	animRenderer = animInfo;

	// state : 0~1, �ʴ� 16������, ���, ���� ����, ��ü ����
	coinAnimList[0] = new SheetAnimation(0, 30.0f, L"resources/image/coin_sheet_1.png", 8, 8);
	coinAnimList[1] = new SheetAnimation(1, 30.0f, L"resources/image/coin_sheet_2.png", 8, 8);

	for (int i = 0; i < 2; i++)
		animRenderer->PushBackAnimation(coinAnimList[i]);
}

Coin::~Coin()
{
}

void Coin::Update()
{
	if (InputManager::GetKeyDown(VK_SPACE)) {
		SwitchCoin();
	}
}

void Coin::SwitchCoin()
{
	static int cur = 0;
	if (cur == 1) 
	{
		cur = 0;
		animRenderer->ChangeAnimation(0);
	}
	else 
	{
		cur = 1;
		animRenderer->ChangeAnimation(1);
	}
}