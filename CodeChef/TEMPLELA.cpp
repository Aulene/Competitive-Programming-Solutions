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

int a[107];
// n/2 + 1

int main()
	{
		int t, n, i, j;

		cin >> t;

		while(t--)
			{
				bool ans = 1;

				cin >> n;

				for(i = 1; i <= n; i++)
					cin >> a[i];

				if(a[1] != 1 || a[n] != 1)
					ans = 0;

				for(i = 1; i <= n/2+1; i++)
					if(a[i] != i)
						ans=0;

				j=1;
				for(i = n; i >= n/2+1; i--)
					if(a[i] != j)
						ans=0;
					else
						j++;

				if(ans)
					cout << "yes" << endl;
				else
					cout << "no" << endl;
			}

		return 0;
	}