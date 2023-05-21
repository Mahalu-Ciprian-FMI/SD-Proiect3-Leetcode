#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
ifstream f("timbre.in");
ofstream g("timbre.out");

int main()
{
	long n, m, k;
	f >> n >> m >> k;
	long mi, ci;
	long mn = 200001, sum = 0;
	vector<pair<long, long>> v(200001);
	for (auto i = 0;i < m;i++)
	{
		f >> mi;
		v[i].first = mi;
		f >> ci;
		v[i].second = ci;
	}
	while(n>0)
	{
		int contor = 0;
		mn = 2000001;
		for (auto i = 0;i < m;i++) {
			if ((mn > v[i].second) && (v[i].first >= n))
			{
				mn = v[i].second;
				contor = i;
			}
		}
		n = n - k;
		sum += mn;
		v[contor].first = 0;
	}
	g << sum;
	return 0;
}
