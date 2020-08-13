//मनुष्य होना मेरा भाग्य लेकिन
//हिन्दू होना मेरा सौभाग्य है..!!
//"रामसेतू" और अयोध्या में "मन्दिर" उस समय से है..!!
//जब इस धरती पर न जीजस थे,
//जय श्री राम
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define em emplace_back
using namespace std;
const int INT_MAX=1e9;
class solution
{
    int n,c;
    int x,y;
    vector<vector<int>>input;
    public:
    solution (int n,int c,int x,int y)
    {
        this->n=n;
        this->c=c;
        this->x=x;
        this->y=y;
        input.resize(n+1,vector<int>(c+1,0));
    }
    bool checkEven(long long num)
    {
        if(!(num&1))
        return false;
        else
        return true;
    }
    template<typename T>
    int getLength(T &input)
    {
        return input.size();
    }
    template<typename T,typename Q>
    void swap(T &a,Q &b)
    {
        a=a^b;
        b=a^b;
        a=a^b;
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
                scanf("%d",&input[i][j]);
            }
        }
    }
    int findAns(int r,int col,int sum,vector<vector<int>>&dp)
    {
        //cout<<r<<" "<<col<<" "<<sum<<endl;
        if(r==n-1 && col==c-1)
        {
            return dp[r][col]=input[r][col];
        }
        if(r>=n || col>=c || col<0 || r<0)
        return 1e9;
        if(dp[r][col]!=-1)
        return dp[r][col];
        return dp[r][col]=input[r][col]+min(findAns(r+1,col,sum+input[r][col],dp),findAns(r,col+1,sum+input[r][col],dp));
    }
    void buttomup()
    {
        vector<vector<int>>dp(n,vector<int>(c,-1));
        dp[x-1][y-1]=input[x-1][y-1];
        for(int i=x-1;i<n;i+=1)
        {
            for(int j=y-1;j<c;j+=1)
            {
                if(i==x-1 && j==y-1)
                continue;
                if(i-1<0)
                dp[i][j]=max(dp[i][j],dp[i][j-1]-input[i][j]);
                if(j-1<0)
                dp[i][j]=max(dp[i][j],dp[i-1][j]-input[i][j]);
                if(i-1>=0 && j-1>=0)
                dp[i][j]=max({dp[i][j],dp[i][j-1]-input[i][j],dp[i-1][j]-input[i][j]});
            }
        }
        //display2D(dp);
        if(dp[n-1][c-1]!=-1)
        {
            printf("Y %d\n",dp[n-1][c-1]);
        }
        else
        {
            printf("N\n");
        }
    }
    void findAnsUtil()
    {
        int s=x-1;
        int p=y-1;
        vector<vector<int>>dp1(n,vector<int>(c,-1));
        int a=findAns(x,p,0,dp1);
        //display2D(dp1);
        vector<vector<int>>dp2(n,vector<int>(c,-1));
        int b=findAns(s,y,0,dp2);
        //display2D(dp2);
        int c=min(a,b);
        //cout<<a<<" "<<b<<endl;
        if(c>input[x-1][y-1])
        {
            printf("N\n");
        }
        else
        {
            printf("Y %d\n",input[x-1][y-1]-c);
        }
    }
};
int main()
{
    int n,c;
    scanf("%d %d",&n,&c);
    int x,y;
    scanf("%d %d",&x,&y);
    solution sc(n,c,x,y);
    sc.takeInput();
    //sc.buttomup();
    sc.findAnsUtil();
    return 0;
}