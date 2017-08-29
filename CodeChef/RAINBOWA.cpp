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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[107], M[107];
int s[] = {1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, x, jindex;

		cin >> t;

		while(t--)
			{
				memset(M, 0, sizeof M);
				bool ans = 1;

				jindex = x = j = 0;

				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> a[i], j = max(a[i], j);
						if(a[i] == 7 && jindex == 0) jindex = i;
					}

				for(i = 0; i < jindex; i++) M[a[i]]++;
				for(i = jindex; i < n; i++) M[a[i]]--;

				if(j != 7) ans = 0;

				i = j = x = 0;

				while(i < n && s[x] != 0)
					{
						j = max(j, s[x]);

						while(a[i] == s[x])
							i++;

						x++;

						if(a[i] != s[x] && i < n)
							{
								ans = 0;
								// printf("I = %d, X = %d, Ai = %d, Sx = %d\n", i, x, a[i], s[x]);
							}
					}

				for(i = 1; i < 7; i++)
					{
						if(M[i] != 0) ans = 0;
						// cout << i << " " <<  M[i] << endl;
					}

				if(ans && s[x] == 0) cout << "yes" << endl;
				else cout << "no" << endl;
			}

		return 0;
	}