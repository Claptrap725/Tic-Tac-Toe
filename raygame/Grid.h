#pragma once
#include "GameObject.h"
#include "Tile.h"

class Grid : public GameObject
{
public:
	Grid();
	~Grid();

	Tile spots[3][3];

	void Initialize() override;

	int CheckBoard();
	int CheckLine(Vector2 s1, Vector2 s2, Vector2 s3);

};