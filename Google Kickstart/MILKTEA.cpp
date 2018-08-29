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

int pref[107];
unordered_map <string, int> mx;
int ans;
int n, m, p;

int recur(int idx, string s, int sum)
{
	if(sum > ans) return 0;

	if(idx == p)
		{
			if(!mx[s])
				ans = min(ans, sum);
			return 0;
		}

	recur(idx + 1, s + '1', sum + (n - pref[idx]));
	recur(idx + 1, s + '0', sum + pref[idx]);
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t, T, i, j, k, u, v;
		string s;

		ifstream cin ("/Users/Aulene/Desktop/input.txt");
		ofstream cout ("/Users/Aulene/Desktop/output.txt");
		
		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");

		cin >> t;

		for(T = 1; T <= t; T++)
			{
				ans = INT_MAX;
				mx.clear();
				memset(pref, 0, sizeof(pref));

				cin >> n >> m >> p;

				for(i = 0; i < n; i++)
					{
						cin >> s;
						for(j = 0; j < p; j++)
							if(s[j] == '1') pref[j]++;
					}

				for(i = 0; i < m; i++)
					{
						cin >> s;
						mx[s] = 1;
					}

				recur(0, "", 0);
				cout << "Case #" << T << ": " << ans << endl;
			}
		return 0;
	}