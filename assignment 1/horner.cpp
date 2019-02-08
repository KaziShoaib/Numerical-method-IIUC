#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    double co[100], r, x;
    int i, n;
    cout<<"input degree of polynomial : ";
    cin>>n;
    for(i=n;i>=0;i--)
    {
        cout<<"input co-efficient of x^"<<i<<" : ";
        cin>>co[i];
    }
    cout<<"input value of x : ";
    cin>>x;
    r=co[n];
    for(i=n-1;i>=0;i--)
    {
        r = r*x + co[i];
    }
    cout<<"value of polynomial : "<<r<<endl;
    return 0;
}
