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
int n;
in("%d",&n);
vector<int>input(n);
for(int i=0;i<n;++i)
in("%d",&input[i]);
set<int>ap,gp;
int sum=0;
for(int i=0;i<input.size();i++)
sum+=input[i];
for(int i=1;i<n;++i)
{
ap.insert(input[i]-input[i-1]);
if(input[i-1]!=0 || input[i]!=0)
gp.insert(input[i]/input[i-1]);
else
gp.insert(0);
}
if(ap.size()==1 && gp.size()==1)
{
auto it=ap.begin();
auto it2=gp.begin();
if(*(it)==*(it2))
cout<<"both"<<endl;
else
{
int num1=abs(input[1]-input[0]);
if(*(it)==num1)
cout<<"arithmetic"<<endl;
else
cout<<"geometric"<<endl;
}
}
else if(ap.size()==1 && gp.size()>1)
cout<<"arithmetic"<<endl;
else if(gp.size()==1 && ap.size()>1)
cout<<"geometric"<<endl;
else if(ap.size()>1 && gp.size()>1)
cout<<"random"<<endl;
return 0;
}
