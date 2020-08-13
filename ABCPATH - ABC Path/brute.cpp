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
//string str;
int a;
int findAns(vector<vector<char>>arr,int r,int c,char next,vector<vector<int>>&dp)
{
cout<<r<<" "<<c<<" "<<next<<endl;
if(c<0)
return 0 ;
if(r<0)
return 0 ;
if(c>=arr[r].size())
{
c=0;
r++;
}
if(r>=arr.size())
return 0;
//if(dp[r][c]!=-1)
//return dp[r][c];
if(arr[r][c]!=next)
return 0;
else 
return 1+(findAns(arr,r,c+1,next+1,dp)+findAns(arr,r+1,c,next+1,dp)+findAns(arr,r+1,c+1,next+1,dp)+ findAns(arr,r+1,c-1,next+1,dp));
//dp[r][c]=a;
//return dp[r][c];
}
int main()
{
int n,m;
int c=1;
while(cin>>n>>m && n!=0 && m!=0)
{
vector<vector<char>>arr(n,vector<char>(m));
vector<vector<int>>dp(n+1,vector<int>(m+1,0));
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
char c;
cin>>arr[i][j];
}
}
int p=0;
for(int i=0;i<arr.size();i++)
{
for(int j=0;j<arr[i].size();j++)
{
if(arr[i][j]=='A')
{
cout<<findAns(arr,i,j,'A',dp)<<endl;
p=max(p,findAns(arr,i,j,'A',dp));
}
}
}
cout<<"Case "<<c++<<": "<<p<<endl;
}
return 0;
}
