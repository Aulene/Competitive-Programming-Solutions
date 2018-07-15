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

int a[17], b[17];
queue <int> q1, q2;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, n1, n2, i, j, op = 0;
		int u, v;

		cin >> n;

		cin >> n1;
		for(i = 0; i < n1; i++) cin >> a[i], q1.p(a[i]);
		cin >> n2;
		for(i = 0; i < n2; i++) cin >> b[i], q2.p(b[i]);

		while(1)
			{
				if(q1.empty() || q2.empty() || op >= 1000000) break;

				u = q1.front();
				v = q2.front();

				q1.pop(), q2.pop();

				if(u > v) q1.p(v), q1.p(u);
				else q2.p(u), q2.p(v);

				op++;
			}
		
		if(op >= 1000000) cout << -1 << endl;
		else if(!q1.empty()) cout << op << " " << 1 << endl;
		else cout << op << " " << 2 << endl;
		return 0;
	}