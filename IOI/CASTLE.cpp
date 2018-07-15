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

bool walls[57][57][7]; // k = 1 north, 2 east, 3 south, 4 west
bool vis[57][57];
vector < pair < pair <int, int>, string> > vs;
vector <int> vs2;
int num = 0, largeRoom = 0;
int n, m;

void fixWall(int x, int y, int num)
{
	if(num >= 8) // south
		{
			walls[x][y][3] = 1;
			num -= 8;
			vs.pb(mp(mp(x, y), "S"));
			vs2.pb(3);
		}

	if(num >= 4) // east
		{
			walls[x][y][2] = 1;
			num -= 4;
			vs.pb(mp(mp(x, y), "E"));
			vs2.pb(2);
		}

	if(num >= 2) // north
		{
			walls[x][y][1] = 1;
			num -= 2;
			vs.pb(mp(mp(x, y), "N"));
			vs2.pb(1);
		}

	if(num >= 1) // west
		{
			walls[x][y][4] = 1;
			num -= 1;
			vs.pb(mp(mp(x, y), "W"));
			vs2.pb(4);
		}
}

int dfs1(int x, int y)
{
	if(x <= 0 || x > n || y <= 0 || y > m) return 0;
	if(vis[x][y]) return 0;

	int sz = 1;

	vis[x][y] = 1;

	if(!walls[x][y][1]) sz += dfs1(x - 1, y);
	if(!walls[x][y][2]) sz += dfs1(x, y + 1);
	if(!walls[x][y][3]) sz += dfs1(x + 1, y);
	if(!walls[x][y][4]) sz += dfs1(x, y - 1);
	return sz;
}

void numRooms(int n, int m)
{
	largeRoom = 0;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			vis[i][j] = 0;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(!vis[i][j])
				{
					num++;
					largeRoom = max(largeRoom, dfs1(i, j));
				}
}



signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, x;
		int ans1, ans2;
		pair < pair <int, int>, pair <int, string> > ans = mp(mp(-1, -1), mp(-1, "X"));

		cin >> n >> m;

		swap(n, m);

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				{
					cin >> x;
					fixWall(i, j, x);
				}

		numRooms(n, m);
		ans1 = num; ans2 = largeRoom;

		
		for(i = 0; i < vs.size(); i++)
			{	
				walls[vs[i].f.f][vs[i].f.s][vs2[i]] = 0;
				numRooms(n, m);

				if(largeRoom > ans.s.f)
					{
						ans.f = vs[i].f;
						ans.s = mp(largeRoom, vs[i].s);
					}
				else if(largeRoom == ans.s.f)
					{
						if(vs[i].f.s == ans.f.s)
							{
								if(vs[i].f.f == ans.f.f)
									{
										if(vs[i].s == "E" && ans.s.s == "E")
											{
												ans.f = vs[i].f;
												ans.s = mp(largeRoom, vs[i].s);
											}
										else
											{
												ans.f = vs[i].f;
												ans.s = mp(largeRoom, vs[i].s);
											}
									}
								else
									{
										ans.f = vs[i].f;
										ans.s = mp(largeRoom, vs[i].s);
									}
							}
						else
							{
								ans.f = vs[i].f;
								ans.s = mp(largeRoom, vs[i].s);
							}

					}

				walls[vs[i].f.f][vs[i].f.s][vs2[i]] = 1;
			}

		cout << ans1 << endl << ans2 << endl;
		cout << ans.s.f << endl;
		cout << ans.f.f << " " << ans.f.s << " " << ans.s.s << endl;

		return 0;
	}