//Problema 3.Vila2

#include <iostream>
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
	deque<int>dq_dismin, dq_dismax;
	f >> n >> k;
	vector <int> v(n);
	for (int i = 0;i < n;i++)
		f >> v[i];
	for (int i = 0;i < n;i++)
	{
		while (!dq_dismin.empty() && (v[dq_dismin.back()] >= v[i]) && !dq_dismin.empty())
			dq_dismin.pop_back();
		while (!dq_dismax.empty() && (v[dq_dismax.back()] <= v[i]) && !dq_dismax.empty())
			dq_dismax.pop_back();
		dq_dismin.push_back(i);
		dq_dismax.push_back(i);
		while (!dq_dismin.empty() && (i - k - 1 == dq_dismin.front()) && !dq_dismin.empty())
			dq_dismin.pop_front();
		while (!dq_dismax.empty() && (i - k - 1 == dq_dismax.front()) && !dq_dismax.empty())
			dq_dismax.pop_front();
		if (mx <= (v[dq_dismax.front()] - v[dq_dismin.front()]))
			mx = (v[dq_dismax.front()] - v[dq_dismin.front()]);
	}
	cout << mx;
	g << mx;
	return 0;
}
