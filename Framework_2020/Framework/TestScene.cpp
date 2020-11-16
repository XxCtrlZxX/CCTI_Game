#include "stdafx.h"
#include "TestScene.h"
#include "FontObject.h"
void TestScene::Initialize()
{
	testObject = new AnimationObject(new AnimationInfo());
	Push(testObject);

	//UI ������Ʈ��, ī�޶�� ������� ȭ�� ���� ��ġ�� �������� �մϴ�.
	FontObject* fo = new FontObject();
	PushUI(fo);
	fo->transform->SetPosition(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
}
