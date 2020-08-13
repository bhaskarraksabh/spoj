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
const int modder=1000000007;
class solution
{
    int n;
    string str;
    unordered_map<string,int>m1;
    vector<int>input;
    public:
    solution()
    {

    }
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
    void bruteForce(int &count,string aux="",int idx=0)
    {
        if(idx>=str.size())
        {
            if(m1[aux]==0)
            {
                count+=1;
                cout<<aux<<endl;
                m1[aux]+=1;
            }
            return;
        }
        bruteForce(count,aux+str[idx],idx+1);
        bruteForce(count,aux,idx+1);
    }
    void takeInput()
    {
        cin>>str;
        int count=0;
        //bruteForce(count);
        vector<int>hash(26,-1);
        vector<int>dp(str.size()+1,0);
        dp[0]=1;
        int n=getLength(str);
        for(int i=1;i<=n;i+=1)
        {
            dp[i]=mod(2*dp[i-1],modder);
            if(hash[str[i-1]-'A']!=-1)
            dp[i]=mod(dp[i]-dp[hash[str[i-1]-'A']],modder);
            hash[str[i-1]-'A']=i-1;
        }
       // display(dp);
        cout<<dp[n]%modder<<endl;
    }
    void findAns()
    {


    }
};
int main()
{
    int testcases;
    scanf("%d",&testcases);
    while(testcases--)
    {
        solution sc;
        sc.takeInput();
    }
    return 0;
}