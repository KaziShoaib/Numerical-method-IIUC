#include<iostream>

using namespace std;

int main()
{
    double diff[100][100], x[100], term, val, xr;
    int i, j, n;
    cout<<"input n : ";
    cin>>n;
    n--;
    cout<<"input values of x ";
    for(i=0;i<=n;i++)
        cin>>x[i];
    cout<<"input values of y ";
    for(i=0;i<=n;i++)
        cin>>diff[0][i];
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            diff[i][j]=(diff[i-1][j]-diff[i-1][j-1])/(x[j]-x[j-i]);
            //cout<<diff[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"input x : ";
    cin>>xr;
    val = 0;
    term = 1;
    for(i=0;i<=n;i++)
    {
        if(i)
            term*=(xr-x[i-1]);
        //cout<<term<<' '<<diff[i][i]*term<<endl;
        val+=diff[i][i]*term;
    }
    cout<<"answer is : ";
    cout<<val<<endl;
}
