//Problema 7.alibaba

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
ifstream f("alibaba.in");
ofstream g("alibaba.out");
int main()
{
	int n, k;
	f >> n >> k;
	string nr;
	f >> nr;
	stack<char>stiva;
	for (int i = 0;i < n;i++)
	{
		while (stiva.empty() == false && stiva.top() < nr[i] && k)
		{
			stiva.pop();
			k = k - 1;
		}
		stiva.push(nr[i]);
	}
	while (k)
	{
		stiva.pop();
		k = k - 1;
	}
	string nr_final;
	while (stiva.empty() == false)
	{nr_final = nr_final + (stiva.top()); 
	stiva.pop();
}
	for (int i = nr_final.size()-1;i>=0;i--) // /n ha
	{
		g << nr_final[i];
	}
	return 0;
}
