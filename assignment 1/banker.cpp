#include<iostream>
#include<string>

using namespace std;

int main()
{
    string num;
    int digit, pos, len, carry=0, i, val;
    cout<<"insert number : ";
    cin>>num;
    len = num.size();
    cout<<"how many digits after decimal point : ";
    cin>>digit;
    pos=num.find(".");
    if(pos!=std::string::npos)
    {
        if((pos+digit+1<len)&&(num[pos+digit+1]>'5'||(num[pos+digit+1]=='5'&&(num[pos+digit]-'0')%2)))
        {
            i=pos+digit;
            do
            {
                //cout<<num[i]<<endl;
                if(num[i]=='.')
                {
                    carry=1;
                    i--;
                    continue;
                }
                val=num[i]-'0';
                val++;
                carry=val/10;
                val=val%10;
                num[i]=val+'0';
                i--;
            }while(carry&&i>=0);
        }
    }
    if(pos!=std::string::npos&&pos+digit<len)
    {
        num.erase(num.begin()+pos+digit+1,num.end());
        if(num[pos+digit]=='.')
            num.erase(num.begin()+pos+digit);
    }
    int count=0;
    if(digit&&pos==std::string::npos)
    {
        num.push_back('.');
        while(digit)
        {
            num.push_back('0');
            digit--;
        }
    }
    if(pos!=std::string::npos&&(pos+digit>=len))
    {
        count=(pos+digit)-(len-1);
        while(count)
        {
            num.push_back('0');
            count--;
        }
    }
    if(carry)
        cout<<"1";
    cout<<num<<endl;
    return 0;
}
