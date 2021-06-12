#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "Draw.h"
#include "console.h"

int Random(int, int);

int main() 
{
    int i, posx, posy;
    
    //Set Seed for rand() Function
    srand(time(0));
    //Maximize
    MaximizeOutputWindow();

    for(i = 3; i< 30; i++)
    {
        posy = i-3;
        posx = 25+i-3;
        gotoxy(posy,posx);

        textcolor(LIGHTBLUE);
        Beep(i*50, i*50);
        Square(i);
    }
    for(i = 3; i< 30; i++)
    {
        posy = i-3;
        posx = 133-(i-3)*2;
        gotoxy(posy,posx);

        textcolor(LIGHTRED);
        Beep(i*50, i*50);
        Square(i);
    }

    getch();
    return 0;
}

int Random(int first, int last)
{
    int r;
    last += (1-first);
    r = rand()%last + first;
    return r;
}