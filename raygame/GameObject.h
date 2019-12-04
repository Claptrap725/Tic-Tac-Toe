#pragma once
#include "raylib.h"

class GameObject
{
private:

public:
	GameObject();
	~GameObject();

	//pointer to the current texture
	Texture2D *texture;
	//true if Initialize() has been called
	bool initialized = false;
	//position in world space
	Vector2 position;
	//scale in world space
	float scale;
	//Color that will be applied to texture
	Color color;

	//called shorty after being created
	void virtual Initialize();
	//called every frame if initilized
	void virtual Update();
	//sets the texture to the passed texture
	void SetTexture(Texture2D *texture);
	//called every frame if initilized. Draws current texture
	void virtual Draw();
};

