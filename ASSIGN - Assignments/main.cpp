#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<stack>
#include<queue>
#define ll long long 
using namespace std;
class solution
{
    vector<vector<int>>input;
    vector<bool>visited;
    vector<vector<ll>>dp;
    int n;
    ll c;
    public:
    solution (int n)
    {
        c=0;
        this->n=n;
        input.resize(n);
        visited.resize(n,false);
        dp.resize(n+1,vector<ll>(1<<n,-1));
    }
    template<typename T>
    void display(vector<T>input)
    {
        for(auto i:input)
        cout<<i<<" ";
        cout<<endl;
    }
    template<typename T>
    void display2D(vector<vector<T>>input)
    {
        for(auto i:input)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    template<typename T>
    void displayPair(vector<pair<T,T>>input)
    {
        for(auto i:input)
        cout<<i.first<<" "<<i.second<<endl;
    }
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        {
            for(int j=0;j<n;j+=1)
            {
                int num;
                scanf("%d",&num);
                input[i].emplace_back(num);
            }
        }
       // display2D(input);
    }
    vector<pair<int,int>>ans;
    ll bruteForce(ll mask=0,int idx=0)
    {
        if(idx>=n)
        {
           // cout<<mask<<endl;
            return 1;
        }
        if(dp[idx][mask]!=-1)
        return dp[idx][mask];
        dp[idx][mask]=0;
        for(int i=0;i<input[idx].size();i+=1)
        {
            if(input[idx][i] && !(mask&(1<<i)))
            dp[idx][mask]+=bruteForce(mask|(1<<i),idx+1);
        }
        return dp[idx][mask];
    }
    void displayer()
    {
        //printf("%d\n",dp[n][1<<n]);
        //display2D(dp);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcases;
    scanf("%d",&testcases);
    while(testcases--)
    {
        int n;
        scanf("%d",&n);
        //cout<<"Inside"<<endl;
        ll s=1<<n;
        //cout<<s<<endl;
        solution sc(n);
        sc.takeInput();
        printf("%lld\n",sc.bruteForce());
        sc.displayer();
    }
    return 0;
}