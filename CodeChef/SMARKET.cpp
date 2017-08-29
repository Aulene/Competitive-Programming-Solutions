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

struct query {
	int l;
	int r;
	int order;
	int i;
};

int a[100007], orders[100007];
query q[100007];
int LeftmostElement, RightmostElement, block=317;
int currentL, currentR;

bool compare(query x, query y)
{
	if(x.l/block != y.l/block)
		return x.l/block < y.l/block;
	return x.r < y.r; 
}

int main()
	{
		int t, n, i, Q, x, y, z;

		cin >> t;

		while(t--)
			{
				currentL=currentR=0;

				cin >> n >> Q;

				for(i=0; i<n; i++)
					cin >> a[i];

				for(i=0; i<Q; i++)
					{
						cin >> q[i].l >> q[i].r >> q[i].order;
						q[i].l--;
						q[i].r--;
						q[i].i = i;
					}

				sort(q, q+Q, compare);

			}

		return 0;
	}