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
struct tree
{
    int start,end;
    int first,second,val;
    struct tree *left,*right;
    tree(tree *l,tree *r,int low,int high)
    {
        left=l;
        right=r;
        start=low;
        end=high;
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
    struct tree *build(struct tree *root,int low,int high)
    {
        if(low>=high)
        {
            root->first=root->second=input[low];
            root->val=input[low];
            return root;
        }
        int mid=low+(high-low)/2;
        root->left=new tree(NULL,NULL,low,mid);
        root->right=new tree(NULL,NULL,mid+1,high);
        struct tree *a=build(root->left,low,mid);
        struct tree *b=build(root->right,mid+1,high);
        root->left=a;
        root->right=b;
        /*if start and end is equal
        find the nearest 
        */
        if(a->start==a->end && b->start==b->end)
        {
            if(a->first>b->first)
            {
                root->second=a->first;
                root->first=b->first;
            }
            else
            {
                root->second=b->first;
                root->first=a->second;
            }
        }
        else if(a->start==a->end)
        {
            if(a->second>b->second)
            {
                root->second=a->second;
                root->first=b->second;
            }
            else
            {
                root->second=b->second;
                if(a->second>b->first)
                root->first=a->second;
                else
                root->first=b->first;
            }
        }
        else if(b->start==b->end)
        {
            if(b->second>a->second)
            {
                root->second=b->second;
                root->first=a->second;
            }
            else
            {
                root->second=a->second;
                if(a->first>b->second)
                root->first=a->first;
                else
                root->first=b->second;
            }
        }
        else
        {
            if(b->second>a->second)
            {
                root->second=b->second;
                root->first=max({a->second,a->first,b->first});
            }
            else
            {
                root->second=a->second;
                root->first=max({a->first,b->first,b->second});
            }
            
        }
        return root;
    }
    void display(struct tree *root)
    {
        if(root!=NULL)
        {
            cout<<root->start<<" "<<root->end<<" "<<root->first<<" "<<root->second<<endl;
            display(root->left);
            display(root->right);
        }
    }
    int bruteForce(int low,int high)
    {
        vector<int>s;
        for(int i=low;i<=high;i+=1)
        {
            s.em(input[i]);
        }
        sort(s.begin(),s.end());
        return s[s.size()-1]+s[s.size()-2];
    }
    void update(struct tree *&root,int idx,int val)
    {
        if(root->start==idx && root->start==root->end)
        {
            root->first=root->second=val;
            return;
        }
        if(root->end<idx || root->start>idx)
        return;
        if(root->left==NULL && root->right==NULL)
        return;
        update(root->left,idx,val);
        update(root->right,idx,val);
        struct tree *a=root->left;
        struct tree *b=root->right;
        if(a->start==a->end && b->start==b->end)
        {
            if(a->first>b->first)
            {
                root->second=a->first;
                root->first=b->first;
            }
            else
            {
                root->second=b->first;
                root->first=a->second;
            }
        }
        else if(a->start==a->end)
        {
            if(a->second>b->second)
            {
                root->second=a->second;
                root->first=b->second;
            }
            else
            {
                root->second=b->second;
                if(a->second>b->first)
                root->first=a->second;
                else
                root->first=b->first;
            }
        }
        else if(b->start==b->end)
        {
            if(b->second>a->second)
            {
                root->second=b->second;
                root->first=a->second;
            }
            else
            {
                root->second=a->second;
                if(a->first>b->second)
                root->first=a->first;
                else
                root->first=b->second;
            }
        }
        else
        {
            if(b->second>a->second)
            {
                root->second=b->second;
                root->first=max({a->second,a->first,b->first});
            }
            else
            {
                root->second=a->second;
                root->first=max({a->first,b->first,b->second});
            }
        }
    }
    struct tree *merge(struct tree *a,struct tree *b)
    {
        struct tree *root1;
        root1=new tree(NULL,NULL,a->start,b->end);
        if(a->start==a->end && b->start==b->end)
        {
            if(a->first>b->first)
            {
                root1->second=a->first;
                root1->first=b->first;
            }
            else
            {
                root1->second=b->first;
                root1->first=a->second;
            }
        }
        else if(a->start==a->end)
        {
            if(a->second>b->second)
            {
                root1->second=a->second;
                root1->first=b->second;
            }
            else
            {
                root1->second=b->second;
                if(a->second>b->first)
                root1->first=a->second;
                else
                root1->first=b->first;
            }
        }
        else if(b->start==b->end)
        {
            if(b->second>a->second)
            {
                root1->second=b->second;
                root1->first=a->second;
            }
            else
            {
                root1->second=a->second;
                if(a->first>b->second)
                root1->first=a->first;
                else
                root1->first=b->second;
            }
        }
        else
        {
            if(b->second>a->second)
            {
                root1->second=b->second;
                root1->first=max({a->second,a->first,b->first});
            }
            else
            {
                root1->second=a->second;
                root1->first=max({a->first,b->first,b->second});
            }
        }
        return root1;
    }
    struct tree *query(struct tree *root,int low,int high)
    {
        if(root->start>high || root->end<low)
        return NULL;
        if(root->start>=low && root->end<=high)
        {
            return root;
        }
        struct tree *a=query(root->left,low,high);
        struct tree *b=query(root->right,low,high);
        if(a==NULL)
        return b;
        else if(b==NULL)
        return a;
        else
        {
            struct tree *c=merge(a,b);
            //cout<<a->start<<" "<<a->end<<" "<<b->start<<" "<<b->end<<" "<<c->first<<" "<<c->second<<endl; 
            return c;
        }
    }
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        scanf("%d",&input[i]);
        root=build(root,0,n-1);
        //display(root);
        int q;
        scanf("%d",&q);
        int count=0;
        while(q--)
        {
            count+=1;
            char a;
            int b,c;
            cin>>a>>b>>c;
            if(a=='U')
            {
                input[b-1]=c;
                update(root,b-1,c);
            }
            else
            {
                struct tree *ans=query(root,b-1,c-1);
                int a1=ans->first+ans->second;
                //int a2=bruteForce(b-1,c-1);
                if(b==c)
                a1=ans->first;
                cout<<a1<<endl;
            }
        }
    }
    void findAns()
    {


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