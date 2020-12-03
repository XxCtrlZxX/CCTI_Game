#include "stdafx.h"
#include "Button.h"
#include "InputManager.h"

Button::Button(const wchar_t* uri)
	: GameObject(uri), isHover(false)
{
	col = new AABBCollider(this, renderer);
}

Button::~Button()
{
	SAFE_DELETE(col);
}

void Button::Update()
{
	if (col->isMouseOnUI())
	{
		if (!isHover)	// Hover �Լ� �ѹ��� �����ϱ� ���� bool�� �÷���
		{
			OnMouseHover();	
			isHover = true;
		}

		if (InputManager::GetKeyDown(VK_LBUTTON))
			OnClick();
	}
	else if (isHover)
	{
		OnMouseExit();
		isHover = false;
	}
}
