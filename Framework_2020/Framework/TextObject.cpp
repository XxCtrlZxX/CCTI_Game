#include "stdafx.h"
#include "TextObject.h"

TextObject::TextObject(const wchar_t* text)
	:GameObject(fontRenderer = new FontInfo())
{
	font = new Font(L"Amatic SC", 32.0f, 0.0f, 0.0f, 0.0f, 1.0f, true);	//��Ʈ, ���� ���� ���ϴ� Font Ŭ���� ����(Font.h ����), �⺻ ũ�� 20pt
	fontRenderer->font = this->font;					//�ؽ�Ʈ�� �Ӽ��� �������ݴϴ�.
	fontRenderer->text = std::wstring(text);
}

TextObject::TextObject(std::wstring text)
	:GameObject(fontRenderer = new FontInfo())
{
	font = new Font(L"Amatic SC", 32.0f, 0.0f, 0.0f, 0.0f, 1.0f, true);	//��Ʈ, ���� ���� ���ϴ� Font Ŭ���� ����(Font.h ����), �⺻ ũ�� 20pt
	fontRenderer->font = this->font;					//�ؽ�Ʈ�� �Ӽ��� �������ݴϴ�.
	fontRenderer->text = text;
}

TextObject::~TextObject()
{
	SAFE_DELETE(font);
}
