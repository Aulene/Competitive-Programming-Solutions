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

// #define int long long int
// #define double long double
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

map < pair <int, int>, double> mx;

double recur(int w, int b)
{
	if(w <= 0) return 0;
	if(b <= 0) return 1;

	pair <int, int> sex = mp(w, b);
	if(mx.find(sex) != mx.end()) return mx[sex];

	double ans = (double) w / (w + b), ans2, ans3, ans4;

	ans2 = ((double) b / (w + b)); b--;
	ans2 *= ((double) b / (w + b)); b--;

	if(ans2 > 1e-13)
		{
			ans3 = (double) recur(w, b - 1) * ((double) b / (w + b));
			ans4 = (double) recur(w - 1, b) * ((double) w / (w + b));
			ans += (double) ans2 * ((double) (ans3 + ans4));
		}

	return mx[sex] = ans;
}

int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int w, b;
		double ans;

		cin >> w >> b;
		ans = recur(w, b);

		printf("%.11f\n", ans);
		return 0;
	}