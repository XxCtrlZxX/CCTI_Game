#pragma once
#include "Scene.h"
#include "Arrow.h"
#include "Coin.h"

#define BOARD_INTERVAL 75	// ���� �� ĭ ������ ����

class BoardScene : public Scene
{
public:
	BoardScene();
	~BoardScene();

	GameObject* background;
	Arrow* arrow;
	std::vector<Coin*> coins;

	virtual void Initialize();
};

