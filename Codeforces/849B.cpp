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
#define double long double
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair <int, int> > pts;
vector <double> slopes;
unordered_map <double, int> M;

double slp(pair <int, int> a, pair <int, int> b)
{
	double ans = (double) (b.s - a.s) / (b.f - a.f);
	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, remm = 0;
		bool ans = 1;
		double m1, m2, m, rem;
		pair <int, int> orig;

		cin >> n;

		cin >> j;
		orig = mp(1, j);

		for(i = 2; i <= n; i++)
			{
				cin >> j;
				pts.pb(mp(i, j));
			}

		for(i = 0; i < pts.size(); i++)
			{
				m = slp(orig, pts[i]);
				slopes.pb(m);
				M[m]++;
			}

		for(i = 0; i < slopes.size(); i++)
			if(M[slopes[i]] > remm)
				{
					remm = M[slopes[i]];
					rem = slopes[i];
				}

		m1 = rem;

		for(i = 0; i < slopes.size(); i++)
			if(slopes[i] == rem)
				pts.erase(pts.begin() + i), slopes.erase(slopes.begin() + i);
		
		if(pts.size() == 0) ans = 0;

		orig = pts[0];
		pts.erase(pts.begin());
		slopes.clear();
		M.clear();

		for(i = 0; i < pts.size(); i++)
			{
				m = slp(orig, pts[i]);
				slopes.pb(m);
				M[m]++;
			}

		remm = 0;

		for(i = 0; i < slopes.size(); i++)
			if(M[slopes[i]] > remm)
				{
					remm = M[slopes[i]];
					rem = slopes[i];
				}

		m2 = rem;

		for(i = 0; i < slopes.size(); i++)
			if(slopes[i] == rem)
				pts.erase(pts.begin() + i), slopes.erase(slopes.begin() + i);

		cout << m1 << " " << m2 << endl;

		if(m1 == m2 && pts.size() == 0 && ans) cout << "Yes\n";
		else cout << "No\n";

		return 0;
	}