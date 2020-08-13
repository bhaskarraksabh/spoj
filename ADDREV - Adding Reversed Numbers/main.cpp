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
ios::sync_with_stdio(0);
cin.tie(0);
int testcases;
in("%d",&testcases);
while(testcases--)
{
ll num1,num2;
in("%lld %lld",&num1,&num2);
ll num3,num4;
num3=num1;
int c=0;
while(num3>0)
{
c++;
num3=num3/10;
}
num3=0;
c-=1;
while(num1>0)
{
int rem=num1%10;
num3+=rem*pow(10,c);
--c;
num1=num1/10;
}
num4=num2;
c=0;
while(num4>0)
{
c++;
num4=num4/10;
}
c-=1;
num4=0;
while(num2>0)
{
int rem=num2%10;
num4+=rem*pow(10,c);
--c;
num2=num2/10;
}
//print("%lld %lld\n",num3,num4);
ll num5=num3+num4;
ll num6=0;
c=0;
num6=num5;
while(num6>0)
{
c++;
num6=num6/10;
}
c-=1;
num6=0;
while(num5>0)
{
int rem=num5%10;
num6+=rem*pow(10,c);
--c;
num5=num5/10;
}
print("%lld\n",num6);
}
return 0;
}
