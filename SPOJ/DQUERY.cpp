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

#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[300007], ansv[200007], m[1000007];

vector < pair < pair <int, int>, int > > queries;
int ans = 0, block;

bool cmp1(pair < pair <int, int>, int > a, pair < pair <int, int>, int > b)
{
	int x = a.f.f / block, y = b.f.f / block;
	if(x != y)
		return x < y;
	return a.f.s < b.f.s;
}

int add(int pos)
{
	m[a[pos]]++;
	if(m[a[pos]] == 1) ans++;
	return 0;
}

int remove(int pos)
{
	m[a[pos]]--;
	if(m[a[pos]] == 0) ans--;
	return 0;
}

int main()
	{
		ios_base::sync_with_stdio(false); 
		cin.tie(NULL); 

		int n, i, j, u, v, q, L, R;
		int currentL = 0, currentR = 0;

		scanf("%d", &n);

		for(i = 0; i < n; i++)
			scanf("%d", &a[i]);

		scanf("%d", &q);

		for(i = 0; i < q; i++)
			{
				scanf("%d %d", &u, &v);
				u--, v--;
				queries.pb(mp(mp(u, v), i));
			}

		block = ceil(sqrt(n));
		sort(queries.begin(), queries.end(), cmp1);
		
		for(i = 0; i < q; i++)
			{
				L = queries[i].f.f, R = queries[i].f.s;

				while(currentL < L)
					{
						remove(currentL);
						currentL++;
					}

				while(currentL > L)
					{
						add(currentL - 1);
						currentL--;
					}

				while(currentR <= R)
					{
						add(currentR);
						currentR++;
					}

				while(currentR > R + 1)
					{
						remove(currentR - 1);
						currentR--;
					}

				ansv[queries[i].s] = ans;
			}

		for(i = 0; i < q; i++)
			printf("%d\n", ansv[i]);

		return 0;
	}