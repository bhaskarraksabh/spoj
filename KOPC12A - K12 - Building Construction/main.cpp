//मनुष्य होना मेरा भाग्य लेकिन
//हिन्दू होना मेरा सौभाग्य है..!!
//"रामसेतू" और अयोध्या में "मन्दिर" उस समय से है..!!
//जब इस धरती पर न जीजस थे,
//और न ही इस्लाम का कोई अस्तित्व था..!!
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
class solution
{
    int n;
    vector<long long>input,cost;
    public:
    solution (int n)
    {
        this->n=n;
        input.resize(n);
        cost.resize(n);
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
    long long bruteForce()
    {
        long long m=*max_element(input.begin(),input.end());
        long long ans=1e18;
        int element=0;
        for(int i=1;i<=m;i+=1)
        {
            long long profit=0;
            for(int j=0;j<n;j+=1)
            {
                profit+=(abs(i-input[j])*cost[j]);
            }
            ans=min(profit,ans);
            if(profit==ans)
            element=i;
        }
        cout<<element<<endl;
        return ans;
    }
    void takeInput(int c)
    {
        for(int i=0;i<n;i+=1)
        scanf("%lld",&input[i]);
        for(int i=0;i<n;i+=1)
        scanf("%lld",&cost[i]);
        long long low=1;
        long long high=*max_element(input.begin(),input.end());
        long long h=*max_element(cost.begin(),cost.end());
        //long long a1=bruteForce();
        while(low<high)
        {
            //cout<<low<<" "<<high<<endl;
            long long mid1=low+(high-low)/3;//0+(3-0)/3=1;
            long long profit1=0,profit2=0;
            long long mid2=high-(high-low)/3;//3-(3-0)/3=2;
            for(int i=0;i<n;i+=1)
            {
                profit1+=(abs(mid1-input[i])*cost[i]);
            }
            for(int i=0;i<n;i+=1)
            {
                profit2+=(abs(mid2-input[i])*cost[i]);
            }
            if(profit1<profit2)
            high=mid2-1;
            else
            low=mid1+1;
            //cout<<low<<" "<<high<<" "<<mid1<<" "<<mid2<<" "<<profit1<<" "<<profit2<<endl;
        }
        //cout<<low<<" "<<high<<endl;
        long long profit=0;
        for(int i=0;i<n;i+=1)
        profit+=(abs(low-input[i])*cost[i]);
        cout<<profit<<endl;
    }
    void findAns()
    {


    }
};
int main()
{
    int testcases;
    scanf("%d",&testcases);
    int c=1;
    while(testcases--)
    {
        int n;
        scanf("%d",&n);
        solution sc(n);
        sc.takeInput(c);
        c+=1;
    }
    return 0;
}