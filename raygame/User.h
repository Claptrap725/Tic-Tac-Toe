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

	//Total wins this session
	int wins;
	//Total losses this session
	int losses;
	//Total Ties this session
	int ties;
};