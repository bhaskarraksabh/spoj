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
    int sum;
    int lowpoint;
    struct tree *left;
    struct tree *right;
    int start;
    int end;
    char text;
    tree(){ }
    tree(char t,tree *l,tree *r,int low,int high)
    {
        text=t;
        lowpoint=0;
        left=l;
        right=r;
        start=low;
        end=high;
        sum=0;
    }
};
class solution
{
    string str;
    struct tree *root;
    int n;
    public:
    solution (int n)
    {
        this->n=n;
        root=new tree('N',NULL,NULL,0,n-1);
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
            cout<<root->text<<" "<<root->start<<" "<<root->end<<" "<<root->lowpoint<<" "<<root->sum<<endl;
            displayer(root->left);
            displayer(root->right);
        }
    }
    void update(struct tree *&root,int pos)
    {
       // cout<<root->start<<" "<<root->end<<endl;
        if(root->start>pos || root->end<pos)
        return;
        if(root->start==root->end && root->start==pos)
        {
            if(root->text=='(')
            {
                root->text=')';
                root->sum=-1;
                root->lowpoint=-1;
            }
            else
            {
                root->text='(';
                root->sum=1;
                root->lowpoint=1;
            }
            return;
        }
        
        if(pos<=root->end)
        update(root->left,pos);
        update(root->right,pos);
        root->lowpoint=min(root->left->lowpoint,root->right->lowpoint+root->left->sum);
        root->sum=root->left->sum+root->right->sum;
        return;
    }
    void takeInput()
    {
        cin>>str;
        root=build(0,n-1,root);
        //displayer(root);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int k;
            scanf("%d",&k);
            if(k==0)
            {
                if(root->sum==0 && root->lowpoint==0)
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
            else
            {
                update(root,k-1);
            }
        }
    }
    struct tree *build(int low,int high,struct tree *root)
    {
        if(low>=high)
        {
            root->text=str[low];
            if(str[low]=='(')
            {
                root->sum=1;
                root->lowpoint=0;
            }
            else
            {
                root->sum=-1;
                root->lowpoint=-1;
            }
            return root;
        }
        int mid=low+(high-low)/2;
        root->left=new tree('N',NULL,NULL,low,mid);
        root->right=new tree('N',NULL,NULL,mid+1,high);
        struct tree *a=build(low,mid,root->left);
        struct tree *b=build(mid+1,high,root->right);
        root->left=a;
        root->right=b;
        root->lowpoint=min(a->lowpoint,b->lowpoint+a->sum);
        root->sum=root->left->sum+root->right->sum;
        return root;
    }
    
    void findAns()
    {


    }
    void printer(int c)
    {
        cout<<"Test "<<c<<":"<<endl;
    }
    
};
int main()
{
    int num;
    int c=1;
    while(cin>>num)
    {
        solution sc(num);
        sc.printer(c);
        sc.takeInput();
        c+=1;
    }
    return 0;
}