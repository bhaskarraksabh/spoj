#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution
{
    int n,q;
    vector<int>input;
    public:
    solution (int n,int q)
    {
        this->n=n;
        this->q=q;
        input.resize(n);
    }
    void takeInput()
    {
        for(int i=0;i<n;i+=1)
        scanf("%d",&input[i]);
        sort(input.begin(),input.end());
    }
    vector<int>packet;
    int m=0;
    void bruteForce(int idx=0)
    {
        if(idx>=n && packet.size()==q)
        {
            for(int i=0;i+1<packet.size();i+=1)
            {
                m=max(abs(packet[i]-packet[i+1]),m);
                cout<<packet[i]<<" ";
            }
            cout<<packet[packet.size()-1];
            cout<<endl;
            return;
        }
        if(idx>=n)
        return;
        packet.emplace_back(input[idx]);
        bruteForce(idx+1);
        packet.erase(packet.end()-1);
        bruteForce(idx+1);
    }
    void findAns()
    {
         int low=0;
         int high=input[n-1]-input[0];
         while(low<=high)
         {
             int c=1;
             int mid=low+(high-low)/2;
             int curr=input[0];
             int placedpos=0;
             for(int i=1;i<n;i+=1)
             {
                 if(input[i]-curr>=mid)
                 {
                     c+=1;
                     curr=input[i];
                 }
             }
             //cout<<c<<" "<<low<<" "<<mid<<" "<<high<<endl;
             if(c<q)
             high=mid-1;
             else
             low=mid+1;
         }
         printf("%d\n",low-1);
    }
};
int main()
{
    int testcases;
    scanf("%d",&testcases);
    int n,q;
    while(testcases--)
    {
    scanf("%d %d",&n,&q);
    solution sc(n,q);
    sc.takeInput();
    //sc.bruteForce();
    sc.findAns();
    }
    return 0;
}