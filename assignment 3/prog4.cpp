#include<cstdio>
#include<cmath>

using namespace std;

double mat[10][10], b[10], x[10];
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
        int indx=i;
        for(j=i+1;j<=n;j++)
            if(fabs(mat[j][i])>fabs(mat[i][i]))
                indx=j;
        //print();
        for(j=1;j<=n;j++)
        {
            double temp=mat[indx][j];
            mat[indx][j]=mat[i][j];
            mat[i][j]=temp;
        }
        double temp=b[indx];
        b[indx]=b[i];
        b[i]=temp;
        //print();
        for(j=i+1;j<=n;j++)
        {
            double piv=mat[j][i]/mat[i][i];
            //printf("%lf\n",piv);
            for(k=1;k<=n;k++)
            {
                mat[j][k]-=mat[i][k]*piv;
                //print();
            }
            b[j]-=b[i]*piv;
            //print();
        }
        //print();
    }
    printf("\n\nAfter Gauss elimination : ");
    print();
    printf("\n\nSolutions : \n");
    for(i=n;i>=1;i--)
    {
        x[i]=b[i];
        for(j=i+1;j<=n;j++)
            x[i]-=mat[i][j]*x[j];
        x[i]/=mat[i][i];
    }
    for(i=1;i<=n;i++)
        printf("x[%d] : %.2lf\n",i,x[i]);

    return 0;
}
