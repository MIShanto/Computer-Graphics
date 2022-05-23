#include<graphics.h>
#include<stdio.h>

void MidpointCircle(int r, int xc, int yc)
{
    int x, y;
    float p;

    p=1-r; //(5/4) - r for float
    x = 0;
    y = r;

    do
    {
        if(p<0)
        {
            x++;

            p += 2*x + 1;
        }
        else
        {
            x++;
            y--;

            p += 2*x + 1 - 2*y;
        }

        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);

        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);

        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
    while(x < y);
}
int main()
{
   initwindow(500,500);

    MidpointCircle(100, 100, 100);

    getch();

    return 0;
}
