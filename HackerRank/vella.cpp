#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

double ct[100007];
int n, i, sum = 0, maxct = 0, mode;;
int a[100007];
double standard = 0, x;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> n; 

		for(i = 0; i < n; i++)
			{
				cin >> a[i];
				sum += a[i];
				ct[a[i]]++;

				if(ct[a[i]] > maxct)
					{
						mode = a[i];
						maxct = ct[a[i]];
					}
			}

		double mean = sum / n;

		if(n % 2 == 0)
			cout << "MEDIAN = " << (a[n / 2 - 1] + a[n / 2]) / 2 << endl;
		else
			cout << "MEDIAN = " << a[n / 2 - 1] << endl;
		cout << "MEAN = " << sum / n << endl;
		cout << "MODE = " << mode << endl;

		for(i = 0; i < n; i++)
			{
				x = abs(mean - a[i]);
				standard += pow(x, 2);
			}

		standard /= n;
		standard = sqrt(standard);

		cout << "STANDARD = " << standard << endl;

		return 0;	
	}