#pragma once
#include "ScoreText.h"
#include "Coin.h"
#include "Tile.h"

#define MAX_TURN 500
#define TURN_INTERVAL 3

class GameManager// : public GameObject
{
public:
	GameManager();

public:
	static void Init();
	static void AddScore(int d);

	static void TurnUpdate();
	static void GameCheck();

	static GameManager* GetInstance();

	// �ӽ÷� arrow update���� ����
	static void Update();	// ������ Ŭ���� ���� �� �����̸� �ֱ� ����
	float delayTime;

	// ��ü���� ���� ����
	int score;
	int currentTurn;
	int maxTurn;
	bool isGameClear;

	// ��Ʈ ���� ����
	int hintPos;
	bool isHintTime;

	ScoreText* scoreText;
	static void PutScoreText(ScoreText* st);

	std::vector<Coin*> coins;
	static void PutCoins(std::vector<Coin*> &c);

	Tile* tile;
	static void PutTile(Tile* t);
};

