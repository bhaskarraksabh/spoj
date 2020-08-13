// divide and conquer for maximum sum subarray
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
    int n;
    vector<int>input;
    public:
    solution (int n)
    {
        this->n=n;
        input.resize(n);
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
        scanf("%d",&input[i]);
        int ans=divideandconquer(0,n-1);
    }
    int divideandconquer(int low,int high)
    {
        if(low>=high)
        {
            return input[low];
        }
        int mid=low+(high-low)/2;
        int a=divideandconquer(low,mid);
        int b=divideandconquer(mid+1,high);
        int c=findAns(low,mid,high);
        return max({a,b,c});
    }
    int findAns(int low,int mid,int high)
    {
        int ans1=input[mid];
        int mans1=input[mid];
        int mans2=input[mid+1];
        for(int i=mid-1;i>=low;i-=1)
        {
            ans1+=input[i];
            mans1=max(mans1,ans1);
        }
        ans1=input[mid+1];
        for(int i=mid+2;i<=high;i+=1)
        {
            ans1+=input[i];
            mans2=max(ans1,mans2);
        }
        return max({mans1,mans2,mans1+mans2});
    }
    
};
int main()
{
    int n;
    scanf("%d",&n);
    solution sc(n);
    sc.takeInput();
    return 0;
}