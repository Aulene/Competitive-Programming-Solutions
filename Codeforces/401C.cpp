#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<bitset>
#define mod 1000000007
#define li long long int
#define ll int
#define readi(x) scanf("%d",&x)
#define  reads(x)  scanf("%s",&x)
#define readl(x) scanf("%I64d",&x)
#define rep(i,n) for(i=0;i<n;i++)
#define revp(i,n) for(i=(n-1);i>=0;i--)
#define myrep1(i,a,b) for(i=a;i<=b;i++)
#define myrep2(i,a,b) for(i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define MAXN 2000000000000000000
#define MINN -1000000000000
#define N 100010
#define ran rank
using namespace std;
stack<ll> s;
int main()
{
	ll n,m,k,i;
  cin>>n>>m;
  if(m==(n-1))
  {
  	for(i=0;i<(n+m);i++)
  	{
  		if(i%2==0)
  		{
  			cout<<"0";
		  }
		  else
	     {
	     	cout<<"1";
		 }
	  }
  }
  else if((m>=(n))&&(m<=((n+1)*2)))
  {
  	k=m-n;

  	while(k--)
  	{
  		s.push(1);
	  }
	  for(i=0;i<n;i++)
	  {
	  	cout<<"1";
	  	if(!s.empty())
	  	{
	  		cout<<"1";
	  		s.pop();
		  }
		  cout<<"0";
	  }
	  while(!s.empty())
	  {
	  	cout<<"1";
	  	s.pop();
		 }
  }
  else
  {
  	cout<<"-1";
  }
	
	
	

}