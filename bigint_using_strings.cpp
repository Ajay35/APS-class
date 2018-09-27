#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
int smaller(string,string);
string add(string,string);
string subtract(string,string);
string multiply(string,string);
string division(string,string);
int bigger(string,string);
string longgcd(string,string);
char get_sign(string,string);
int compare(string,string);


char get_sign(string str1,string str2)
{
    char sign1='+',sign2='+',sign='*';
    if(str1[0]=='-')
    {
        str1=str1.substr(1);
        sign1='-';
    }
    if(str2[0]=='-')
    {
        str2=str2.substr(1);
        sign2='-';
    }
    int b=bigger(str1,str2);
    //cout<<"b value:"<<b<<endl;
    if(b!=1)
        sign='-';
    //cout<<sign<<endl;
    return sign;
}

int bigger(string str1,string str2)
{
    int big=-1;
    if(str1[0]=='-')
        str1=str1.substr(1);
    if(str2[0]=='-')
        str2=str2.substr(1);
    if(str1.size()>str2.size())
    {
        big=1;
    }
    else if(str1.size()<str2.size())
    {
        big=2;
    }
    else
    {
        for(int i=0;i<str1.size();i++)
        {
            if(str1[i]<str2[i])
            {
                big=2;
            }
        }
        if(big==-1)
            big=1;
    }
    return big;
}
string add(string str1,string str2)
{
      string res="";
      if((str1[0]!='-' && str2[0]!='-'))
    {
        //cout<<"both positive"<<endl;
        int len1=str1.size();
        int len2=str2.size();
        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());
        if(len1>=len2)
        {
            int sum=0,carry=0,i;
            for(i=0;i<len2;i++)
            {
                sum=(str1[i]-'0')+(str2[i]-'0')+carry;
                res+=(sum%10)+'0';
                carry=(sum/10);
            }
            for(int i=len2;i<len1;i++)
            {
                sum=str1[i]-'0'+carry;
                res+=(sum%10)+'0';
                carry=sum/10;
            }
            if(carry!=0)
                res+=carry+'0';
        }
        else
        {
            int sum=0,carry=0,i;
            for(i=0;i<len1;i++)
            {
                sum=(str1[i]-'0')+(str2[i]-'0')+carry;
                res+=(sum%10)+'0';
                carry=(sum/10);
            }
            for(int i=len1;i<len2;i++)
            {
                sum=str2[i]-'0'+carry;
                res+=(sum%10)+'0';
                carry=sum/10;
            }
            if(carry!=0)
                res+=carry+'0';
        }
        reverse(res.begin(),res.end());
    }
    else if(str1[0]=='-' && str2[0]=='-')
    {
        /*addition of both negative numbers*/
        //cout<<"both neg"<<endl;
        str1=str1.substr(1);
        str2=str2.substr(1);
        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());
        int len1=str1.size();
        int len2=str2.size();
        if(len1>=len2)
        {
            int sum=0,carry=0,i;
            for(i=0;i<len2;i++)
            {
                sum=(str1[i]-'0')+(str2[i]-'0')+carry;
                res+=(sum%10)+'0';
                carry=(sum/10);
            }
            for(int i=len2;i<len1;i++)
            {
                sum=str1[i]-'0'+carry;
                res+=(sum%10)+'0';
                carry=sum/10;
            }
            if(carry!=0)
                res+=carry+'0';
        }
        else
        {
            str1=str1.substr(1);
            str2=str2.substr(1);
            reverse(str1.begin(),str1.end());
            reverse(str2.begin(),str2.end());
            len1=str1.size();
            len2=str2.size();
            int sum=0,carry=0,i;
            for(i=0;i<len1;i++)
            {
                sum=(str1[i]-'0')+(str2[i]-'0')+carry;
                res+=(sum%10)+'0';
                carry=(sum/10);
            }
            for(int i=len1;i<len2;i++)
            {
                sum=str2[i]-'0'+carry;
                res+=(sum%10)+'0';
                carry=sum/10;
            }
            if(carry!=0)
                res+=carry+'0';
        }
        reverse(res.begin(),res.end());
        res='-'+res;
    }
    else if(str1[0]=='-' && str2[0]!='-')
    {
        res=subtract(str2,str1.substr(1));
        char s=get_sign(str1,str2);
        if(s!='+' && s!='*')
            res=get_sign(str1,str2)+res;
    }
    else if(str1[0]!='-' && str2[0]=='-')
    {
        res=subtract(str1,str2.substr(1));
        /*char s=get_sign(str1,str2);
        if(s!='+' && s!='*')
            res=get_sign(str1,str2)+res;*/
    }
    else if(str1[0]=='-' && str2[0]=='-')
    {
        str1=str1.substr(1);
        str2=str2.substr(1);
        int len1=str1.size();
        int len2=str2.size();
        if(len1>=len2)
        {
            int sum=0,carry=0,i;
            for(i=0;i<len2;i++)
            {
                sum=(str1[i]-'0')+(str2[i]-'0')+carry;
                res+=(sum%10)+'0';
                carry=(sum/10);
            }
            for(int i=len2;i<len1;i++)
            {
                sum=str1[i]-'0'+carry;
                res+=(sum%10)+'0';
                carry=sum/10;
            }
            if(carry!=0)
                res+=carry+'0';
        }
        else
        {
            int sum=0,carry=0,i;
            for(i=0;i<len1;i++)
            {
                sum=(str1[i]-'0')+(str2[i]-'0')+carry;
                res+=(sum%10)+'0';
                carry=(sum/10);
            }
            for(int i=len1;i<len2;i++)
            {
                sum=str2[i]-'0'+carry;
                res+=(sum%10)+'0';
                carry=sum/10;
            }
            if(carry!=0)
                res+=carry+'0';
        }
        res='-'+res;
        reverse(res.begin(),res.end());
    }
    return res;
}

string subtract(string str1,string str2)
{
    string res="";
    if(str1[0]!='-' && str2[0]!='-')
    {
        /*subtract 2 positive numbers*/
        int b=compare(str1,str2);
        if(b!=1)
        {
            //cout<<"which is bigger:"<<b<<endl;
            swap(str1,str2);
        }
        int len1=str1.size();
        int len2=str2.size();
        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());
        int sub=0,carry=0,i;
        for(i=0;i<len2;i++)
        {
            sub=(str1[i]-'0')-(str2[i]-'0')-carry;
            if(sub<0)
            {
                sub+=10;
                res+=(sub+'0');
                carry=1;
            }
            else
            {
                res+=(sub+'0');
                carry=0;
            }
        }
        for(int i=len2;i<len1;i++)
        {
            sub=str1[i]-'0'-carry;
            if(sub<0)
            {
                sub+=10;
                res+=(sub+'0');
                carry=1;
            }
            else
            {
                res+=(sub+'0');
                carry=0;
            }
        }
        reverse(res.begin(),res.end());
        res.erase(0, min(res.find_first_not_of('0'), res.size()-1));
        if(b!=1)
            swap(str1,str2);

         if(b==2)
             res='-'+res;
    }
    else if(str1[0]=='-' && str2[0]=='-')
    {
        res=add(str2.substr(1),str1);
    }
    else if(str1[0]!='-' && str2[0]=='-')
    {
        res=add(str1,str2.substr(1));
    }
    else if(str1[0]=='-' && str2[0]!='-')
    {
        res=add(str1.substr(1),str2);
        res='-'+res;
    }
    return res;
}
string multiply(string str1,string str2)
{
    char sign1='+',sign2='+';
    if(str1[0]=='-')
    {
        sign1='-';
        str1=str1.substr(1);
    }
    if(str2[0]=='-')
    {
        sign2='-';
        str2=str2.substr(1);
    }
        int len1=str1.size(),len2=str2.size(),count=0;
        vector<int> result(len1+len2,0);
        string res="";
        for(int i=len1-1;i>=0;i--)
        {
            for(int j=len2-1;j>=0;j--)
            {
                result[i+j+1]+=(str1[i]-'0')*(str2[j]-'0');
            }
        }  
        for (int i=len1+len2-1;i>0;i--)
        {
            if (result[i]>=10)
            {
                result[i-1]+=result[i]/10;
                result[i]%=10;
            }
        }
        for(int i=0;i<result.size();i++)
        {
            if(result[i]==0 && i==count) 
                ++count;
            else
                res+= result[i]+'0';
        }
        if(res=="")
            res="0";
        if((sign1=='-' && sign2=='-') || (sign1=='+' && sign2=='+'))
            res=res;
        else
            res='-'+res;
        return res;
}
string division(string str1,string str2)
{
    string count="",res="",one="1";
    int b=1;
    char sign='+';
    if(str1[0]=='-')
    {
        sign='-';
        str1=str1.substr(1);
    }
    else if(str1[0]=='-')
    {
        if(sign=='-')
            sign='+';
        str2=str2.substr(1);
    }
    res=str1;
   // cout<<res<<" "<<str2<<endl;
    while(b!=0 && b!=2)
    {    
        //cout<<"res:"<<res<<endl;
        b=compare(res,str2);
       // cout<<"compare value:"<<b<<endl;
        //char c=getchar();
        if(b==0)
        {
            count=add(count,one);
            break;
        }
        if(b==2)
            break;
        res=subtract(res,str2);
        count=add(count,one);
       // cout<<"count:"<<count<<endl;
    }
    if(count=="")
        count="0";
    return count;
}
int compare(string str1,string str2)
{
    if(str1.size()>str2.size())
        return 1;
    else if(str1.size()<str2.size())
        return 2;
    for(int i=0;i<str1.size();i++)
    {
        if(str1[i]>str2[i])
        {
            return 1;
        }
        if(str2[i]>str1[i])
        {
            return 2;
        }
    }
    return 0;
}
string longgcd(string str1,string str2)
{
    if(str1[0]=='-')
    {
        str1=str1.substr(1);
    }
    string lgcd="";
    if(str2[0]=='-')
    {
        str2=str2.substr(1);
    }
    while(str1!=str2)
    {
        int b=compare(str1,str2);    
        if(b==1)
        {
            str1=subtract(str1,str2);
        }
        else if(b==2)
        {
            str2=subtract(str2,str1);
        }
    }
    return str1;
}

int main(int argc, char const *argv[])
{
    int t,k;
    string str1,str2;
    cin>>t;
    while(t--)
    {
        cin>>str1;
        cin>>str2;
        cin>>k;

        if(k==1)
        {
            cout<<add(str1,str2)<<endl;
        }
        else if(k==2)
        {
            cout<<subtract(str1,str2)<<endl;
        }
        else if(k==3)
        {
            cout<<multiply(str1,str2)<<endl;
        }
        else if(k==4)
        {
            cout<<division(str1,str2)<<endl;
        }
        else
        {
            cout<<longgcd(str1,str2)<<endl;
        }
        //cout<<"add:"<<add(str1,str2)<<endl;
        //cout<<"sub:"<<subtract(str1,str2)<<endl;
        //cout<<"prod:"<<multiply(str1,str2)<<endl;
        //cout<<"div:"<<division(str1,str2)<<endl;
        //cout<<"gcd:"<<longgcd(str1,str2)<<endl;
    }
    return 0;
}
