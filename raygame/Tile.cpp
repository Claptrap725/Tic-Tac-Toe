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
	rect.width = 80;
	rect.height = 80;
	//adjust rectangle to be centered on image
	rect.x = position.x;
	rect.y = position.y;
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
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || Game::aiClick)
	{
		//check if they clicked on us
		if (CheckCollisionPointRec(GetMousePosition(), rect))
		{
			Game::aiClick = false;
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
		color = Game::players[0]->color;
	}
	else if (value == 2)
	{
		SetTexture(&Game::circleTexture);
		color = Game::players[1]->color;
	}
	else
	{
		SetTexture(&Game::blankTexture);
		color = Color(WHITE);
	}
}

//called every frame if initilized. Draws current texture
void Tile::Draw()
{
	// if we are still blank
	if (value == 0)
	{
		//check if they are hovering on us
		if (CheckCollisionPointRec(GetMousePosition(), rect))
		{
			//Draw a hightlighted box
			DrawRectangle(rect.x, rect.y, rect.width, rect.height, GOLD);
		}
	}

	//Draws a box around each tile object to make up a grid pattern
	Vector2 texturePos = position;
	texturePos.x += 15;
	texturePos.y += 15;
	DrawTextureEx(*texture, texturePos, 0, scale, color);
	DrawRectangleLinesEx(rect, 3, BLACK);

}
