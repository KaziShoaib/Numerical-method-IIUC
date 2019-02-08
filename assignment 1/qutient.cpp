#include<iostream>

using namespace std;

int n, a[100], b[100], xr;

void input(void)
{
    int i;
    cout<<"input degree of equation : ";
    cin>>n;
    cout<<endl;
    for(i=n;i>=0;i--)
    {
        cout<<"input co-efficient of x^"<<i<<" : ";
        cin>>a[i];
    }
    cout<<endl;
    cout<<"input a root of the equation : ";
    cin>>xr;
    cout<<endl;
}

void calc()
{
    int i;
    b[n]=0;
    for(i=n;i>=1;i--)
        b[i-1]=a[i]+xr*b[i];
}

void print()
{
    int i;
    cout<<"the quotient polynomial is : ";
    for(i=n-1;i>=0;i--)
    {
        if(b[i]==0)
            continue;
        if(b[i]>0&&i!=n-1)
            cout<<"+ ";
        else if(b[i]<0)
        {
            cout<<"- ";
            b[i]*=-1;
        }
        if(i==0)
            cout<<b[i];
        else if(b[i]!=1)
            cout<<b[i];
        if(i>0)
            cout<<"x";
        if(i>1)
            cout<<"^"<<i;
        cout<<" ";
    }
}

int main()
{
    input();
    calc();
    print();
    return 0;
}
