#pragma once
#include "raylib.h"

class GameObject
{
private:

public:
	GameObject();
	GameObject(GameObject*);
	~GameObject();

	Texture2D *texture;
	bool initialized = false;
	Vector2 position;
	float rotation;
	float scale;
	int index;

	void Initialize();
	void Update();
	void ChangeTexture(Texture2D *texture);
	void Draw();
};

