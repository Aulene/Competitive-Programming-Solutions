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

vector <int> ins;

// 0 = up, 1 = right, 2 = down, 3 = left

int advance(int dir, int &x, int &y)
{
	if(dir == 0) y++;
	else if(dir == 1) x++;
	else if(dir == 2) y--;
	else x--;
	return 0;
}

int go(int index, int dir, int &x, int &y)
{
	// cout << "OPEN" << endl;
	for(int i = index; i < ins.size(); i++)
		{
			// cout << i << " " << ins[i] << endl;
			if(ins[i] == 1) advance(dir, x, y);
			else if(ins[i] == 2) dir = (dir + 3) % 4;
			else dir = (dir + 1) % 4;
		}
	// cout << "CLOSE\n";
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int x, y, x1, y1, n, i, j, u, v, dir = 0, ndir; 
		int xf, yf;
		string s;

		int ans = 0, ansi = -1;

		cin >> xf >> yf >> n;

		for(i = 0; i < n; i++)
			{
				cin >> s;
				if(s == "Forward") ins.pb(1);
				else if(s == "Left") ins.pb(2);
				else ins.pb(3);
			}
		
		x1 = 0, y1 = 0;

		for(i = 0; i < n; i++)
			{
				// cout << x1 << " " << y1 << endl;

				if(ins[i] == 1)
					{
						x = x1, y = y1;
						// Change dir left
						ndir = (dir + 3) % 4;
						go(i + 1, ndir, x, y);

						// cout << i << " left " << x << " " << y << endl;

						if(x == xf && y == yf)
							{
								ansi = i + 1;
								ans = 2;
							}

						x = x1, y = y1;
						// Change dir right
						ndir = (dir + 1) % 4;
						go(i + 1, ndir, x, y);

						// cout << i << " right " << x << " " << y << endl;

						if(x == xf && y == yf)
							{
								ansi = i + 1;
								ans = 3;
							}
					}
				else if(ins[i] == 2)
					{
						x = x1, y = y1;
						// forward
						ndir = dir;
						advance(ndir, x, y);
						go(i + 1, ndir, x, y);

						// cout << i << " forward " << x << " " << y << endl;

						if(x == xf && y == yf)
							{
								ansi = i + 1;
								ans = 1;
							}

						x = x1, y = y1;
						// Change dir right
						ndir = (dir + 1) % 4;
						go(i + 1, ndir, x, y);

						// cout << i << " right " << x << " " << y << endl;

						if(x == xf && y == yf)
							{
								ansi = i + 1;
								ans = 3;
							}
					}
				else
					{
						//forward
						x = x1, y = y1;
						ndir = dir;
						advance(ndir, x, y);
						go(i + 1, ndir, x, y);

						// cout << i << " forward " << x << " " << y << endl;

						if(x == xf && y == yf)
							{
								ansi = i + 1;
								ans = 1;
							}

						x = x1, y = y1;
						// Change dir left
						ndir = (dir + 3) % 4;
						go(i + 1, ndir, x, y);

						if(x == xf && y == yf)
							{
								ansi = i + 1;
								ans = 2;
							}
						// cout << i << " left " << x << " " << y << endl;
					}

				if(ansi != -1)
					{
						break;
					}
				else
					{
						if(ins[i] == 1) advance(dir, x1, y1);
						else if(ins[i] == 2) dir = (dir + 3) % 4;
						else dir = (dir + 1) % 4;
					}
			}


		cout << ansi << " ";
		if(ans == 1) cout << "Forward";
		else if(ans == 2) cout << "Left";
		else cout << "Right";
		return 0;
	}