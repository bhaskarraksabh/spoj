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
struct ans
{
int str;
int length;
};
bool comp(struct ans &p1,struct ans &p2)
{
return p1.str<p2.str;
}
int bin_search(vector<ans>s2,int num)
{
int low=0;
int high=s2.size()-1;
while(low<=high)
{
int mid=(low+high)/2;
if(s2[mid].str==num)
return s2[mid].length;
if(num<s2[mid].str)
high=mid-1;
else if(num>s2[mid].str)
low=mid+1;
}
return -1;
}
int main()
{
string a,b;
while(cin>>a>>b && (a!="0" && b!="0"))
{
vector<ans>s1,s2;
string aux1,aux2;
aux1=a;
aux2=b;
int l=2;
ans ans1;
ans1.str=stoi(a);
ans1.length=1;
s1.em(ans1);
ans1.str=stoi(b);
ans1.length=1;
s2.em(ans1);
while(a!="1")
{
string aux;
int sum=0;
int flag=0;
for(int i=0;i<a.size();i++)
sum+=(a[i]-'0')*(a[i]-'0');
for(int i=0;i<s1.size();i++)
{
if(s1[i].str==sum)
{
flag=1;
break;
}
}
if(flag==1)
break;
ans ans1;
ans1.str=sum;
ans1.length=l;
s1.em(ans1);
l+=1;
a=to_string(sum);
}

l=2;
while(b!="1")
{
string aux;
int sum=0;
int flag=0;
for(int i=0;i<b.size();i++)
sum+=(b[i]-'0')*(b[i]-'0');
for(int i=0;i<s2.size();i++)
{
if(s2[i].str==sum)
{
flag=1;
break;
}
}
if(flag==1)
break;
ans ans1;
ans1.str=sum;
ans1.length=l;
s2.em(ans1);
l+=1;
b=to_string(sum);
}
sort(s1.begin(),s1.end(),comp);
sort(s2.begin(),s2.end(),comp);
int flag=0;
int m=1e9;
for(auto i:s1)
{
int search=bin_search(s2,i.str);
if(search!=-1)
{
m=min(m,i.length+search);
}
}
/*for(auto i:s1)
cout<<i.str<<" "<<i.length<<endl;
cout<<endl;
for(auto i:s2)
cout<<i.str<<" "<<i.length<<endl;*/
if(m==1e9)
cout<<aux1<<" "<<aux2<<" "<<0<<endl;
else
cout<<aux1<<" "<<aux2<<" "<<m<<endl;
}
return 0;
}
