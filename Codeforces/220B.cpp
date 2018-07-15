#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int block, answer = 0;
int a[100007], ans[100007], mx[100007];
vector < pair < pair <int, int>, int> > vs;

bool cmp(pair < pair <int, int>, int> a, pair < pair <int, int>, int> b)
{
	if(a.f.f / block != b.f.f / block) 
		return a.f.f / block < b.f.f / block;
	return a.f.s < b.f.s;
}

void add(int position) {
	if(a[position] > 1e5) return;
	
	if(mx[a[position]] == a[position]) {
		answer--;
	}
	mx[a[position]]++;
	if(mx[a[position]] == a[position]) {
		answer++;
	}
}

void remove(int position) {
	if(a[position] > 1e5) return;

	if(mx[a[position]] == a[position]) {
		answer--;
	}
	mx[a[position]]--;

	if(mx[a[position]] == a[position]) {
		answer++;
	}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		int currentL = 0, currentR = 0;

		cin >> n >> m;

		for(i = 0; i < n; i++) cin >> a[i];

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				vs.pb(mp(mp(u - 1, v - 1), i));
			}

		block = sqrt(n);
		sort(vs.begin(), vs.end(), cmp);

		// for(i = 0; i < m; i++) cout << vs[i].f.f << " " << vs[i].f.s << endl;

		j = 0;

		for(j = 0; j < m; j++)
			{
				u = vs[j].f.f, v = vs[j].f.s;

				// cout << u << " " << v << endl;

				while(currentL < u) {
					remove(currentL);
					currentL++;
				}
				while(currentL > u) {
					add(currentL - 1);
					currentL--;
				}
				while(currentR <= v) {
					add(currentR);
					currentR++;
				}
				while(currentR > v + 1) {
					remove(currentR - 1);
					currentR--;
				}

				// cout << "SET:\n";
				// for(set <int> :: iterator it = anus.begin(); it != anus.end(); it++) 
				// 	cout << *it << " "; cout << endl;
				// for(i = 1; i <= 7; i++) cout << mx[i] << " "; cout << endl;

				ans[vs[j].s] = answer;
			}

		for(i = 0; i < m; i++) cout << ans[i] << endl;
		return 0;
	}