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

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair <int, int> > h;
int n;

double dist(pair <int, int> a, pair <int, int> b) { return sqrt(pow(abs(a.f - b.f), 2) + pow(abs(a.s - b.s), 2)); }

void cpy(bool a[], bool b[]) 
{
	for(int i = 0; i < n; i++) b[i] = a[i];
}

double recur(int idx, int bmask)
{
	if(idx >= n) return 0;
	if(bmask & (1 << idx)) return recur(idx + 1, bmask);

	int bmask2;
	double ans = 100000000007, d;

	for(int i = idx + 1; i < n; i++)
		if(!(bmask & (1 << i)))
			{
				bmask2 = bmask;
				bmask2 = bmask2 | (1 << idx);
				bmask2 = bmask2 | (1 << i);
				d = dist(h[idx], h[i]);
				// cout << d << endl;
				ans = min(ans, recur(idx + 1, bmask2) + d);
			}
	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j = 1, t, x, y;
		pair <int, int> p;
		double ans; string s;

		while(cin >> n)
			{
				if(!n) break;

				h.clear();
				n *= 2;

				for(i = 0; i < n; i++)
					{
						cin >> s >> x >> y;
						p = mp(x, y);
						h.pb(p);
					}

				ans = recur(0, 0);
				printf("Case %lld: %.2f\n", j, ans);
				j++;			
			}

		return 0;
	}