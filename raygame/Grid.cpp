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
	//board goes in the middle of the screen
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() / 2;
	//set proper size scale
	scale = 0.5f;

	//create all Tile objects
	//used a double for loop to easily give each Tile
	//a unique location in relation to the Grid
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			spots[x][y] = *new Tile;
			spots[x][y].position.x = position.x + x * 100 - 150;
			spots[x][y].position.y = position.y + y * 100 - 150;
			spots[x][y].scale = 0.1f;
			spots[x][y].Initialize();
			spots[x][y].SetTexture(&Game::blankTexture);
		}
	}
	//apply our texture
	SetTexture(&Game::boardTexture);
	//adjust position to fit the visiable 
	//texture in the middle of the screen
	position.x = 253;
	position.y = 70;

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

//return 0 if game in progress, 1 if X won, 2 if O won, 3 if Tie
int Grid::CheckBoard()
{
	//Check to see if there is any 3 in a row that are
	//the same and not blank by checking all possible
	//winning conditions.

	//Horizontal win conditions
	if (CheckLine(tl, tm, tr) != 0)
	{
		return spots[(int)tl.x][(int)tl.y].value;
	}
	if (CheckLine(ml, mm, mr) != 0)
	{
		return spots[(int)ml.x][(int)ml.y].value;
	}
	if (CheckLine(bl, bm, br) != 0)
	{
		return spots[(int)bl.x][(int)bl.y].value;
	}

	//Vectical win conditions
	if (CheckLine(tl, ml, bl) != 0)
	{
		return spots[(int)tl.x][(int)tl.y].value;
	}
	if (CheckLine(tm, mm, bm) != 0)
	{
		return spots[(int)tm.x][(int)tm.y].value;
	}
	if (CheckLine(tr, mr, br) != 0)
	{
		return spots[(int)tr.x][(int)tr.y].value;
	}

	//Diagonal win conditions
	if (CheckLine(tl, mm, br) != 0)
	{
		return spots[(int)tl.x][(int)tl.y].value;
	}
	if (CheckLine(tr, mm, bl) != 0)
	{
		return spots[(int)tr.x][(int)tr.y].value;
	}

	//Now that we know there is no X or O that is
	//3 in a row, check to see if all Tiles are
	//used up. Then there is a tie.

	
	bool tie = true;
	//search all tiles
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (spots[x][y].value == 0)
			{
				//value == 0 means that tile is blank
				//so the game is not yet a tie
				tie = false;
			}
		}
	}
	if (tie)
	{
		//return the vaule for a tie
		return 3;
	}

	//no end condition. Game is still in progress
	return 0;
}

//return 0 if the 3 Tiles aren't the same or are blank, 1 if all are X, 2 if all are O
int Grid::CheckLine(Vector2 s1, Vector2 s2, Vector2 s3)
{
	//see if the 1st and 2nd Tiles are the same
	if (spots[(int)s1.x][(int)s1.y].value == spots[(int)s2.x][(int)s2.y].value)
	{
		//see if the 1st and 3rd Tiles are the same
		if (spots[(int)s1.x][(int)s1.y].value == spots[(int)s3.x][(int)s3.y].value)
		{
			//all are equal
			//return what the value is
			return spots[(int)s1.x][(int)s1.y].value;
		}
	}

	//they do not equal
	return 0;
}