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
// dont know why used both min and max got tle :(
struct tree
{
    int start,end;
    long long lazy;
    struct tree *left,*right;
    long long val;
    long long sum;
    long long sqsum;
    long long mi,ma;
    tree(tree *l,tree *r,int low,int high)
    {
        start=low;
        end=high;
        left=l;
        right=r;
        sum=sqsum=0;
        lazy=0;
    }
};
class solution
{
    int n;
    vector<long long>input;
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
            root->val=input[low];
            root->sum=input[low];
            root->sqsum=sqrt(input[low]);
            root->mi=root->val;
            root->ma=root->val;
            return root;
        }
        int mid=low+(high-low)/2;
        root->left=new tree(NULL,NULL,low,mid);
        root->right=new tree(NULL,NULL,mid+1,high);
        struct tree *a=build(root->left,low,mid);
        struct tree *b=build(root->right,mid+1,high);
        root->left=a;
        root->right=b;
        root->sum=a->sum+b->sum;
        root->ma=max(root->left->ma,root->right->ma);
        return root;
    }
    long long query(struct tree *root,int low,int high)
    {
        if(root->start>high || root->end<low)
        return 0;
        if(root->start>=low && root->end<=high)
        return root->sum;
        return query(root->left,low,high)+query(root->right,low,high);
    }
    void updateRange(struct tree *&root,int low,int high)
    {
        if(root->ma==1)
        return;
        if(root->start==root->end && root->start>=low && root->end<=high)
        {
            root->val=sqrt(root->val);
            root->sum=root->val;
            root->ma=root->val;
            return;
        }
        if(root->start>high || root->end<low)
        return;
        updateRange(root->left,low,high);
        updateRange(root->right,low,high);
        root->sum=root->left->sum+root->right->sum;
        root->ma=max(root->left->ma,root->right->ma);
        return;
    }
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        scanf("%lld",&input[i]);
        root=build(root,0,n-1);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(b>c)
            swap(b,c);
            --b;
            --c;
            if(a==1)
            {
                printf("%lld\n",query(root,b,c));
            }
            else
            {
                updateRange(root,b,c);
            }
        }
    }
};
int main()
{
    int n;
    int t=0;
    while(scanf("%d",&n)!=EOF)
    {
        ++t;
        printf("Case #%d:\n",t);
        solution sc(n);
        sc.takeInput();
        printf("\n");
    }
    return 0;
}