#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "TestScene.h"

int main()
{
	Framework* f = new Framework;
	//���� Scene, ���� Ÿ��Ʋ, �ػ�(����, ����), â��� ���θ� �����մϴ�.
	f->Run(new TestScene(),L"Ÿ��Ʋ", SCREEN_WIDTH, SCREEN_HEIGHT, false);
	SAFE_DELETE(f);

	return 0;
}