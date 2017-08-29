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

int fdp[207][207][17], hdp[207][207][17]; // fdp[][][] - num t1, num t2, consect1, hdp[][][] = numt1, numt2, consechorse
 
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n1, n2, k1, k2, i, j, k, l;
		int N, K;

		cin >> n1 >> n2 >> k1 >> k2;

		N = n1 + n2;

		fdp[1][0][1] = 1;
		ddp[0][1][1] = 1;

		for(i = 1; i <= n1; i++)
			{
				for(j = 1; j <= n2; j++)
					{

					}
			}

		return 0;
	}