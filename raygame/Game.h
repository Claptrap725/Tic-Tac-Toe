#pragma once
#include "GameObject.h"
#include <iostream>
#include "Grid.h"

namespace Game
{
	//stores the Texture for an X
	extern Texture2D crossTexture;
	//stores the Texture for an O
	extern Texture2D circleTexture;
	//stores the Texture for a blank image
	extern Texture2D blankTexture;
	//stores the Texture for the game board
	extern Texture2D boardTexture;
	//the gameboard object
	extern Grid gameBoard;
	//true if it is X's turn
	extern bool turnIsCross;

	//called at the start of the game
	void Start();
	//called when the player presses R
	void Restart();
	//called once every frame
	void Update();
	//called after update include all texture drawing
	void Draw();
	//adds a pointer to gameObjects[] so they will be updated and drawn
	void AddGameObject(GameObject* g);
	//called when a player clicks on a tile that hasn't be clicked
	void PlayerUsedTrun();
};