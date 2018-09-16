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

int a[100007];
multiset <int> mx;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, a, b, i, j, u, v;

		cin >> n >> a >> b;

		for(i = 1; i <= n; i++) cin >> a[i], mx.insert(a[i]);



		return 0;
	}