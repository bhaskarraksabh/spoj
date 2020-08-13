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
#include <climits>
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
    int start, end;
    long prefix,suffix,sum,m;
    struct tree *left,*right;
    tree() {}
    tree(tree *l,tree *r,int low,int high)
    {
        left=l;
        right=r;
        start=low;
        end=high;
        prefix=0;
        suffix=0;
        sum=0;
        m=INT_MIN;
    }
};
class solution
{
    int n;
    vector<int>input;
    struct tree *root;
    public:
    solution (int n)
    {
        this->n=n;
        input.resize(n);
        root=new tree(NULL,NULL,0,n-1);
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
    struct tree *build(int low,int high,struct tree *root)
    {
        if(low>=high)
        {
            root->m=input[low];
            root->prefix=input[low];
            root->suffix=input[low];
            root->sum=input[low];
            return root;
        }
        int mid=low+(high-low)/2;
        root->left=new tree(NULL,NULL,low,mid);
        root->right=new tree(NULL,NULL,mid+1,high);
        struct tree *a=build(low,mid,root->left);
        struct tree *b=build(mid+1,high,root->right);
        root->left=a;
        root->right=b;
        struct tree *c=divider(low,mid,high,a,b);
        root->prefix=c->prefix;
        root->suffix=c->suffix;
        root->sum=c->sum;
        root->m=c->m;
        return root;
    }
    struct tree *divider(int low,int mid,int high,struct tree *a,struct tree *b)
    {
        struct tree *node=new tree(NULL,NULL,0,0);
        node->prefix=max({a->prefix,a->sum+b->sum,a->sum+b->prefix});
        node->suffix=max({b->suffix,a->sum+b->sum,b->sum+a->suffix});
        node->sum=a->sum+b->sum;
        node->m=max({node->prefix,node->suffix,node->sum,a->m,b->m,a->suffix+b->prefix});
        return node;
    }
    void displayer(struct tree *root)
    {
        if(root!=NULL)
        {
            cout<<root->start<<" "<<root->end<<" "<<root->prefix<<" "<<root->m<<" "<<root->suffix<<endl;
            displayer(root->left);
            displayer(root->right);
        }
    }
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        scanf("%d",&input[i]);
        root=build(0,n-1,root);
        //displayer(root);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(a==1)
            {
                struct tree *ab=findAns(root,b-1,c-1);
                printf("%ld\n",ab->m);
            }
            else
            {
                update(root,b-1,c);
                //displayer(root);
            }
        }
    }
    void update(struct tree *&root,int pos,int val)
    {
        if(root->start>pos || root->end<pos)
        return;
        if(root->start==root->end && root->start==pos)
        {
            root->m=val;
            root->prefix=val;
            root->suffix=val;
            root->sum=val;
            return;
        }
        if(pos<=root->end)
        update(root->left,pos,val);
        update(root->right,pos,val);
        struct tree *c=divider(0,0,0,root->left,root->right);
        root->prefix=c->prefix;
        root->suffix=c->suffix;
        root->sum=c->sum;
        root->m=c->m;
        return;
    }
    struct tree *findAns(struct tree *root,int low,int high)
    {
        if(root->start>=low && root->end<=high)
        return root;
        if(root->start>high || root->end<low)
        return NULL;
        struct tree *a=findAns(root->left,low,high);
        struct tree *b=findAns(root->right,low,high);
        struct tree *c;
        if(a && b)
        c=divider(0,0,0,a,b);
        else if(a)
        c=a;
        else
        c=b;
        return c;
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