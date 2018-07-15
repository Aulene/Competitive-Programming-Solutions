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

vector < pair <int, int> > in, out;
int lol[107], pref[107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int a, b, c, u, v, i, ans = 0;

		cin >> a >> b >> c;

		for(i = 0; i < 3; i++)
			{
				cin >> u >> v;
				lol[u] = 1, lol[v + 1] = -1;
			}

		for(i = 1; i < 102; i++)
			{
				pref[i] = pref[i - 1] + lol[i];

				cout << pref[i] << " ";
				if(pref[i] == 1) ans += a;
				else if(pref[i] == 2) ans += b;
				else if(pref[i] == 3) ans += c;
			}
		
		cout << ans << endl;


		return 0;
	}