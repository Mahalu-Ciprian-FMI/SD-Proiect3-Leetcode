#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("rmq.in");
ofstream g("rmq.out");

int sparse_table[17][100001];
int main()
{
	int n, m;
	f >> n >> m;
	vector<int> v(100001);
	for (int i = 0;i < n;i++)
		f >> v[i];
	for (int i = 0;i < n;i++)
		sparse_table[0][i] = v[i];
	for (int i = 1;(1 << i) <= n;i++)
		for (int j = 0;((j - 1) + (1 << i)) <= n;j++)
			sparse_table[i][j] = std::min(sparse_table[i - 1][j], sparse_table[i - 1][j + (1 << (i - 1))]);
	for (int i = 0;i < m;i++)
	{
		int minim = 0;
		int a, b;
		f >> a >> b;
		int k = int(std::log2(b - a + 1));
		minim = std::min(sparse_table[k][a-1], sparse_table[k][int(b - pow(2, k))]);
		g << minim<<"\n";
	}
	return 0;
}
