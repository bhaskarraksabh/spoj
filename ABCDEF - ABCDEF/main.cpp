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
cout<<i<<fixed<<" ";
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
int n;
in("%d",&n);
vector<double>input(n);
for(int i=0;i<n;i++)
in("%lf",&input[i]);
ll c=0;
vector<double>res;
for(int i=0;i<input.size();++i)
{
for(int j=0;j<input.size();++j)
{
for(int k=0;k<input.size();++k)
{
double ans=input[i]*input[j]+input[k];
res.em(ans);
}
}
}
sort(res.begin(),res.end());
//displaySingle(res);
for(int i=0;i<input.size();++i)
{
for(int j=0;j<input.size();++j)
{
for(int k=0;k<input.size();++k)
{
if(input[i]<0 || input[i]>0)
{
double ans=(input[i]*input[j])+(input[i]*input[k]);
ll m=upper_bound(res.begin(),res.end(),ans)-lower_bound(res.begin(),res.end(),ans);
c+=m;
}
}
}
}
cout<<c<<endl;
return 0;
}
