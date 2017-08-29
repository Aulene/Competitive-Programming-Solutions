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

using namespace std;

int main()
{
    long long int i,n,x,y,cost[200005],l[200005],r[200005],a[200005],mini=INT_MAX;
    cin>>n>>x;
    for(i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        a[i]=(r[i]-l[i]+1);
        cin>>cost[i];
    }
    int flag=0;
    map<int,int> m;
    for(i=0;i<n;i++)
    {
        if(m.find(x-a[i])!=m.end())
        {
            y=m[a[i]]+m[x-a[i]];
            if(y<mini)
            {
                mini=y;
            }
            flag=1;
        }
        m[a[i]]=cost[i];
    }
    if(flag==1)
    {
        cout<<mini<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
}
