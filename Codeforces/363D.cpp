#include <bits/stdc++.h>
//ugh do it later too involved
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

vi b, c;
int pers[100007];
priority_queue < pair <int, int>, vector < pair <int, int> >, less < pair <int, int> > > pq;

int binarySearch()

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, s, i, j, u, v, ans1 = 0, ans2 = 0;	

		cin >> n >> m >> s;

		for(i = 1; i <= n; i++) cin >> u, b.pb(u);
		for(i = 1; i <= m; i++) cin >> u, c.pb(u);

		sort(b.begin(), b.end(), greater <int>());
		sort(c.begin(), c.end());
	

		return 0;
	}