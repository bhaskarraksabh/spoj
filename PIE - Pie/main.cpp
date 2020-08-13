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
    vector<double>input;
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
        scanf("%lf",&input[i]);
        findAns();
    }
    bool double_equals(double a, double b, double epsilon = 0.001)
    {
    return abs(a - b) < epsilon;
    }
    void findAns()
    {
        double low=0;
        double pi=acos(-1);
        double high=0;
        double m=*max_element(input.begin(),input.end());
        high=pi*m*m;
        int n=getLength(input);
        while(!double_equals(low,high))
        {
            double mid=low+(high-low)/2;
            double sum=0;
            int count=0;
            double vol=pi*k*k;
            for(int i=0;i<n;i+=1)
            {
                double num=(pi*input[i]*input[i]);
                //cout<<num<<endl;
                count+=(int)(num/mid);
            }
            if(count>=k+1)
            low=mid;
            else
            high=mid;
            //cout<<low<<" "<<mid<<" "<<high<<" "<<count<<endl;

        }
        cout<<fixed<<low<<endl;
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