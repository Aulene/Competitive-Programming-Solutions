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
#include <cstdlib>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[17], ans[17], b[17][17], sz[17], l[17];
bool taken[17];
bool ansf;

int recur(int index, int ax[])
{
	if(ansf) return 0;

	if(index > 6)
		{
			for(int i = 1; i <= 6; i++)
				if(b[i][ax[i]])
					return 0;
			
			ansf = 1;

			for(int i = 1; i <= 6; i++) ans[i] = ax[i];
			return 0;
		}

	if(ax[index]) return recur(index + 1, ax);

	int bx[17];

	for(int i = index + 1; i <= 6; i++)
		if(ax[i] == 0 && b[index][i] == 0)
			{
				for(int j = 1; j <= 6; j++) bx[j] = ax[j];

				bx[index] = i;
				bx[i] = index;
				recur(index + 1, bx);			
			}

	return 0;
}


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, k;
		
		srand(time(NULL));

		cout << "500" << endl;
		for(i = 1; i <= 500; i++)
			cout << arc4random() % 6 + 1 << " ";
	}