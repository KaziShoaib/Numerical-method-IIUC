#include<stdio.h>
#include<math.h>

double func(double x)
{
    return pow(x,3)+1;
}

int main()
{
    double a, b, h, x[10], y[10], res;
    int n, i;
    printf("input lower limit : ");
    scanf("%lf",&a);
    printf("input upper limit : ");
    scanf("%lf",&b);
    printf("input number of sub-intervals : ");
    scanf("%d",&n);
    h=(b-a)/n;
    x[0]=a;
    y[0]=func(a);
    for(i=1;i<=n;i++)
    {
        x[i]=x[i-1]+h;
        y[i]=func(x[i]);
        printf("%lf\n",y[i]);
    }
    res=y[0]+y[n];
    for(i=1;i<n;i++)
        res+=y[i]*2;
    res*=h/2;
    printf("final result %lf",res);
    return 0;
}
