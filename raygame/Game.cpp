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
				winState = 1;
			}
			else if (result == 2)
			{
				winState = 2;
			}
			else if (result == 3)
			{
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
			DrawText("THE WINNER IS X!", 80, 150, 70, Color(GREEN));
		}
		else if (winState == 2)
		{
			DrawText("THE WINNER IS O!", 80, 150, 70, Color(GREEN));
		}
		else if (winState == 3)
		{
			DrawText("THE GAME IS A TIE!", 30, 150, 70, Color(GREEN));
		}
		else//winState == 0
		{
			if (turnIsCross)
			{
				DrawText("X's turn.", 300, 400, 30, Color(RED));
			}
			else 
			{
				DrawText("O's turn.", 300, 400, 30, Color(BLUE));
			}
		}
		DrawText("Press \'R\' to restart.", 250, 360, 30, Color(BLACK));

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