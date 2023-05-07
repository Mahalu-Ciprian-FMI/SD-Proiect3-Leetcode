//Problema 7. Deque

#include <iostream>
#include <cstring>
#include <queue>
#include <deque>
#include <fstream>
using namespace std;
ifstream f("deque.in");
ofstream g("deque.out");
int main()
{
	deque<int> dq;
	vector<int> a;
	int n, k;
	f >> n >> k;
	for (int i = 0;i < n;i++)
		f >> a[i];
	int mn = 100000001, sum = 0, ok = 1;
	for (int i = 0;i < k;i++)
	{
		while (ok)
		{
			if (a[i] < a[dq.back()] && !(dq.empty())) //eliminam toate din coada mai mari ca element curent
				dq.pop_back();
			else
				ok = 0;;
		}
		dq.push_back(i);
	}
	ok = 1;
	sum += a[dq.front()];
	for (int i = k + 1;i < n;i++) // acum acelasi lucru de la pozitile k+1 in sus;
	{
		if (i - dq.front() == k)
			dq.pop_front();
		while (ok)
			{
			if ((!dq.empty()) && a[dq.back() > a[i]])
				dq.pop_back();
			else
				ok = 0;
		}
		dq.push_back(i);
		sum += a[dq.front()];
	}
	//cout<<sum;
	g << sum;
	return 0;
}
