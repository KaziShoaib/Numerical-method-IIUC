#include<iostream>
#include<cmath>

using namespace std;

int func(int x)
{
    return 2 - x*x;
}

int main()
{
    int x1, x0;
    cout<<"This program finds the root of equation x^2 + x - 2 = 0\n using fixed point method"<<endl;
    cout<<"This program assumes x = 2 - x^2 as the equivalent equation"<<endl<<endl;
    cout<<"input an initial value : ";
    cin>>x0;
    while(1)
    {
        x1=func(x0);
        if(fabs(x1-x0)<.0005)
        {
            cout<<"root is : "<<x1;
            break;
        }
        x0=x1;
    }
    return 0;
}
