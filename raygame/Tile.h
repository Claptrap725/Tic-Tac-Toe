#pragma once
#include "GameObject.h"
class Tile : public GameObject
{
public:
	Tile();
	~Tile();

	int value;
	Rectangle rect;

	void Initialize() override;
	void Update() override;

	void OnClick();
	void ChangeValue(int val);

	void Draw() override;


};