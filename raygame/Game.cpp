#include "Game.h"

namespace Game
{
	GameObject* gameObjects[100];
	int gameObjectsCount;

	Texture2D crossTexture;
	Texture2D circleTexture;
	Texture2D blankTexture;
	Texture2D boardTexture;
	Grid gameBoard;
	bool turnIsCross;

	void Start()
	{
		crossTexture = LoadTexture("cross.png");
		circleTexture = LoadTexture("circle.png");
		blankTexture = LoadTexture("blank.png");
		boardTexture = LoadTexture("board.png");
		turnIsCross = true;
		gameBoard.Initialize();
	}

	void Update()
	{
		for (int i = 0; i < gameObjectsCount; i++) 
		{
			gameObjects[i]->Update();
		}
		int result = gameBoard.CheckBoard();
		if (result == 1)
		{
			std::cout << "cross";
		}
		else if (result == 2)
		{
			std::cout << "circle";

		}
	}

	void Draw()
	{
		for (int i = 0; i < gameObjectsCount; i++) 
		{
			gameObjects[i]->Draw();
		}
	}

	int AddGameObject(GameObject * g)
	{
		gameObjects[gameObjectsCount] = g;
		gameObjectsCount++;
		return gameObjectsCount - 1;
	}

	void RemoveGameObject(int index)
	{

	}

	void PlayerUsedTrun()
	{
		if (turnIsCross)
		{
			turnIsCross = false;
		}
		else
		{
			turnIsCross = true;
		}
	}

}