#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<stack>
#include<queue>
#define ll long long unsigned int
using namespace std;
class solution
{
    ll num;
    unordered_map<ll,ll>m1;
    public:
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
    solution ()
    {

    }
    void takeInput()
    {
        while(cin>>num)
        {
            int prev=0;
            printf("%lld\n",findAns(num));
        }
    }
    ll findAns(ll n1)
    {
        if(n1==0)
        return 0;
        if(m1.count(n1))
        return m1[n1];
        m1[n1]=max(n1,findAns(n1/2)+findAns(n1/3)+findAns(n1/4));
        //cout<<n1<<" "<<k<<endl;
        return m1[n1];
    }
    
};
int main()
{
    solution sc;
    sc.takeInput();
    return 0;
}