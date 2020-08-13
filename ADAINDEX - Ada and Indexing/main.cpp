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
struct trie
{
    struct trie *child[26];
    int count[26];
    bool isend;
    trie()
    {
        memset(child,0,sizeof(child));
        memset(count,0,sizeof(count));
        isend=false;
    }
};
class solution
{
    int n,q;
    vector<string>input;
    struct trie *root;
    public:
    solution (int n,int q)
    {
        this->n=n;
        this->q=q;
        input.resize(n);
        root=new trie();
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
    template<typename T>
    int getLength(T &input)
    {
        return input.size();
    }
    void insert(string str)
    {
        int n=getLength(str);
        struct trie *curr=root;
        for(int i=0;i<n;i+=1)
        {
            if(curr->child[str[i]-'a']==NULL)
            {
                curr->child[str[i]-'a']=new trie();                
            }
            curr->count[str[i]-'a']+=1;
            curr=curr->child[str[i]-'a'];
        }
        curr->isend=true;
    }
    int search(string str)
    {
        struct trie *curr=root;
        int c=0;
        int n=getLength(str);
        int flag=0;
        int num=0;
        for(int i=0;i<n;i+=1)
        {
            //cout<<str[i]<<" "<<curr->count[str[i]-'a']<<endl;
            if(curr->child[str[i]-'a']>0)
            {
                num=curr->count[str[i]-'a'];
                curr=curr->child[str[i]-'a'];
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        return num;
        else
        return 0;
    }
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        {
            cin>>input[i];
            insert(input[i]);
        }
        string str;
        while(q--)
        {
            cin>>str;
            
            printf("%d\n",search(str));
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