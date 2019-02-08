#include<stdio.h>

double func(double x, double y)
{
    return x+y;
}

int main()
{
    double px, py, cx, cy, h, dest, m1, m2, m3, m4;
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
        m1=func(px,py);
        m2=func(px+h/2.0,py+(m1*h)/2.0);
        m3=func(px+h/2.0,py+(m2*h)/2.0);
        m4=func(px+h,py+m3*h);
        cy=py+(1.0/6.0)*(m1+2*m2+2*m3+m4)*h;
        printf("step %d value %lf\n",i,cy);
        px=cx;
        py=cy;
    }
    printf("final result is %lf\n",cy);
    return 0;
}
