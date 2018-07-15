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

int n, k;
vector < vector <int> > s;
vector < vector <int> > ans;
bool ansx;

int compute(vector < vector <int> > s)
{
	int sum = 0;

	for(int i = 0; i < n; i++)
		{
			int u = 0;
			for(int j = 0; j < n; j++)
				u += s[i][j];
			sum += pow(u, 2);
		}

	return sum;
}

int recur(vector < vector <int> > s, int x, int y)
{
	vector < vector <int> > xy;

	if(ansx) return 0;

	if(x > n)
		{
			int f = compute(s);

			if(f == k)
				{
					ansx = 1;
					ans = s;
				}

			return 0;
		}

	if(y > n) return recur(s, x + 1, 1);

	recur(s, x, y + 1);
	xy = s;
	xy[x][y] = 1;
	recur(xy, x, y + 1);

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, i, j, u, v;

		cin >> t;

		while(t--)
			{
				if(n == 1)
					{
						if(k != 0) cout << -1 << endl;
						else cout << 0 << endl;
					}
				else if(n == 2)
					{
						if(k == 1)
							{
								cout << "01\n00";
							}
						else cout << -1 << endl;
					}
				else if(n == 3)
					{
						if(k == 3)
							{
								cout << "010\n001\n100\n";
							}
						else if(k == 5) cout << "011\n001\n000\n"
					}
			}
		return 0;
	}