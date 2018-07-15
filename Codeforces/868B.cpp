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

		double h, m, s, t1, t2, S, M, H, tx, i, j;
		bool ansx = 1;

		cin >> h >> m >> s >> t1 >> t2;

		t1 *= 30, t2 *= 30;

		if(t1 < t2)
			{
				tx = 360 + t1, S = s * 6;
				M = 6 * m + S / 60;
				H = h * 30 + M / 60;
				
				if(((t1 < S && S < t2) || (t1 < M && M < t2) || (t1 < H && H < t2)) && (((t2 < S && S < 360) || (t2 < M && M < 360) || (t2 < H && H < 360)) || ((0 <= S && S < t2) || (0 <= M && M < t2) || (0 <= H && H < t2))))
				ansx = 0;
			}
		else
			{
				j = t1;
				t1 = t2;
				t2 = j;

				if(t1 < t2)
					{
						tx = 360 + t1, S = s * 6;
						M = 6 * m + S / 60;
						H = h * 30 + M / 60;

						if(((t1 < S && S < t2) || (t1 < M && M < t2) || (t1 < H && H < t2)) && (((t2 < S && S < 360) || (t2 < M && M < 360) || (t2 < H && H < 360)) || ((0 <= S && S < t2) || (0 <= M && M < t2) || (0 <= H && H < t2))))
							ansx = 0;
					}	
			}

		if(ansx) cout << "YES\n";
		else cout << "NO\n";
	}