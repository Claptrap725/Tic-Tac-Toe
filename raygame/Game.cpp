#include "Game.h"
#include <string>

// Used for everything Gameplay
namespace Game
{
	//list of all initialized gameObjects
	GameObject* gameObjects[100];
	//amount of initialized gameObjects
	int gameObjectsCount;
	//0 = game in progress, 1 = X wins, 2 = O wins, 3 = Tie, 4 if the AI has rebelled
	int winState = 0;
	//who went first last game
	bool turnWasCross;

	//stores the Texture for an X
	Texture2D crossTexture;
	//stores the Texture for an O
	Texture2D circleTexture;
	//stores the Texture for a blank image
	Texture2D blankTexture;
	//the gameboard object
	Grid gameBoard;
	//true if it is X's turn
	bool turnIsCross;
	//size of gameboard
	int gridSize = 1;
	//holds the 2 players
	User** players = new User*[2];
	//keeps track of what turn we are on
	int turn;
	//lets Tiles know if it is an AI's turn
	bool aiClick = false;

	//called at the start of the game
	void Start()
	{
		//load our images into memory
		crossTexture = LoadTexture("cross.png");
		circleTexture = LoadTexture("circle.png");
		blankTexture = LoadTexture("blank.png");
		//X goes first
		turnIsCross = true;
		turnWasCross = true;
		//initialize the players
		players[0] = new User();
		players[1] = new User();
		turn = 1;

		//initialize the gameBoard
		gameBoard.Initialize();
	}

	//called when the player presses R
	void Restart()
	{
		//reset varibles and reinitialize the gameBoard
		winState = 0;
		gameObjectsCount = 0;
		if (turnWasCross)
		{
			turnIsCross = false;
			turnWasCross = false;
		}
		else
		{
			turnIsCross = true;
			turnWasCross = true;
		}
		gameBoard.Initialize();
		turn = 1;
	}

	//called once every frame
	void Update()
	{
		//game is still going
		if (winState == 0)
		{
			if (turnIsCross)
			{
				if (players[0]->AI)
				{
					//get next AI move
					Int2 aiMove = players[0]->GetNextTurnAI();
					//move mouse to that Tile
					SetMousePosition({ gameBoard.spots[aiMove.x][aiMove.y].position.x + 40, gameBoard.spots[aiMove.x][aiMove.y].position.y + 40 });
					aiClick = true;
				}
			}
			else
			{
				if (players[1]->AI)
				{
					//get next AI move
					Int2 aiMove = players[1]->GetNextTurnAI();
					//move mouse to that Tile
					SetMousePosition({ gameBoard.spots[aiMove.x][aiMove.y].position.x + 40, gameBoard.spots[aiMove.x][aiMove.y].position.y + 40 });
					aiClick = true;
				}
			}

			//call Update on all gameObjects
			for (int i = 0; i < gameObjectsCount; i++) 
			{
				gameObjects[i]->Update();
			}

			//Check to see if a player has won the game and set winState appropriately
			winState = gameBoard.CheckBoard();
			if (winState == 1)
			{
				players[0]->wins++;
				players[1]->losses++;
			}
			else if (winState == 2)
			{
				players[0]->losses++;
				players[1]->wins++;
			}
			else if (winState == 3)
			{
				players[0]->ties++;
				players[1]->ties++;

				//2 AI's will restart the game themselves
				if (players[0]->AI && players[1]->AI)
				{
					//Unless the AI has found the game to be futile
					if (players[0]->ties >= 10000)
					{
						winState = 4;
					}
					else
					{
						Restart();
					}
				}
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
		DrawText(players[0]->username, 40, 50, 28, Color(BLACK));

		std::string wins1temp = "Wins: " + std::to_string(players[0]->wins);
		DrawText(wins1temp.c_str(), 40, 80, 20, Color(BLACK));

		std::string losses1temp = "Losses: " + std::to_string(players[0]->losses);
		DrawText(losses1temp.c_str(), 40, 100, 20, Color(BLACK));

		std::string ties1temp = "Ties: " + std::to_string(players[0]->ties);
		DrawText(ties1temp.c_str(), 40, 120, 20, Color(BLACK));
		//

		//Draw Player 2 stats
		DrawText(players[1]->username, 620, 50, 28, Color(BLACK));

		std::string wins2temp = "Wins: " + std::to_string(players[1]->wins);
		DrawText(wins2temp.c_str(), 620, 80, 20, Color(BLACK));

		std::string losses2temp = "Losses: " + std::to_string(players[1]->losses);
		DrawText(losses2temp.c_str(), 620, 100, 20, Color(BLACK));

		std::string ties2temp = "Ties: " + std::to_string(players[1]->ties);
		DrawText(ties2temp.c_str(), 620, 120, 20, Color(BLACK));
		//

		//Display who has won the game
		if (winState == 1)
		{
			DrawText("THE WINNER IS X!", 80, 150, 70, Color(players[0]->color));
		}
		else if (winState == 2)
		{
			DrawText("THE WINNER IS O!", 80, 150, 70, Color(players[1]->color));
		}
		else if (winState == 3)
		{
			DrawText("THE GAME IS A TIE!", 30, 150, 70, Color(BLACK));
		}
		else if (winState == 4)
		{
			DrawText("A STRANGE GAME.", 30, 150, 60, DARKGRAY);
			DrawText("THE ONLY WINNING", 30, 200, 60, DARKGRAY);
			DrawText("MOVE IS NOT TO PLAY.", 30, 250, 60, DARKGRAY);
		}
		else//winState == 0
		{
			//Display who's turn it is
			if (turnIsCross)
			{
				DrawText("X's\nturn.", 620, 250, 50, Color(players[0]->color));
			}
			else 
			{
				DrawText("O's\nturn.", 620, 250, 50, Color(players[1]->color));
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
		turn++;
	}

}