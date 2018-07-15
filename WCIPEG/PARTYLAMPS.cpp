#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> ones, zeroes;
vector < pair <string, int> > ans;
unordered_map <string, bool> sux;
int ansx = 0;

void generator(string s, int m, int ops)
{
	if(m == 4)
		{
			ans.pb(mp(s, ops));
			return;
		}

	string s1 = s;

	if(m == 0)
		{
			for(int i = 0; i < s.size(); i++)
				if(s[i] == '1') s[i] = '0';
				else s[i] = '1';
			generator(s, m + 1, ops + 1);
		}
	else if(m == 1)
		{
			for(int i = 0; i < s.size(); i++)
				if(i % 2 == 0)
					{
						if(s[i] == '1') s[i] = '0';
						else s[i] = '1';
					}
			generator(s, m + 1, ops + 1);
		}
	else if(m == 2)
		{
			for(int i = 0; i < s.size(); i++)
				if(i % 2 == 1)
					{
						if(s[i] == '1') s[i] = '0';
						else s[i] = '1';
					}
			generator(s, m + 1, ops + 1);
		}
	else
		{
			for(int i = 0; i < s.size(); i++)
				if(i % 3 == 0)
					{
						if(s[i] == '1') s[i] = '0';
						else s[i] = '1';
					}
			generator(s, m + 1, ops + 1);
		}

	generator(s1, m + 1, ops);
}

bool checker(string s)
{
	for(int i = 0; i < ones.size(); i++)
		if(s[ones[i]] != '1') return 0;
	for(int i = 0; i < zeroes.size(); i++)
		if(s[zeroes[i]] != '0') return 0;
	sux[s] = 1;
	ansx++;
	return 1;
}
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		// ifstream cin ("lamps.in");
		// ofstream cout ("lamps.out");

		int n, m, i, j, u, v;
		pair <string, int> sx;

		cin >> n >> m;

		string s (n, '1');

		while(1)
			{
				cin >> u;
				if(u == -1) break; u--;
				ones.pb(u); 
			}

		while(1)
			{
				cin >> u;
				if(u == -1) break; u--;
				zeroes.pb(u); 
			}

		generator(s, 0, 0);
		sort(ans.begin(), ans.end());

		for(i = 0; i < ans.size(); i++)
			{
				sx = ans[i];
				s = sx.f, v = sx.s;

				if(sux[s]) continue;

				if(m == 0)
					{
						if(v == 0)
							{
								if(checker(s)) cout << s << endl;
							}
					}
				else if(m == 1)
					{
						if(v == 1)
							{
								if(checker(s)) cout << s << endl;
							}
					}
				else if(m == 2)
					{
						if(v == 0 || v == 2)
							{
								if(checker(s)) cout << s << endl;
							}	
					}
				else if(m == 3)
					{
						if(v == 1 || v == 3)
							{
								if(checker(s)) cout << s << endl;
							}
					}
				else if(m == 4)
					{
						if(v == 0 || v == 2 || v == 4)
							{
								if(checker(s)) cout << s << endl;
							}
					}
				else
					{
						if(checker(s)) cout << s << endl;
					}
			}
		
		if(ansx == 0) cout << "IMPOSSIBLE\n";
		return 0;
	}