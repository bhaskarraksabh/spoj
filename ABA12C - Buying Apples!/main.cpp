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
for(auto j:i)
{
print("%d ",j);
}
print("\n");
}
}
int findAns(vector<int>input,int n,int index,int c,vector<vector<int>>&dp,int kg,int k)
{
if(c>n)
return 1e5;
if(kg>k)
return 1e5;
if(kg==k)
return 0;
if(index>=input.size())
return 0;
if(dp[c][kg]!=1e5)
return dp[c][kg];
for(int i=1;i<input.size();i+=1)
{
if(input[i]!=-1)
{
dp[c][kg]=min(dp[c][kg],input[i]+findAns(input,n,index,c+1,dp,kg+i,k));
}
}
return dp[c][kg];
}
int main()
{
int testcases;
in("%d",&testcases);
while(testcases--)
{
int n,k;
in("%d %d",&n,&k);
vector<int>input(k+1);
for(int i=1;i<=k;i++)
in("%d",&input[i]);
vector<int>res;
vector<vector<int>>dp(k+1,vector<int>(k+1,1e5));
int ans=findAns(input,n,0,0,dp,0,k);
if(ans==1e5)
cout<<-1<<endl;
else
cout<<ans<<endl;
//display2D(dp);
}
return 0;
}
