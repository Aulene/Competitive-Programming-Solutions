#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
using namespace std;
int TAB[107];
int main()
{
    int n;
    int m;
    scanf("%d%d",&n,&m);
    if(n==1 and m==0)
    {
    	printf("1");
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==n)
        {
        	printf("%d",b);
        	return 0;
        }
		TAB[a]=b;
    }
    int ilo=0;
    bool logic=0;
    int odp;
	for(int i=1;i<=103;i++)
	{
		logic=0;
		for(int j=1;j<=100;j++)
		{
			if(TAB[j]!=0)
			{
				if(j%i==0)
				{
					if(TAB[j]!=(j/i))
					{
						logic=1;
					}
				}
				else
				{
					if(TAB[j]!=(j/i)+1)
					{
						logic=1;
					}
				}
			}
		}
		if(logic==0)
		{
			ilo++;
			odp=i;
		}
	}
    if(ilo!=1)
    {
    	printf("-1");
    }
    else
    {
    	if(n%odp==0)
    	{
    		printf("%d",n/odp);
    		return 0;
    	}
    	printf("%d",(n/odp)+1);
    }
}