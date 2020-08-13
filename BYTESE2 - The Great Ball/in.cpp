#include<iostream>
using namespace std;
int main()
{
int testcases=0;
cout<<"100"<<endl;
for(int j=0;j<100;j+=1)
{
cout<<"100"<<endl;
for(int i=0;i<100;i+=1)
{
int num=rand();
int num2=rand();
while(num>num2)
num=rand();
cout<<num<<" "<<num2<<endl;
}
}
return 0;
}
