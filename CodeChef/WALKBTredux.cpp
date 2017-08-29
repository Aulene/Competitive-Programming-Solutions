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

set <string> M;

signed main()
{
	int t, n, m, i, c, ans, add, j, num;
	string s, s1;
	set <string> :: iterator it;
	char q;

	cin >> t;

	while(t--)
		{
			M.clear();
			ans = 0;

			cin >> n >> m;

			string s('0', n);

			while(m--)
				{
					cin >> q;

					if(q == '!')
						{
							cin >> c;

							j = n - c - 1, add = 0;

							if(s[j] == '0') s[j] = '1';
							else
								{
									s[j] = '0';

									for(i = j - 1; i >= 0; i--)
										{
											if(s[i] == '0')
												{
													s[i] = '1';
													break;
												}
											else s[i] = '0';
										}
								}

							for(it = M.begin(); it != M.end(); it++)
								{
									s1 = *it, num = 0;

									for(j = 0; j < n; j++)
										{
											if(s[j] != s1[j]) break;
											num++;
										}

									add = max(add, num);
								}

							M.insert(s);
							ans += n - add;
						}
					else
						cout << ans + 1 << endl;
				}
		}
}
