//Problema 5. Hotel

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("standard.in");
ofstream g("standard.out");

int main()
{
	int n;
	int vp[10];
	string s;
	f >> n >> s;
	for (int i = 0;i <=9;i++)
		vp[i] = 0;
	for (int i = 0;i < n;i++)
	{
		if (s[i] == 'L')
		{
			int j = 0;
			while (vp[j] != 0 && j!=9) //iteram pana gasim ceva=0;
				j++;
			vp[j] = 1;
		}
		if (s[i] == 'R')
		{
			int k = 9;
			while (vp[k] != 0 && k!=0) // ca la 'L' dar de la dreapta la stanga
				k--;
			vp[k] = 1;
		}
		if (s[i] !='L' && s[i] != 'R')
			vp[int(s[i] - '0')] = 0; // atunci un guest pleaca;
	}
	for (int i = 0;i < 10;i++)
	{
		cout<<vp[i];
		g << vp[i];
	}
	return 0;
}
