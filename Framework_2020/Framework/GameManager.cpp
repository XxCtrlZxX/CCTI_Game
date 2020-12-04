#include "stdafx.h"
#include "GameManager.h"
#include "OverScene.h"
#include "Random.h"
#include "TimeManager.h"

GameManager::GameManager()
{
}

GameManager* GameManager::GetInstance()
{
	/* if (instance == nullptr) {
		static GameManager gmr;
		instance = &gmr;
	}
	return instance; */

	static GameManager gmr;
	return &gmr;
}

void GameManager::Update()
{
	GameManager* i = GetInstance();
	
	// Ŭ����� ������ 0.5��
	if (i->isGameClear)
	{
		if (i->delayTime < 0.5f)
			i->delayTime += TimeManager::GetDeltaTime();
		else {
			DEBUG("Clear!")
			Scene::ChangeScene(new OverScene(i->score));
		}
	}
}

void GameManager::Init()
{
	GameManager* i = GetInstance();

	i->currentTurn = 0;
	i->maxTurn = MAX_TURN;
	i->score = MAX_TURN;
	i->isHintTime = false;

	i->delayTime = 0;
	i->isGameClear = false;
}

void GameManager::AddScore(int d)
{
	GameManager* i = GetInstance();

	i->score += d;
	i->scoreText->UpdateScore();

	if (i->score <= 0)
		Scene::ChangeScene(new OverScene());	// ���� ����
}

void GameManager::TurnUpdate()
{
	// �� ���� �� ����
	GameManager* i = GetInstance();

	i->currentTurn++;

	// ��Ʈ ó��
	if (i->currentTurn % TURN_INTERVAL == TURN_INTERVAL - 1) {	// �� �Ͽ� �� ���� Ÿ�� ����
		i->hintPos = Random::Range(0, 8);
		i->tile->FadeIn(i->hintPos);
		i->isHintTime = true;
		std::cout << "��Ʈ �غ�� : " << i->hintPos << std::endl;
	}
	else if (i->currentTurn % TURN_INTERVAL == 0) {	// �� �������� �� �����
		std::cout << "��Ʈ �� : " << i->hintPos << std::endl;
		i->tile->FadeOut(i->hintPos);
		i->isHintTime = false;
	}
}

void GameManager::GameCheck()
{
	// ���� �� ������ �� ����
	GameManager* i = GetInstance();

	// ��� ���� ������ üũ
	i->isGameClear = true;
	for (int k = 0; k < i->coins.size() - 1; k++) {
		// ���� �Ͱ� ���� ���� ������ -> �ٸ��� flag = false
		if (i->isGameClear && i->coins[k]->GetCurrentCur() == i->coins[k + 1]->GetCurrentCur()) {
			i->isGameClear = true;
		}
		else {
			i->isGameClear = false;
		}
	}

	// debug
	for (int j = 0; j < i->coins.size(); j++) {
		std::cout << i->coins[j]->GetCurrentCur() << " ";
		if (j % 3 == 2)
			std::cout << std::endl;
	}

	//if (flag)
		//Scene::ChangeScene(new OverScene(i->score));	// Ŭ����
}

void GameManager::PutScoreText(ScoreText* st)
{
	GetInstance()->scoreText = st;
}

void GameManager::PutCoins(std::vector<Coin*> &c)
{
	GetInstance()->coins = c;
}

void GameManager::PutTile(Tile* t)
{
	GetInstance()->tile = t;
}
