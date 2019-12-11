#include "User.h"
#include "Game.h"

User::User()
{
	//default values
	for (int i = 0; i < 16; i++)
	{
		username[i] = '\0';
	}
	color = WHITE;
	AI = false;
	wins = 0;
	losses = 0;
	ties = 0;
}

User::~User()
{
}

//the interworkings of joshua
//returns which tile the AI is choosing
//[0,0][1,0][2,0]
//[0,1][1,1][2,1]
//[0,2][1,2][2,2]
Int2 User::GetNextTurnAI()
{
	//just a pointer so I don't have to type Game::gameBoard.spots everytime
	Grid* grid = &Game::gameBoard;
	// used to compare the first Tile in a row (or column or diagonal) to the rest in the same row
	int tempVal = 0;
	//this AI's value in relation to Tiles
	int val;
	//the oponent's value in relation to Tiles
	int valO;
	if (Game::turnIsCross)
	{
		val = 1;
		valO = 2;
	}
	else
	{
		val = 2;
		valO = 1;
	}

	//if we go first then take the bottem right corner
	if (Game::turn == 1)
		return { 2,2 };

	//see if we can win and take it
	//columns
	for (int x = 0; x < 3; x++)
	{
		if (grid->spots[x][0].value == val && grid->spots[x][1].value == val && grid->spots[x][2].value == 0)
			return { x,2 };
		if (grid->spots[x][1].value == val && grid->spots[x][2].value == val && grid->spots[x][0].value == 0)
			return { x,0 };
		if (grid->spots[x][0].value == val && grid->spots[x][2].value == val && grid->spots[x][1].value == 0)
			return { x,1 };
	}
	//rows
	for (int y = 0; y < 3; y++)
	{
		if (grid->spots[0][y].value == val && grid->spots[1][y].value == val && grid->spots[2][y].value == 0)
			return { 2,y };
		if (grid->spots[1][y].value == val && grid->spots[2][y].value == val && grid->spots[0][y].value == 0)
			return { 0,y };
		if (grid->spots[0][y].value == val && grid->spots[2][y].value == val && grid->spots[1][y].value == 0)
			return { 1,y };
	}
	//diag top left to bottem right
	if (grid->spots[0][0].value == val && grid->spots[1][1].value == val && grid->spots[2][2].value == 0)
		return { 2,2 };
	if (grid->spots[1][1].value == val && grid->spots[2][2].value == val && grid->spots[0][0].value == 0)
		return { 0,0 };
	if (grid->spots[0][0].value == val && grid->spots[2][2].value == val && grid->spots[1][1].value == 0)
		return { 1,1 };

	//diag top right to bottem left
	if (grid->spots[2][0].value == val && grid->spots[1][1].value == val && grid->spots[0][2].value == 0)
		return { 0,2 };
	if (grid->spots[1][1].value == val && grid->spots[0][2].value == val && grid->spots[2][0].value == 0)
		return { 2,0 };
	if (grid->spots[2][0].value == val && grid->spots[0][2].value == val && grid->spots[1][1].value == 0)
		return { 1,1 };

	//see if they will win and stop it
	//columns
	for (int x = 0; x < 3; x++)
	{
		if (grid->spots[x][0].value == valO && grid->spots[x][1].value == valO && grid->spots[x][2].value == 0)
			return { x,2 };
		if (grid->spots[x][1].value == valO && grid->spots[x][2].value == valO && grid->spots[x][0].value == 0)
			return { x,0 };
		if (grid->spots[x][0].value == valO && grid->spots[x][2].value == valO && grid->spots[x][1].value == 0)
			return { x,1 };
	}
	//rows
	for (int y = 0; y < 3; y++)
	{
		if (grid->spots[0][y].value == valO && grid->spots[1][y].value == valO && grid->spots[2][y].value == 0)
			return { 2,y };
		if (grid->spots[1][y].value == valO && grid->spots[2][y].value == valO && grid->spots[0][y].value == 0)
			return { 0,y };
		if (grid->spots[0][y].value == valO && grid->spots[2][y].value == valO && grid->spots[1][y].value == 0)
			return { 1,y };
	}
	//diag top left to bottem right
	if (grid->spots[0][0].value == valO && grid->spots[1][1].value == valO && grid->spots[2][2].value == 0)
		return { 2,2 };
	if (grid->spots[1][1].value == valO && grid->spots[2][2].value == valO && grid->spots[0][0].value == 0)
		return { 0,0 };
	if (grid->spots[0][0].value == valO && grid->spots[2][2].value == valO && grid->spots[1][1].value == 0)
		return { 1,1 };

	//diag top right to bottem left
	if (grid->spots[2][0].value == valO && grid->spots[1][1].value == valO && grid->spots[0][2].value == 0)
		return { 0,2 };
	if (grid->spots[1][1].value == valO && grid->spots[0][2].value == valO && grid->spots[2][0].value == 0)
		return { 2,0 };
	if (grid->spots[2][0].value == valO && grid->spots[0][2].value == valO && grid->spots[1][1].value == 0)
		return { 1,1 };


	//Make a move that will lead to a win
	//Our second turn when we go first
	if (Game::turn == 3)
	{
		//depending on the openents first move pick the best move
		if (grid->spots[2][1].value == valO)//win
			return { 1,2 };

		if (grid->spots[2][0].value == valO)//win
			return { 1,2 };

		if (grid->spots[1][0].value == valO)//win
			return { 0,2 };

		if (grid->spots[0][0].value == valO)//win
			return { 0,2 };

		if (grid->spots[0][1].value == valO)//win
			return { 0,2 };

		if (grid->spots[0][2].value == valO)//win
			return { 0,0 };

		if (grid->spots[1][2].value == valO)//win
			return { 2,0 };

		if (grid->spots[1][1].value == valO)//cat
			return { 2,1 };
	}

	//Our third turn when we go first
	if (Game::turn == 5)
	{
		//all of these moves will cause two winning paths for the AI
		//therefore the AI wins on next round
		if (grid->spots[2][1].value == valO && grid->spots[0][2].value == valO)
			return { 1,1 };

		if (grid->spots[2][0].value == valO && grid->spots[0][2].value == valO)
			return { 1,1 };

		if (grid->spots[1][0].value == valO)//no need to check other pos
			return { 1,1 };

		if (grid->spots[0][0].value == valO)//no need to check other pos
			return { 2,0 };

		if (grid->spots[0][1].value == valO)//no need to check other pos
			return { 2,0 };

		if (grid->spots[1][1].value == valO)//no need to check other pos
			return { 2,0 };

		if (grid->spots[1][2].value == valO && grid->spots[2][1].value == valO)
			return { 0,0 };
	}


	//Make a move that will lead to a cat game
	//Our first turn when we go second
	if (Game::turn == 2)
	{
		if (grid->spots[1][1].value == 0)
			return { 1,1 };
		else
			return { 2,2 };
	}

	//Our second turn when we go second
	if (Game::turn == 4)
	{
		if (grid->spots[2][0].value == valO && grid->spots[0][2].value == valO)
			return { 1,0 };
		if (grid->spots[0][0].value == valO && grid->spots[2][2].value == valO)
			return { 1,0 };
	}

	//if no clear moves then take an open corner
	if (grid->spots[0][0].value == 0)
		return { 0,0 };
	if (grid->spots[2][0].value == 0)
		return { 2,0 };
	if (grid->spots[0][2].value == 0)
		return { 0,2 };
	if (grid->spots[2][2].value == 0)
		return { 2,2 };

	//if no corners are open then take an open side
	if (grid->spots[1][0].value == 0)
		return { 1,0 };
	if (grid->spots[2][1].value == 0)
		return { 2,1 };
	if (grid->spots[1][2].value == 0)
		return { 1,2 };
	if (grid->spots[0][1].value == 0)
		return { 0,1 };

	//something failed
	return { -1,-1 };
}