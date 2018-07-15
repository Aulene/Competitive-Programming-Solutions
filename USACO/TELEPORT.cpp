#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		ifstream cin("teleport.in");
		ofstream cout ("teleport.out");

		int a, b, x, y;

		cin >> a >> b >> x >> y;

		if(x > y) swap(x, y);
		if(a > b) swap(a, b);

		int a1 = abs(b - y) + abs(a - x), a2 = abs(b - a);
		cout << min(a1, a2) << endl;

		return 0;
	}