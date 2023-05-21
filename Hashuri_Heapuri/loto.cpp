#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
ifstream f("loto.in");
ofstream g("loto.out");

int main()
{
	vector<int> v(101);
	unordered_map<int, int[3]> map;
	int n;
	long long s;
	f >> n >> s;
	int ok = 0;
	for (int i = 0;i < n;i++)
	{
		f >> v[i];
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = i;j < n;j++)
		{
			for (int k = j;k < n;k++)
			{
				map[v[i] + v[j] + v[k]][0] = v[i];
				map[v[i] + v[j] + v[k]][1] = v[j];
				map[v[i] + v[j] + v[k]][2] = v[k];
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = i;j < n;j++)
		{
			for (int k = j;k < n;k++)
			{
				long aux = s - (v[i] + v[j] + v[k]);
				if (map.find(aux) != map.end())
				{
					g << v[i] << " " << v[j] << " " << v[k];
					g << " " << map[aux][0] << " " << map[aux][1] << " " << map[aux][2];
					ok = 1;
					break;
				}
			}
			if (ok)
				break;
}
		if (ok)
			break;
}
	if (ok == 0)
		g << -1;
	return 0;
}
