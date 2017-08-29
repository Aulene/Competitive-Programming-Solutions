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

int a[307], b[307];
int suffixA[307], suffixB[307];

int build(int f[], int suf[], int n)
{
	int i, x=0;
	for(i=0; i<n; i++)
			{
				cin >> f[i];

				if(i>0)
					{
						suf[x]=f[i]-f[i-1];
						x++;
					}
			}
	return 0;
}

int main()
	{
		int n, i, x=0;

		cin >> n;

		build(a, suffixA, n);
		build(b, suffixB, n);

		for(i=0; i<n; i++)
			cout << suffixA[i] << " ";
		cout << endl;

		for(i=0; i<n; i++)
			cout << suffixB[i] << " ";
		cout << endl;

		return 0;
	}