#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007], m[100007];

signed main()
	{
		ifstream cin ("input.txt");
		ofstream cout ("output.txt");

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;
		int ans1, ans2, ans = mod;


		cin >> n;

		for(i = 1; i <= n; i++)
			{
				cin >> a[i];
				m[a[i]]++;
			}

		for(i = 1; i < 10007; i++)
			m[i] = m[i - 1] + m[i];


		for(i = 1; i <= 5000; i++)
			{
				v = 2 * i;
				ans1 = m[i - 1] + m[10000] - m[v]; 
				ans = min(ans, ans1);
			} 

		cout << ans << endl;

		return 0;
	}