#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "TestScene.h"
#include "StartScene.h"
#include "BoardScene.h"

int main()
{
	//�����ӿ�ũ ��ü�� �����ϴ� ��ü�Դϴ�.
	Framework* f = new Framework;
	//���� Scene, ���� Ÿ��Ʋ, �ػ�(����, ����), â��� ���θ� �����մϴ�.
	f->Run(new BoardScene(), L"Comfort Taxi Coffee!!", 800, 800, false);
	SAFE_DELETE(f);

	//�޸� ������ Ȯ���� �� ����մϴ�. stdafx.h�� �����ϼ���.
	//_CrtDumpMemoryLeaks();
	return 0;
}