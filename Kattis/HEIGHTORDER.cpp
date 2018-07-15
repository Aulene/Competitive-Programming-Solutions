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

vector <int> vs, as;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, t;
		int k, K;

		cin >> t;

		while(t--)
			{
				vs.clear();
				vs.resize(20);

				int ans = 0;

				cin >> K;

				for(i = 0; i < 20; i++)
					{
						cin >> u;

						for(j = 0; j < i; j++)
							{
								if(vs[j] > u)
									{
										for(k = i; k > j; k--) vs[k] = vs[k - 1], ans++;
										// ans += vs.size() - j;
										break;
									}
							}

						vs[j] = u;

						// for(j = 0; j < vs.size(); j++) cout << vs[j] << " "; cout << endl;
					}

				// for(i = 0; i < vs.size(); i++) cout << vs[i] << " "; cout << endl;
				cout << K << " " << ans << endl;
			}

		return 0;
	}