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
    int i, j, k, l, r, c, ri, ci;
    double mat[10][10], co[10][10], b[10], x[10];
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
    double d = det();
    if(fabs(d-0)<lim)
    {
        printf("not possible\n");
        exit(1);
    }
    for(k=1;k<=r;k++)
    {
        for(l=1;l<=r;l++)
        {
            ri=0;
            for(i=1;i<=r;i++)
            {
                if(i==k)
                    continue;
                ri++;
                ci=0;
                for(j=1;j<=r;j++)
                {
                    if(j==l)
                        continue;
                    s[ri][++ci]=mat[i][j];
                }
            }
            n=r-1;
            co[k][l]=det();
            if((k+l)%2)
                co[k][l]*=-1;
            co[k][l]*=mat[k][l];
        }
    }
    double temp;
    printf("\nCo-factor\n");;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=r;j++)
            printf("%6.2lf",co[i][j]);
        printf("\n");
    }
    for(i=1;i<=r;i++)
        for(j=i+1;j<=r;j++)
        {
            temp=co[i][j];
            co[i][j]=co[j][i];
            co[j][i]=temp;
        }
    printf("\ntransposed Co-factor\n");;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=r;j++)
            printf("%6.2lf",co[i][j]);
        printf("\n");
    }
    printf("\nINVERSE\n");
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=r;j++)
        {
            co[i][j]/=d;
            printf("%.2lf ",co[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=r;i++)
    {
        x[i]=0;
        for(j=1;j<=r;j++)
        {
            //printf("%.2lf*%.2lf\n",co[i][j],b[j]);
            x[i]+=co[i][j]*b[j];
        }
    }
    printf("\nSOLUTION\n");
    for(i=1;i<=r;i++)
        printf("%.2lf\n",x[i]);
    return 0;
}
