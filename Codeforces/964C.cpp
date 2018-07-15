#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define int long long int
#define mod 1000000009
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100000007], b[100000007];
unordered_map <int, int> ax, bx;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, A, B, k, t, i, j, sum, ans;
		string st;

		cin >> n >> A >> B >> k;	
		cin >> st;

		n++;
		t = n / k;

		a[0] = b[0] = bx[0] = ax[0] = 1;

		for(i = 1; i <= k;i++)
			{
				a[i] = (a[i - 1] * A) % mod;
				b[i] = (b[i - 1] * B) % mod;
			}  

		for(i = 1; i < t; i++)
			{
				ax[i] = (ax[i - 1] * a[k]) % mod; 		
				bx[i] = (bx[i - 1] * b[k]) % mod;
			}

		for(i = 0; i < k; i++)
			{
				if(st[i] == '+') ans = (ans + a[k - i - 1] * b[i]) % mod;
				else ans = (ans - a[k - i - 1] * b[i]) % mod;
			}

		for(i = 0; i < t; i++)
			sum = (sum + (((ax[t - i - 1] * bx[i]) % mod) * ans) % mod) % mod;

		if(ans >= 0) cout << sum << endl;
		else cout << (mod + sum) % mod << endl;
		return 0;
	}