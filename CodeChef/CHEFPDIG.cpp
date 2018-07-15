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

int avail[10007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, x, y;
		char op;
		string s;

		cin >> t;

		while(t--)
			{
				cin >> s;
				n = s.size();

				for(i = 0; i < 10007; i++) avail[i] = 0;

				for(i = 0; i < n; i++)
					avail[s[i] - '0']++;

				for(i = 65; i <= 90; i++)
					{
						x = i % 10;
						y = i / 10;

						if(x == y)
							{
								if(avail[x] > 1)
									{
										op = i;
										cout << op;
									}
							}
						else if(avail[x] && avail[y])
							{
								op = i;
								cout << op;
							}
					}
				cout << endl;
			}

		return 0;
	}