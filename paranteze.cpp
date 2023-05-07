//Problema 1.Paranteze
#include <iostream>
#include <cstring>
#include <stack>
#include <fstream>
using namespace std;
ifstream f("paranteze.in");
ofstream g("paranteze.out");
  
int main()
{
	int n, mx = 0;
	string s;
	stack<int> stiva;
	f >> n;
	for (int i = 0;i <n;i++) // i va retine pozitia
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stiva.push(i);
		else {
			if ((s[stiva.top()] == '(' && s[i] == ')') || (s[stiva.top()] = '[' && s[i] == ']') || (s[stiva.top()] == '{' && s[i] == '}'))
			{
				stiva.pop();
				if ((i - stiva.top()) > mx) // distanta de pe stiva intre varful stivei si pozitia curenta
					mx = i - stiva.top();
			}
			else
				stiva.push(i);
		}
	}
	//cout<<mx;
	g << mx;
	return 0;
}
