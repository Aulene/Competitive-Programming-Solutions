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

		int a, b, ans, f = 1;

		cin >> a >> b;

		if(a % 2 == 0)
			{
				ans = a / 2;
				for(int i = 1; i <= b; i++)
					f = (f * ans) % a;
				cout << f << endl;
			}
		else cout << 0 << endl;
		return 0;
	}