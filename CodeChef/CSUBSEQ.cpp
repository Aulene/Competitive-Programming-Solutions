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

int mx[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, k, i, j;
		string s;

		cin >> t;

		while(t--)
			{
				cin >> n >> k >> s;

				for(i = n - 1; i >= 0; i--)
					{
						if(s[i])
						mx[s[i]]++;
					}
			}
		return 0;
	}