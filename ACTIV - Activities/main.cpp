#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
class solution
{   
    int n;
    public:vector<pair<int,int>>input;
    const int mod=1e8;
    int dp[100001];
    solution(int n)
    {
        this->n=n;
        input.resize(n);
        memset(dp,0,sizeof(dp));
    }
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        scanf("%d %d",&input[i].first,&input[i].second);
        sort(input.begin(),input.end(),sorter);
    }
    static bool sorter(const pair<int,int>&p1,const pair<int,int>&p2)
    {
        return p1.second<p2.second;
    }
    int c=0;
    vector<pair<int,int>>something;
    void bruteForce(int idx=0)
    {
        if(idx>=n)
        {
            if(something.size()!=0)
            c+=1;
            cout<<"ANSWER"<<endl;
            for(auto i:something)
            cout<<i.first<<" "<<i.second<<endl;
            return;
        }
        if(something.size()==0)
        {
            something.emplace_back(input[idx]);
            bruteForce(idx+1);
            something.erase(something.end()-1);
            bruteForce(idx+1);
        }
        else
        {
            pair<int,int>p1=input[idx];
            pair<int,int>p2=something[something.size()-1];
            if(p1.first>=p2.second)
            {
                something.emplace_back(p1);
                bruteForce(idx+1);
                something.erase(something.end()-1);
                bruteForce(idx+1);
            }
            else
            bruteForce(idx+1);
        }
    }
    int search(int key,int h)
    {
        int low=0;
        int high=h;
        int ind=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(input[mid].second<=key)
            {
                low=mid+1;
                ind=mid;
            }
            else
            high=mid-1;
        }
        return ind;
    }
    int findAns()
    {
        for(int i=0;i<input.size();i+=1)
        {
            if(i==0)
            dp[i]=1;
            else
            {
                int up=search(input[i].first,i-1);
                if(up!=-1)
                dp[i]=(dp[i]+dp[up]+1+dp[i-1])%mod;
                else
                dp[i]=(dp[i-1]+1)%mod;
            }
        }
        return dp[input.size()-1];
    }
};
int main()
{
    int n;
    while(scanf("%d",&n) && n!=-1)
    {
        solution sc(n);
        sc.takeInput();
        //sc.bruteForce();
        string ans=to_string(sc.findAns());
        if(ans.size()==8)
        cout<<ans<<endl;
        else
        {
            int numzero=8-ans.size();
            for(int i=0;i<numzero;i+=1)
            cout<<0;
            cout<<ans<<endl;
        }
    }
    return 0;
}