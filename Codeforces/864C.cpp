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

		int a, b, f, k, ans = 0, l = 0, i;
		bool ansx = 0;

		cin >> a >> b >> f >> k;

		if(b < a)
			{
				cout << -1 << endl;
				return 0;
			}

		l = b - f;

		for(i = 1; i < k; i++)
			{
				if(i % 2 == 0)
					{
						ans++;
						l = b;

						if(2 * f > l)
							{
								// cout << l << " " << f << endl;
								ansx = 1;
								break;
							}

						l -= 2 * f;
					}
				else
					{
						if((a - f) * 2 > l)
							{
								ans++;
								l = b;

								if((a - f) * 2 > l)
									{
										// cout << l << " " << f << endl;
										ansx = 1;
										break;
									}
							}

						l -= (a - f) * 2;
					}
			}

		if(ansx)
			{
				cout << -1 << endl;
				return 0;
			}

		if(k % 2 == 0)
			{
				if(f > l) ans++;
			}
		else
			{
				if((a - f) > l) ans++;
			}

		cout << ans << endl;
		return 0;
	}