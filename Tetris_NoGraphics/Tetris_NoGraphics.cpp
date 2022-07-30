// Tetris_NoGraphics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

std::wstring tetromino[7];

int Rotate(int px, int py, int r) // takes x,y (px,py) and calculates where shape exists within array+possible rotation (r as 0,1,2,3)
{
    switch (r % 4)
    {
    case 0: return py * 4 + px;        //0 degrees
    case 1: return 12 + py - (py * 4); //90 degrees, starts with 12 as (0,0) in array at 90 degrees is 12
    case 2: return 15 - (py * 4) - px; //180 degrees
    case 3: return 3 - py + (px * 4);  //270 degrees
    }
}

int main()
{
    //Create assets
    tetromino[0].append(L"..X."); //4x4 array of "yes or no"; 4 elements wide by 4 lines deep
    tetromino[0].append(L"..X."); //uses a "full-stop symbol" . to represent empty space and a captial X to represent part of the shape
    tetromino[0].append(L"..X."); //appending this way creates a single string, but easy to see what the shape will be
    tetromino[0].append(L"..X."); //using single array instead of multi-dimensional to allow rotation by indicies+calculations (instead of asset for each shape)

    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"....");

    tetromino[2].append(L".X..");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"....");

    tetromino[3].append(L"....");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");

    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X.");
    tetromino[4].append(L"....");

    tetromino[5].append(L"....");
    tetromino[5].append(L".XX.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");

    tetromino[6].append(L"....");
    tetromino[6].append(L".XX.");
    tetromino[6].append(L".X..");
    tetromino[6].append(L".X..");

    return 0;
}


