#include "Game.h"

namespace Game
{
	GameObject* gameObjects[100];
	int gameObjectsCount;

	Texture2D crossTexture;
	Texture2D circleTexture;
	Texture2D blankTexture;

	GameObject spots[3][3];

	void Start()
	{
		crossTexture = LoadTextureFromImage(LoadImage("cross.png"));
		circleTexture = LoadTextureFromImage(LoadImage("circle.png"));
		blankTexture = LoadTextureFromImage(LoadImage("blank.png"));
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				spots[x][y] = new GameObject;
				spots[x][y].Initialize();
				spots[x][y].ChangeTexture(&crossTexture);
				spots[x][y].position.x += x*100 - 150;
				spots[x][y].position.y += y*100 - 150;
				spots[x][y].scale = 0.1f;

			}
		}
	}

	void Update()
	{
		for (int i = 0; i < gameObjectsCount; i++) 
		{
			gameObjects[i]->Update();
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

}