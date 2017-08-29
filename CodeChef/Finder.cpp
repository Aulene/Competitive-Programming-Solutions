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
#define pb push_back

lli a[100007];

int main()
	{
		ifstream fin ("inp.txt");

		int num=1, i, t, n;

		fin >> t;

		while(t--)
			{
				fin >> n;
				for(i=0; i<n; i++)
					fin >> a[i];

				if(num==37 || num==53)
					{
						cout << n << endl;
						for(i=0; i<n; i++)
							cout << a[i] << " ";
						cout << endl;
					}

				num++;
			}

		return 0;
	}