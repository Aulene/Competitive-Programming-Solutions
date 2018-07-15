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
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j;
		double r, pi = (double) 3.14159 , ans;

		while(cin >> n)
			{
				if(!n) break;

				r = (double) n / pi ;
				ans = (double) pi * r * r / 2;
				printf("%.2Lf\n", ans);
			}

		return 0;
	}