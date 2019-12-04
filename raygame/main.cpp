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
#define cout std::cout
#define cin std::cin
char* GetTextInput(char* input, const char* msg);
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	Game::Start();
	//cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	// Sign in
	//--------------------------------------------------------------------------------------
	std::ofstream data;
	data.open("UserData.csv");
	

	data.close();

	
	char username1[16]{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	GetTextInput(username1, "Please enter your username.");
	
	char password1[16]{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	GetTextInput(password1, "Please enter your password.");

	


	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		
		Game::Update();

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		Game::Draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

char* GetTextInput(char* input, const char* msg)
{
	Rectangle textBox = { GetScreenWidth() / 2 - 200, 180, 425, 50 };
	//char input[16] = "\0";
	int letterCount = 0;

	//Input loop
	while (!WindowShouldClose())
	{
		// Get pressed key (character) on the queue
		int key = GetKeyPressed();

		if ((key >= 32) && (key <= 125) && (letterCount < 15))
		{
			input[letterCount] = (char)key;
			letterCount++;
			key = 0;
		}
		else if (IsKeyReleased(KEY_ENTER))
		{
			return input;
		}

		if (IsKeyPressed(KEY_BACKSPACE))
		{
			letterCount--;
			if (letterCount < 0) letterCount = 0;
			input[letterCount] = '\0';
		}


		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText(msg, 240, 140, 25, BLACK);
		DrawRectangleRec(textBox, LIGHTGRAY);
		DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, RED);
		DrawText(input, textBox.x + 5, textBox.y + 8, 40, MAROON);

		EndDrawing();
	}
}