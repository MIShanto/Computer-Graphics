#include<iostream>
#include<graphics.h>
#include<math.h>

int main()
{

    initwindow(500, 500);

    int x1=200,y1=200,x2=300,y2=200;
    double angle;

    setcolor(3);
    line(x1,y1,x2,y2);

    printf("Angle of rotation:");
    scanf("%lf", &angle);

    angle=(angle*3.14)/180; //convert to radian

    // clock wise
    int xr = x1+((x2-x1)*cos(angle)-(y2-y1)*sin(angle));
    int yr = y1+((x2-x1)*sin(angle)+(y2-y1)*cos(angle));

    setcolor(2);
    line(x1,y1,xr,yr);

    getch();
    return 0;
}
