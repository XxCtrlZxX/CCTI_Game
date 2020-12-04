#include "stdafx.h"
#include "Coin.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "GameManager.h"

Coin::Coin(AnimationInfo* animInfo)
	: GameObject(animInfo), cur(0), flipCount(0), takenTime(0), isLastCoin(0)
{
	delayTimes.clear();
	animRenderer = animInfo;

	// state : 0~1, �ʴ� 16������, ���, ���� ����, ��ü ����
	coinAnimList.push_back(new SheetAnimation(0, 30.0f, L"resources/image/coin_sheet_1.png", 8, 8));
	coinAnimList.push_back(new SheetAnimation(1, 30.0f, L"resources/image/coin_sheet_2.png", 8, 8));
	coinAnimList[0]->SetAnimateOnce(true);
	coinAnimList[1]->SetAnimateOnce(true);

	for (int i = 0; i < 2; i++)
		animRenderer->PushBackAnimation(coinAnimList[i]);
}

Coin::~Coin()
{
}

void Coin::Update()
{
	if (flipCount > 0)
	{
		// ��Ÿ�� ���
		if (delayTimes.front() >= takenTime)
		{
			takenTime += TimeManager::GetDeltaTime();
		}
		else
		{
			// ��Ÿ�� ��
			this->FlipCoin();
			takenTime = 0;
			flipCount--;
			delayTimes.pop_front();	// ������ �ϳ��� ����
		}
	}
}

void Coin::FlipWithDelay(float delayTime)
{
	// Ƚ�� 1 ������ -> �ߺ� ���� ����
	flipCount++;
	delayTimes.push_back(delayTime);
}

void Coin::FlipCoin()
{
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

	// TODO: ���Ǻ� ���� �����ϱ� : ��Ʈ�� ���� ���� �������� ���� �߻�
	// �������� isLastCoin ������ ���ļ� ����� ���� ����
	// ����Ʈ�� �����
	// bool �� �����
	if (isLastCoin) {
		std::cout << "üũ��" << std::endl;
		GameManager::GetInstance()->GameCheck();
		isLastCoin = false;
	}
}

int Coin::GetCurrentCur()
{
	return cur;
}

void Coin::SetLastCoin()
{
	this->isLastCoin = true;
}
