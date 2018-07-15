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

vector < pair <int, int> > ans;
int dp[37][37];
bool vis[37];

int d(int a)
{
	for(int i = 0; i < 26; i++)
		{
			if(dp[a][i] == 1)
				{
					if(!vis[i])
						{
							ans.pb(mp(a, i)); 
							dp[a][i]++;
							dp[i][a]++;
							vis[i]=1;
							d(i);
				 		}
				}
		}

	return 0;
}

signed main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, y, x, i;
	string s1, s2;
	cin >> n >> s1 >> s2;

	for(i = 0; i < n; i++)
		{
			y = s1[i] - 'a';
			x = s2[i] - 'a';

			dp[x][y] = 1;
			dp[y][x] = 1;
		}

	for(i = 0; i < 26; i++)
		if(!vis[i])
			{
				vis[i] = 1;
				d(i);
			}

	cout << ans.size() << endl;

	for(i = 0; i < ans.size(); i++)
		cout << (char)(ans[i].f + 'a') << " " << (char)(ans[i].s + 'a') << endl;
 
 	return 0;
}	