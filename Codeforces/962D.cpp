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
#define mid (start + end) / 2

int a[150007];
unordered_map < int, vector<int> > ms;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j;
		pair <int, int> u, v;
		cin >> n;
		
		for(i = 1; i <= n; i++) {
			cin >> a[i];
			ms[a[i]].pb(i);
		}

		for(int i = )





		return 0;
	}