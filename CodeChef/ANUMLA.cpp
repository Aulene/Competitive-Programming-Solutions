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

priority_queue < int, vector <int>, greater <int> > pq;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v;

		cin >> t;

		while(t--)
			{
				cin >> n;

				int nums = pow(2, n);

				for(i = 0; i < nums; i++)
					{
						cin >> u;
						pq.p(u);
					}	

				while(pq.top() == 0) pq.pop();

				for(i = 0; i < n; i++)
					{
						cout << pq.top() << " ";
						pq.pop();
					}

				while(!pq.empty()) pq.pop();
				cout << endl;				
			}
		return 0;
	}