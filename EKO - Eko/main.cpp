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
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        scanf("%d",&input[i]);
        long low=*min_element(input.begin(),input.end());
        long high=*max_element(input.begin(),input.end());
        while(low<=high)
        {
            long mid=low+(high-low)/2;
            long c=0;
            for(int i=0;i<n;i+=1)
            {
                if(input[i]>=mid)
                c+=input[i]-mid;
            }
           // cout<<mid<<" "<<c<<endl;
            if(c>=k)
            low=mid+1;
            else
            high=mid-1;
        }
        cout<<low-1<<endl;

    }
    void findAns()
    {


    }
};
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    solution sc(n,k);
    sc.takeInput();
    return 0;
}