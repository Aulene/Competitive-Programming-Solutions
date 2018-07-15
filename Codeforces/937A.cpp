#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[107];
set <int> s;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, ans = 0;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> j;
				s.insert(j);
			}

		if(*s.begin()==0) cout << s.size() - 1;
		else cout << s.size();

		return 0;
	}