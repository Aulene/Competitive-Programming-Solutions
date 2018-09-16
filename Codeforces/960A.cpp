#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

unordered_map <char, int> m;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s;
		bool ansx = 1;
		int n, i, j, u, v;

		cin >> s;
		n = s.size();

		for(int i = 0; i < n; i++)
			{
				m[s[i]]++;
				if(i < n - 1 && s[i] > s[i + 1]) ansx = 0;
			}
			
		if(ansx && ((m['c'] == m['a']) || (m['c'] == m['b'])) && m['a'] && m['b'] && m['c']) cout << "YES";
		else cout << "NO";
		22
		return 0;
	}