// IN THE NAME OF GOD
// I AM NOT gennady korotkevich  SO I WILL BUILD BRUTE FORCE FIRST :)
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
while(testcases--)
{
unordered_map<int,int>m1;
int n;
in("%d",&n);
vector<int>input(n);
vector<int>res;
for(int i=0;i<n;i+=1)
in("%d",&input[i]);
long long sum=0;
for(int i=0;i+1<input.size();i+=1)
res.em(abs(input[i]-input[i+1]));
int np=res.size();
//displaySingle(res);
for(int i=0;i<np;i+=1)
sum+=(res[i]*(i+1)*(np-i));
print("%lld\n",sum);
}
return 0;
}
