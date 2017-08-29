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

int main()
	{
		int i, j;
		int n=1;

		ifstream fin1 ("opcor.txt");
		ifstream fin2 ("opn.txt");

		while(fin1 >> i)
			{
				fin2 >> j;

				if(i!=j)
					cout << n << endl;
				n++;
			}
		return 0;
	}