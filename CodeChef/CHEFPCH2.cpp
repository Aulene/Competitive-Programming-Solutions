#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;
int A[100007];

void pSubstr(int n)
{
  int count=0;
  int dp[n][n];
  memset(dp,0,sizeof(dp));
  int P[n][n];
  memset(P,0,sizeof(P));
  for(int i=0;i<n;i++)
  {
     P[i][i]=1;
     dp[i][i]=1;
  }
 
  for(int l=2;l<n;l++)
  {
    for(int i=1;i<n-l+1;i++)
    {
       int j=i+l-1;
 
       if(A[i]==A[j]&&P[i+1][j-1])
         P[i][j]=1;
 
       if(P[i][j])
         dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+1;
       else
         dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
    }
 
    for(int i=1;i<=n;i++)
    {
      for(int j=i;j<=n;j++)
      {
         if((j-i)%2==0)
           count+=dp[i-1][j-1];
      }
    }
 
    cout<<count<<endl;
  }
 
  cout<<count<<endl;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     int n,k;
     cin>>n>>k;
     for(int i=0;i<k;i++)
     {
        int p,q;
        cin>>p>>q;
        A[p]=q;
     }
    pSubstr(n);
  }
  return 0;
}