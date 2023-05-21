#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
ifstream f("muzica.in");
ofstream g("muzica.out");

int main()
{
	long long n, m, number;
	f >> n >> m;
	long long a, b, c, d, e, corespunde = 0;
	f >> a >> b >> c >> d >> e;
	unordered_map<long long, bool> map(10001);
	for (int i = 0;i < n;i++)
	{
		f >> number;
		map[number] = 1;
	}
	for (int i = 0;i < m;i++)
	{
		if (i == 0)
			if (map.find(a)!= map.end())
			{
				corespunde++;
				map.erase(a);
			}
		if(i==1)
			if (map.find(b)!= map.end())
			{
				corespunde++;
				map.erase(b);
			}
		if (i != 0 && i != 1) {
			int aux = ((c * b) + (d * a)) % e;
			a = b;
			b = aux;
			if (map.count(aux) != 0)
			{
				corespunde++;
				map.erase(aux);
			}
		}
	}
	g << corespunde;
	return 0;
}
