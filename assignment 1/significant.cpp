#include<iostream>
#include<string>

using namespace std;

int main()
{
    string num;
    int pos, trail, bef, aft, len, i, j;
    cin>>num;
    len = num.size();
    trail=0;
    for(j=len-1;j>=0&&num[j]=='0';j--)
        trail++;
    bef=aft=0;
    for(i=0;num[i]=='0'&&i<len&&j>0;i++)
        bef++;
    if(num[i]=='.')
    {
        i++;
        while(num[i]=='0'&&i<len)
        {
            aft++;
            i++;
        }
        if(i==len)
            aft=0;
    }
    //cout<<trail<<' '<<bef<<' '<<aft<<endl;
    len-=bef+aft;
    pos = num.find(".");
    if(pos!=std::string::npos)
        len--;
    else
        len-=trail;
    cout<<len<<endl;
    return 0;
}
