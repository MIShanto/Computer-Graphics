#include<graphics.h>
#include<math.h>
#include<stdio.h>

int main()
{
    int x[4],y[4],i;

    double put_x,put_y,t;

    initwindow(500, 500);

    printf("\n Input four x and y coordinates ");
    for(i=0;i<4;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        putpixel(x[i],y[i],3);
        circle(x[i],y[i],4);
    }

    for(t=0.0;t<=1.0;t=t+0.001)
    {
        put_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        put_y =  pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];

        putpixel(put_x,put_y, WHITE);
    }
    getch();

    closegraph();
}

