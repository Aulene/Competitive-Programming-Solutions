#include<iostream>
#include<cstdio>
#include<cstdlib>
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
#define p push

struct cmp
{
   	bool operator()(int a, int b)
        {
            return a>b;
        }
};


int main()
{ 
	int i;
    priority_queue<int, vector<int>, cmp> iAmNumberOne;
    
    for(i=0; i<10; i++)
    	iAmNumberOne.p(i);
    
    cout << iAmNumberOne.top() << endl;
    iAmNumberOne.pop();
    cout << iAmNumberOne.top() << endl;
    
    return 0;
}
