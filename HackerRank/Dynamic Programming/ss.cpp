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

char a[10][10];

int main()
	{	
		int i, j, x1, y1, x2, y2;

		for(i=0; i<10; i++)
			for(j=0; j<10; j++)
				a[i][j]='.';

		int n;
		cin >> n;

		while(n--)
			{
				cin >> x1 >> y1 >> x2 >> y2;

				for(i=x1; i<=x2; i++)
					for(j=y1; j<=y2; j++)
						a[i][j]='X';
			}

		for(i=0; i<10; i++)
			{
				for(j=0; j<10; j++)
					cout << a[i][j];
				cout << endl;
			}
		return 0;
	}