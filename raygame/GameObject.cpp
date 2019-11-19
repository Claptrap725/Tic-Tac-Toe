#include <iostream>
#include "GameObject.h"
#include "Game.h"



GameObject::GameObject()
{
}

GameObject::GameObject(GameObject * g)
{
	if (g != nullptr)
	{
		position.x = g->position.x;
		position.y = g->position.y;
		rotation = g->rotation;
		initialized = g->initialized;
	}

}


GameObject::~GameObject()
{
}



void GameObject::Initialize()
{
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() / 2;
	rotation = 0;
	initialized = true;

	index = Game::AddGameObject(this);
}

void GameObject::Update()
{
	//std::cout << "(" << position.x << ", " << position.y << ")";
}

void GameObject::ChangeTexture(Texture2D * _texture)
{
	texture = _texture;
}



void GameObject::Draw()
{
	DrawTextureEx(*texture, position, rotation, scale, Color(WHITE));
	DrawCircle(position.x + 25, position.y + 25, 5, Color(BLACK));
}

