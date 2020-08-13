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
// basic fibonaaci
vector<string>res;
void findAns(string str,int index,int &c,char a,char b)
{
if(index>=str.size())
{
c+=1;
return;
}
findAns(str,index+1,c,a,b);
if(index+1<str.size())
{
string aux;
aux+=str[index];
aux+=str[index+1];
if(stoi(aux)<=26)
findAns(str,index+2,c,a,b);
}
}
int main()
{
string str;
while(cin>>str && str!="0")
{
vector<string>ans;
int c=0;
char a,b;
findAns(str,0,c,a,b);
cout<<c<<endl;
}
return 0;
}
