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
#define p push
#define pb push_back
#define mp make_pair

lli a[507];

int main()
	{
		lli t, n, i;

		a[1] = 1;
		a[2] = 2;
		a[3] = 4;

		for(i=4; i<=500; i++)
			a[i] = 3*i - 5;

		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i=1; i<=n; i++)
					cout << a[i] << " ";
				cout << endl;
			}

		return 0;
	}