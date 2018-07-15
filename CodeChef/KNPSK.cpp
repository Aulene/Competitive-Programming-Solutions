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

vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, w, c, i, j;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> w >> c;
				vs.pb(mp(w, c));
			}

		
		return 0;
	}