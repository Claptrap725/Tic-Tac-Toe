#pragma once
#include "GameObject.h"
#include <iostream>
#include "Grid.h"

namespace Game
{
	extern Texture2D crossTexture;
	extern Texture2D circleTexture;
	extern Texture2D blankTexture;
	extern Texture2D boardTexture;
	extern Grid gameBoard;
	extern bool turnIsCross;

	void Start();
	void Restart();
	void Update();
	void Draw();
	int AddGameObject(GameObject* g);
	void RemoveGameObject(int index);
	void PlayerUsedTrun();
};