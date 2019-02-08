#include<stdio.h>
#include<math.h>

double func(double x)
{
    //return x/(1+pow(x,2));
    return 1/x;
}

int main()
{
    double x[10], y[10], res, a=1, b=7, h;
    int n=6, i;
    h=(b-a)/n;
    x[0]=a;
    y[0]=func(a);
    for(i=1;i<=n;i++)
    {
        x[i]=x[i-1]+h;
        y[i]=func(x[i]);
    }
    res=y[0]+y[n];
    for(i=1;i<n;i++)
        if(i%3==0)
            res+=y[i]*2;
        else
            res+=y[i]*3;
    res=res*(3*h)/8;
    printf("final result : %lf",res);
    return 0;
}
