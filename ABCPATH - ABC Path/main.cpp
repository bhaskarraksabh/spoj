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
int findAns(int row,int col,int n,int m,vector<vector<char>>arr,vector<vector<int>>&dp,char next,vector<vector<int>>&visited)
{
//cout<<row<<" "<<col<<" "<<next<<endl;
//display2D(dp);
if(row>=n || col>=m || row<0 || col<0 || arr[row][col]!=next || visited[row][col]==1)
return 0;
int res1,res2,res3,res4,res5,res6,res7,res8;
res1=res2=res3=res4=res5=res6=res7=res8=0;
if(dp[row][col]!=-1)
return dp[row][col];
else
{
//dp[row][col]=0;
visited[row][col]=1;
res1=1+findAns(row+1,col,n,m,arr,dp,next+1,visited);
res2=1+findAns(row+1,col+1,n,m,arr,dp,next+1,visited);
res3=1+findAns(row+1,col-1,n,m,arr,dp,next+1,visited);
res4=1+findAns(row,col+1,n,m,arr,dp,next+1,visited);
res5=1+findAns(row,col-1,n,m,arr,dp,next+1,visited);
res6=1+findAns(row-1,col,n,m,arr,dp,next+1,visited);
res7=1+findAns(row-1,col-1,n,m,arr,dp,next+1,visited);
res8=1+findAns(row-1,col+1,n,m,arr,dp,next+1,visited);
}
dp[row][col]=max(max(max(res1,res2),max(res3,res4)),max(max(res5,res6),max(res7,res8)));
return dp[row][col];
}
int main()
{
int n,m;
int c=1;
while(cin>>n>>m && n!=0 && m!=0)
{
vector<vector<char>>arr(n,vector<char>(m));
vector<vector<int>>dp(n,vector<int>(m,-1));
vector<vector<int>>visited(n,vector<int>(m,0));
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
int k=findAns(i,j,n,m,arr,dp,'A',visited);
//cout<<k<<endl;
p=max(p,k);
//cout<<findAns(i,j,n,m,arr,dp,'A')<<endl;
//display2D(dp);
}
}
}
cout<<"Case "<<c++<<": "<<p<<endl;
}
return 0;
}
