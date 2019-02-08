#include<cstdio>

using namespace std;

int main()
{
    double x[100], y[100], sx=0, sy=0, sxy=0, sxs=0, a, b;
    int n, i;
    //freopen("2.c.txt","w",stdout);
    printf("how many points : ");
    scanf("%d",&n);
    printf("input x and y values : \n");
    for(i=1;i<=n;i++)
    {
        scanf("%lf %lf",&x[i], &y[i]);
        sx+=x[i];
        sy+=y[i];
        sxy+=x[i]*y[i];
        sxs+=x[i]*x[i];
    }
    printf("n=%d sx=%.2lf sy=%.2lf\nsx=%.2lf sxs=%.2lf sxy=%.2lf\n",n,sx,sy,sx,sxs,sxy);
    a=(sy*sxs-sx*sxy)/(n*sxs-sx*sx);
    b=(n*sxy-sx*sy)/(n*sxs-sx*sx);
    printf("a=%.4lf \nb=%.4lf",a,b);
    return 0;
}
