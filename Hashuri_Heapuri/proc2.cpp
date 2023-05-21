#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
ifstream f("proc2.in");
ofstream g("proc2.out");

int main()
{
	int n, m;
	int si, di;
	f >> n >> m;
	priority_queue<int> P1;
	for (int i = 1;i <= n;i++)
	{
		P1.push(-(i));
	}
	priority_queue<pair<int, int>> P2;
	for (int i = 0;i < m;i++)
	{
		f >> si >> di;
		while (P2.empty()!=true && (-( P2.top().first)) <= si)
		{
			P1.push(-(P2.top().second));
			P2.pop();
		}
		P2.push({ - (si + di), -(P1.top())});
		g << (-(P1.top())) << "\n";
		P1.pop();
	}


	return 0;
}
