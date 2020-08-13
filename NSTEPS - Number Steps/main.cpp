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
//for(auto i:m1)
//cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
while(testcases--)
{
int a,b;
in("%d %d",&a,&b);
if(a%2==0 && b%2==0)
{
if(a-b==0 || a-b==2)
{
cout<<a+b<<endl;
}
else
cout<<"No Number"<<endl;
}
else if(a%2!=0 && b%2!=0)
{
if(a-b==0 || a-b==2)
{
cout<<a+b-1<<endl;
}
else
cout<<"No Number"<<endl;
}
else
cout<<"No Number"<<endl;
}
return 0;
}
