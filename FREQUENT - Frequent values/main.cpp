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
struct tree
{
    long long prefix;
    long long prefixnum;
    long long suffix;
    long long suffixnum;
    long long m;
    long long val;
    long long start,end;
    struct tree *left,*right;
    tree(long long num,tree *l,tree *r,long long low,long long high)
    {
        left=l;
        right=r;
        start=low;
        end=high;
        val=num;
        m=0;
        prefix=suffix=1;
        m=1;
    }
};
class solution
{
    int n,q;
    vector<long long>input;
    struct tree *root;
    public:
    solution (int n,int q)
    {
        this->n=n;
        this->q=q;
        input.resize(n);
        root=new tree(0,NULL,NULL,0,n-1);
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
    void displayer(struct tree *root)
    {
        if(root!=NULL)
        {
            cout<<root->start<<" "<<root->end<<" "<<root->prefix<<" "<<root->suffix<<" "<<root->prefixnum<<" "<<root->suffixnum<<" "<<root->m<<endl;
            displayer(root->left);
            displayer(root->right);
        }
    }
    struct tree *build(int low,int high,struct tree *root)
    {
        if(low>=high)
        {
            root->val=input[low];
            root->prefixnum=input[low];
            root->suffixnum=input[low];
            return root;
        }
        int mid=low+(high-low)/2;
        root->left=new tree(0,NULL,NULL,low,mid);
        root->right=new tree(0,NULL,NULL,mid+1,high);
        struct tree *a=build(low,mid,root->left);
        struct tree *b=build(mid+1,high,root->right);
        struct tree *c=conquer(a,b);
        root->left=a;
        root->right=b;
        root->m=c->m;
        root->prefix=c->prefix;
        root->suffix=c->suffix;
        root->prefixnum=c->prefixnum;
        root->suffixnum=c->suffixnum;
        return root;
    }
    struct tree *conquer(struct tree *a,struct tree *b)
    {
        struct tree *c=new tree(0,NULL,NULL,0,0);
        c->prefixnum=a->prefixnum;
        c->suffixnum=b->suffixnum;
        c->prefix=a->prefix;
        c->suffix=b->suffix;
        c->m=max(a->m,b->m);
        if(a->prefixnum==b->prefixnum)
        {
            c->prefix=a->prefix+b->prefix;
        }
        if(a->suffixnum==b->suffixnum)
        {
            c->suffix=a->suffix+b->suffix;
        }
        if(a->suffixnum==b->prefixnum)
        {
            c->m=max(c->m,a->suffix+b->prefix);
        }
        return c;
    }
    int bruteForce(int low,int high)
    {
        unordered_map<int,int>m1;
        for(int i=low;i<=high;i+=1)
        m1[input[i]]+=1;
        int m=0;
        for(auto i:m1)
        m=max(m,i.second);
        return m;
    }
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        scanf("%lld",&input[i]);
        sort(input.begin(),input.end());
        root=build(0,n-1,root);
        //displayer(root);
        while(q--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            struct tree *a1=getFrequency(root,a-1,b-1);
            //int a2=bruteForce(a-1,b-1);
            printf("%lld\n",a1->m);
        }
    }
    struct tree *getFrequency(struct tree *root,int qlow,int qhigh)
    {
        if(root->start>=qlow && root->end<=qhigh)
        {
            return root;
        }
        if(root->start>qhigh || root->end<qlow)
        return NULL;
        struct tree *a=getFrequency(root->left,qlow,qhigh);
        struct tree *b=getFrequency(root->right,qlow,qhigh);
        if(a!=NULL && b!=NULL)
        {
            struct tree *c=new tree(0,NULL,NULL,0,0);
            c->prefixnum=a->prefixnum;
            c->suffixnum=b->suffixnum;
            c->prefix=a->prefix;
            c->suffix=b->suffix;
            c->m=max(a->m,b->m);
            if(a->prefixnum==b->prefixnum)
            {
                c->prefix=a->prefix+b->prefix;
            }
            if(a->suffixnum==b->suffixnum)
            {
                c->suffix=a->suffix+b->suffix;
            }
            if(a->suffixnum==b->prefixnum)
            {
                c->m=max(c->m,a->suffix+b->prefix);
            }
            return c;
        }
        else if(a!=NULL)
        return a;
        else
        return b;
    }
    void findAns()
    {


    }
    
};
int main()
{
    int n,q;
    while(cin>>n && n!=0)
    {
        scanf("%d",&q);
        solution sc(n,q);
        sc.takeInput();
    }
    return 0;
}