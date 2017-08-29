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

int t[100007];
int f[17][17];

int main()
	{
		int b, i;

		cin >> b;

		while(b--)
			{
				for(i = 0; i < 3; i++)
					t[i] = i;
				for(i = 3; i <= 15; i++)
					t[i] = 0;

				cin >> t[3] >> t[4] >> t[5] >> t[6];

				f[0][0] = 0, f[0][1] = 0, f[0][2] = 0;
				f[1][0] = 0, f[1][1] = 1, f[1][2] = 2;
				f[2][0] = 0, f[2][1] = 2, f[2][2] = 2;

				// 8
				t[11] = f[t[1]][t[3]];
				t[11] = f[t[11]][t[5]];
				t[8] = f[t[1]][t[11]];

				// 10
				t[10] = f[t[4]][t[6]];


				// 9
				// t[11] = f[t[3]][t[6]];
				// t[12] = f[t[4]][t[5]];
				// t[13] = f[t[11]][t[13]];
				// t[14] = f[t[12]][t[14]];
				
				// t[9] = f[t[13]][t[9]];
				// t[9] = f[t[14]][t[9]];

				for(i = 0; i <= 15; i++)
					cout << i << " " ;
				cout << endl;

				for(i = 0; i <= 15; i++)
					cout << t[i] << " " ;
				cout << endl;

				for(i = 7; i < 11; i++)
					cout << t[i];
				cout << endl;

			}
		return 0;
	}