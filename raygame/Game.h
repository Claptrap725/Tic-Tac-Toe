#pragma once
#include "GameObject.h"
#include <iostream>

namespace Game
{
	void Start();
	void Update();
	void Draw();
	int AddGameObject(GameObject* g);
	void RemoveGameObject(int index);
	Texture2D* getOrLoadTexture(char filename[]);
};