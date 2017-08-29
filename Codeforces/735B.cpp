#include<iostream>
#include<algorithm>

using namespace std;

#define lli long long int

int a[100007];

int main()
{
	lli n, n1, n2, i;
	lli temp;

	cin >> n >> n1 >> n2;

	for(i=0; i<n; i++)
		cin >> a[i];

	sort(a, a+n);

	double ans;
	double sum1=0, sum2=0;
	double num=0;

	if(n1>n2)
		{
			temp=n1;
			n1=n2;
			n2=temp;
		}

	for(i=n-1; i>=0; i--)
		{
			if(num==n1+n2)
				break;

			if(num<n1)
				{
					sum1+=a[i];
					num++;
				}
			else
				{
					sum2+=a[i];
					num++;
				}
		}

	ans=sum1/n1+sum2/n2;
	printf("%0.12f", ans);
	cout << endl;
	return 0;
}