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

int a[200007], pos[200007];

int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);

		int n, q, k, i, x, j;

		pos[0]=1;

		cin >> n >> k >> q;

		for(i=0; i<k; i++)
			cin >> a[i];

		sort(a, a+k);

		for(i=0; i<k; i++)
			{
				if(pos[a[i]])
					continue;
				
				for(j=0; j+a[i]<200007; j++)
					{
						if(pos[j])
							pos[a[i]+j]=1;
					}
			}

		while(q--)
			{
				cin >> x;

				if(pos[x])
					cout << "Yes\n";
				else
					cout << "No\n";
			}

		return 0;
	}