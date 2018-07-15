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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j;

		cin >> t;

		if(t % 2 == 0)
			{
				cout << (t - 1) * 2 << " " << 2 << endl;
				cout << 1 << " " << 2;
			}
		else
			{
				cout << (t - 1) * 2 + 1 << " " << 2 << endl;
				cout << 1 << " " << 2;
			}
 		return 0;
	}