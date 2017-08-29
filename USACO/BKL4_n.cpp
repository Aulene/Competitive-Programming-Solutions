#include<iostream>
using namespace std;
#define lli long long int
#define mod 1000000007
#define pb push_back

vector<string> a;

int main()
	{
		string s1, s2, s3, s4, s5, s, st, std;
		int i, ans=1, j;
		vector<string>::iterator it;
		s1="sin";
		s2="log";
		s3="tan";
		s4="cos";
		s5="ln0";
		for(i=0; i<4; i++)
			{
				a.pb(s1);
				a.pb(s2);
				a.pb(s3);
				a.pb(s4);
				a.pb(s5);

				s1=s1.substr(0, s1.size()-1);
				s2=s2.substr(0, s2.size()-1);
				s3=s3.substr(0, s3.size()-1);
				s4=s4.substr(0, s4.size()-1);
				s5=s5.substr(0, s5.size()-1);
			}

		a.pb("e");
		/*
		for(it=a.begin(); it!=a.end(); it++)
			cout << *it << endl;
		*/

		cin >> s;

		while(s.size()>0)
			{
				int flag=s.size();
				for(j=3; j>=1; j--)
					{
						st=s.substr(0, j);
						cout << st << endl;

						for(it=a.begin(); it!=a.end(); it++)
							{
								std=*it;
								if(st==std)
									{
										s=s.substr(j, s.size()-j-);
										i=i+j;
										cout << s << endl;
										break;
									}
							}
					}ak;
					}

				if(flag==s.size())
					{
						ans=0;
						break;
					}
			}

		cout << ans << endl;
		return 0;
	}