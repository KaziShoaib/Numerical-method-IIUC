
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
    cout<<endl<<endl;
    u = (xr-x[0])/(x[1]-x[0]);
    double val = 0;
    double term = 1;
    for(int i = 0;i<=n;i++)
    {
        if(i!=0)
            term*= (u-(i-1));
        //cout<<diff[i][0]<<' '<<term<<endl;
        val+=diff[i][0]*term/fact(i);
        cout<<diff[i][0]<<endl;
        cout<<term<<endl;
        cout<<diff[i][0]*term/fact(i)<<endl<<endl;
        //cout<<val<<endl;
    }
    cout<<val<<endl;
    return 0;
}
