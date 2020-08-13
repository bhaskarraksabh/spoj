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
#include<cmath>
using namespace std;
class solution
{
    int testcases;
    string start,end;
    int dp[20][2][200];
    public:
    solution ()
    {

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
        scanf("%d",&testcases);
        while(testcases--)
        {
            cin>>start>>end;
            int first=stoi(start)-1;
            memset(dp,-1,sizeof(dp));
            int a2=findAns(end);
            memset(dp,-1,sizeof(dp));
            int a1=findAns(to_string(first));
            //cout<<a1<<" "<<a2<<endl;
            printf("%d\n",a2-a1);
        }
    }
    bool check(int num)
    {
        if(num==1 || num==0)
        return false;
        for(int i=2;i<=sqrt(num);i+=1)
        {
            if(num%i==0)
            return false;
        }
        return true;
    }
    int findAns(string ender,string aux="",int idx=0,int tight=1,int sum=0)
    {
        if(idx>=ender.size())
        {
            if(check(sum))
            {
            //cout<<aux<<endl;
            return 1;
            }
            else
            return 0;
        }
        if(dp[idx][tight][sum]!=-1)
        return dp[idx][tight][sum];
        int ans=0;
        if(tight==1)
        {
            for(int i=0;i<=ender[idx]-'0';i+=1)
            {
                if(i==ender[idx]-'0')
                {
                    aux+=to_string(i);
                    ans+=findAns(ender,aux,idx+1,1,sum+i);
                    aux.erase(aux.end()-1);
                }
                else
                {
                    aux+=to_string(i);
                    ans+=findAns(ender,aux,idx+1,0,sum+i);
                    aux.erase(aux.end()-1);
                }
            }
        }
        else
        {
            for(int i=0;i<=9;i+=1)
            {
                aux+=to_string(i);
                ans+=findAns(ender,aux,idx+1,0,sum+i);
                aux.erase(aux.end()-1);
            }
        }
        return dp[idx][tight][sum]=ans;
    }
    
};
int main()
{
    solution sc;
    sc.takeInput();
    return 0;
}