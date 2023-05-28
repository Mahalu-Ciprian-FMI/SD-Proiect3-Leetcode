#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("farfurii.in");
ofstream g("farfurii.out");

int main()
{
	long long n, k, m = 0, repetition = 0;
	f >> n >> k;
	while (k > ((m * (m - 1)) >> 1))
		m++;
	for (long long i = 1;i <= n - m;i++)
		g << i << " ";
	if (k < ((m*(m-1))>>1))
	{
		repetition = n + k - ((m * (m - 1)) >> 1);
		g << repetition << " ";
	}
	for (long long i = n;i > n - m;i--)
	{
		if (i != repetition)
		{
			g << i << " ";
		}
	}
	/*if (k == ((m * (m + 1)) >> 1))
{
	for (int i = 1;i <= n - m;i++)
	{
		g << i << " ";
		//cout << i << " ";
	}
	for (int i = n;i >= (n + 1 - m);i--)
	{
		g << i << " ";
		//cout << i << " ";
	}
}
if (k < ((m * (m + 1)) >> 1))
{
	for (int i = 1;i < n - m;i++)
	{
		g << i << " ";
		//cout << i << " ";
	}
	int repetition= n - (((m * (m + 1)) >> 1) - k);
	g << n - (((m * (m + 1)) >> 1) - k) << " ";
	//cout << n - (((m * (m + 1)) >> 1) - k) << " ";
	for (int i = n;i >= n - m;i--)
	{
		if (i != repetition)
		{
			g << i << " ";
			//cout << i << " ";
		}
	}
}*/
	return 0;
}
