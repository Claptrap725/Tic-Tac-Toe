#pragma once
#include "GameObject.h"
#include "Tile.h"

class Grid : public GameObject
{
public:
	Grid();
	~Grid();

	//2D array of different places to make a move
	Tile** spots;


	//called shorty after being created
	void Initialize() override;

	//return 0 if game in progress, 1 if X won, 2 if O won, 3 if Tie
	int CheckBoard();
	//called every frame if initilized. Draws current texture
	void Draw() override;
};