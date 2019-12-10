#include "Grid.h"
#include "Game.h"
#include "raylib.h"

Grid::Grid()
{
	
}
Grid::~Grid()
{
}

//called shorty after being created
void Grid::Initialize()
{
	//set proper size scale
	scale = 0.5f;
	//board goes in the middle of the screen
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() / 2;

	// Create all Tile objects into 2D array
	spots = new Tile*[Game::gridSize];
	for (int i = 0; i < Game::gridSize; ++i)
		spots[i] = new Tile[Game::gridSize];

	//use a double for loop to easily give each Tile
	//a unique location in relation to the Grid
	for (int y = 0; y < Game::gridSize; y++)
	{
		for (int x = 0; x < Game::gridSize; x++)
		{
			spots[x][y].scale = 0.1f;
			spots[x][y].position.x = position.x + x * 80 - Game::gridSize * 40 + 40 - 40;
			spots[x][y].position.y = position.y + y * 80 - Game::gridSize * 40 + 40 - 40;
			spots[x][y].Initialize();
			spots[x][y].SetTexture(&Game::blankTexture);
		}
	}
	//default color
	color = Color(WHITE);

	//we have been initialized
	initialized = true;
	//now add ourselves to the game
	Game::AddGameObject(this);
}

//return 0 if game in progress, 1 if X won, 2 if O won, 3 if Tie
int Grid::CheckBoard()
{
	// used to compare the first Tile in a row (or column or diagonal) to the rest in the same row
	int tempVal = 0;

	//verticle check
	//-----------------------------------------------
	//for every column
	for (int i = 0; i < Game::gridSize; i++)
	{
		//remember the first element in that column
		tempVal = spots[i][0].value;
		//if it isn't blank
		if (tempVal != 0)
		{
			//compare the first element to all the other elements
			for (int j = 0; j < Game::gridSize; j++)
			{
				//if not the same then this column doesn't have a winner
				if (spots[i][j].value != tempVal)
					break;

				if (j + 1 == Game::gridSize)
				{
					//all are the same so return who the winner is
					return tempVal;
				}
			}
		}
	}

	//horizontal check
	//-----------------------------------------------
	//for every row
	for (int i = 0; i < Game::gridSize; i++)
	{
		//remember the first element in that row
		tempVal = spots[0][i].value;
		//if it isn't blank
		if (tempVal != 0)
		{
			//compare the first element to all the other elements
			for (int j = 0; j < Game::gridSize; j++)
			{
				//if not the same then this row doesn't have a winner
				if (spots[j][i].value != tempVal)
					break;

				if (j + 1 == Game::gridSize)
				{
					//all are the same so return who the winner is
					return tempVal;
				}
			}
		}
	}

	//diagonal check (from top left)
	//-----------------------------------------------
	//remember the first element in that diagonal
	tempVal = spots[0][0].value;
	//if it isn't blank
	if (tempVal != 0)
	{
		//compare the first element to all the other elements
		for (int i = 0; i < Game::gridSize; i++)
		{
			//if not the same then this diagonal doesn't have a winner
			if (spots[i][i].value != tempVal)
				break;

			if (i + 1 == Game::gridSize)
			{
				//all are the same so return who the winner is
				return tempVal;
			}
		}
	}

	//diagonal check (from bottem left)
	//-----------------------------------------------
	//remember the first element in that diagonal
	tempVal = spots[0][Game::gridSize - 1].value;
	//if it isn't blank
	if (tempVal != 0)
	{
		//compare the first element to all the other elements
		for (int i = 0; i < Game::gridSize; i++)
		{
			//if not the same then this diagonal doesn't have a winner
			if (spots[i][Game::gridSize - 1 - i].value != tempVal)
				break;

			if (i + 1 == Game::gridSize)
			{
				//all are the same so return who the winner is
				return tempVal;
			}
		}
	}

	//Tie check
	//-----------------------------------------------
	for (int i = 0; i < Game::gridSize; i++)
	{
		for (int j = 0; j < Game::gridSize; j++)
		{
			//if this tile is blank
			if (spots[i][j].value == 0)
			{
				//no win conditions and game is still in progress
				return 0;
			}
		}
	}

	//no win conditions and no blank spots so the game is a tie
	return 3;
}

//called every frame if initilized.
void Grid::Draw()
{
	//Draws a white border around the game board to hide the outside lines of the tiles
	Rectangle rec = { GetScreenWidth() / 2, GetScreenHeight() / 2, Game::gridSize * 80, Game::gridSize * 80 };
	rec.x -= 40 * Game::gridSize;
	rec.y -= 40 * Game::gridSize;
	DrawRectangleLinesEx(rec, 10, RAYWHITE);
}
