#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
int n;
while(cin>>n && n!=0)
{
vector<int>input(n);
for(int i=0;i<n;i+=1)
scanf("%d",&input[i]);
sort(input.begin(),input.end());
long ans=0;
for(int i=0;i<input.size();i+=1)
{
for(int j=i+1;j<input.size();j+=1)
{
long target=input[i]+input[j];
int low=0;
int high=input.size()-1;
while(low<=high)
{
int mid=low+(high-low)/2;
if(input[mid]<=target)
low=mid+1;
else
high=mid-1;
}
ans+=input.size()-low;
}
}
printf("%ld\n",ans);
}
return 0;
}
