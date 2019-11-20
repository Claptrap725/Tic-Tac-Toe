#include "Tile.h"
#include "Game.h"
#include <iostream>


Tile::Tile()
{
}
Tile::~Tile()
{
}

void Tile::Initialize()
{
	rotation = 0;
	value = 0;
	rect = *new Rectangle();
	rect.width = 70;
	rect.height = 70;
	rect.x = position.x - 10;
	rect.y = position.y - 10;
	initialized = true;

	index = Game::AddGameObject(this);
}

void Tile::Update()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), rect))
		{
			OnClick();
		}
	}
}

void Tile::OnClick()
{
	if (value == 0)
	{
		if (Game::turnIsCross)
		{
			ChangeValue(1);
		}
		else
		{
			ChangeValue(2);
		}
		Game::PlayerUsedTrun();
	}
}

void Tile::ChangeValue(int val)
{
	value = val;

	if (value == 1) 
	{
		SetTexture(&Game::crossTexture);
	}
	else if (value == 2)
	{
		SetTexture(&Game::circleTexture);
	}
	else
	{
		SetTexture(&Game::blankTexture);
	}

}

void Tile::Draw()
{
	GameObject::Draw();
	DrawRectangleLinesEx(rect, 1, Color(RED));
}
