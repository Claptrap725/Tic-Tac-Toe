#include "Game.h"

namespace Game
{
	GameObject* gameObjects[100];
	int gameObjectsCount;
	int winState = 0;

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

	void Restart()
	{
		winState = 0;
		gameObjectsCount = 0;
		turnIsCross = true;
		gameBoard.Initialize();
	}

	void Update()
	{
		if (winState == 0)
		{
			for (int i = 0; i < gameObjectsCount; i++) 
			{
				gameObjects[i]->Update();
			}
			int result = gameBoard.CheckBoard();
			if (result == 1)
			{
				std::cout << "cross";
				winState = 1;
			}
			else if (result == 2)
			{
				std::cout << "circle";
				winState = 2;
			}
			else if (result == 3)
			{
				std::cout << "tie";
				winState = 3;
			}

		}


	}

	void Draw()
	{
		for (int i = 0; i < gameObjectsCount; i++) 
		{
			gameObjects[i]->Draw();
		}
		if (winState == 1)
		{
			DrawText("THE WINNER IS X!", 200, 50, 50, Color(GREEN));
		}
		else if (winState == 2)
		{
			DrawText("THE WINNER IS O!", 200, 50, 50, Color(GREEN));
		}
		else if (winState == 3)
		{
			DrawText("THE GAME IS A TIE!", 200, 50, 50, Color(GREEN));
		}

		if (IsKeyPressed(KEY_R))
		{
			Restart();
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