// IN THE NAME OF GOD
// I AM NOT gennady korotkevich  SO I WILL BUILD BRUTE FORCE FIRST :)
//à¤�à¤¦à¥�à¤¯à¤®à¥�à¤¨ à¤¹à¤¿ à¤¸à¤¿à¤¦à¥�à¤§à¥�à¤¯à¤¨à¥�à¤¤à¤¿ à¤�à¤¾à¤°à¥�à¤¯à¤¾à¤£à¤¿ à¤¨ à¤®à¤¨à¥�à¤°à¤¥à¥�à¤�à¥¤ à¤¨à¤¹à¤¿ à¤¸à¥�à¤ªà¥�à¤¤à¤¸à¥�à¤¯ à¤¸à¤¿à¤�à¤¹à¤¸à¥�à¤¯ à¤®à¥�à¤�à¥� à¤ªà¥�à¤°à¤µà¤¿à¤¶à¤¨à¥�à¤¤à¤¿ à¤®à¥�à¤�à¤¾à¤� Any task can be accomplished only through proactive enthusiasm, never by imaginary thoughts alone
//à¤�à¤¦à¥�à¤§à¤°à¥�à¤¦à¤¾à¤¤à¥�à¤®à¤¨à¤¾à¤¤à¥�à¤®à¤¾à¤¨à¤� à¤¨à¤¾à¤¤à¥�à¤®à¤¾à¤¨à¤®à¤µà¤¸à¤¾à¤¦à¤¯à¥�à¤¤à¥�à¥¤ à¤�à¤¤à¥�à¤®à¥�à¤µ à¤¹à¥�à¤¯à¤¾à¤¤à¥�à¤®à¤¨à¥� à¤¬à¤¨à¥�à¤§à¥�à¤°à¤¾à¤¤à¥�à¤®à¥�à¤µ à¤°à¤¿à¤ªà¥�à¤°à¤¾à¤¤à¥�à¤®à¤¨à¤�//A man must elevate himself by his own self, not degrade himself. Mind is the friend of the individual and his enemy as well
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
int a,b;
in("%d %d",&a,&b);
int c=0;
while(a>0 && b>0)
{
if(a==1 && b==1)
break;
if(a<b)
{
a-=1;
b-=2;
c+=1;
}
else
{
a-=2;
b-=1;
c+=1;
}
}
print("%d\n",c);
}
return 0;
}
