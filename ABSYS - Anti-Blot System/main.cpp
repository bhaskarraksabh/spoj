// IN THE NAME OF GOD
#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long unsigned int
#define LL long long
#define justl long
#define em emplace_back
#define pb push_back
#define INF 1e7+5
#define MOD 1e9+7
#define print printf
#define in scanf
#define pop_back pb1
using namespace std;
typedef pair<int,int> pi;
struct hash_pair { 
template <class T1, class T2> 
size_t operator()(const pair<T1, T2>& p) const
{ 
auto hash1 = hash<T1>{}(p.first); 
auto hash2 = hash<T2>{}(p.second); 
return hash1 ^ hash2; 
} 
}; 
template<class type>
void displaySingle(type &arr)
{
for(auto i:arr)
cout<<i<<" ";
cout<<endl;
}
template<class type>
void displayDouble(type &arr)
{
for(auto i:arr)
cout<<i.first<<" "<<i.second<<endl;
}
template<class type>
void display2D(type &arr)
{
for(auto i:arr)
{
for(auto j:arr[i])
{
print("%d ",j);
}
print("\n");
}
}
int main()
{
int testcases;
in("%d",&testcases);
testcases*=2;
testcases+=1;
while(testcases--)
{
string str;
getline(cin,str);
string str1,str2,str3;
int first=0,second=0;
for(int i=0;i<str.size();i++)
{
if(str[i]=='+')
first=1;
else if(str[i]=='=')
second=1;
else if(first==0)
str1+=str[i];
else if(second==0)
str2+=str[i];
else
str3+=str[i];
}
size_t found1=str1.find("machula");
size_t found2=str2.find("machula");
size_t found3=str3.find("machula");
if(found1!=string::npos)
{
ll num1=stoll(str2);
ll num2=stoll(str3);
ll num3=num2-num1;
cout<<num3<<" + "<<num1<<" = "<<num2<<endl;
}
else if(found2!=string::npos)
{
ll num1=stoll(str1);
ll num2=stoll(str3);
ll num3=num2-num1;
cout<<num1<<" + "<<num3<<" = "<<num2<<endl;
}
else if(found3!=string::npos)
{
ll num1=stoll(str1);
ll num2=stoll(str2);
ll num3=num2+num1;
cout<<num1<<" + "<<num2<<" = "<<num3<<endl;
}
}
return 0;
}
