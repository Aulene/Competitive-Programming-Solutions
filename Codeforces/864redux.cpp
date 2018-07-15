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

#define ll long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define s second

int main()
{
	ll a,b,f,k,flag=1, i;
	scanf("%lld %lld %lld %lld",&a,&b,&f,&k);
	ll curr=b,c=0,d=0;
	for(i=1;i<=k;i++)
	{
	if(f==0)
	{
	  curr=curr-f;
	  d++;
	  if(d==k)
	  {
	    if(curr<(a-f))
	    {c++;
	    curr=b-(a-f);
	    if(curr<0)
	    flag=0;
	    }
	  }
 
	  if(curr<2*(a-f))
	  {c++;
	  curr=b-2*(a-f);
	  if(curr<0)
	  {flag=0;
	  break;}
	  }
	  else if(curr>=2*(a-f))
	  curr=curr-2*(a-f);
	  f=1;
	}
	else if(f==1) 
	{
		d++;
	  if(d==k)
	  {
	    if(curr<(a))
	    {c++;
	    curr=b-a;
	    if(curr<0)
	    flag=0;
	    }
	  }
	  if(curr>=2*(f))
	  curr=curr-2*f;
	  else if(curr<2*f)
	  {curr=b-2*f;
	   c++;
	   if(curr<0)
	   {flag=0;
	   break;}
	  }
	  f=0;
	}
 
	}
	if(flag==0)
	printf("-1\n");
	else
	printf("%lld\n",c);
	return 0;
}