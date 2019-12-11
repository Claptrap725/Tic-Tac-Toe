#pragma once
#include "raylib.h"


class User
{
public:
	User();
	~User();

	//Username of the User
	char username[16];
	//User's player color
	Color color;
	//is the user an AI
	bool AI;

	//Total wins this session
	int wins;
	//Total losses this session
	int losses;
	//Total Ties this session
	int ties;

	//returns which tile the AI is choosing
	//[0,0][1,0][2,0]
	//[0,1][1,1][2,1]
	//[0,2][1,2][2,2]
	Int2 GetNextTurnAI();
};