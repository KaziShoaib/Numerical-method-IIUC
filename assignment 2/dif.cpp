#include<iostream>

using namespace std;

int n, diff[100][100], x[100];

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
    {
        cout<<"del^"<<i<<" : ";
        for(int j=0;j<=n-i;j++)
        {
            diff[i][j]=diff[i-1][j+1] - diff[i-1][j];
            cout<<diff[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
