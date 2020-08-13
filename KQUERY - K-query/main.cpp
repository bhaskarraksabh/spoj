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
    vector<int>arr;
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
    struct tree *merge(struct tree *a,struct tree *b)
    {
        int i=0;
        int j=0;
        struct tree *c=new tree(NULL,NULL,0,0);
        int n1=getLength(a->arr);
        int n2=getLength(b->arr);
        c->arr.resize(n1+n2);
        int k=0;
        while(i<n1 && j<n2)
        {
            if(a->arr[i]<b->arr[j])
            {
                c->arr[k++]=a->arr[i++];
            }
            else
            {
                c->arr[k++]=b->arr[j++];
            }
        }
        while(i<n1)
        {
            c->arr[k++]=a->arr[i++];
        }
        while(j<n2)
        {
            c->arr[k++]=b->arr[j++];
        }
        return c;
    }
    struct tree *build(struct tree *root,int low,int high)
    {
        if(low>=high)
        {
            root->arr.em(input[low]);
            return root;
        }
        int mid=low+(high-low)/2;
        root->left=new tree(NULL,NULL,low,mid);
        root->right=new tree(NULL,NULL,mid+1,high);
        struct tree *a=build(root->left,low,mid);
        struct tree *b=build(root->right,mid+1,high);
        struct tree *c=merge(a,b);
        root->arr=c->arr;
        root->left=a;
        root->right=b;
        return root;
    }
    void displayer(struct tree *root)
    {
        if(root!=NULL)
        {
            cout<<root->start<<" "<<root->end<<endl;
            display(root->arr);
            displayer(root->left);
            displayer(root->right);
        }
    }
    int lowerbound(struct tree *root,int val)
    {
        int low=0;
        int high=root->arr.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(root->arr[mid]<=val)
            low=mid+1;
            else
            high=mid-1;
        }
        return low;
    }
    int query(struct tree *root,int low,int high,int val)
    {
        if(root->start>high || root->end<low)
        return 0;
        if(root->start>=low && root->end<=high)
        return root->arr.size()-lowerbound(root,val);
        return query(root->left,low,high,val)+query(root->right,low,high,val);
    }
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        scanf("%d",&input[i]);
        root=build(root,0,n-1);
        //displayer(root);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            --a,--b;
            //cout<<root->arr.end()-lower_bound(root->arr.begin(),root->arr.end(),c)<<endl;
            int ans=query(root,a,b,c);
            cout<<ans<<endl;
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