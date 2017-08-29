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
#define p push
#define pb push_back
#define mp make_pair

int a[100007];
int tree[400007];

int build(int index, int l, int r)
{
	if(l==r)
		{
			tree[index]=a[l];
		}
	else
		{
			int mid=(l+r)/2;
			build(2*index, l, mid);
			build(2*index+1, mid+1, r);
			tree[index]=min(tree[2*index], tree[2*index+1]);
		}
	return tree[index];
}

int queryMin(int index, int l, int r, int x, int y)
{
	if(x==l && y==r)
		return tree[index];	
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
		int n, i, q, u, v;

		cin >> n;

		for(i=1; i<=n; i++)
			cin >> a[i];

		build(1, 1, n);

		cin >> q;

		while(q--)
			{
				cin >> u >> v;
				u++;
				v++;
				cout << queryMin(1, 1, n, u, v) << endl;
			}
		return 0;
	}