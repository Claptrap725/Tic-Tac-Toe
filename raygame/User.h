#pragma once
#include "raylib.h"

class User
{
	//Using private to store passwords? Top notch security am I right?
private:
	//Password of the user
	char password[15];
public:
	User();
	~User();

	//Username of the User
	char username[15];
	//User's player color
	Color color;

	int allTimeWins;
	int allTimeLosses;
	int allTimeTies;
};