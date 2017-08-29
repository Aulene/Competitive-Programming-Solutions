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

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back	
#define mp make_pair
#define f first
#define s second

stack < pair <int, char> > s;
vector < pair <int, int> > v;
int a[100007];
lli prefix[100007], dp[100007];

bool match(char a, char b)
{
	if(a == '}' && b == '{') return 1;
	if(a == '>' && b == '<') return 1;
	if(a == ']' && b == '[') return 1;
	if(a == ')' && b == '(') return 1;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, U, V, u, w;
		lli ans;
		char x, y;
		string s1;
		vector < pair <int, int> > :: iterator it;

		scanf("%d", &t);

		while(t--)
			{
				memset(dp, 0, sizeof(dp));
				ans = 0;
				while(!s.empty())
					s.pop();
				v.clear();
				ans = -100000000007;

				scanf("%d", &n);
				cin >> s1;

				for(i = 0; i < n; i++)
					scanf("%d", &a[i]), prefix[i] = prefix[i - 1] + a[i];

				for(i = 0; i < n; i++)
					{
						x = s1[i];

						if(x == '{' || x == '[' || x == '<' || x == '(')
							s.p(mp(i, x));
						else if(!s.empty())
							{
								U = s.top().f;
								y = s.top().s;

								if(match(x, y))
									{
										s.pop();
										dp[i] = max(dp[U - 1], (lli)0) + prefix[i] - prefix[U - 1];
									}
								else
									{
										while(!s.empty())
											s.pop();
									}
							}
					}

				for(i = 0; i < n; i++)
					{
						// cout << dp[i] << " ";
						ans = max(ans, dp[i]);
					}
				// cout << endl;

				printf("%lld\n", ans);
 			}	
		return 0;
	}