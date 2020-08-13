#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class solution
{
    int n,q;
    public:vector<vector<int>>input;
    solution(int n,int q)
    {
        this->n=n;
        this->q=q;
        input.resize(n);
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
    void dfs(bool visited[],int node)
    {
        visited[node]=true;
        for(int i=0;i<input[node].size();i+=1)
        {
            if(visited[input[node][i]]==false)
            dfs(visited,input[node][i]);
        }
    }
    void findAns()
    {
        bool visited[n];
        memset(visited,false,sizeof(visited));
        int c=0;
        for(int i=0;i<n;i+=1)
        {
            if(visited[i]==false)
            {
                c+=1;
                dfs(visited,i);
            }
        }
        printf("%d\n",c);
    }
};
int main()
{
    int testcases;
    scanf("%d",&testcases);
    while(testcases--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        solution sc(n,q);
        sc.takeInput();
        sc.findAns();
    }
    return 0;
}