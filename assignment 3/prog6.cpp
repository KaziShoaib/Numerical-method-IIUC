#include<cstdio>
#include<cmath>
#include<iostream>
#define lim .0005


using namespace std;

double a[100][100], b[100];
int n;

int main()
{
    int i, j, k;
    printf("input n : ");
    scanf("%d",&n);
    printf("input system of linear equations : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%lf",&a[i][j]);
        scanf("%lf",&b[i]);
    }/*
    for(i=1;i<=n;i++)
    {
        int indx=i;
        for(j=i+1;j<=n;j++)
            if(a[j][i]>a[i][i])
                indx=j;
        for(j=1;j<=n;j++)
        {
            double temp=a[indx][j];
            a[indx][j]=a[i][j];
            a[i][j]=temp;
        }
        double temp=b[indx];
        b[indx]=b[i];
        b[i]=temp;
    }*/
    double x[100]={0}, r[100];
    int flag=0, indx=0;
    while(!flag)
    {
        for(i=1;i<=n;i++)
        {
            r[i]=b[i];
            //printf("%.5lf\n",r[i]);
            for(j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                r[i]-=a[i][j]*x[j];
            }
            r[i]/=a[i][i];
        }
        indx++;/*
        printf("%d:",indx);
        for(i=1;i<=n;i++)
            printf("%.2lf ",r[i]);
        printf("\n");
        char ch;
        //cin>>ch;*/
        int count=0;
        for(i=1;i<=n;i++)
        {

            if(fabs(r[i]-x[i])<lim)
                count++;
            x[i]=r[i];
        }
        flag=count==n;

    }
    printf("total %d iterations\n",indx);
    for(i=1;i<=n;i++)
        printf("%.2lf\n",x[i]);
    return 0;
}
