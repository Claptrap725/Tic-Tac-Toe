#include "Grid.h"
#include "Game.h"
#include "raylib.h"
//location used to access the Top Left tile
Vector2 tl;
//location used to access the Top Middle tile
Vector2 tm;
//location used to access the Top Right tile
Vector2 tr;
//location used to access the Middle Left tile
Vector2 ml;
//location used to access the Middle Middle tile
Vector2 mm;
//location used to access the Middle Right tile
Vector2 mr;
//location used to access the Bottem Left tile
Vector2 bl;
//location used to access the Bottem Middle tile
Vector2 bm;
//location used to access the Bottem Right tile
Vector2 br;

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


	spots = new Tile*[Game::gridSize];
	for (int i = 0; i < Game::gridSize; ++i)
		spots[i] = new Tile[Game::gridSize];

	//create all Tile objects
	//used a double for loop to easily give each Tile
	//a unique location in relation to the Grid
	for (int y = 0; y < Game::gridSize; y++)
	{
		for (int x = 0; x < Game::gridSize; x++)
		{
			spots[x][y] = *new Tile;
			spots[x][y].scale = 0.1f;
			spots[x][y].position.x = position.x + x * 80 - Game::gridSize * 40 + 40 - 40;
			spots[x][y].position.y = position.y + y * 80 - Game::gridSize * 40 + 40 - 40;
			spots[x][y].Initialize();
			spots[x][y].SetTexture(&Game::blankTexture);
		}
	}
	//default color
	color = Color(WHITE);


	//set shorcut variables to be the correct locations
	tl.x = 0;
	tm.x = 1;
	tr.x = 2;
	ml.x = 0;
	mm.x = 1;
	mr.x = 2;
	bl.x = 0;
	bm.x = 1;
	br.x = 2;

	tl.y = 0;
	tm.y = 0;
	tr.y = 0;
	ml.y = 1; 
	mm.y = 1;
	mr.y = 1;
	bl.y = 2;
	bm.y = 2;
	br.y = 2;

	//we have been initialized
	initialized = true;
	//now add ourselves to the game
	Game::AddGameObject(this);
}

//return 0 if the 3 Tiles aren't the same or are blank, 1 if all are X, 2 if all are O
int Grid::CheckBoard()
{
	int tempVal = 0;

	//verticle check
	for (int i = 0; i < Game::gridSize; i++)
	{
		tempVal = spots[i][0].value;
		if (tempVal != 0)
		{
			for (int j = 0; j < Game::gridSize; j++)
			{
				if (spots[i][j].value != tempVal)
					break;

				if (j + 1 == Game::gridSize)
				{
					return tempVal;
				}
			}
		}
	}

	//horizontal check
	for (int i = 0; i < Game::gridSize; i++)
	{
		tempVal = spots[0][i].value;
		if (tempVal != 0)
		{
			for (int j = 0; j < Game::gridSize; j++)
			{
				if (spots[j][i].value != tempVal)
					break;

				if (j + 1 == Game::gridSize)
				{
					return tempVal;
				}
			}
		}
	}

	//diagonal check (from top left)
	tempVal = spots[0][0].value;
	for (int i = 0; i < Game::gridSize; i++)
	{
		if (spots[i][i].value != tempVal)
			break;

		if (i + 1 == Game::gridSize)
		{
			return tempVal;
		}
	}

	//diagonal check (from bottem left)
	tempVal = spots[0][Game::gridSize - 1].value;
	for (int i = 0; i < Game::gridSize; i++)
	{
		if (spots[i][Game::gridSize -1 - i].value != tempVal)
			break;

		if (i + 1 == Game::gridSize)
		{
			return tempVal;
		}
	}

	//no win conditions
	return 0;
}

//called every frame if initilized. Draws current texture
void Grid::Draw()
{
	Rectangle rec = { GetScreenWidth() / 2, GetScreenHeight() / 2, Game::gridSize * 80, Game::gridSize * 80 };
	rec.x -= 40 * Game::gridSize;
	rec.y -= 40 * Game::gridSize;
	DrawRectangleLinesEx(rec, 10, RAYWHITE);
}
