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
    char val;
    char op;
    struct tree *left,*right;
    tree(){}
    tree(tree *l,tree *r,char v)
    {
        if(v=='+' || v=='-' || v=='*' || v=='/')
        op=v;
        else
        op='N';
        val=v;
        left=l;
        right=r;
    }
};
const int p=4;
class solution
{
    int n;
    string str;
    string rpn;
    vector<int>input;
    char answer[4][4];
    unordered_map<char,int>m1;
    public:
    solution ()
    {
        answer[0][0]='N';
        answer[0][1]='T';
        answer[0][2]='T';
        answer[0][3]='T';
        answer[1][0]='N';
        answer[1][1]='T';
        answer[1][2]='T';
        answer[1][3]='T';
        answer[2][0]='N';
        answer[2][1]='N';
        answer[2][2]='N';
        answer[2][3]='T';
        answer[3][0]='N';
        answer[3][1]='N';
        answer[3][2]='N';
        answer[3][3]='T';
        m1['+']=0;
        m1['-']=1;
        m1['*']=2;
        m1['/']=3;
        //this->n=n;
        //input.resize(n);
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
    int precedence(char s)
    {
        if(s=='+')
        return 1;
        else if(s=='-')
        return 1;
        else if(s=='*')
        return 2;
        else if(s=='/')
        return 2;
        else
        return -1;
    }
    string findRPN()
    {
        string rpn;
        stack<char>s1;
        int n=getLength(str);
        for(int i=0;i<n;i+=1)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                rpn+=str[i];
            }
            if(str[i]=='(')
            s1.push(str[i]);
            else if(str[i]==')')
            {
                while(!s1.empty() && s1.top()!='(')
                {
                    rpn+=s1.top();
                    s1.pop();
                }
                if(!s1.empty())
                s1.pop();
            }
            else if((str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'))
            {
                 if(s1.size()>0)
                 {
                    while(!s1.empty() && precedence(str[i])<=precedence(s1.top()))
                    {
                    rpn+=s1.top();
                    s1.pop();
                    }
                }
                s1.push(str[i]);
            }
        }
        while(!s1.empty())
        {
            rpn+=s1.top();
            s1.pop();
        }
        return rpn;
    }
    void displayer(struct tree *root,int priority)
    {
        int leftpriority,rightpriority;
        switch(root->val)
        {
            case '+':
            {
                leftpriority=rightpriority=2;
                break;
            }
            case '-':
            {
                leftpriority=2;
                rightpriority=1;
                break;
            }
            case '*':
            {
                leftpriority=rightpriority=1;
                break;
            }
            case '/':
            {
                leftpriority=1;
                rightpriority=0;
                break;
            }        //cout<<root->val<<" "<<leftpriority<<" "<<rightpriority<<" "<<priority<<endl;
            cout<<root->val;
            return;
        }
        //cout<<root->val<<" "<<leftpriority<<" "<<rightpriority<<" "<<priority<<endl;
        if(leftpriority>priority)
        cout<<"(";
        displayer(root->left,leftpriority);
        cout<<root->val;
        displayer(root->right,rightpriority);
        if(leftpriority>priority)
        cout<<")";
    }
    void takeInput()
    {
        cin>>str;
        rpn=findRPN();
        //cout<<rpn<<endl;
        struct tree *root;
        stack<tree*>s1;
        int n=getLength(rpn);
        for(int i=0;i<n;i+=1)
        {
            if(rpn[i]=='+' || rpn[i]=='-' || rpn[i]=='*' || rpn[i]=='/')
            {
                struct tree *t1=new tree(NULL,NULL,rpn[i]);
                struct tree *t2=s1.top();
                t2->op=rpn[i];
                s1.pop();
                struct tree *t3=s1.top();
                s1.pop();
                t3->op=rpn[i];
                t1->left=t3;
                t1->right=t2;
                s1.push(t1);
            }
            else
            {
                struct tree *t1=new tree(NULL,NULL,rpn[i]);
                s1.push(t1);
            }
        }
        root=s1.top();
        s1.pop();
        displayer(root,4);
        cout<<endl;
        //cout<<res<<endl;

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
        solution sc;
        sc.takeInput();
    }
    return 0;
}