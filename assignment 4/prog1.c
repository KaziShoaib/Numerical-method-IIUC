#include<stdio.h>

double x[10], y[10][10], mult[6]={0,0,1,-1,11.0/12.0,-5.0/6.0};
int n;

int main()
{
    int i, j, work, indx, sign;
    double der, secder, xr, h;
    printf("how many values for x and y : ");
    scanf("%d",&n);
    printf("x : ");
    n--;
    for(i=0;i<=n;i++)
        scanf("%lf",&x[i]);
    printf("y : ");
    for(i=0;i<=n;i++)
        scanf("%lf",&y[0][i]);
    printf("at which point do you want to find derivative : ");
    scanf("%lf",&xr);
    h=x[1]-x[0];
    for(i=0;i<=n;i++)
        if(xr==x[i])
            work=i;
    indx=-1;
    for(i=work;i<=n;i++)
    {
        indx++;
        x[indx]=x[i];
        y[0][indx]=y[0][i];
    }
    n=indx;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=n-i;j++)
            y[i][j]=y[i-1][j+1]-y[i-1][j];
    }
    der=0;
    sign=1;
    for(i=1;i<=n;i++)
    {
        der+=sign*(1.0/(double)i)*y[i][0];
        //printf("%lf*%lf/%lf*%lf\n",sign,1.0,(double)i,y[i][0]);
       // printf("%lf\n",y[i][0]);
        sign*=-1;
    }
    der*=1.0/h;
    printf("first derivative %lf\n",der);
    secder=0;
    for(i=2;i<=n;i++)
        secder+=mult[i]*y[i][0];
    secder*=(1/(h*h));
    printf("second derivative %lf\n",secder);
    return 0;
}
