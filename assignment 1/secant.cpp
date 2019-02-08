#include<iostream>
#include<cmath>
#define E .0005

using namespace std;

int n, count;
double co[100];

double func(double x)
{
    int i;
    double val=0;
    for(i=n;i>=0;i--)
        val+=co[i]*pow(x,i);
    return val;
}

void input()
{
    int i;
    cout<<"input degree of equation : ";
    cin>>n;
    for(i=n;i>=0;i--)
    {
        cout<<"input co-efficient of x^"<<i<<" : ";
        cin>>co[i];
    }
    cout<<endl;
    count=0;
}

double secant()
{
    double x1, x2, x3, f1, f2;
    cout<<"input two starting values : ";
    cin>>x1>>x2;
    cout<<endl;
    f1=func(x1);
    f2=func(x2);
    while(true)
    {
        x3=(f2*x1-f1*x2)/(f2-f1);
        count++;
        cout<<"iteration "<<count<<" -> "<<endl;
        cout<<"x1 : "<<x1<<endl<<"f(x1) : "<<f1<<endl<<"x2 : "<<x2<<endl<<"f(x2) : "<<f2<<endl<<"x3 : "<<x3<<endl<<endl;
        if(fabs(x3-x2)<E)
            return x3;
        x1=x2;
        f1=f2;
        x2=x3;
        f2=func(x3);
    }
}

int main()
{
    input();
    double root = secant();
    cout<<"root : "<<root<<endl;
    cout<<"function value at root : "<<func(root)<<endl;
    return 0;
}
