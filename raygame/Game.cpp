#include "Game.h"
#include <string>

namespace Game
{
	//list of all initialized gameObjects
	GameObject* gameObjects[100];
	//amount of initialized gameObjects
	int gameObjectsCount;
	//0 = game in progress, 1 = X wins, 2 = O wins, 3 = Tie
	int winState = 0;

	//stores the Texture for an X
	Texture2D crossTexture;
	//stores the Texture for an O
	Texture2D circleTexture;
	//stores the Texture for a blank image
	Texture2D blankTexture;
	//stores the Texture for the game board
	Texture2D boardTexture;
	//the gameboard object
	Grid gameBoard;
	//true if it is X's turn
	bool turnIsCross;
	//size of gameboard
	int gridSize = 1;

	//User profile for player 1
	User player1;
	//User profile for player 2
	User player2;

	//called at the start of the game
	void Start()
	{
		//load our images into memory
		crossTexture = LoadTexture("cross.png");
		circleTexture = LoadTexture("circle.png");
		blankTexture = LoadTexture("blank.png");
		boardTexture = LoadTexture("board.png");
		//X goes first
		turnIsCross = true;
		//initialize the gameBoard
		gameBoard.Initialize();
	}

	//called when the player presses R
	void Restart()
	{
		//reset varibles and reinitialize the gameBoard
		winState = 0;
		gameObjectsCount = 0;
		turnIsCross = true;
		gameBoard.Initialize();
	}

	//called once every frame
	void Update()
	{
		//game is still going
		if (winState == 0)
		{
			//call Update on all gameObjects
			for (int i = 0; i < gameObjectsCount; i++) 
			{
				gameObjects[i]->Update();
			}

			//Check to see if a player has won the game and set winState appropriately
			winState = gameBoard.CheckBoard();
			if (winState == 1)
			{
				player1.wins++;
				player2.losses++;
			}
			else if (winState == 2)
			{
				player1.losses++;
				player2.wins++;
			}
			else if (winState == 3)
			{
				player1.ties++;
				player2.ties++;
			}
		}
	}

	//called after update include all texture drawing
	void Draw()
	{
		//call Draw on all gameObjects
		for (int i = 0; i < gameObjectsCount; i++) 
		{
			gameObjects[i]->Draw();
		}

		//Draw Player 1 stats
		DrawText(player1.username, 40, 50, 28, Color(BLACK));

		std::string wins1temp = "Wins: " + std::to_string(player1.wins);
		DrawText(wins1temp.c_str(), 40, 80, 20, Color(BLACK));

		std::string losses1temp = "Losses: " + std::to_string(player1.losses);
		DrawText(losses1temp.c_str(), 40, 100, 20, Color(BLACK));

		std::string ties1temp = "Ties: " + std::to_string(player1.ties);
		DrawText(ties1temp.c_str(), 40, 120, 20, Color(BLACK));
		//

		//Draw Player 2 stats
		DrawText(player2.username, 620, 50, 28, Color(BLACK));

		std::string wins2temp = "Wins: " + std::to_string(player2.wins);
		DrawText(wins2temp.c_str(), 620, 80, 20, Color(BLACK));

		std::string losses2temp = "Losses: " + std::to_string(player2.losses);
		DrawText(losses2temp.c_str(), 620, 100, 20, Color(BLACK));

		std::string ties2temp = "Ties: " + std::to_string(player2.ties);
		DrawText(ties2temp.c_str(), 620, 120, 20, Color(BLACK));
		//

		//Display who has won the game
		if (winState == 1)
		{
			DrawText("THE WINNER IS X!", 80, 150, 70, Color(player1.color));
		}
		else if (winState == 2)
		{
			DrawText("THE WINNER IS O!", 80, 150, 70, Color(player2.color));
		}
		else if (winState == 3)
		{
			DrawText("THE GAME IS A TIE!", 30, 150, 70, Color(BLACK));
		}
		else//winState == 0
		{
			//Display who's turn it is
			if (turnIsCross)
			{
				DrawText("X's\nturn.", 620, 250, 50, Color(player1.color));
			}
			else 
			{
				DrawText("O's\nturn.", 620, 250, 50, Color(player2.color));
			}
		}
		//Let the player know how to restart the game
		DrawText("Press \'R\' to restart.", 30, 420, 30, Color(BLACK));

		//restart if the player presses R. 
		//This is at the end of the draw method so that the next frame 
		//will be the newly loaded game
		if (IsKeyPressed(KEY_R))
		{
			Restart();
		}
	}

	//adds a pointer to gameObjects[] so they will be updated and drawn
	void AddGameObject(GameObject * g)
	{
		gameObjects[gameObjectsCount] = g;
		gameObjectsCount++;
	}

	//called when a player clicks on a tile that hasn't be clicked
	void PlayerUsedTrun()
	{
		//flips who's turn it is
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