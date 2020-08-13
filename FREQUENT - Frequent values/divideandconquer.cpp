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
struct node
{
    int prefix;
    int prefixnum;
    int suffix;
    int suffixnum;
    int m;
    int val;
    int start,end;
    struct node *left,*right;
    node(int num,int low,int high,node *l,node *r)
    {
        left=l;
        right=r;
        start=low;
        end=high;
        val=num;
        m=0;
        prefix=suffix=1;
    }
};
class solution
{
    int n;
    vector<int>input;
    struct node *root;
    public:
    solution (int n)
    {
        this->n=n;
        input.resize(n);
        root=new node(0,0,n-1,NULL,NULL);
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
    node *findFreq(int low,int high,struct node *root)
    {
        if(low>=high)
        {
            root->val=input[low];
            root->prefixnum=input[low];
            root->suffixnum=input[low];
            root->prefix=1;
            root->suffix=1;
            root->m=1;
            return root;
        }  
        int mid=low+(high-low)/2;
        root->left=new node(0,low,mid,NULL,NULL);
        root->right=new node(0,mid+1,high,NULL,NULL);
        node *a=findFreq(low,mid,root->left);
        node *b=findFreq(mid+1,high,root->right);
        root->left=a;
        root->right=b;
        node *ans=conquer(root->left,root->right);
        root->suffixnum=ans->suffixnum;
        root->prefixnum=ans->prefixnum;
        root->prefix=ans->prefix;
        root->suffix=ans->suffix;
        root->m=ans->m;
        return root;
    }
    //6 8 0 6 7 4 7 1 7 0
    //0 0 1 4 6 6 7 7 7 8
    //here if a->suffixnum and b->prefixnum are equal then it does not belong to prefix and suffix
    //so whatever value is there we need to check if both are equal or not
    node *conquer(struct node *a,struct node *b)
    {
       node *c=new node(0,0,0,NULL,NULL);
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
           c->m=max({c->m,a->suffix+b->prefix});
       }
       return c;
    }
    void displayer(struct node *a)
    {
        if(a!=NULL)
        {
            cout<<a->start<<" "<<a->end<<" "<<a->prefixnum<<" "<<a->suffixnum<<" "<<a->prefix<<" "<<a->suffix<<" "<<a->m<<endl;
            displayer(a->left);
            displayer(a->right);
        }
    }
    void takeInput(int c)
    {
        for(int i=0;i<n;i+=1)
        scanf("%d",&input[i]);
        sort(input.begin(),input.end());
        node *a1=findFreq(0,n-1,root);
        int a=root->m;
        int a2=findAns();
        if(a!=a2)
        {
            cout<<a<<" "<<a2<<endl;
            displayer(root);
            cout<<"Not equal"<<" "<<c<<endl;
        }
        //cout<<a1<<endl;
    }
    int findAns()
    {
        unordered_map<int,int>m1;
        for(auto i:input)
        m1[i]+=1;
        int a2=-99999;
        for(auto i:m1)
        a2=max(a2,i.second);
        return a2;
    }
    
};
int main()
{
    int n;
    int c=1;
    while(cin>>n)
    {
        //scanf("%d",&n);
        solution sc(n);
        sc.takeInput(c);
        c+=1;
    }
    return 0;
}