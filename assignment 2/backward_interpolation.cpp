
#include<iostream>

using namespace std;

double fact(int x)
{
    double r = 1;
    for(int i=2;i<=x;i++)
        r*=i;
    return r;
}

double diff[100][100], x[100], xr, u, val;
int n;

int main()
{
    cout<<"input n : ";
    cin>>n;
    n--;
    cout<<"input the values of x : "<<endl;
    for(int i=0;i<=n;i++)
        cin>>x[i];
    cout<<"input the values of y : "<<endl;
    for(int i=0;i<=n;i++)
        cin>>diff[0][i];
    cout<<endl<<endl;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n-i;j++)
            diff[i][j]=diff[i-1][j+1] - diff[i-1][j];
    cout<<"input x : ";
    cin>>xr;
    u = (xr-x[n])/(x[1]-x[0]);
    cout<<"u : "<<u<<endl<<endl;
    double val = 0;
    double term = 1;
    for(int i = 0;i<=n;i++)
    {
        if(i)
            term*= (u+(i-1));
        //cout<<diff[i][n-i]<<' '<<term<<endl;
        val+=diff[i][n-i]*term/fact(i);
        //cout<<val<<endl;
        cout<<"diff : "<<diff[i][n-i]<<endl;
        cout<<"term : "<<term<<endl;
        cout<<"adding : "<<diff[i][n-i]*term/fact(i)<<endl<<endl;
    }
    cout<<val<<endl;
    return 0;
}

