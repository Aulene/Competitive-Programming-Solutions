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

unordered_map <int, int> M;
vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, x, u = 0, v = 0;
	 	vector <int> :: iterator it;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> x;
				if(!M[x]) vs.pb(x);
				M[x]++;
			}

		sort(vs.begin(), vs.end(), greater <int> ());

		for(it = vs.begin(); it != vs.end(); it++)
			{
				x = *it;

				if(M[x] >= 2)
					{
						if(!u) u = x, M[x]-=2;;
					}

				

				if(M[x] >= 2)
					{
						if(!v) v = x;
					}
			}

		cout << u * v;
		return 0;
	}
