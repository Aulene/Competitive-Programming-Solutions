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

bool present[1000007];

int main()
	{
		lli t, n, k;
		lli i, j, m, x;
		vector <int>::iterator it;
		lli num;
		bool sad, all;

		cin >> t;

		while(t--)
			{
				sad=0;
				all=0;

				for(i=0; i<1000007; i++)
					present[i]=0;

				scanf("%lld %lld", &n, &k);

				for(i=1; i<=n; i++)
					{
						scanf("%lld", &m);

						for(j=0; j<m; j++)
							{
								scanf("%lld", &x);
								present[x]=1;
							}

						if(i==n-1)
							{
								for(j=1; j<=k; j++)
									if(!present[j])
										all=1;
							}
					}

				for(i=1; i<=k; i++)
					if(!present[i])
						sad=1;

				if(sad)
					cout << "sad" << endl;
				else if(all)
					cout << "all" << endl;
				else
					cout << "some" << endl;
			}

		return 0;
	}