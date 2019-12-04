#include "Tile.h"
#include "Game.h"
#include <iostream>


Tile::Tile()
{
}
Tile::~Tile()
{
}

//called shorty after being created
void Tile::Initialize()
{
	//start off being a blank tile
	value = 0;
	//create rectangle
	rect = *new Rectangle();
	//set rectangle size
	rect.width = 70;
	rect.height = 70;
	//adjust rectangle to be centered on image
	rect.x = position.x - 10;
	rect.y = position.y - 10;
	//default color
	color = Color(WHITE);


	//we have been initialized
	initialized = true;
	//now add ourselves to the game
	Game::AddGameObject(this);
}

//called every frame if initilized
void Tile::Update()
{
	//if the user clicks
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		//check if they clicked on us
		if (CheckCollisionPointRec(GetMousePosition(), rect))
		{
			OnClick();
		}
	}
}

//called when the mouse clicks within the bounds of rect
void Tile::OnClick()
{
	//only do something if we haven't already been set
	if (value == 0)
	{
		//set our value to be that of the current player
		if (Game::turnIsCross)
		{
			ChangeValue(1);
		}
		else
		{
			ChangeValue(2);
		}
		//Let Game know a player used their turn
		Game::PlayerUsedTrun();
	}
}

//changes value and updates texture
void Tile::ChangeValue(int val)
{
	//update value variable
	value = val;

	//set our texture to the appropriate texture
	if (value == 1) 
	{
		SetTexture(&Game::crossTexture);
		color = Game::player1.color;
	}
	else if (value == 2)
	{
		SetTexture(&Game::circleTexture);
		color = Game::player2.color;
	}
	else
	{
		SetTexture(&Game::blankTexture);
		color = Color(WHITE);
	}
}