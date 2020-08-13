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
    vector<long long unsigned int>input;
    unordered_map<long long unsigned int,long long unsigned int>m1;
    public:
    solution (int n)
    {
        this->n=n;
        input.resize(n);
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
    int findMask(long long unsigned int num)
    {
        int mask=0;
        while(num>0)
        {
            int rem=num%10;
            mask|=(1<<rem);
            num=num/10;
        }
        return mask;
    }
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        scanf("%lld",&input[i]);
        for(int i=0;i<n;i+=1)
        {
            int m=findMask(input[i]);
            //cout<<m<<" "<<input[i]<<endl;
            m1[m]+=1;
        }
        long long unsigned int count=0;
        for(int i=0;i<1024;i+=1)
        {
            count+=((m1[i]*(m1[i]-1))/2);
            for(int j=i+1;j<1024;j+=1)
            {
                if(i&j)
                count+=((m1[i]*m1[j]));
            }
            //cout<<count<<endl;
        }
        cout<<count<<endl;
    }
    void findAns()
    {


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