#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#define ll long long
using namespace std;
class solution
{
public:vector<ll>a,b,c,d;
  solution (int n)
  {
      a.resize(n);
      b.resize(n);
      c.resize(n);
      d.resize(n);
  }
  void insert(int n)
  {
      for(int i=0;i<n;i+=1)
        scanf("%lld %lld %lld %lld",&a[i],&b[i],&c[i],&d[i]);
      
  }
  void brute(int n)
  {
      int count=0;
      unordered_map<int,int>m1;
      for(int i=0;i<a.size();i+=1)
      {
          for(int j=0;j<b.size();j+=1)
          {
              for(int k=0;k<c.size();k+=1)
              {
                  for(int l=0;l<d.size();l+=1)
                  {
                      if(a[i]+b[j]+c[k]+d[l]==0)
                      {
                      //printf("%lld %lld\n",a[i]+b[j],c[k]+d[l]);
                      count+=1;
                      }
                  }
              }
          }
      }
      //for(auto i:m1)
      //c+=i.second/2;
      cout<<count<<endl;
  }
  void display(vector<int>arr)
  {
      for(auto i:arr)
      cout<<i<<" ";
      cout<<endl;
  }
  void answer(int n)
  {
      long long unsigned int count=0;
      vector<long>suma,sumb;
      for(int i=0;i<a.size();i+=1)
      {
          for(int j=0;j<b.size();j+=1)
          suma.emplace_back(a[i]+b[j]);
      }
      for(int i=0;i<c.size();i+=1)
      {
          for(int j=0;j<d.size();j+=1)
          {
              sumb.emplace_back(-1*(c[i]+d[j]));
          }
      }
      sort(suma.begin(),suma.end());
      sort(sumb.begin(),sumb.end());
      for(auto i:suma)
      {
          auto it=equal_range(sumb.begin(),sumb.end(),i);
          int n1=it.first-sumb.begin();
          int n2=it.second-sumb.begin();
          count+=abs(n2-n1);
      }
      printf("%lld\n",count);
  }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    scanf("%d",&n);
    solution sc(n);
    sc.insert(n);
    //sc.brute(n);
    sc.answer(n);
    return 0;
}