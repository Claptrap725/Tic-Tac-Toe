/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
using namespace std;

void GetTextInput(char* input, const char* msg);
Color GetColorInput(const char* msg);
int GetNumberInput(const char* msg);

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(600);

	// used to fix bug at start of game
	bool firstGameFrame = true;

	// ask users which grid size they would like to play on
	Game::gridSize = GetNumberInput("What Grid size do you want to play on?");

	// initilize game based on size of grid
	Game::Start();
	
	// Sign in
	//--------------------------------------------------------------------------------------
	GetTextInput(Game::players[0]->username, "Player 1: Please enter your username.");
	if (Game::players[0]->username[0] == '\0')
	{
		// if the user doesn't type anything
		// ¯\_(o_o)_/¯
		Game::players[0]->username[0] = '¯';
		Game::players[0]->username[1] = '\\';
		Game::players[0]->username[2] = '_';
		Game::players[0]->username[3] = '(';
		Game::players[0]->username[4] = 'o';
		Game::players[0]->username[5] = '_';
		Game::players[0]->username[6] = 'o';
		Game::players[0]->username[7] = ')';
		Game::players[0]->username[8] = '_';
		Game::players[0]->username[9] = '/';
		Game::players[0]->username[10] = '¯';
	}
	//Check if the their name is that of the AI
	if (Game::gridSize == 3 && Game::players[0]->username[0] == 'j')
	{
		if (Game::players[0]->username[1] == 'o')
		{
			if (Game::players[0]->username[2] == 's')
			{
				if (Game::players[0]->username[3] == 'h')
				{
					if (Game::players[0]->username[4] == 'u')
					{
						if (Game::players[0]->username[5] == 'a')
						{
							if (Game::players[0]->username[6] == '\0')
							{
								Game::players[0]->AI = true;
							}
						}
					}
				}
			}
		}
	}
	Game::players[0]->color = GetColorInput("Player 1: Please pick your player color.");

	GetTextInput(Game::players[1]->username, "Player 2: Please enter your username.");
	if (Game::players[1]->username[0] == '\0')
	{
		// if the user doesn't type anything
		// ¯\_(o_o)_/¯
		Game::players[1]->username[0] = '¯';
		Game::players[1]->username[1] = '\\';
		Game::players[1]->username[2] = '_';
		Game::players[1]->username[3] = '(';
		Game::players[1]->username[4] = 'o';
		Game::players[1]->username[5] = '_';
		Game::players[1]->username[6] = 'o';
		Game::players[1]->username[7] = ')';
		Game::players[1]->username[8] = '_';
		Game::players[1]->username[9] = '/';
		Game::players[1]->username[10] = '¯';
	}
	//Check if the their name is that of the AI
	if (Game::gridSize == 3 && Game::players[1]->username[0] == 'j')
	{
		if (Game::players[1]->username[1] == 'o')
		{
			if (Game::players[1]->username[2] == 's')
			{
				if (Game::players[1]->username[3] == 'h')
				{
					if (Game::players[1]->username[4] == 'u')
					{
						if (Game::players[1]->username[5] == 'a')
						{
							if (Game::players[1]->username[6] == '\0')
							{
								Game::players[1]->AI = true;
							}
						}
					}
				}
			}
		}
	}
	Game::players[1]->color = GetColorInput("Player 2: Please pick your player color.");


	// Gameplay
	//--------------------------------------------------------------------------------------
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// update Raylib on first frame to prevent an accidental move
		if (firstGameFrame)
		{
			firstGameFrame = false;
			BeginDrawing();
			ClearBackground(RAYWHITE);
			EndDrawing();
		}
		else
		{
			// Update Game code
			Game::Update();

			// Draw and update Raylib
			BeginDrawing();
			ClearBackground(RAYWHITE);

			Game::Draw();

			EndDrawing();
		}
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        

	return 0;
}

// Opens Text box window and promps user with msg and will set out to user input. Will close when user presses ENTER key
void GetTextInput(char* output, const char* msg)
{
	Rectangle textBox = { GetScreenWidth() / 2 - 200, 180, 425, 50 };
	int letterCount = 0;

	//Input loop
	while (!WindowShouldClose())
	{
		// Get the key pressed this frame
		int key = GetKeyPressed();

		// Check if the key is a letter, number, or symbol
		if ((key >= 32) && (key <= 125) && (letterCount < 15))
		{
			// add character to output and set key to null
			output[letterCount] = (char)key;
			letterCount++;
			key = 0;
		}
		else if (IsKeyPressed(KEY_ENTER))
		{
			// When the user presses enter update Raylib one more time then close text box
			BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawText(msg, 200, 140, 25, BLACK);
			DrawRectangleRec(textBox, LIGHTGRAY);
			DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, RED);
			DrawText(output, textBox.x + 5, textBox.y + 8, 40, MAROON);

			EndDrawing();
			return;
		}

		if (IsKeyPressed(KEY_BACKSPACE))
		{
			// Set the last char to null and lower letterCount to backspace
			letterCount--;
			if (letterCount < 0) letterCount = 0;
			output[letterCount] = '\0';
		}

		// draw currently typed text and update Raylib
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText(msg, 200, 140, 25, BLACK);
		if (Game::gridSize == 3)
			DrawText("To make this player an AI name it \"joshua\"", 160, 400, 25, BLACK);
		DrawRectangleRec(textBox, LIGHTGRAY);
		DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, RED);
		DrawText(output, textBox.x + 5, textBox.y + 8, 40, MAROON);

		EndDrawing();
	}
}

// Opens Color picker window and returns with the Color that the user clicks on. Closes after returning
Color GetColorInput(const char* msg)
{
	// create 8 buttons
	Rectangle pink = {10, 200, 80, 80};
	Rectangle red = { 110, 200, 80, 80 };
	Rectangle orange = { 210, 200, 80, 80 };
	Rectangle yellow = { 310, 200, 80, 80 };
	Rectangle green = { 410, 200, 80, 80 };
	Rectangle blue = { 510, 200, 80, 80 };
	Rectangle purple = { 610, 200, 80, 80 };
	Rectangle brown = { 710, 200, 80, 80 };

	//Input loop
	while (!WindowShouldClose())
	{
		// when the user clicks check to see if they clicked on a button and return if they did
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (CheckCollisionPointRec(GetMousePosition(), pink))
			{
				return Color(PINK);
			}
			else if (CheckCollisionPointRec(GetMousePosition(), red))
			{
				return Color(RED);
			}
			else if (CheckCollisionPointRec(GetMousePosition(), orange))
			{
				return Color(ORANGE);
			}
			else if (CheckCollisionPointRec(GetMousePosition(), yellow))
			{
				return Color(YELLOW);
			}
			else if (CheckCollisionPointRec(GetMousePosition(), green))
			{
				return Color(GREEN);
			}
			else if (CheckCollisionPointRec(GetMousePosition(), blue))
			{
				return Color(BLUE);
			}
			else if (CheckCollisionPointRec(GetMousePosition(), purple))
			{
				return Color(PURPLE);
			}
			else if (CheckCollisionPointRec(GetMousePosition(), brown))
			{
				return Color(BROWN);
			}
		}

		// Draw buttons and cause update for Raylib
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText(msg, 200, 140, 25, BLACK);
		DrawRectangleRec(pink, PINK);
		DrawRectangleRec(red, RED);
		DrawRectangleRec(orange, ORANGE);
		DrawRectangleRec(yellow, YELLOW);
		DrawRectangleRec(green, GREEN);
		DrawRectangleRec(blue, BLUE);
		DrawRectangleRec(purple, PURPLE);
		DrawRectangleRec(brown, BROWN);

		EndDrawing();
	}

	return Color(WHITE);
}

// Opens Number picker (only 2-5) Window and returns the Number clicked on by the user. Closes after returning
int GetNumberInput(const char* msg)
{
	// Create four different buttons
	Rectangle two = { 210, 200, 80, 80 };
	Rectangle three = { 310, 200, 80, 80 };
	Rectangle four = { 410, 200, 80, 80 };
	Rectangle five = { 510, 200, 80, 80 };

	//Input loop
	while (!WindowShouldClose())
	{
		// when the user clicks check to see if they clicked on a button and return if they did
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (CheckCollisionPointRec(GetMousePosition(), two))
			{
				return 2;
			}
			else if (CheckCollisionPointRec(GetMousePosition(), three))
			{
				return 3;
			}
			else if (CheckCollisionPointRec(GetMousePosition(), four))
			{
				return 4;
			}
			else if (CheckCollisionPointRec(GetMousePosition(), five))
			{
				return 5;
			}
		}

		// Draw buttons and cause update for Raylib
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText(msg, 200, 140, 25, BLACK);
		DrawRectangleRec(two, LIME);
		DrawText("2", 240, 230, 40, BLACK);
		DrawRectangleRec(three, LIME);
		DrawText("3", 340, 230, 40, BLACK);
		DrawRectangleRec(four, LIME);
		DrawText("4", 440, 230, 40, BLACK);
		DrawRectangleRec(five, LIME);
		DrawText("5", 540, 230, 40, BLACK);

		EndDrawing();
	}

	return 0;
}