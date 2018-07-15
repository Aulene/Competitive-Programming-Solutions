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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

priority_queue < pair <double, int>, vector < pair <double, int> >, greater < pair <double, int> > > pq;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s;
		int n, i, mid;
		double k, d, l = 0, r = 1;
		pair <double, int> pr;

		cin >> s;
		n = s.size();

		for(i = 0; i < n; i++)
			{
				k = (l + r) / 2;

				if(s[i] == 'l') r = k;
				else l = k;

				pq.p(mp(k, i + 1));	

				// cout << l << " " << r << endl;
			}

		while(!pq.empty())
			{
				pr = pq.top();
				pq.pop();
				// cout << pr.s << " " << pr.f << endl;
				cout << pr.s << endl;
			}

		return 0;
	}
