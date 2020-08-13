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
class solution
{
    int h,w;
    vector<vector<int>>input,dp;
    public:
    solution (int h,int w)
    {
        this->h=h;
        this->w=w;
        input.resize(h,vector<int>(w,0));
        dp.resize(h,vector<int>(w,-1));
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
    int m=0;
    void takeInput()
    {
        for(int i=0;i<h;i+=1)
        {
            for(int j=0;j<w;j+=1)
            {
                scanf("%d",&input[i][j]);
            }
        }
        cout<<findAns()<<endl;

    }
    int findAns()
    {
        for(int i=0;i<input[0].size();i+=1)
        dp[0][i]=input[0][i];
        for(int i=1;i<h;i+=1)
        {
            for(int j=0;j<w;j+=1)
            {
                if(j-1>=0)
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+input[i][j]);
                if(j+1<w)
                dp[i][j]=max(dp[i][j],dp[i-1][j+1]+input[i][j]);
                dp[i][j]=max(dp[i][j],dp[i-1][j]+input[i][j]);
            }
        }
        /*for(int i=0;i<h;i+=1)
        {
            for(int j=0;j<w;j+=1)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        int m=0;
        for(int i=0;i<w;i+=1)
        m=max(dp[h-1][i],m);
        return m;
    }
    
};
int main()
{
    int testcases;
    scanf("%d",&testcases);
    while(testcases--)
    {
        int h,w;
        scanf("%d %d",&h,&w);
        solution sc(h,w);
        sc.takeInput();
    }
    return 0;
}