#pragma once
#include "GameObject.h"
#include "Tile.h"

class Grid : public GameObject
{
public:
	Grid();
	~Grid();

	//2D array of different places to make a move
	Tile spots[3][3];

	//called shorty after being created
	void Initialize() override;

	//return 0 if game in progress, 1 if X won, 2 if O won, 3 if Tie
	int CheckBoard();
	//return 0 if the 3 Tiles aren't the same or are blank, 1 if all are X, 2 if all are O
	int CheckLine(Vector2 s1, Vector2 s2, Vector2 s3);

};