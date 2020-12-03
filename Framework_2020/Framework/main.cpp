#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "TestScene.h"
#include "StartScene.h"
#include "BoardScene.h"
#include "MainScene.h"
#include "OverScene.h"

int main()
{
	//�����ӿ�ũ ��ü�� �����ϴ� ��ü�Դϴ�.
	Framework* f = new Framework;
	//���� Scene, ���� Ÿ��Ʋ, �ػ�(����, ����), â��� ���θ� �����մϴ�.
	f->Run(new MainScene(), L"Comfort Coffee Taxi Independent!!", 800, 600, false);
	SAFE_DELETE(f);

	//�޸� ������ Ȯ���� �� ����մϴ�. stdafx.h�� �����ϼ���.
	//_CrtDumpMemoryLeaks();
	return 0;
}