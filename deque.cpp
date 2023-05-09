#include <iostream>
#include <cstring>
#include <queue>
#include <deque>
#include <vector>
#include <fstream>
using namespace std;
ifstream f("deque.in");
ofstream g("deque.out");
int main()
{
	deque<int> dq;
	int n, k;
	f >> n >> k;
	vector<int> a(n);
	for (int i = 0;i < n;i++)
		f >> a[i];
	long sum = 0;
	for (int i = 0;i < n;i++)
	{
		while(!(dq.empty()) &&(a[i] <= a[dq.back()]))
			dq.pop_back();
		dq.push_back(i);
		//cout << dq.back() << "back";
		//cout << dq.front() << "front";
		if (k == i - dq.front())
			dq.pop_front();
		if (i>=k-1)
			sum += a[dq.front()];
	}
	//cout << sum;
	g << sum;
	return 0;
}
