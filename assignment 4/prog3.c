#include<stdio.h>
#include<math.h>
#define PI 3.1416

double func(double x)
{
    return 1/x;
    //return exp(sin(x));
}

int main()
{
    double a=1, b=7, h, x[10], y[10], res=0;
    int i, n=6;
    h=(b-a)/n;
    printf("%lf\n",h);
    x[0]=a;
    y[0]=func(a);
    for(i=1;i<=n;i++)
    {
        x[i]=x[i-1]+h;
        y[i]=func(x[i]);
    }
    res=y[0]+y[n];
    for(i=1;i<n;i++)
        if(i%2==0)
            res+=y[i]*2;
        else
            res+=y[i]*4;
    res*=h/3;
    printf("final result : %lf\n",res);
    return 0;
}
