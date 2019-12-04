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

	int wins;
	int losses;
	int ties;
};