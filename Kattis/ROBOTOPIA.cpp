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

int vis[10007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, i, numans, x, y;

		pair <int, int> fst, snd, third, ans;

		cin >> t;

		while(t--)
			{
				cin >> fst.f >> fst.s >> snd.f >> snd.s >> third.f >> third.s;

				numans = 0;

				for(i = 0; i <= 10000; i++) vis[i] = 0;

				for(i = 0; i <= 10000; i++)
					if(vis[i] == 0)
						{
							// fst.f * x + snd.f * y = third.f
							// => y = (third.f - fst.f * x) / snd.f

							x = (third.f - fst.f * i) / snd.f;
							y = (third.s - fst.s * i) / snd.s;

							if((third.f - fst.f * i) % snd.f != 0) continue;
							if((third.s - fst.s * i) % snd.s != 0) continue;

							// cout << i << " " << x << " " << y << endl;

							if(x == y && x >= 0 && y >= 0)
								{
									numans++;
									ans.f = i;
									ans.s = x;
									vis[i] = vis[x] = 1;
								}
						}

				if(numans != 1) cout << "?" << endl;
				else cout << ans.f << " " << ans.s << endl;
 			}

		return 0;
	}