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
vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, sum, u;
		string s;

		cin >> t;

		while(t--)
			{
				vs.clear();

				cin >> s;
				n = s.size();

				sum = 0;

				for(i = 0; i < n; i++) a[i] = s[i] - '0', sum += a[i];

				if(a[n - 1] % 2)
					{
						if(a[n - 2] % 2)
							cout << -1 << endl;
						else
							{
								u = sum - a[n - 1];
								
								if(u % 3) cout << -1 << endl;
								else 
									{
										for(i = 0; i < n - 1; i++) cout << a[i];
										cout << endl;
									}
							}
					}
				else
					{
						for(i = 0; i < n; i++)
							{
								u = sum - a[i];

								if(u % 3 == 0)
									{
										if(i == n - 1)
											{
												if(a[n - 2] % 2 == 0)
													vs.pb(i);
											}
										else vs.pb(i);
									}
							}

						if(vs.size() == 0) cout << -1 << endl;
						else
							{
								for(i = 0; i < vs.size(); i++)
									{
										u = vs[i];
										if(a[u] < a[u + 1])
											break;
									}

								for(i = 0; i < n; i++)
									if(i != u) cout << a[i];
								cout << endl;
							}
						
					}
			}
		return 0;
	}