//Problema 3.Vila2

#include <iostream>
#include <cstring>
#include <queue>
#include <deque>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
ifstream f("vila2.in");
ofstream g("vila2.out");
  
int main()
{
	int n, k, mx = 0;
	vector<int> v;
	deque<int>dq_dismin, dq_dismax;
	f >> n >> k;
	for (int i = 0;i < n;i++)
		f >> v[i];
	for (int i = 0;i < n;i++)
	{
		while (v[dq_dismin.back()] > v[i])
			dq_dismin.pop_back();
		while (v[dq_dismax.back()] < v[i])
			dq_dismax.pop_back();
		dq_dismin.push_back(i); 
		if (k > i - dq_dismin.front())
			dq_dismin.front();
		dq_dismax.push_back(i);
		if(k< i-dq_dismax.front())
			dq_dismax.front();
		if (mx <= abs(dq_dismin.front() - dq_dismax.front()))
			mx = abs(dq_dismin.front() - dq_dismax.front());
	}
	//cout<<mx;
	g << mx;
	return 0;
}
