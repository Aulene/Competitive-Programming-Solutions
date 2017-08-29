/*
ID: aussyle1
PROG: runround
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<sstream>
#include<climits>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>   
#include<queue>
#include<stack>
#include<set>
#include<list>
#include<fstream>

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

bool nozero(string s)
{
    int n, i;
    n=s.size();

    for(i=0; i<n; i++)
        if(s[i]=='0')
            return 0;

    return 1;
}

bool unique(string s)
{
    map<char, int> a;

    int n=s.size(), i;

    for(i=0; i<n; i++)
        if(a[s[i]])
            return 0;
        else
            a[s[i]]++;

    return 1;
}

string tostr(int n)
{
    ostringstream temp;
    temp<<n;
    return temp.str();
}

bool isRunaround(string s)
{
    bool visited[17];
    memset(visited, 0, sizeof(visited));

    lli i, count, run, newi, n;
    bool ans=1;
    
    n=s.size();
    
    i=0;
    
    while(!visited[i])
        {
            //cout << i << " " << s[i] << endl;
            visited[i]=1;
            run=s[i]-'0';
            //cout << run << endl;
            i+=run;
            i=i%n;
        }

    if(i!=0)
        ans=0;

    //cout << endl;
    for(i=0; i<n; i++)
        if(!visited[i])
            ans=0;

    return ans;
}

int main()
{
    ifstream fin ("runround.in");
    ofstream fout ("runround.out");

    lli n, i;
    string s;
    
    fin >> n;

    for(i=n+1; ; i++)
        {
            //cout << i << endl;
            s=tostr(i);
            //cout << s << endl;
            if(nozero(s) &&  unique(s) && isRunaround(s))
                {
                    fout << s << endl;
                    return 0;
                }
        }
    
    return 0;
}
