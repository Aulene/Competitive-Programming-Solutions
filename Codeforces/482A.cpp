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

bool diff[100007];
vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j;

		cin >> n >> k;

		vs.pb(1);

		for(i = 1; i < n; i++)
			{
				if(k == 0) vs.pb(vs[i - 1] + 1);
				else
					{
						vs.pb(vs[i - 1] + i);
						k--;
					}
			}

		for(i = 0; i < vs.size(); i++) cout << vs[i] << " ";
		return 0;
	}