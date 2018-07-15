#include <iostream>
#include <fstream>
#include <iomanip>
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

string s1, s2;
int n, x;
int tp = 0, fx = 0;

void recur(int idx, int pos)
{
	if(idx >= n)
		{
			if(pos == x) fx++;
			tp++;
			return;
		}

	if(s2[idx] == '+') recur(idx + 1, pos + 1);
	else if(s2[idx] == '-') recur(idx + 1, pos - 1);
	else
		{
			recur(idx + 1, pos + 1);
			recur(idx + 1, pos - 1);
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		
		int i, j;
		double ans;
		cin >> s1 >> s2;

		n = s1.size();

		for(i = 0; i < n; i++)
			{
				if(s1[i] == '+') x++;
				else x--;
			}

		recur(0, 0);

		ans = (double) fx / tp ;
		printf("%.11f\n", ans);

		return 0;
	}