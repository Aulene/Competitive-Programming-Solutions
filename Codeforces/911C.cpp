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

int a[7], num[7];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i;

		for(i = 0; i < 3; i++)
			{
				cin >> a[i], num[a[i]]++;
			}

		if(num[1] || (num[2] > 1) || (num[3] == 3) || (num[4] == 2 && num[2] == 1)) cout << "YES\n";
		else cout << "NO\n";

		return 0;
	}