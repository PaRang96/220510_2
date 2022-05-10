#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

int Map[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

struct FVector2D
{
	int X;
	int Y;
};

void SetLocation(FVector2D NewLocation);

void DrawBG(FVector2D StartPosition)
{
	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			FVector2D Temp;
			Temp.X = X + StartPosition.X;
			Temp.Y = Y + StartPosition.Y;
			SetLocation(Temp);
			if (Map[Y][X] == 1)
			{
				cout << '#';
			}
			else
			{
				cout << ' ';
			}
		}
	}

}

int main()
{
	bool bRunning = true;
	FVector2D PlayerPosition;
	PlayerPosition.X = 0;
	PlayerPosition.Y = 0;

	srand(static_cast<unsigned int>(time(nullptr)));
	FVector2D StartPosition;
	StartPosition.X = rand() % 10 + 1;
	StartPosition.Y = rand() % 10 + 1;

	while (bRunning)
	{
		int KeyCode = _getch();

		switch (KeyCode)
		{
		case 'w':
		case 'W':
			if (Map[PlayerPosition.Y - 1][PlayerPosition.X] == 1)
			{
				PlayerPosition.Y = PlayerPosition.Y;
				continue;
			}
			PlayerPosition.Y--;
			break;
		case 's':
		case 'S':
			if (Map[PlayerPosition.Y + 1][PlayerPosition.X] == 1)
			{
				PlayerPosition.Y = PlayerPosition.Y;
				continue;
			}
			PlayerPosition.Y++;
			break;
		case 'a':
		case 'A':
			if (Map[PlayerPosition.Y][PlayerPosition.X - 1] == 1)
			{
				PlayerPosition.X = PlayerPosition.X;
				continue;
			}
			PlayerPosition.X--;
			break;
		case 'd':
		case 'D':
			if (Map[PlayerPosition.Y][PlayerPosition.X + 1] == 1)
			{
				PlayerPosition.X = PlayerPosition.X;
				continue;
			}
			PlayerPosition.X++;
			break;
		case 27:
			bRunning = false;
			break;
		}

		PlayerPosition.X = PlayerPosition.X < 1 ? 1 : PlayerPosition.X;
		PlayerPosition.Y = PlayerPosition.Y < 1 ? 1 : PlayerPosition.Y;
		PlayerPosition.X = PlayerPosition.X >= 9 ? 8 : PlayerPosition.X;
		PlayerPosition.Y = PlayerPosition.Y >= 9 ? 8 : PlayerPosition.Y;

		system("cls");

		DrawBG(StartPosition);
		FVector2D Temp;
		Temp.X = PlayerPosition.X + StartPosition.X;
		Temp.Y = PlayerPosition.Y + StartPosition.Y;
		SetLocation(Temp);
		cout << "P";
	}


	return 0;
}

void SetLocation(FVector2D NewLocation)
{
	COORD Cur;
	Cur.X = NewLocation.X;
	Cur.Y = NewLocation.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}