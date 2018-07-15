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

int w[507][507], node[507], floyd[507][507];

stack <int> s;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, k, sum;

		cin >> n;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				cin >> floyd[i][j];

		for(i = 1; i <= n; i++) cin >> node[i];

		for(i = n; i >= 1; i--)
			{
				for(j = 1; j <= n; j++)
					for(k = 1; k <= n; k++)
						floyd[node[j]][node[k]] = min(floyd[node[j]][node[k]], floyd[node[j]][node[i]] + floyd[node[i]][node[k]]);
		
				sum = 0;

				for(j = i; j <= n; j++)
					for(k = i; k <= n; k++) 
						sum += floyd[node[j]][node[k]];
										
				s.p(sum);
			}

		while(!s.empty())
			{
				cout << s.top() << " ";
				s.pop();
			}

		return 0;
	}