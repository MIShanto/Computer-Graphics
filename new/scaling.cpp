#include<graphics.h>
#include<stdio.h>

int xa, ya, xb, yb, mx, my;

void Scaling(int x, int y) // line scaling
{
    //set original line color to red
    setcolor(RED);

    line(xa, ya, xb, yb); // original line

    //scale
    mx = (xa + xb) / 2;
    my = (ya + yb) / 2;

    xa = mx + (xa - mx) * x;
    ya = my + (ya - my) * y;

    xb = mx + (xb - mx) * x;
    yb = my + (yb - my) * y;

    //set scaled line color to white
    setcolor(WHITE);

    line(xa+100, ya, xb+100, yb); // translated scaled line
}

int main()
{
    int gd = DETECT, gm, err;

    initgraph(&gd, &gm, "");

    xa = ya = 50;
    xb = yb = 150;

    Scaling(2,2);

    getch();

    return 0;
}
