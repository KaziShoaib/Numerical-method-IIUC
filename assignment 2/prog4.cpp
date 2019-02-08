#include<iostream>

using namespace std;

int main()
{
    int i, j, n;
    double val, yr, x[100], y[100], a, b;
    cout<<"input value of n : ";
    cin>>n;
    cout<<"input values of x :"<<endl;
    n--;
    for(i=0;i<=n;i++)
        cin>>x[i];
    cout<<"input values of y :"<<endl;
    for(i=0;i<=n;i++)
        cin>>y[i];
    cout<<"input y : ";
    cin>>yr;
    val = 0;
    for(i=0;i<=n;i++)
    {
        a = 1;
        b = 1;
        for(j=0;j<=n;j++)
            if(i!=j)
            {
                a *= yr - y[j];
                b *= y[i] - y[j];
            }
        cout<<a<<' '<<b<<' '<<((double)a/(double)b)*x[i]<<endl;
        val += ((double)a/(double)b)*x[i];
    }
    cout<<val<<endl;
    return 0;
}
