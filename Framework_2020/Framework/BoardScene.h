#pragma once
#include "Scene.h"
#include "Arrow.h"
#include "Coin.h"

class BoardScene : public Scene
{
public:
	BoardScene();
	~BoardScene();

	GameObject* background;
	Arrow* arrow;
	Coin* coins;	// TODO: ���� �迭 ���� �� ���� ��ġ

	virtual void Initialize();
};

