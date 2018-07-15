/*
 ID: aussyle1
 PROG: prefix
 LANG: C++11
 */

#include <bits/stdc++.h>

using namespace std;

// #define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int trie[2777][37];
int ex[2777 * 37];
int dp[200017];
string s;

int triverse(int orig, int sidx, int tidx)
{
	if(sidx > s.size()) return 0;
	if(ex[tidx])
		{
			// cout << "op" << endl;
			
			// cout << orig << " " << sidx << " " << tidx << " " << trie[tidx][s[sidx] - 'A'] << endl;
			// cout << dp[sidx] + (sidx - orig) << " " << dp[orig] << endl;
			
			dp[orig] = max(dp[sidx] + (sidx - orig), dp[orig]);
			
			// cout << "cls" << endl;
			// return dp[sidx] + 1;
		}

	int ans = 0;

	if(trie[tidx][s[sidx] - 'A'] != 0)
		{
			// cout << tidx << " " << s[sidx] << " -> " << trie[tidx][s[sidx] - 'A'] << endl;
			triverse(orig, sidx + 1, trie[tidx][s[sidx] - 'A']);
		}

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		ifstream cin ("prefix.in");
		ofstream cout ("prefix.out");

		string s1;
		int n = 2, i, j, k, u, v, ans = 0;
		// ex[0] = 1;

		while(cin >> s)
			{
				if(s[0] == '.') break;

				int idx = 1;

				for(i = 0; i < s.size(); i++)
					{
						if(trie[idx][s[i] - 'A'] == 0)
							{
								trie[idx][s[i] - 'A'] = n;
								n++;
							}

						// cout << idx << " " << s[i] << " -> " << trie[idx][s[i] - 'A'] << endl; 

						idx = trie[idx][s[i] - 'A'];
					}

				ex[idx] = 1;
				// cout << idx << endl;
			}
		// cout << endl << endl;

		s = "";

		while(cin >> s1)
			{
				s += s1;
			}

		// cin >> s;
		for(i = s.size(); i >= 0; i--)
			{
				triverse(i, i, 1);
				// cout << i << " " << dp[i] << endl;
			}

		// for(i = 0; i < s.size(); i++)
		// 	cout << i << " " << dp[i] << endl;

		cout << dp[0] << endl;

		return 0;
	}