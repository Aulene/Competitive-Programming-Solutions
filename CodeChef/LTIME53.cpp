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

int a[100007];
vector <string> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, t, sum, v;
		string s;

		cin >> t;

		while(t--)
			{
				vs.clear();

				bool ansx = 0;

				sum = 0;

				cin >> s;
				n = s.size();

				for(i = 0; i < n; i++)
					a[i] = s[i] - '0', sum += a[i];

				for(i = 0; i < n; i++)
					{
						int u = sum - a[i];

						if(u % 3 == 0)
							{
								string sx = "";

								for(j = 0; j < n; j++)
									if(i != j) sx += s[j];
								vs.pb(sx);
							}
					}

				sort(vs.begin(), vs.end());

				for(i = vs.size() - 1; i >= 0; i--) 
					{
						char x = vs[i][n - 2];
						int u = x - '0';

						if(u % 2 == 0)
							{
								cout << vs[i] << endl;
								break;
							}
					}

				if(i == -1) cout << -1 << endl;

			}
		return 0;
	}