#include<graphics.h>
#include<stdio.h>

int xa, ya, xb, yb, tx, ty;

void Translation() // line translation
{
    //set original line color to red
    setcolor(RED);

    line(xa, ya, xb, yb); // original line

    //translate
    xa += tx;
    xb += tx;

    ya += ty;
    yb += ty;

    //set translated line color to white
    setcolor(WHITE);

    line(xa, ya, xb, yb); // translated line
}

int main()
{
    int gd = DETECT, gm, err;

    initgraph(&gd, &gm, "");

    xa = ya = 50;
    xb = yb = 150;
    tx = 100;
    ty = 0;

    Translation();

    getch();

    return 0;
}
