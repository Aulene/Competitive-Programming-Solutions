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

lli u[107], v[107];

int main()
	{
		lli t, n, m, i;

		cin >> t;

		while(t--)
			{
				cin >> n >> m;

				for(i=0; i<m; i++)
					cin >> u[i] >> v[i];

				if(n%2 == 0)
					cout << "yes" << endl;
				else
					cout << "no" << endl;
			}


		return 0;
	}