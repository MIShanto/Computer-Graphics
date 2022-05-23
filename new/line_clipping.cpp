#include<stdio.h>
#include<math.h>
#include<graphics.h>

int W_Xmin, W_Xmax, W_Ymin, W_Ymax;

typedef struct coordinate
{
    int x, y;
    char code[4];
}Point;

void DrawWindow()
{
    line(W_Xmin, W_Ymin, W_Xmax, W_Ymin );
    line(W_Xmax, W_Ymin, W_Xmax, W_Ymax );
    line(W_Xmax, W_Ymax, W_Xmin, W_Ymax );
    line(W_Xmin, W_Ymax, W_Xmin, W_Ymin );
}

Point SetCode(Point p)
{
    Point ptemp;

    if(p.y<100)
        ptemp.code[0]='1'; //Top
    else
        ptemp.code[0]='0';

    if(p.y>350)
        ptemp.code[1]='1'; //Bottom
    else
        ptemp.code[1]='0';

    if(p.x>450)
        ptemp.code[2]='1'; //Right
    else
        ptemp.code[2]='0';

    if(p.x<150)
        ptemp.code[3]='1'; //Left
    else
        ptemp.code[3]='0';

    ptemp.x = p.x;
    ptemp.y = p.y;

    return ptemp;
}

int Visibility(Point p1, Point p2)
{
    int i, flag = 0;

    for(i=0;i<4;i++)
    {
        if((p1.code[i]!='0') || (p2.code[i]!='0'))
        flag=1; // line is not completely inside
    }

    if(flag == 0) // line completely inside
        return 0;

    //else do additional checks
    for(i=0;i<4;i++)
    {
        // if both have 1 on same bit position, line completely outside
        if((p1.code[i]==p2.code[i]) && (p1.code[i]=='1'))
        return 1;
    }

    return 2;

}

Point Clip(Point p1, Point p2)
{
    Point temp;
    float m, k;
    int x, y, i;

    m=(float)(p2.y-p1.y)/(p2.x-p1.x);

    if(p1.code[3]=='1')
        x = W_Xmin; // left intersection

    if(p1.code[2]=='1')
        x = W_Xmax; // right intersection

    if((p1.code[3]=='1') || (p1.code[2]=='1'))
    {
        k=(p1.y+(m*(x-p1.x)));

        temp.y=k;
        temp.x=x;

        for(i=0;i<4;i++)
            temp.code[i]=p1.code[i];

        if(temp.y<=W_Ymax && temp.y>=W_Ymin)
            return (temp);
    }

    if(p1.code[0]=='1')
        y = W_Ymin; // top intersection

    if(p1.code[1]=='1')
        y = W_Ymax; // down intersection



    if((p1.code[0]=='1') || (p1.code[1]=='1'))
    {
        k=(float)p1.x+(float)(y-p1.y)/m;

        temp.x=k;
        temp.y=y;

        for(i=0;i<4;i++)
            temp.code[i]=p1.code[i];

        return(temp);
    }



}

int main()
{
    int gd = DETECT, gm, v;

    initgraph(&gd, &gm, "");

    //set window boundary
    W_Xmin = 150;
    W_Xmax = 450;
    W_Ymin = 100;
    W_Ymax = 350;

    //set points of line
    Point p1, p2, p3, p4;
    p1.x = 0;
    p1.y = 0;
    p2.x = 500;
    p2.y = 400;

    DrawWindow();

    //draw line before clipping
    line(p1.x, p1.y, p2.x, p2.y);
    delay(2000); // 2 sec delay

    //set binary codes to points
    p1 = SetCode(p1);
    p2 = SetCode(p2);

    v = Visibility(p1,p2);

    if(v==0) // completely inside
    {
        cleardevice();
        delay(1000); // 1 sec delay

        DrawWindow();

        //draw old line
        line(p1.x, p1.y, p2.x, p2.y);
    }
    else if(v==1) // completely outside
    {
        cleardevice();
        delay(1000); // 1 sec delay

        DrawWindow();
    }
    else if(v==2) // clip
    {
        cleardevice();
        delay(1000); // 1 sec delay

        DrawWindow();

        p3 = Clip(p1, p2); // to clip p1
        p4 = Clip(p2, p1); // to clip p2

        //draw clipped line
        line(p3.x, p3.y, p4.x, p4.y);
    }

    getch();

    return 0;
}
