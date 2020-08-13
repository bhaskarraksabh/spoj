#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
class solution
{
    int n,q;
    vector<vector<int>>input;
    vector<int>color;
    vector<int>visited;
    public:
    solution (int n,int q)
    {
        this->n=n;
        this->q=q;
        input.resize(n+1);
        color.resize(n+1,-1);
        visited.resize(n+1,0);
    }
    void takeInput()
    {
        for(int i=0;i<q;i+=1)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            input[a].emplace_back(b);
            input[b].emplace_back(a);
        }
    }
    bool bfs(int node)
    {
        queue<int>q1;
        q1.push(node);
        int col=1;
        color[node]=col;
        while(!q1.empty())
        {
            node=q1.front();
            q1.pop();
            visited[node]=1;
            col=color[node];
            for(int i=0;i<input[node].size();i+=1)
            {
                if(color[input[node][i]]==-1)
                {
                q1.push(input[node][i]);
                color[input[node][i]]=1-color[node];
                }
                else if(color[input[node][i]]==color[node])
                return false;
            }
        }
        return true;
    }
    void printer(int flag,int cas)
    {
        string print="Scenario #";
        if(flag==0)
        {
            cout<<print<<cas<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;
        }
        else
        {
            cout<<print<<cas<<":"<<endl;
            cout<<"Suspicious bugs found!"<<endl;
        }
        

    }
    void bfsutil(int c)
    {
        int flag=0;
        for(int i=1;i<=n;i+=1)
        {
            if(visited[i]==0)
            {
                if(bfs(i))
                {
                   // cout<<"no bugs "<<i<<endl;
                    continue;
                }
                else
                {
                  //  cout<<"bugs at "<<i<<endl;
                    flag=1;
                    break;
                }
            }
        }
        printer(flag,c);
    }
    void display(vector<int>input)
    {
        for(auto i:input)
        cout<<i<<" ";
        cout<<endl;
    }
};
int main()
{
    int testcases;
    scanf("%d",&testcases);
    int c=1;
    while(testcases--)
    {
    int n,q;
    scanf("%d %d",&n,&q);
    solution sc(n,q);
    sc.takeInput();
    sc.bfsutil(c);
    c+=1;
    }
    return 0;
}