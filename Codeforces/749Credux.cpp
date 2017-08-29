#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;
 
int main()
{
    int n, i;
    string s;
    int r=0, d=0, occR, occD, x;
    
    cin >> n >> s;

    for(i=0; i<n; i++)
        if(s[i]=='D')
            d++;
        else
            r++;
    occR=r;
    occD=d;
    
    while(true)
        {
            x=r;

            if(d<r)
                {
                    x=r;
                    r-=d;
                }
            else
                {
                    x=d;
                    d-=r;
                }

            if(r==2 && d==2)
                {
                    if(occR>occD)
                        cout << "R" << endl;
                    else
                        cout << "D" << endl;
                    break;
                }

            if(r==1 && d==2)
                {
                    cout << "D" << endl;
                    break;
                }

            if(r==2 && d==1)
                {
                    cout << "R" << endl;
                    break;
                }

            if(r==2 && d==0)
                {
                    cout << "R" << endl;
                    break;
                }

            if(d==2 && r==0)
                {
                    cout << "R" << endl;
                    break;
                }

            if(r==1 && d==2)
                {
                    cout << "D" << endl;
                    break;
                }

            if(r==2 && d==1)
                {
                    cout << "R" << endl;
                    break;
                }

            if(r==0 && d==1)
                {
                    cout << "D" << endl;
                    break;
                }
            else if(r==1 && d==0)
                {
                    cout << "R" << endl;
                    break;
                }
        }
    return 0;
}