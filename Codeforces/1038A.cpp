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

int a[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, k, i, j, u, v, ans = INT_MAX;
		string s;

		cin >> n >> k;
			
		cin >> s;

		for(i = 0; i < n; i++) a[s[i] - 'A']++;

		for(i = 0; i < k; i++) ans = min(ans, a[i]);

		cout << ans * k << endl;
	
		return 0;
	}