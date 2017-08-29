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

int a[57][57];

int main()
	{
		int n, i, j, x, y, s, k, l, r;
		bool ans = 1;

		cin >> n;

		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				cin >> a[i][j];

		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				if(a[i][j] != 1)
				{
					bool ansEx = 0;

					for(k=0; k<n; k++)
						for(l=0; l<n; l++)
							{
								if(a[i][k] + a[l][j] == a[i][j])
									ansEx = 1;
							}

					if(!ansEx)
						ans = 0;
				}

		if(ans)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		return 0;
	}