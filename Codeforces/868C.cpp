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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007][7],b[7];

int main() {
	int i,j,k,c,n,m,v=0,d=0,w=0;
	cin>>n>>k;
	if(n%2==0)
		w=n/2;
	else
		w=(n/2)+1;

	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			cin>>a[i][j];
		}
	}
	for(j=0;j<k;j++)
	{
		c=0;
		for(i=0;i<n;i++)
		{
			if(a[j][i]==1)
				c++;
		}
		b[v]=c;
		v++;
	}
	for(i=0;i<v;i++)
	{
		if(b[i]>w)
		{
			d++;
			break;
		}
	}
	if(d>0)
		cout<<"NO";
	else
		cout<<"YES";
	return 0;
}