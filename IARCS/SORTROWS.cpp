
#include<iostream>
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

struct rows
{
	int size;
	int a[57];
};

rows p[1007];

bool compare(rows x, rows y)
{
	int i;

	for(i=0; i<min(x.size, y.size); i++)
		if(x.a[i] != y.a[i])
			return x.a[i] < y.a[i];

	return x.size < y.size;
}

int main()
	{
		int n, i, j, num;
		int u;

		cin >> n;

		for(i=0; i<n; i++)
			{
				num=0;

				while(cin >> u)
					{
						if(u==-1)
							break;

						p[i].a[num]=u;
						num++;
					}

				p[i].size=num;
			}

		sort(p, p+n, compare);

		for(i=0; i<n; i++)
			{
				for(j=0; j<p[i].size; j++)
					cout << p[i].a[j] << " ";
				cout << endl;
			}
		return 0;
	}