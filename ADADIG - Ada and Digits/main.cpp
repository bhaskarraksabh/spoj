#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
long mod=1e9+7;
class solution
{
    public:long factorial[300001];
    solution()
    {
        factorial[0]=1;
        for(long i=1;i<=300000;i+=1)
        factorial[i]=((factorial[i-1]%mod)*(i%mod))%mod;
    }
    string str;
    long power(long a,long b)
    {
            long x=1,y=a; 
            while(b > 0)
            {
            if(b%2 == 1)
            {
            x=(x*y);
            if(x>mod) x%=mod;
            }
            y = (y*y);
            if(y>mod) y%=mod; 
            b /= 2;
            }
    return x;
    }
    long inverseFactorial(long a)
    {
        return power(a,mod-2)%mod;
    }
    void bruteForce(long long unsigned int prod,long long unsigned int sum,long num,vector<long>factor,long prev,long &c)
    {
        if(sum>num || prod>num)
        return;
        if(prod==num)
        {
            //cout<<str<<endl;
            long numone=num-sum;
            unordered_map<char,long>m1;
            long s=str.size()+numone;
            long f=factorial[s];
            m1['1']=numone;
            for(auto i:str)
            {
                m1[i]+=1;
            }
            long a2=1;
            long an=1;
            for(auto i:m1)
            {
                //cout<<i.second<<endl;
                if(i.second!=0)
                {
                an=inverseFactorial(factorial[i.second])%mod;
                //cout<<an<<" "<<i.second<<endl;
                a2=((a2%mod)*(an%mod))%mod;
                }
            }
            c=((c%mod)+(f%mod)*(a2%mod))%mod;
            //cout<<str<<" "<<numone<<" "<<c<<" "<<a2<<" "<<f<<endl;
            return;
        }
        for(long i=prev;i<factor.size();i+=1)
        {
            str+=to_string(factor[i]);
            bruteForce(prod*factor[i],sum+factor[i],num,factor,i,c);
            str.erase(str.end()-1);
        }
    }
};
int main()
{
    long testcases;
    scanf("%ld",&testcases);
    solution sc;
    while(testcases--)
    {
        long num;
        scanf("%ld",&num);
        vector<long>factor;
        long c=0;
        for(long i=2;i<=9;i+=1)
        {
            if(num%i==0)
            factor.emplace_back(i);
        }
        sc.bruteForce(1,0,num,factor,0,c);
        printf("%ld\n",c);
    }
    return 0;
}