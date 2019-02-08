#include<cstdio>
#include<cmath>
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
    int r, i, j;
    double mat[10][10];
    printf("input n : ");
    scanf("%d",&r);
    printf("input the matrix : \n");
    for(i=1;i<=r;i++)
        for(j=1;j<=r;j++)
        {
            scanf("%lf",&mat[i][j]);
            s[i][j]=mat[i][j];
        }
    n=r;
    printf("value of determinant : %.2lf",det());
    return 0;
}
