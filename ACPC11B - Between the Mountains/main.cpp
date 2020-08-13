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
while(testcases--)
{
int n,m;
int k1,k2;
k1=k2=1e9;
in("%d",&n);
vector<int>input(n);
for(int i=0;i<n;++i)
{
int num;
in("%d",&input[i]);
}
in("%d",&m);
vector<int>input1(m);
for(int i=0;i<m;++i)
{
int num;
in("%d",&input1[i]);
}
sort(input.begin(),input.end());
sort(input1.begin(),input1.end());
int i=0;
int j=0;
while(i<input.size() && j<input1.size())
{
k1=min(k1,abs(input[i]-input1[j]));
if(input[i]<input1[j])
i+=1;
else
j+=1;
}
cout<<k1<<endl;
}
return 0;
}
