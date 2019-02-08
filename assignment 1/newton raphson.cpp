#include<iostream>
#include<cmath>
#define E .0005

using namespace std;

int n;
double co[100], dco[100], x1, x0, counter;

double val(double x)
{
    int i;
    double r=0;
    for(i=n;i>=0;i--)
        r+=co[i]*pow(x,i);
    //cout<<"f of "<<x<<" is "<<r<<endl;
    return r;
}

double dval(double x)
{
    int i;
    double r=0;
    for(i=n-1;i>=0;i--)
        r+=dco[i]*pow(x,i);
    //cout<<"f prime of "<<x<<" is "<<r<<endl;
    return r;
}

void input(void)
{
    int i;
    cout<<"input degree of equation : ";
    cin>>n;
    for(i=n;i>=0;i--)
    {
        cout<<"input co-efficient of x^"<<i<<" : ";
        cin>>co[i];
        if(i)
            dco[i-1]=co[i]*i;
    }
    cout<<endl<<endl;
    while(true)
    {
        cout<<"input first approximation : ";
        cin>>x0;
        if(dval(x0)>0||dval(x0)<0)
            break;
    }
    counter = 0;
    cout<<endl<<endl;
}

double calc(void)
{
    while(true)
    {
        counter++;
        x1 = x0 - val(x0)/dval(x0);
        cout<<"iteration "<<counter<<endl;
        cout<<" x0 : "<<x0<<" x1 : "<<x1<<endl;
        if(fabs(x1-x0)<E)
            break;
        x0 = x1;
    }
    return x1;
}

int main()
{
    input();
    double root = calc();
    cout<<endl<<endl;
    cout<<"root : "<<root<<endl;
    cout<<"function value : "<<val(root)<<endl;
    cout<<"number of iteration : "<<counter<<endl;
    return 0;
}
