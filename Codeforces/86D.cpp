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
#define lli long long int
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair < pair <lli, lli>, pair <lli, lli> > > qs;
lli a[2000007], cnt[2000007];;
lli ans[2000007], BLOCK;

bool comp(pair < pair <lli, lli>, pair <lli, lli> > a, pair < pair <lli, lli>, pair <lli, lli> > b)
{
	if(a.f.f / BLOCK != b.f.f / BLOCK)
		return a.f.f / BLOCK < b.f.f / BLOCK;
	return a.f.s < b.f.s;
}

inline void add(lli x, lli &sum)
{
	sum = sum - a[x] * cnt[a[x]] * cnt[a[x]];
	cnt[a[x]]++;
	sum = sum + a[x] * cnt[a[x]] * cnt[a[x]];
}

inline void remove(lli x, lli &sum)
{
	sum = sum - a[x] * cnt[a[x]] * cnt[a[x]];
	cnt[a[x]]--;
	sum = sum + a[x] * cnt[a[x]] * cnt[a[x]];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		lli n, m, i, j, u, v;
		lli left = 0, right = 0;
		lli sum = 0;

		scanf("%lld %lld", &n, &m);

		BLOCK = sqrt(n);
		for(i = 0; i < n; i++)
			scanf("%lld", &a[i]);

		for(i = 0; i < m; i++)
			{
				scanf("%lld %lld", &u, &v);
				qs.pb(mp(mp(u - 1, v - 1), mp(i, 0)));
			}

		sort(qs.begin(), qs.end(), comp);

		// for(i = 0; i < m; i++)
		// 	cout << qs[i].f.f << " " << qs[i].f.s << endl;

		for(i = 0; i < m; i++)
			{
				u = qs[i].f.f, v = qs[i].f.s;

				while(left < u)
					{
						remove(left, sum);
						left++;
					}

				while(left > u)
					{
						add(left - 1, sum);
						left--;
					}

				while(right <= v)
					{
						add(right, sum);
						right++;
					}

				while(right > v + 1)
					{
						remove(right - 1, sum);
						right--;
					}

				qs[i].s.s = sum;
			}

		for(i = 0; i < m; i++)
			ans[qs[i].s.f] = qs[i].s.s;

		for(i = 0; i < m; i++)
			cout << ans[i] << endl;

		return 0;
	}