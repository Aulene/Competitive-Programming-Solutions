#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int c[200007], a[200007], parent[200007];

int par(int idx)
{
	if(parent[idx] != idx) parent[idx] = par(parent[idx]);
	return parent[idx];
}

int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, q, u, v, x;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> c[i], a[i] = c[i], parent[i] = i;
		parent[n + 1] = n + 1;

		cin >> m;

		while(m--)
			{
				cin >> q;

				if(q == 1)
					{
						cin >> j >> v;

						while(v != 0 && j <= n)
							{
								if(a[j] > v) 
									{
										a[j] -= v;
										v = 0;
									}
								else
									{
										v -= a[j];
										a[j] = 0;
										parent[j] = par(j + 1);
										j = par(j);
									}
							}
					}
				else
					{
						cin >> u;
						cout << c[u] - a[u] << endl;
					}
			}
		return 0;
	}