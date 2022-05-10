#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

int map[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

struct FVector2D
{
    int X;
    int Y;
};

void SetLocation(FVector2D NewLocation);

void DrawMap();

int main()
{
    // default settings
    bool bRunning = true;
    FVector2D PlayerPosition;
    PlayerPosition.X = 1;
    PlayerPosition.Y = 1;

    // console output once
    DrawMap();

    SetLocation(PlayerPosition);
    cout << "P";

    // console output while getting input by keyboard
    while (bRunning)
    {
        // input
        int KeyCode = _getch();

        switch (KeyCode)
        {
        case 'w':
        case 'W':
            PlayerPosition.Y--;
            break;
        case 's':
        case 'S':
            PlayerPosition.Y++;
            break;
        case 'a':
        case 'A':
            PlayerPosition.X--;
            break;
        case 'd':
        case 'D':
            PlayerPosition.X++;
            break;
        case 27:
            bRunning = false;
            break;
        }

        // logics
        PlayerPosition.X = (PlayerPosition.X < 1 ? 1 : PlayerPosition.X);
        PlayerPosition.Y = (PlayerPosition.Y < 1 ? 1 : PlayerPosition.Y);
        PlayerPosition.X = (PlayerPosition.X > 17 ? 17 : PlayerPosition.X);
        PlayerPosition.Y = (PlayerPosition.Y > 8 ? 8 : PlayerPosition.Y);

        system("cls");

        // draw map
        DrawMap();

        SetLocation(PlayerPosition);
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

void DrawMap()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] == 1)
            {
                cout << '#' << ' ';
            }
            else
            {
                cout << ' ' << ' ';
            }
        }
        cout << endl;
    }

}