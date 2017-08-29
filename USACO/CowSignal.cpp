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
#include<fstream>

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

char a[17][17];

int main()
	{
		ifstream fin ("cowsignal.in");
		ofstream fout ("cowsignal.out");

		int r, c, k, i, j, x, y;

		fin >> r >> c >> k;

		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
				fin >> a[i][j];

		for(i=0; i<r; i++)
			{
				for(y=0; y<k; y++)
					{
						for(j=0; j<c; j++)
							{
								for(x=0; x<k; x++)
									fout << a[i][j];
							}
						fout << endl;
					}
			}
		return 0;
	}