// powermodulo from http://www.sanfoundry.com/cpp-program-implement-modular-exponentiation-algorithm/

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define int long long int
#define mod 163577857
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

unordered_map <string, bool> vis;

int ansx = 0;
int K, n;

int recur(string s, int idx)
{
	if(idx > K)
		{
			if(vis[s] == 0)
				{
					// cout << s << endl;
					ansx++;
					vis[s] = 1;
				}

			return 0;
		}

	string sx;

	for(int i = 0; i < s.size(); i++)
		{
			for(int j = 0; j < s.size() - i; j++)
				{
					sx = s;

					for(int k = i; k <= i + j; k++)
						sx[k] = (char) '0' + idx;

					recur(sx, idx + 1);	
				}
		}

	return 0;
}

int modular_pow(int base, int exponent, int modulus)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int recur(int idx, int up, int down)
{
	if(idx > n)
		{
			if(up == K) return 1;
			return 0;
		}

	int ans = 0;

	for(int i = up; i <= K; i++) ans += recur(idx + 1, i, down);
	ans += recur()
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, k, i, j, u, v;
		string s;

		cin >> t;

		while(t--)
			{
				vis.clear();

				int ans = 0;
				ansx = 0;
				s = "";

				cin >> n >> K;
				double 
				cout << pow()
				// for(i = 0; i < n; i++) s += '0';

				// recur(s, 0);

				// for(int i = n; i >= 1; i--)
				// 	ans = (ans + (i * modular_pow(K, i - 1, mod)) % mod) % mod;
				
				// cout << ans << " " << ansx << " " << abs(ans - ansx) << endl;
				// cout << ans << endl;
			}

		return 0;
	}