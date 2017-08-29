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

#define lli long long int
#define mod 1000000007
#define pb push_back

lli a[100007];
lli maxTree[100007];
lli minTree[100007];

int buildMax(int index, int l, int r)
{
	if(l==r)
		{
			maxTree[index]=a[l];
		}
	else
		{
			int mid=(l+r)/2;
			buildMax(2*index, l, mid);
			buildMax(2*index+1, mid+1, r);
			maxTree[index]=max(maxTree[2*index], maxTree[2*index+1]);
		}
	return 0;
}

int buildMin(int index, int l, int r)
{
	if(l==r)
		minTree[index]=a[l];
	else
		{
			int mid=(l+r)/2;
			buildMin(2*index, l, mid);
			buildMin(2*index+1, mid+1, r);
			minTree[index]=min(minTree[2*index], minTree[2*index+1]);
		}
	return 0;
}

int queryMax(int index, int l, int r, int x, int y)
{
	if(x==l && y==r)
		return maxTree[index];
	else
		{
			int mid=(l+r)/2;

			if(y<=mid)
				return queryMax(2*index, l, mid, x, y);
			else if(x>mid)
				return queryMax(2*index+1, mid+1, r, x, y);
			else
				return max(queryMax(2*index, l, mid, x, mid), queryMax(2*index+1, mid+1, r, mid+1, y));
		}
}

int queryMin(int index, int l, int r, int x, int y)
{
	if(x==l && y==r)
		return minTree[index];	
	else
		{
			int mid=(l+r)/2;

			if(y<=mid)
				return queryMin(2*index, l, mid, x, y);
			else if(x>mid)
				return queryMin(2*index+1, mid+1, r, x, y);
			else
				return min(queryMin(2*index, l, mid, x, mid), queryMin(2*index+1, mid+1, r, mid+1, y));
		}
}

int main()
	{
		int n, q, i;
		int u, v;

		cin >> n >> q;

		for(i=1; i<=n; i++)
			cin >> a[i];

		buildMax(1, 1, n);
		buildMin(1, 1, n);

		/*
			for(i=1; i<=2*n; i++)
				cout << minTree[i] << " ";
		*/

		while(q--)
			{
				cin >> u >> v;
				u++;
				v++;
				cout << queryMax(1, 1, n, u, v)-queryMin(1, 1, n, u, v) << endl;
			}
		return 0;
	}