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

#define double long double
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

double dist(int ax, int ay, int bx, int by)
{
	double ans;
	ans = pow(abs(ax - bx), 2) + pow(abs(ay - by), 2);
	return ans;
}

double p2(double a, double b)
{
	double ans = pow(a, 2) + pow(b, 2);
	return ans;
}

bool check(double x, double y, double z)
{
	if(x == y && sqrt((double)p2(x, y)) == z) return 1;
	return 0;
}

bool check2(double x, double y, double z)
{
	if(x == y && y == z && x == z) return 1;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int ax, ay, bx, by, cx, cy;
		double x, y, z;
		bool ans = 1;

		cin >> ax >> ay >> bx >> by >> cx >> cy;
		x = dist(ax, ay, bx, by);
		y = dist(bx, by, cx, cy);
		z = dist(ax, ay, cx, cy);

		// cout << x << " " << y << " " << z << endl;

		if(ax == bx && bx == cx) ans = 0;
		if(ay == by && by == cy) ans = 0;

		if(x == y && ans) cout << "Yes\n";
		else cout << "No\n";

		return 0;
	}