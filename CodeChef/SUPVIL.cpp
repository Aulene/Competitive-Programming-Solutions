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

int main()
{
    int t, n, i, hero=1, vil=1;
    string s, s1, s2;
    
    cin >> t;
    
    while(t--)
    {
        hero=1;
        vil=1;

        bool printed=0;

        cin >> n;
        
        for(i=0; i<n; i++)
            {
                cin >> s;
                
                reverse(s.begin(), s.end());

                s1=s.substr(0, 5);
                s2=s.substr(0, 3);

                if(s1=="namow" || s2=="nam")
                    hero++;
                else
                    vil++;

                if(!printed)
                    {
                        if(hero-vil>=2)
                            {
                                //cout << hero << " " << vil << endl;
                                cout << "superheroes" << endl;
                                printed=1;
                            }
                        else if(vil-hero>=3)
                            {
                                //cout << hero << " " << vil << endl;
                                cout << "villains" << endl;
                                printed=1;
                            }
                    }
           }

        if(!printed)
            cout << "draw" << endl;
        //cout << hero << endl << vil << endl;
    }
    
    return 0;
}