#include "Grid.h"
#include "Game.h"
#include "raylib.h"
Vector2 tl;
Vector2 tm;
Vector2 tr;
Vector2 ml;
Vector2 mm;
Vector2 mr;
Vector2 bl;
Vector2 bm;
Vector2 br;

Grid::Grid()
{
	
}
Grid::~Grid()
{
}

void Grid::Initialize()
{
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() / 2;
	rotation = 0;
	scale = 0.5f;
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
	SetTexture(&Game::boardTexture);
	position.x = 253;
	position.y = 70;

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

	initialized = true;
	index = Game::AddGameObject(this);
}

int Grid::CheckBoard()
{
	//FINISH CODING ME
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

	return 0;
}

int Grid::CheckLine(Vector2 s1, Vector2 s2, Vector2 s3)
{
	if (spots[(int)s1.x][(int)s1.y].value == spots[(int)s2.x][(int)s2.y].value)
	{
		if (spots[(int)s1.x][(int)s1.y].value == spots[(int)s3.x][(int)s3.y].value)
		{
			return spots[(int)s1.x][(int)s1.y].value;
		}
	}


	return 0;
}