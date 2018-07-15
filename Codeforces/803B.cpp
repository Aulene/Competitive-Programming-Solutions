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

int a[200007], la[200007], ra[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j;

		cin >> n;
		for(i = 0; i < n; i++) cin >> a[i], la[i] = ra[i] = 200007;

		j = -1;

		for(i = 0; i < n; i++)
			{
				if(a[i] == 0) j = i;

				if(j != -1)
				la[i] = i - j;
				// cout << i << " " << j << endl;
			}

		j = -1;

		for(i = n - 1; i >= 0; i--)
			{
				if(a[i] == 0) j = i;

				if(j != -1)
				ra[i] = j - i;
			}
		
		for(i = 0; i < n; i++) cout << min(la[i], ra[i]) << " ";

		return 0;
	}