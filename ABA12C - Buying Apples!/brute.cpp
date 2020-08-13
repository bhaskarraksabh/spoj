    // IN THE NAME OF GOD
    #include<bits/stdc++.h>
    #define REP(i,n) for(int i=0;i<(n);i++)
    #define FOR(i,a,b) for(int i=(a);i<=(b);i++)
    #define FORD(i,a,b) for(int i=(a);i>=(b);i--)
    #define ll long long unsigned int
    #define LL long long
    #define justl long
    #define em emplace_back
    #define pb push_back
    #define INF 1e7+5
    #define MOD 1e9+7
    #define print printf
    #define in scanf
    #define pop_back pb1
    using namespace std;
    typedef pair<int,int> pi;
    struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
    auto hash1 = hash<T1>{}(p.first); 
    auto hash2 = hash<T2>{}(p.second); 
    return hash1 ^ hash2; 
    } 
    }; 
    template<class type>
    void displaySingle(type &arr)
    {
    for(auto i:arr)
    cout<<i<<" ";
    cout<<endl;
    }
    template<class type>
    void displayDouble(type &arr)
    {
    for(auto i:arr)
    cout<<i.first<<" "<<i.second<<endl;
    }
    template<class type>
    void display2D(type &arr)
    {
    for(auto i:arr)
    {
    for(auto j:arr[i])
    {
    print("%d ",j);
    }
    print("\n");
    }
    }
    void findAns(vector<int>input,int k,int kg,vector<int>res,int n,int &m)
    {
    if(kg>k)
    return;
    if(res.size()>n)
    return;
    if(kg==k)
    {
    //displaySingle(res);
    int sum=accumulate(res.begin(),res.end(),0);
    m=min(m,sum);
    return;
    }
    else
    {
    for(int i=1;i<input.size();i++)
    {
    if(input[i]!=-1)
    {
    res.em(input[i]);
    kg+=i;
    findAns(input,k,kg,res,n,m);
    kg-=i;
    res.erase(res.end()-1);
    }
    }
    }
    }
    int main()
    {
    int testcases;
    in("%d",&testcases);
    while(testcases--)
    {
    int n,k;
    in("%d %d",&n,&k);
    vector<int>input(k+1);
    for(int i=1;i<=k;i++)
    in("%d",&input[i]);
    vector<int>res;
    int m=1e9+7;
    findAns(input,k,0,res,n,m);
    if(m==1e9+7)
    cout<<-1<<endl;
    else
    cout<<m<<endl;
}
    return 0;
    }
     
