#include<cstdio>
#include<cmath>
#include<cstdlib>
#define lim 1e-10

using namespace std;

double s[10][10];
int n, count;

double det()
{
    int i, j, k, indx;
    double temp, mul;
    count=0;
    for(k=1;k<=n;k++)
    {
        indx=k;
        for(i=k+1;i<=n;i++)
            if(fabs(s[i][k])>fabs(s[k][k]))
                indx=i;
        if(indx!=k)
        {
            for(j=1;j<=n;j++)
            {
                temp=s[indx][j];
                s[indx][j]=s[k][j];
                s[k][j]=temp;
            }
            count++;
        }
        for(i=k+1;i<=n;i++)
        {
            mul=s[i][k]/s[k][k];
            for(j=1;j<=n;j++)
                s[i][j]=s[i][j]-s[k][j]*mul;
        }
    }
    double r = 1;
    for(i=1;i<=n;i++)
        r*=s[i][i];
    if(count%2)
        r*=-1;
    return r;
}

int main()
{
    int i, j, k, r;
    double mat[10][10], b[10], d;
    printf("input n : ");
    scanf("%d",&r);
    printf("input system of linear equations : \n");
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=r;j++)
        {
            scanf("%lf",&mat[i][j]);
            s[i][j]=mat[i][j];
        }
        scanf("%lf",&b[i]);
    }
    n=r;
    d=det();
    if(fabs(d-0)<lim)
    {
        printf("not possible\n");
        exit(1);
    }
    printf("Solutions:\n\n");
    for(k=1;k<=r;k++)
    {
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=r;j++)
            {
                if(j==k)
                    s[i][j]=b[i];
                else
                    s[i][j]=mat[i][j];
            }
        }
        printf("%.2lf\n",det()/d);
    }
    return 0;
}
