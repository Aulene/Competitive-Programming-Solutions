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

int a[100007], b[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, d = 0;

		cin >> n;

		for(i = 0; i < n; i++)
			cin >> a[i], b[i] = a[i];

		sort(b, b + n);
		
		for(i = 0; i < n; i++)
			if(a[i] != b[i])
				d++;

		if(d <= 2) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}