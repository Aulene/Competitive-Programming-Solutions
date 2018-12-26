#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int>
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

const int N = 200007;
const int M = 2000007;

vector < pair < pair <int, int>, pair <int, int> > > qs;
int a[M], cnt[M];
int ans[M], sq[M], BLOCK;

bool comp(pair < pair <int, int>, pair <int, int> > a, pair < pair <int, int>, pair <int, int> > b)
{
	if(a.f.f / BLOCK != b.f.f / BLOCK)
		return a.f.f / BLOCK < b.f.f / BLOCK;
	return a.f.s < b.f.s;
}

inline void add(int x, int &sum)
{
	sum = sum - a[x] * sq[cnt[a[x]]];
	cnt[a[x]]++;
	sum = sum + a[x] * sq[cnt[a[x]]];
}

inline void remove(int x, int &sum)
{
	sum = sum - a[x] * sq[cnt[a[x]]];
	cnt[a[x]]--;
	sum = sum + a[x] * sq[cnt[a[x]]];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		for(int i = 1; i < M; i++) sq[i] = i * i;
		
		int n, m, i, j, u, v;
		int left = 0, right = 0;
		int sum = 0;

		cin >> n >> m;

		BLOCK = sqrt(n);
		for(i = 0; i < n; i++) cin >> a[i];

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
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