#include<stdio.h>
#include<graphics.h>

void midp(int r, int xc,int yc)
{
    int x,y;
    float d;

    d=1-r; //(5/4) - r for float
    x=0;
    y=r;

    do
    {
        if(d<0)
         {
         x=x+1;
         d=d+2*x+1;
         }
        else
         {
         x=x+1;
         y=y-1;
         d=d+2*x-2*y+1;
         }
        putpixel(xc+x,yc+y,5);
        putpixel(xc-y,yc-x,5);
        putpixel(xc+y,yc-x,5);
        putpixel(xc-y,yc+x,5);
        putpixel(xc+y,yc+x,5);
        putpixel(xc-x,yc-y,5);
        putpixel(xc+x,yc-y,5);
        putpixel(xc-x,yc+y,5);

    } while(x<y);
}

int main()
{
    int gd=DETECT,gm;
    int xc,yc,r;

    printf("Enter center and radius");

    scanf("%d%d%d",&xc,&yc,&r);

    initgraph(&gd,&gm,"");
    midp(r,xc,yc);

    delay(1500);

    getch();
    closegraph();
    return 0;
}
