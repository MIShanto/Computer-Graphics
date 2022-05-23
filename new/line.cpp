#include<graphics.h>
#include<stdio.h>

void Bresenham(int xa, int ya, int xb, int yb)
{
    int dx = abs(xa-xb);
    int dy = abs(ya-yb);
    int p = 2*dy - dx; // p0
    int twoDy = 2*dy;
    int twoDyDx = 2*(dy-dx);
    int x, y, xEnd;

    if(xa >= xb)
    {
        x = xb;
        y = yb;
        xEnd = xa;
    }
    else
    {
        x = xa;
        y = ya;
        xEnd = xb;
    }

    putpixel(x, y, WHITE);

    while(x < xEnd)
    {
        x++;

        if(p < 0)
        {
            p = p + twoDy;
        }
        else
        {
            y++;
            p += twoDyDx;
        }

        putpixel(x, y, WHITE);
    }

}

int main()
{
    initwindow(500,500);

    Bresenham(100, 5, 200, 110);

    getch();

    return 0;
}
