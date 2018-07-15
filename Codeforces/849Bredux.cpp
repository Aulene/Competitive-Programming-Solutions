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

int n, xcord[1007], ycord[1007];
vector <int> V;

signed main()
{
	int u, v, none = 0, i, gcd;
	pair <int, int> p;

	cin >> n;
	
	for(i = 0; i < n; i++)
		{
			xcord[i] = i;
			cin >> ycord[i];
		}

	map < pair<int, int>, vector<int> > M;

	for(i = 1; i < n; i++)
		{
			u = xcord[i];
			v = ycord[i] - ycord[0];

			if(v == 0) u = 1;
			else
				{
					int gcd = __gcd(u, v);
					gcd = abs(gcd);

					u /= gcd;
					v /= gcd;
				}

			M[mp(u, v)].pb(i);
		}

	for (auto it = M.begin(); it != M.end(); it++)
		{
			if(it->second.size() > 1) p = it -> first, none++;
			else V.pb((it -> second)[0]);
		}

	if(none > 1 || V.size() == 0)
		cout << "No" << endl;
	else if(V.size() == 1)
		cout << "Yes" << endl;
	else 
		{
			M.clear();

			for(i = 1; i < V.size(); i++)
				{
					u = xcord[V[i]] - xcord[V[0]];
					v = ycord[V[i]] - ycord[V[0]];

					if(v == 0)
						u = 1;
					else 
						{
							gcd = __gcd(u, v);
							gcd = abs(gcd);
							u /= gcd;
							v /= gcd;
						}

					M[mp(u, v)].pb(V[i]);
				}

			if(M.size() > 1) cout << "No" << endl;
			else if(V.size() == n - 1) cout << "Yes" << endl;
			else 
				{

					if(p == M.begin() -> first) cout << "Yes" << endl;
					else cout << "No" << endl;
				}
		}

	return 0;
}