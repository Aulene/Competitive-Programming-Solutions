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

		int t;
		double n, v1, v2;
		double u, v, w;

		cin >> t;

		while(t--)
			{
				cin >> n >> v1 >> v2;

				u = (sqrt(2) * n) / v1;
				v = (2 * n) / v2;

				if(u > v) cout << "Elevator\n";
				else cout << "Stairs\n";
			}
		return 0;
	}