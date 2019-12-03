#include <iostream>
#include "GameObject.h"
#include "Game.h"

GameObject::GameObject()
{
}
GameObject::~GameObject()
{
}

//called shorty after being created
void GameObject::Initialize()
{
	//go to middle of screen (default spawn point)
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() / 2;

	//we have been initialized
	initialized = true;
	//now add ourselves to the game
	Game::AddGameObject(this);
}

//called every frame if initilized
void GameObject::Update()
{
}

//sets the texture to the passed texture
void GameObject::SetTexture(Texture2D * _texture)
{
	texture = _texture;
}

//called every frame if initilized. Draws current texture
void GameObject::Draw()
{
	//Draw a texture if we have one or just draw a circle
	if (texture != nullptr)
		DrawTextureEx(*texture, position, 0, scale, Color(WHITE));
	else
		DrawCircle(position.x + 25, position.y + 25, 5, Color(BLACK));
}

