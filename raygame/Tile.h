#pragma once
#include "GameObject.h"
class Tile : public GameObject
{
public:
	Tile();
	~Tile();

	//stores the value of this tile (0 if blank, 1 if X, 2 if O)
	int value;
	//Tile collision box
	Rectangle rect;

	//called shorty after being created
	void Initialize() override;
	//called every frame if initilized
	void Update() override;

	//called when the mouse clicks within the bounds of rect
	void OnClick();
	//changes value and updates texture
	void ChangeValue(int val);
	//called every frame if initilized. Draws current texture
	void Draw() override;

};