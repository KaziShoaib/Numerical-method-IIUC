#include<cstdio>

using namespace std;

double mat[10][10], b[10];
int n;

void print()
{
    int i, j;
    printf("\n\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf(" %.2lf",mat[i][j]);
        printf(" %.2lf",b[i]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int  i, j, k;
    //freopen("1.c.txt","w",stdout);
    printf("input n : ");
    scanf("%d",&n);
    printf("input system of linear equations : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%lf",&mat[i][j]);
        scanf("%lf",&b[i]);
    }
    for(i=1;i<=n;i++)
    {
        //printf("%d\n",i);
        //print();
        double a=mat[i][i];
        for(j=1;j<=n;j++)
            mat[i][j]/=a;
        b[i]/=a;
        //print();
        for(j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            double piv=mat[j][i];
            //printf("%lf\n",piv);
            for(k=1;k<=n;k++)
            {
                mat[j][k]-=mat[i][k]*piv;
                //print();
            }
            b[j]-=b[i]*piv;
            print();
        }
        //print();
    }
    printf("\n\nAfter running Gauss-Jordan elimination");
    print();
    printf("\n\nSolutions\n");
    for(i=1;i<=n;i++)
        printf("x[%d] : %.2lf\n",i,b[i]);
    return 0;
}
