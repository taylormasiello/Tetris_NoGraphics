// Tetris_NoGraphics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

std::wstring tetromino[7];
int nFieldWidth = 12;           //store elements of field as an unsigned char[]; all map info in single array
int nFieldHeight = 18;
unsigned char* pField = nullptr; //will be allocated dynamically

int nScreenWidth = 120;          //Console Screen Size X (columns) (default X,Y of windows command prompt)
int nScreenHeight = 30;         //Console Screen Size Y (rows)

int Rotate(int px, int py, int r) //takes x,y (px,py) and calculates where shape exists within array+possible rotation (r as 0,1,2,3), returns appropriate index 
{
    switch (r % 4)
    {
    case 0: return py * 4 + px;        //0 degrees
    case 1: return 12 + py - (py * 4); //90 degrees, starts with 12 as (0,0) in array at 90 degrees is 12
    case 2: return 15 - (py * 4) - px; //180 degrees
    case 3: return 3 - py + (px * 4);  //270 degrees
    }

    return 0;
}

int main()
{
    //Create Screen Buffer (effectively use command line as a screen buffer, Creates wchar_t[] for screen width,height (X,Y), filled with blanks)
    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);   //Grabs HANDLE to consoleBuffer
    SetConsoleActiveScreenBuffer(hConsole);       //sets to activeScreenBuffer (cannot use cout, will have to use a seperate command to draw to the buffer
    DWORD dwBytesWritten = 0;

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

    pField = new unsigned char[nFieldWidth * nFieldHeight]; //(Create play field buffer) initializes field[], sets everything to 0 (empty space) unless on side || bottom [] boundary
    for (int x = 0; x < nFieldWidth; x++)    //Board Boundary
        for (int y = 0; y < nFieldHeight; y++)
            pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0; //if x boundary == 0, or it's width || height of field, set to 9 (boundary value)





    //Game Loop
    bool bGameOver = false;

    while (!bGameOver)
    {
        //Draw Field (whole board [bouandaries, empty spaces, tetrominos])
        //iterates thru X&Y, offsets by 2 (to avoid drawing exactly topleft corner, helps show boundary)
        //sets output based on char in string[] (if in field[] value is: 0 will draw ' ', 1-7 for tetrominos will draw as A-G, 8 makes a line as = , border as #)
        //takes whatever position is in field[], that gives a value that's used to index into string[] to determine what's dispalyed on screen
        for (int x = 0; x < nFieldWidth; x++) 
            for (int y = 0; y < nFieldHeight; y++)
                screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]]; 

        //Display Frame; draws screen[] & dimensions starting at position 0,0 to console
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
    }



    

    return 0;
}


