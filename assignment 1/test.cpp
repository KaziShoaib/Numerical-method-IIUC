#include<iostream>
#include<cmath>
#define E .0005

using namespace std;

int n, count;
double co[100];

void input(void)
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

double func(double x)
{
    int i;
    double val=0;
    for(i=n;i>=0;i--)
        val+=co[i]*pow(x,i);
    return val;
}

double falspos()
{
    double x1, x2, x0, f1, f2, f0, prev=0;
    do
    {
        cout<<"input initial values : ";
        cin>>x1>>x2;
        f1=func(x1);
        f2=func(x2);
    }while(!(f1*f2<0));
    cout<<endl;
    while(true)
    {
        x0=x1-f1*(x2-x1)/(f2-f1);
        count++;
        cout<<"iteration : "<<count<<endl;
        f0=func(x0);
        if(f0*f1<0)
        {
            x2=x0;
            f2=f0;
        }
        else
        {
            x1=x0;
            f1=f0;
        }
        cout<<"x1 : "<<x1<<"\nf(x1) : "<<f1<<"\nx2 : "<<x2<<"\nf(x2) : "<<f2<<endl<<endl;
        if(fabs(x1-x2)<E)
            return (x1+x2)/2;
        cin>>prev;
    }
}

int main()
{
    input();
    double root = falspos();
    cout<<"Root : "<<root<<endl;
    cout<<"F(Root) : "<<func(root)<<endl;
    return 0;
}
