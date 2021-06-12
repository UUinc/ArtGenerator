#ifndef DRAW_H
#define DRAW_H
#endif

#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

//Functions Prototype
void Line(int, char);
void Rect(int, int);
void Square(int);
void Triangle(int);
void Circle(int);
int Pythagoras(int, int);

//length how long the line
//rotation 'H' : horizontal | 'V' : vertical | 'D' : Diagonal
void Line(int length, char rotation)
{
    int i,j;
    int posX = wherex();
    int posY = wherey();

    if(length < 1) return; 

    rotation = toupper(rotation);

    switch(rotation)
    {
        case 'H':
            for(i=0; i<length; i++)
            {
                gotoxy(posY,posX+i);
                printf("\xC4");
            }
            break;
        case 'V':
            for(i=0; i<length; i++)
            {
                gotoxy(posY+i,posX);
                printf("\xB3");
            }
            break;
        case 'D':
            for(i=0; i<length; i++)
            {
                gotoxy(posY+i,posX+i);
                printf("\x5C");
            }
            break;
    }    
}
void Rect(int L, int l)
{
    int i;
    int pos;
    int posX = wherex();

    //Error small length
    if(L < 3 || l < 3) return;

    //Left Up Corner 
    printf("\xDA");
    //Up Side
    Line(L-2,'H');
    //Right Up Corner 
    printf("\xBF\n");
    //Get the current position (Left Side)
    //to use the same position for (Right Side) 
    pos = wherey();
    //Move cursor according the previous position
    gotoxy(wherey(), posX);
    //Left Side
    Line(l-2,'V');
    //Move cursor according the previous position
    gotoxy(pos+l-2, posX);
    //Left Down Corner 
    printf("\xC0");
    //Down Side
    Line(L-2,'H');
    //Move Cursor the opposite side of left side (Right Side)
    gotoxy(pos, posX+L-1);
    //Right Side
    Line(l-2,'V');
    //Move Cursor the down by 1
    gotoxy(pos+l-2, posX+L-1);
    //Right Down Corner 
    printf("\xD9");
}
void Square(int length)
{
    Rect(length,(length+1)/2);
}
void Triangle(int length)
{
    int i, pos, len;

    len = length/2;

    gotoxy(wherey(),length/2);
    printf(".\n");
    pos = wherey();
    
    for(i=1; i<len;i++)
    {
        gotoxy(wherey(),length/2-i);
        printf("/\n");
    }
    gotoxy(wherey()-1,wherex()+2);
    
    for(i=0; i<length-3; i++)
    {
        printf("_");
    }

    for(i=0; i<len-1;i++)
    {
        gotoxy(pos+i,length/2+1+i);
        printf("\\\n");
    }
}
int Pythagoras(int a, int radius)
{
    return (int) sqrt(pow(radius,2) - pow(a,2));
}
void Circle(int radius)
{
    //still working on it -_-
}