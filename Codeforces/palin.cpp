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

bool palin(string s, int n)
{
	int i, j = n - 1;

	for(i = 0; j >= i; i++)
		if(s[i] != s[j]) return 0;
		else j--;
	return 1;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, ans;
		string s;
		cin >> t;

		while(t--)
			{
				cin >> s; n = s.size();
				ans = 0;

				sort(s.begin(), s.end());

				do {
					if(palin(s, n)) ans++; 
				} while(next_permutation(s.begin(), s.end()));

				cout << ans << endl;
			}
		return 0;
	}