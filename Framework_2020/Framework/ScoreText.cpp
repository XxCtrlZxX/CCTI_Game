#include "stdafx.h"
#include "ScoreText.h"
#include "GameManager.h"

ScoreText::ScoreText(const wchar_t* text) :
	TextObject(text)
{
	transform->SetPosition(400, 140);
}

ScoreText::ScoreText(std::wstring text) :
	TextObject(text)
{
	transform->SetPosition(400, 140);
}

ScoreText::~ScoreText()
{
}

void ScoreText::UpdateScore()
{
	fontRenderer->text = L"����: " + std::to_wstring(GameManager::GetInstance()->score);
}
