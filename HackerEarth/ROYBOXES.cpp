#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

int n;

int tree[4000007];

int update(int v, int L, int R)
{
	if(L<=)
}

int main()
	{
		int m, q, i, l, r;

		cin >> n >> m;

		while(m--)
			{
				cin >> l >> r;
				build(0, l, r);

				for(i=1; i<=4*n; i++)
					cout << tree[i] << " ";
				cout << endl;

			}

		return 0;
	}