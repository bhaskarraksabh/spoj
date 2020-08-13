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
        start=low;
        end=high;
        left=l;
        right=r;
    }
};
//finally ac
class solution
{
    int n;
    vector<int>input;
    unordered_map<int,int>index,present;
    struct tree *root;
    int q;
    public:
    solution (int n,int q)
    {
        this->q=q;
        this->n=n;
        root=new tree(NULL,NULL,0,n-1);
        input.resize(n);
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
    struct tree *build(int low,int high,struct tree *root)
    {
        if(low>=high)
        {
            root->arr.em(input[low]);
            return root;
        }
        int mid=low+(high-low)/2;
        root->left=new tree(NULL,NULL,low,mid);
        root->right=new tree(NULL,NULL,mid+1,high);
        struct tree *a=build(low,mid,root->left);
        struct tree *b=build(mid+1,high,root->right);
        struct tree *c=merge(a,b);
        root->left=a;
        root->right=b;
        root->arr=c->arr;
        return root;
    }
    void display(struct tree *root)
    {
        if(root!=NULL)
        {
            cout<<root->start<<" "<<root->end<<endl;
            display(root->arr);
            display(root->left);
            display(root->right);
        }
    }
    int query(struct tree *root,int low,int high,int val)
    {  
        if(root->start>=low && root->end<=high)
        return upper_bound(root->arr.begin(),root->arr.end(),val)-root->arr.begin();
        if(root->start>high || root->end<low)
        return 0;
        return query(root->left,low,high,val)+query(root->right,low,high,val);
    }
    int findmin(struct tree *root,int low,int high)
    {
        if(root->start>high || root->end<low)
        return 1e9;
        if(root->start>=low && root->end<=high)
        return root->arr[0];
        return min(findmin(root->left,low,high),findmin(root->right,low,high));
    }
    int findmax(struct tree *root,int low,int high)
    {
        if(root->start>high || root->end<low)
        return 0;
        if(root->start>=low && root->end<=high)
        return root->arr[root->arr.size()-1];
        return max(findmax(root->left,low,high),findmax(root->right,low,high));
    }
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        {
            scanf("%d",&input[i]);
            index[input[i]]=i;
            present[input[i]]++;
        }
        root=build(0,n-1,root);
        //display(root);
        while(q--)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            --a,--b;
            int low=findmin(root,a,b);
            int high=findmax(root,a,b);
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                int ans=query(root,a,b,mid);
                //cout<<low<<" "<<high<<" "<<mid<<" "<<ans<<endl;
                if(ans==c && present[mid]>0 && index[mid]>=a && index[mid]<=b)
                {
                    printf("%d\n",mid);
                    break;
                }
                if(ans<c)
                low=mid+1;
                else
                high=mid-1;
            }
        }
    }
    void findAns()
    {


    }
};
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    solution sc(n,q);
    sc.takeInput();
    return 0;
}