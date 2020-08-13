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
    int val;
    int m;
    struct tree *left;
    struct tree *right;
    tree(tree *l,tree *r,int low,int high)
    {
        left=l;
        right=r;
        start=low;
        end=high;
        m=0;
        val=0;
    }
};
class solution
{
    int n;
    vector<pair<int,int>>input;
    struct tree *root;
    public:
    solution (int n)
    {
        this->n=n;
        input.resize(n);
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
    struct tree *build(int low,int high,struct tree *root)
    {
        if(low>=high)
        {
            return root;
        }
        int mid=low+(high-low)/2;
        root->left=new tree(NULL,NULL,low,mid);
        root->right=new tree(NULL,NULL,mid+1,high);
        root->left=build(low,mid,root->left);
        root->right=build(mid+1,high,root->right);
        return root;
    }
    void update(struct tree *&root,int qlow,int qhigh)
    {
        if(root->start>=qlow && root->end<=qhigh)
        {
            root->val+=1;
            //root->m=1;
        }
        if(root->start>qhigh || root->end<qlow)
        return;
        if(root->left)
        update(root->left,qlow,qhigh);
        if(root->right)
        update(root->right,qlow,qhigh);
        if(root->left && root->right)
        root->m=max({root->m,root->left->val,root->right->val,root->left->m,root->right->m});
    }
    void displayer(struct tree *root)
    {
        if(root!=NULL)
        {
            cout<<root->start<<" "<<root->end<<" "<<root->val<<" "<<root->m<<endl;
            displayer(root->left);
            displayer(root->right);
        }
    }
    void takeInput()
    {
        int ma=0;
        int mi=9999;
        for(int i=0;i<n;i+=1)
        {
            scanf("%d %d",&input[i].first,&input[i].second);
            mi=min(input[i].first,mi);
            ma=max(input[i].second,ma);
        }
        root=new tree(NULL,NULL,mi,ma);
        root=build(mi,ma,root);
        //displayer(root);
        for(int i=0;i<n;i+=1)
        {
            update(root,input[i].first,input[i].second);
        }
        printf("%d\n",root->m);
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