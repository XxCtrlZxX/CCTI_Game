#pragma once
#include "GameScene.h"

//��ư�� �����մϴ�.
//�� ������Ʈ���� ���콺 Ŭ��&&���콺-���� �浹�� �Ͼ�� Ȯ���մϴ�.
//������ ��ư�� �� ��ư�� ��ӹ޾� �����ϸ� �����ϴ�.
//StartButton, ExitButton Ŭ������ �����ϸ� ��� ������ �� ���� �ð̴ϴ�.
class Button :
	public GameObject
{
public:
	AABBCollider* col;
	Button(const wchar_t* uri);
	~Button();

	bool isHover;

	void Update();
	virtual void OnClick() {}
	virtual void OnMouseHover() {}
	virtual void OnMouseExit() {}
};

