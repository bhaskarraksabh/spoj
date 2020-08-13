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
string str;
cin>>str;
unordered_map<char,int>m1;
for(auto i:str)
m1[i]+=1;
string res(str.size(),'N');
int useda,usedb,usedc,usedd;
useda=usedb=usedc=usedd=0;
for(int i=0;i<str.size();i+=2)
{
int np=(i+2)/2;//1
unordered_map<int,int>m2;
for(int j=i;j<i+2;j+=1)
m2[str[j]]+=1;//1 1
int ac=np-m2['A']-useda;//0
int bc=np-m2['B']-usedb;//0
int cc=np-m2['C']-usedc;//1
int dc=np-m2['D']-usedd;//1
useda+=ac+m2['A'];
usedb+=bc+m2['B'];
usedc+=cc+m2['C'];
usedd+=dc+m2['D'];
if(str[i]!='A' && res[i-1]!='A' && ac>0)
{
ac-=1;
res[i]='A';
}
else if(str[i]!='B' && res[i-1]!='B' && bc>0)
{
res[i]='B';
bc-=1;
}
else if(str[i]!='C' && res[i-1]!='C' &&  cc>0)
{
res[i]='C';
cc-=1;
}
else if(str[i]!='D' &&  res[i-1]!='D' && dc>0)
{
res[i]='D';
dc-=1;
}
if(str[i+1]!='A' && res[i]!='A' &&  ac>0)
{
ac-=1;
res[i+1]='A';
}
else if(str[i+1]!='B' && res[i]!='B' &&  bc>0)
{
res[i+1]='B';
bc-=1;
}
else if(str[i+1]!='C' && res[i]!='C' &&  cc>0)
{
res[i+1]='C';
cc-=1;
}
else if(str[i+1]!='D' && res[i]!='D' && dc>0)
{
res[i+1]='D';
dc-=1;
}
}
cout<<res<<endl;
return 0;
}
