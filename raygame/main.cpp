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

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	Game::Start();
	
	// Sign in
	//--------------------------------------------------------------------------------------
	GetTextInput(Game::player1.username, "Player 1: Please enter your username.");
	Game::player1.color = GetColorInput("Player 1: Please pick your player color.");
	
	GetTextInput(Game::player2.username, "Player 2: Please enter your username.");
	Game::player2.color = GetColorInput("Player 2: Please pick your player color.");


	// Gameplay
	//--------------------------------------------------------------------------------------
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		Game::Update();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		Game::Draw();

		EndDrawing();
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        

	return 0;
}

void GetTextInput(char* output, const char* msg)
{
	Rectangle textBox = { GetScreenWidth() / 2 - 200, 180, 425, 50 };
	int letterCount = 0;

	//Input loop
	while (!WindowShouldClose())
	{
		int key = GetKeyPressed();

		if ((key >= 32) && (key <= 125) && (letterCount < 15))
		{
			output[letterCount] = (char)key;
			letterCount++;
			key = 0;
		}
		else if (IsKeyPressed(KEY_ENTER))
		{
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
			letterCount--;
			if (letterCount < 0) letterCount = 0;
			output[letterCount] = '\0';
		}


		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText(msg, 200, 140, 25, BLACK);
		DrawRectangleRec(textBox, LIGHTGRAY);
		DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, RED);
		DrawText(output, textBox.x + 5, textBox.y + 8, 40, MAROON);

		EndDrawing();
	}
}

Color GetColorInput(const char* msg)
{
	Rectangle pink = {10, 200, 80, 80};
	Rectangle red = { 110, 200, 80, 80 };
	Rectangle orange = { 210, 200, 80, 80 };
	Rectangle yellow = { 310, 200, 80, 80 };
	Rectangle green = { 410, 200, 80, 80 };
	Rectangle blue = { 510, 200, 80, 80 };
	Rectangle purple = { 610, 200, 80, 80 };
	Rectangle brown = { 710, 200, 80, 80 };

	while (!WindowShouldClose())
	{
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