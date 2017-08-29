#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

#define max 1000001
using namespace std;
vector <int> prime;
vector<bool> isprime(max,true);
vector<bool> visited(max,false);
vector<int> data(max,-1);
void dp(int n,int last)
{
    if(n >= max || visited[n])
        return;
    visited[n] = true;
    for(int i = last;i<prime.size();i++)
    {
        if(n*prime[i] >= max || data[n*prime[i]] != -1)
            return;
        data[n*prime[i]] = prime[i];
        dp(n*prime[i],i);
    }
}
int main()
{
    isprime[1] = false;
    data[1] = 1;
    for(int i = 4;i<max;i += 2)
        isprime[i] = false;
    for(int i = 3; i*i< max;i += 2)
    {
        for(int j = i*i; j < max;j += i)
            isprime[j] = false;
    }
    prime.push_back(2);
    data[2] = 2;
    for(int i =3;i<max;i += 2)
        if(isprime[i])
        {
            prime.push_back(i);
            data[i] = i;
        }

    for(int i = 0;i<prime.size();i++)
    {
        dp(prime[i],i);
    }
        cout<<"...1\n";
    for(int i = 2;i<=8000;i++)
    {
        cout<<i<<" :- ";
        int temp = i;
        while(temp!= 1)
        {
            cout<<data[temp]<<" ";
            temp = temp/data[temp];
        }
        cout<<endl;
    }

    return 0;
}