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

		int t, n, k, s1, s2, s3;

		cin >> t;

		while(t--)
			{
				cin >> k >> n;

				s1 = n * (n + 1) / 2;
				s2 = n * n;
				s3 = n * (n + 1);

				cout << k << " " << s1 << " " << s2 << " " << s3 << endl;
			}
		return 0;
	}