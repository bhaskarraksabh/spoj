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
#include<sstream>
using namespace std;
class solution
{
    unordered_map<string,int>not_abbr;
    int n;
    public:
    solution (int n)
    {
        this->n=n;
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
    void takeInput()
    {
        string str;
        for(int i=0;i<n;i+=1)
        {
            cin>>str;
            //cout<<str<<endl;
            not_abbr[str]=1;
        }
        string aux;
        while(getline(cin,aux) && aux!="LAST CASE")
        {
            while(aux.length()==0)
            getline(cin,aux);
            //cout<<aux<<endl;
            istringstream iss(aux);
            string w;
            int c=0;
            vector<string>words;
            string abbr;
            while(iss>>w)
            {
                if(c==0)
                abbr=w;
                else if(not_abbr[w]==0)
                words.emplace_back(w);
                c+=1;
            }
            transform(abbr.begin(),abbr.end(),abbr.begin(),::tolower);
            //cout<<abbr<<endl;
            //display(words);
             c=0;
            vector<vector<int>>dp(150,vector<int>(150,-1));
            vector<int>sl(words.size(),0);
            for(int i=1;i<words.size();i+=1)
            sl[i]=sl[i-1]+words[i-1].size();
            int ans=findAns(words,dp,abbr,sl,c);
            printer(ans,abbr);
           // display2D(dp);
        }
    }
    void printer(int ans,string abbr)
    {
        transform(abbr.begin(),abbr.end(),abbr.begin(),::toupper);
        if(ans<=0)
        cout<<abbr<<" is not a valid abbreviation"<<endl;
        else
        cout<<abbr<<" "<<"can be formed in"<<" "<<ans<<" ways"<<endl;
    }
    vector<char>picked;
    int c=0;
    int findAns(vector<string>words,vector<vector<int>>&dp,string abbr,vector<int>sl,int c,int idx=0,int index=0,int prev=0)
    {
        if(idx>=words.size())
        {
            if(index>=abbr.size())
            return 1;
            else
            return 0;
        }
        if(idx<words.size() && index>=abbr.size())
        return 0;
        int s=prev+sl[idx];
        int pos=prev+s;
        if(dp[index][s]!=-1)
        return dp[index][s];
        string str=words[idx];
        int ans=0;
        for(int i=prev;i<str.size();i+=1)
        {
            if(str[i]==abbr[index])
            {
                if(i+1<str.size())
                ans+=findAns(words,dp,abbr,sl,c,idx,index+1,i+1);
                ans+=findAns(words,dp,abbr,sl,c,idx+1,index+1,0);
            }
        }
        return dp[index][s]=ans;
    }
    
};
int main()
{
    int n;
    while(cin>>n && n!=0)
    {
        solution sc(n);
        sc.takeInput();

    }
    return 0;
}