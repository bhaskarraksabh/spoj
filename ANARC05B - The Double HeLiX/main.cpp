//मनुष्य होना मेरा भाग्य लेकिन
//हिन्दू होना मेरा सौभाग्य है..!!
//"रामसेतू" और अयोध्या में "मन्दिर" उस समय से है..!!
//जब इस धरती पर न जीजस थे,
//और न ही इस्लाम का कोई अस्तित्व था..!!
//जय श्री राम
//everything could depending on what you do today
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
    int n,m;
    vector<int>a,b;
    public:
    solution (){

    }
    solution (int n)
    {
        this->n=n;
        a.resize(n);
    }
    bool checkEven(long long num)
    {
        if(!(num&1))
        return false;
        else
        return true;
    }
    inline int mod(int a, int b)
    {
        int ret = a%b; 
        return ret>=0? ret: ret+b; 
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
    int binarysearch(int num)
    {
        int low=0;
        int high=b.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(b[mid]==num)
            return mid;
            else if(b[mid]<num)
            low=mid+1;
            else
            high=mid-1;
        }
        return -1;
    }
    int ma=0;
    long long  bruteForce(vector<pair<int,int>>in1,vector<pair<int,int>>in2,vector<long long>&dp,int idx1=0,int sum=0)
    {
        if(idx1>=in1.size())
        {
            return 0;
        }
        if(dp[idx1]!=-1)
        return dp[idx1];
        int s1,s2;
        s1=s2=0;
        for(int i=in1[idx1].first;i<in1[idx1].second;i+=1)
        {
            s1+=a[i];
        }
        for(int i=in2[idx1].first;i<in2[idx1].second;i+=1)
        {
            s2+=b[i];
        }
        return dp[idx1]=max(s1+bruteForce(in1,in2,dp,idx1+1,sum),s2+bruteForce(in1,in2,dp,idx1+1,sum));
    }
    void takeInput()
    {
        while(scanf("%d",&n) && n!=0)
        {
            a.resize(n);
            for(int i=0;i<n;i+=1)
            scanf("%d",&a[i]);
            scanf("%d",&m);
            b.resize(m);
            for(int i=0;i<m;i+=1)
            scanf("%d",&b[i]);
            int len=max(n,m);
            vector<pair<int,int>>intersect1,intersect2;
            vector<long long>dp;
            dp.resize(len+1,-1);
            int last=0;
            int last1=0;
            for(int i=0;i<n;i+=1)
            {
                int check=binarysearch(a[i]);
                if(check!=-1)
                {
                    intersect1.em(make_pair(last1,i));
                    intersect2.em(make_pair(last,check));
                    last=check;
                    last1=i;
                }
            }
            if(intersect1.size()>0)
            intersect1.em(make_pair(intersect1[intersect1.size()-1].second,n));
            else
            intersect1.em(make_pair(0,n));
            if(intersect2.size()>0)
            intersect2.em(make_pair(intersect2[intersect2.size()-1].second,m));
            else
            intersect2.em(make_pair(0,m));
            //displayPair(intersect1);
            //displayPair(intersect2);
            cout<<bruteForce(intersect1,intersect2,dp)<<endl;
        }
    }
    void findAns()
    {


    }
};
int main()
{
    solution sc;
    sc.takeInput();
    return 0;
}