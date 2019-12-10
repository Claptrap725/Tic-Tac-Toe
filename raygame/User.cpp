#include "User.h"


User::User()
{
	//default values
	for (int i = 0; i < 16; i++)
	{
		username[i] = '\0';
	}
	color = WHITE;
	wins = 0;
	losses = 0;
	ties = 0;
}

User::~User()
{
}
