#include<iostream>
#include<cmath>
#define E .0005

using namespace std;

int n, deg, counter, iteration;
double co[100], dco[100], x1, x0, roots[100];

void input(void)
{
    int i;
    cout<<"input degree of equation : ";
    cin>>n;
    deg=n;
    for(i=n;i>=0;i--)
    {
        cout<<"input co-efficient of x^"<<i<<" : ";
        cin>>co[i];
    }
    cout<<endl<<endl;
}

void find_der(void)
{
    int i;
    for(i=n;i>0;i--)
        dco[i-1]=co[i]*i;
}

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

void synthetic(double xr)
{
    double b[100];
    int i;
    b[n]=0;
    for(i=n;i>0;i--)
        b[i-1]=co[i]+xr*b[i];
    n--;
    for(i=n;i>=0;i--)
        co[i]=b[i];
}

void nr(void)
{
    find_der();
    while(true)
    {
        cout<<"input first approximation : ";
        cin>>x0;
        if(dval(x0)>0||dval(x0)<0)
            break;
    }
    counter=n;
    while(counter>1)
    {
        //find_der();
        iteration=0;
        while(true)
        {
            iteration++;
            x1 = x0 - val(x0)/dval(x0);
            cout<<"iteration "<<iteration<<endl;
            cout<<" x0 : "<<x0<<endl<<" x1 : "<<x1<<endl;
            if(fabs(x1-x0)<E)
                break;
            x0 = x1;
        }
        roots[counter]=x1;
        synthetic(x1);
        cout<<"root "<<counter<<" : "<<roots[counter]<<endl<<endl;
        counter--;
        x0=x1;
        find_der();
    }
    roots[1]=-co[0]/co[1];
    cout<<"root "<<counter<<" : "<<roots[1]<<endl<<endl;
    //return x1;
}

int main()
{
    input();
    nr();
    int i;
    cout<<endl<<endl<<endl;
    cout<<"roots are : "<<endl;
    for(i=deg;i>0;i--)
    {
        cout<<roots[i]<<endl;
    }
    return 0;
}
