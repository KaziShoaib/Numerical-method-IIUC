#include<stdio.h>
#include<math.h>

double func(double x, double y)
{
    return x-y-1;
    //return 1-y;
}

int main()
{
    double px, py, cx, cy, h, dest;
    int i, n;
    printf("input initial value of x : ");
    scanf("%lf",&px);
    printf("input initial value of y : ");
    scanf("%lf",&py);
    printf("input final value of x : ");
    scanf("%lf",&dest);
    printf("is their any h ? (1 for yes || 0 for no) : ");
    scanf("%d",&i);
    if(i==1)
    {
        printf("input h : ");
        scanf("%lf",&h);
    }
    else
        h=dest-px;
    n=ceil((dest-px)/h);
    for(i=1;i<=n;i++)
    {
        cx=px+h;
        cy=py+h*func(px,py);
        printf("step %d value %lf\n",i,cy);
        px=cx;
        py=cy;
    }
    printf("final result is %lf\n",cy);
    return 0;
}
