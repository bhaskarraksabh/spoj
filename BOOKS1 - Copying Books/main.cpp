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
    int n,k;
    vector<int>input;
    public:
    solution (int n,int k)
    {
        this->n=n;
        this->k=k;
        input.resize(n);
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
    void display(vector<T>&input)
    {
        for(auto i:input)
        cout<<i<<" ";
        cout<<endl;
    }
    template<typename T>
    void display2D(vector<vector<T>>&input)
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
        scanf("%d",&input[i]);
        findAns();
    }
    void findAns()
    {
        int low=*max_element(input.begin(),input.end());
        int high=accumulate(input.begin(),input.end(),0);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int curr=0;
            int req=1;
            int n=getLength(input);
            for(int i=0;i<n;i+=1)
            {
                if(curr+input[i]<=mid)
                {
                    curr+=input[i];
                }
                else
                {
                    curr=input[i];
                    req+=1;
                }
            }
            if(req<=k)
            high=mid-1;
            else
            low=mid+1;
        }
        //cout<<low<<endl;
        int n=getLength(input);
        int curr=0;
        int prev=1e9;
        vector<string>res;
        int p=1;
        for(int i=n-1;i>=0;i-=1)
        {
            //cout<<curr<<" "<<p<<endl;
            if(curr+input[i]>low || i==k-p-1)
            {
                    //prev=curr;
                    curr=0;
                    res.em("/");
                    p+=1;
            }
            curr+=input[i];
            res.em(to_string(input[i]));
        }
        reverse(res.begin(),res.end());
        display(res);
    }
};
int main()
{
    int testcases;
    scanf("%d",&testcases);
    while(testcases--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        solution sc(n,k);
        sc.takeInput();
    }
    return 0;
}