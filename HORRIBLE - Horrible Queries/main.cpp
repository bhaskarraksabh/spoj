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
    long long unsigned int sum;
    long long unsigned int start,end;
    int lazyflag;
    long long unsigned int lazysum;
    struct tree *left;
    struct tree *right;
    tree(){}
    tree(tree *l,tree *r,long long unsigned int low,long long unsigned int high)
    {
        start=low;
        end=high;
        lazyflag=0;
        lazysum=0;
        left=l;
        right=r;
        sum=0;
    }
};
class solution
{
    int n;
    struct tree *root;
    public:
    solution (int n)
    {
        this->n=n;
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
    void displayer(struct tree *root)
    {
        if(root!=NULL)
        {
            cout<<root->start<<" "<<root->end<<" "<<root->sum<<" "<<root->lazysum<<endl;
            displayer(root->left);
            displayer(root->right);
        }
    }
    struct tree *build(struct tree *root,int low,int high)
    {
        if(low>=high)
        {
            return root;
        }
        int mid=low+(high-low)/2;
        root->left=new tree(NULL,NULL,low,mid);
        root->right=new tree(NULL,NULL,mid+1,high);
        root->left=build(root->left,low,mid);
        root->right=build(root->right,mid+1,high);
        return root;
    }
    void updateRange(struct tree *&root,int low,int high,int val)
    {
        if(root->lazysum!=0)
        {
            root->sum+=root->lazysum*(root->end-root->start+1);
            if(root->start!=root->end)
            {
                root->left->lazysum+=root->lazysum;
                root->right->lazysum+=root->lazysum;
            }
            root->lazysum=0;
        }
        if(root->start>high || root->end<low)
        return;
        if(root->start>=low && root->end<=high)
        {
            root->sum+=val*(root->end-root->start+1);
            if(root->start!=root->end)
            {
                root->left->lazysum+=val;
                root->right->lazysum+=val;
            }
            return;
        }
        updateRange(root->left,low,high,val);
        updateRange(root->right,low,high,val);
        root->sum=root->left->sum+root->right->sum;
    }
    long long unsigned int queryRange(struct tree *&root,int qlow,int qhigh)
    {
        if(root->lazysum!=0)
        {
            root->sum+=root->lazysum*(root->end-root->start+1);
            if(root->start!=root->end)
            {
                root->left->lazysum+=root->lazysum;
                root->right->lazysum+=root->lazysum;
            }
            root->lazysum=0;
        }
        if(root->start>qhigh || root->end<qlow)
        return 0;
        if(root->start>=qlow && root->end<=qhigh)
        return root->sum;
        return queryRange(root->left,qlow,qhigh)+queryRange(root->right,qlow,qhigh);
    }
    void takeInput()
    {
        int q;
        scanf("%d",&q);
        root=build(root,0,n-1);
        //displayer(root);
        for(int i=0;i<q;i+=1)
        {
            int p,q,r,s;
            scanf("%d %d %d",&p,&q,&r);
            if(p==0)
            {
                scanf("%d",&s);
                updateRange(root,q-1,r-1,s);
                displayer(root);
            }
            else
            {
                cout<<queryRange(root,q-1,r-1)<<endl;
                displayer(root);
            }
        }
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
        int n;
        scanf("%d",&n);
        solution sc(n);
        sc.takeInput();
    }
    return 0;
}