//Problema 5. Hotel

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream f("standard.input");
ofstream g("standard.output");
  
int main()
{
	int n, vp[10];
	string s;
	f >> n >> s;
	for (int i = 0;i < n;i++)
	{
		if (s[i] == 'L')
		{
			int j = 0;
			while (s[j] != '0') //iteram pana gasim ceva=0;
				j++;
			s[j] = 1;
		}
		if (s[i] == 'R')
		{
			int k = 9;
			while (s[k] != '0') // ca la 'L' dar de la dreapta la stanga
				k--;
			s[k] = 1;
		}
		if (s[i] != 'L' && s[i] != 'R')
			vp[s[i] - '0'] = 0; // atunci un guest pleaca;
	}
	for (int i = 0;i < n;i++)
	{//cout<<s[i];
		g << s[i];
}
	return 0;
}
