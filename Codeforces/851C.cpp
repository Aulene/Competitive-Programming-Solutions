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

struct point 
{
	int a, b, c, d, e;
};

vector <point> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, k, a, b, c, d, e;
		point p;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> p.a >> p.b >> p.c >> p.d >> p.e;
				vs.pb(p);
			}

		if(n > 10) cout << 0 << endl;
		else
			{
				for(i = 0; i < n; i++)
					for(j = i + 1; j < n; j++)
						for(k = j + 1; k < n; k++)
							{
								
							}
			}
		return 0;
	}