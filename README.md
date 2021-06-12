# ArtGenerator
let's try make art using code.

First of all this code is just for fun purpose, I wanted to make some art using code so ended up making weird shapes, take a look at the picture (RedBluePortals.jpg).

if you are using BORLAND as compiler you are fine, if not and you dont have gotoxy(), wherex(), wherey(), textcolor(), delay() functions here how you can create them yourself :

DON'T FORGET INCLUDING WINDOWS HEADER
#include <windows.h>
//GOTOXY
void gotoxy(int line, int column)
{
  // Create a COORD structure and fill in its members.
  // This specifies the new position of the cursor that we will set.
  COORD coord;
  coord.X = column;
  coord.Y = line;

  // Obtain a handle to the console screen buffer.
  // (You're just using the standard console, so you can use STD_OUTPUT_HANDLE
  // in conjunction with the GetStdHandle() to retrieve the handle.)
  // Note that because it is a standard handle, we don't need to close it.
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  // Finally, call the SetConsoleCursorPosition function.
  if (!SetConsoleCursorPosition(hConsole, coord))
  {
      // Uh-oh! The function call failed, so you need to handle the error.
      // You can call GetLastError() to get a more specific error code.
      // ...
  }
}
//WHEREX
int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return csbi.dwCursorPosition.X;
}
//WHEREX
int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return csbi.dwCursorPosition.Y;
}
//TEXTCOLOR
void textcolor (int color)
{
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      color + (__BACKGROUND << 4));
}
//DELAY
void delay (int ms)
{
    Sleep(ms);
}

if you have any question feel free to ask
gmail : uu.soft.inc@gmail.com
twitter : https://twitter.com/yahya_lz
