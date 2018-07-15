// DOKI DOKI AARU <3 - Aulene

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

int v1[1007], v2[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n;
		string s;

		// cin >> t;

		// while(t--)
			{
				cin >> s;

				int ans = s.size() / 2 + 1;
				n = s.size();

				// for(int i = 'a'; i <= 'z'; i++) v1[i] = -1, v2[i] = 1000007;

				for(char i = 'a'; i <= 'z'; i++)
					{
						int left = -1, maxdiff = -1, maxdiff2;

						for(int j = 0; j <= n; j++)
							{
								// cout << s[j] << " " << i << endl;
								if(j == n)
									{
										maxdiff2 = max(maxdiff2, n - left);
									}
								if(s[j] == i)
									{
										// cout << i << " " << left << endl;?

										if(left == -1)
											{
												left = j;
												maxdiff2 = left + 1;
											}
										else
											{
												maxdiff = max((j - left), maxdiff);
												left = j;
											}
										
									}
							}

						if(maxdiff != -1)
							{
								maxdiff = max(maxdiff, maxdiff2);
								ans = min(ans, maxdiff);
							}
					}

				cout << ans << endl;

			}

		return 0;
	}