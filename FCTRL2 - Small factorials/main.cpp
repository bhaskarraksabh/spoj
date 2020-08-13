// IN THE NAME OF GOD
#include<bits/stdc++.h>

#define in scanf

using namespace std;
string adder(string res,string aux)
{
string a;
int i,j;
int carry=0;
if(res.size()>aux.size())
{
j=aux.size()-1;
for(i=res.size()-1;i>=0 && j>=0;i--,j--)
{
a+=to_string(((res[i]-'0')+(aux[j]-'0')+carry)%10);
carry=((res[i]-'0')+(aux[j]-'0')+carry)/10;
}
while(i>=0)
{
a+=to_string((res[i]-'0'+carry)%10);
carry=(res[i]-'0'+carry)/10;
i--;
}
if(carry)
a+=to_string(carry);
reverse(a.begin(),a.end());
return a;
}
else
{
j=res.size()-1;
for(i=aux.size()-1;i>=0 && j>=0;i--,j--)
{
a+=to_string(((res[j]-'0')+(aux[i]-'0')+carry)%10);
carry=((res[j]-'0')+(aux[i]-'0')+carry)/10;
}
while(i>=0)
{
a+=to_string((aux[i]-'0'+carry)%10);
carry=(aux[i]-'0'+carry)/10;
i--;
}
if(carry)
a+=to_string(carry);
reverse(a.begin(),a.end());
return a;
}
}
string findMultiple(string s1,string s2)
{
int carry=0;
string res;

if(s1.size()<s2.size())
{
int pos=0;
for(int i=s1.size()-1;i>=0;i--)
{
string aux;
carry=0;
if(pos>0)
{
for(int k=0;k<pos;k++)
aux+='0';
}
for(int j=s2.size()-1;j>=0;j--)
{
int rem=((s1[i]-'0')*(s2[j]-'0')+carry)%10;
aux+=to_string(rem);
carry=((s1[i]-'0')*(s2[j]-'0')+carry)/10;
}
if(carry)
aux+=to_string(carry);
reverse(aux.begin(),aux.end());
if(res=="")
res=aux;
else
res=adder(res,aux);
pos++;
}
}
else
{
int pos=0;
for(int i=s2.size()-1;i>=0;i--)
{
string aux;
carry=0;
if(pos>0)
{
for(int k=0;k<pos;k++)
aux+='0';
}
for(int j=s1.size()-1;j>=0;j--)
{
int rem=((s2[i]-'0')*(s1[j]-'0')+carry)%10;
aux+=to_string(rem);
carry=((s2[i]-'0')*(s1[j]-'0')+carry)/10;
}
if(carry)
aux+=to_string(carry);
reverse(aux.begin(),aux.end());
if(res=="")
res=aux;
else
res=adder(res,aux);
pos++;
}
}
return res;
}
int main()
{
int testcases;
in("%d",&testcases);
vector<string>str(101);
string k="1";
str[0]=k;
str[1]=k;
for(int i=2;i<=100;i++)
{
string s=findMultiple(str[i-1],to_string(i));
str[i]=s;
}
while(testcases--)
{
int num;
in("%d",&num);
cout<<str[num]<<endl;
}
return 0;
}
